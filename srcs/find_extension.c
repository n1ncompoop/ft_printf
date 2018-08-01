#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

char	*ft_strstrchr(char *str, char *s)
{
	int		i;
    int     j;
	j = 0;
    while (str[j])
    {
        i = 0;
        while (s[i])
        {
            if (s[i] == str[j])
            {
                j++;
                return(&str[j]);
            }
            else
                i++;
        }
        j++;
    }
	return (NULL);
}
/*
char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (chr == '\0')
		{
			while (*s)
				s++;
			return ((char *)s);
		}
		else if (*s != chr)
			s++;
		else
			return ((char *)s);
	}
	return (NULL);
}
*/
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	chr;

	i = 0;
	str = (char *)b;
	chr = (unsigned char)c;
	while (i < len)
	{
		str[i] = chr;
		i++;
	}
	return (str);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (void *)malloc(size * (sizeof(mem)))))
		return (NULL);
	else
		ft_memset(mem, 0, size);
	return (mem);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

void    init_t_var(t_var *temp)
{
    temp->flag_dash = 0;
    temp->flag_sign = 0;
    temp->flag_space = 0;
    temp->flag_sharp = '\0';
    temp->flag_zero = 0;
    temp->width = 0;
    temp->precision = 6;
    temp->length = ft_strnew(2);
    temp->conv = '\0';
}

int     check_flags(const char *format, int *i, t_var *temp)
{
    if (format[*i] == '-')
    {
        if (temp->flag_zero != 1)
            temp->flag_dash = 1;
        else
        {
            printf("Can't left justiy ('-') and pad zero ('0')\n");
            return(-1);
        }
        return(1);
    }
    if (format[*i] == '+')
    {
        temp->flag_space = 0;
        temp->flag_sign = 1;
        return(1);
    }
    if (format[*i] == '0')
    {
        if (temp->flag_dash != 1)
            temp->flag_zero = 1;
        else
        {
            printf("print error message\n");
            return(-1);
        }
        return(1);
    }
    if (format[*i] == ' ')
    {
        if (temp->flag_sign != 1)
            temp->flag_space = 1;
        return(1);
    }
    if (format[*i] == '#')
    {
        (*i)++;
        if (format[*i] == 'o')
            temp->flag_sharp = 'o';
        else if ((format[*i] == 'x') || (format[*i] == 'X'))
            temp->flag_sharp = 'x';
        else
        {
            printf("the hash given is not supported %c", format[*i]);
            return(-1);
        }
        //add more #_flag functions
        return(1);
    }
    return(0);
}

void     find_width_precision(const char *format, int *i, t_var *temp)
{
    int     width;
    int     precision;

    width = 0;
    precision = 6; //default value?
    if (format[*i] == '*')
    {
        temp->width = va_arg(list, int);
        (*i)++;
    }
    else
    {
        while (ft_isdigit(format[*i]))
        {
            width = (width * 10) + (format[*i] - '0');
            (*i)++;
        }
    }
    if (format[*i] == '.')
    {
        if (format[*i] == '*')
        {
            temp->precision = va_arg(list, int);
            (*i)++; 
        }
        else
        {
            precision = 0;
            (*i)++;
            while (ft_isdigit(format[*i]))
            {
                precision = (precision * 10) + (format[*i] - '0');
                (*i)++;
            }
        }
    }
    temp->width = width;
    temp->precision = precision;
}

int    find_length(const char *format, int *i, t_var *temp)
{
    if ((format[*i] == 'j' || format[*i] == 'z' || format[*i] == 't' || format[*i] == 'L') )
    {
        temp->length = (char *)&format[*i];
        (*i)++;
        return(1);
    }
    else if (format[*i] == 'h')
    {
        (*i)++;
        if (format[*i] == 'h')
        {
            temp->length = "hh";
            (*i)++;
            return(1);
        }
        else
        {
            temp->length = "h";
            return(1);
        }
    }
    else if (format[*i] == 'l')
    {
        (*i)++;
        if (format[*i] == 'l')
        {
            temp->length = "ll";
            (*i)++;
            return(1);
        }
        else
        {
            temp->length = "l";
            return(1);
        }    
    }
    return (0);
}

int     find_conv(const char *format, int *i, t_var *temp)
{
    if (format[*i] == 's' || format[*i] == 'p' || format[*i] == 'd' || format[*i] == 'u' || format[*i] == '%' ||
    format[*i] == 'o' || format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'i' || format[*i] == 'c')
    {
        temp->conv = (char)format[*i];
        (*i)++;
        return (1);
    }
    else if (format[*i] == 'S' || format[*i] == 'D' || format[*i] == 'U' || format[*i] == 'C')
    {
        temp->conv = (char)(format[*i] + 32);
        (*i)++;
        return (1);
    }
    return(0);
}

int     find_extension(const char *format, int *i, t_var *temp)
{
    int     flg;
    int     ln;
    int     conv;

    while ((flg = check_flags(format, i, temp)))
    {
        if (flg < 0)
        {
            return(-1);
        }
        else if (flg == 0)
        {
            flg = 1;
            break;
        }
        else
            (*i)++;
    }
    find_width_precision(format, i, temp);
    ln = find_length(format, i, temp);
    if ((conv = find_conv(format, i, temp)) && (temp->conv))
    {
        printf("%d%d%dgood\n", flg, ln, conv);
        return(1);
    }
    printf("%d%d%dfail\n", flg, ln, conv);
    return(0);
}

void    print_var_data(t_var *temp)
{
    printf("%d dash\n%d sign\n", temp->flag_dash, temp->flag_sign);
    printf("%d space\n%c sharp\n", temp->flag_space, temp->flag_sharp);
    printf("%d zero\n%d width\n", temp->flag_zero, temp->width);
    printf("%d precision\n%s length\n%c conv\n", temp->precision, temp->length, temp->conv);
}

t_var   percentstr_to_var(char *str)
{
    //char *format, ... in main
    //va_list lstptr;
    //va_start(lstptr, *format)
    t_var   *temp;
    int     i;
    i = 0;
    temp = (t_var *)ft_memalloc(sizeof(t_var));
    init_t_var(temp);
    ///find_extension(str, &i, temp)///
    if (find_extension(str, &i, temp) == 1)
        print_var_data(temp);
    return(temp);
}

int ft_printf(const char *format, ...)
{
    char    *store;
    char    **tmp;
    t_var   *full;
    int     argg;
    size_t  chr_save;
    int     i;
    va_list lst;

    va_start(lst, *format);

    i = 0;
    tmp = (char**)malloc(sizeof(char**));
    while (*format)
    {
        if ((store = ft_strchr(format, '%')) != NULL)
        {//STRING
            *store = '\0';
            tmp[i] = ft_strdup(format);
            printf("%s\n", tmp[i]);
            tmp[i] = (char *)l=malloc(sizeof(char) * ft_strlen(format));
            tmp[i] = format;
            free(format);
            *format = (*store)++;
            i++;
            argg = 1;
        }
        if (argg == 1)
        {//ARGS
            store = ft_strstrchr(format, "sDpdDuUoxXicC%");
            chr_save = (size_t)(store - format);
            tmp[i] = ft_strnew(chr_save);
            ft_strncpy(tmp[i], format, chr_save);
            *format += chr_save;
            argg = 0;
            i++;
            ///new function to convert data to print string
            *full = percentstr_to_var(tmp[i]);

        }
    }

    //find until % -> conv
    //string append to full
    //verify %string
    //convert %string to real
    //append real to full
    
}

int main()
{
    ft_printf("bdsvajb%s", "AAAA");
}6