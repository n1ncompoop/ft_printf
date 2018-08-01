#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
   int		main()
   {
   double	one;
   int		two;

   one = 1099.123;
   two = 50;

   printf("-9.1 % 0.1f---\n", one);
   printf("10.1 %0+10.1d---#\n", two);
//	printf("10.2 %------+++++.2f---\n", one);
//	printf("10.3 %0-+10.3f---\n", one);
printf("11.3 %0+11.3f---\n", one);
printf("12.3 %0+12.3f---\n", one);		
printf("%-6s%-5d\n", "num =", 456);
printf("%-6s%5d\n", "num =", 456);
printf("%6s%-5d\n", "num =", 456);
printf("%%");
printf("%*.*s", 3, 3, "abcdef");	
return(0);
}*/
char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(size + 1)))
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

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
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

int main()
{
	char *s1;
	char *s2;
	char *str;
    size_t d;
    char *tmp;
//	char *test;

	s1 = "adsuadb";
	s2 = "bu";
	str = ft_strstrchr(s1, s2);
//	test = s1 - str;

	d = (size_t)(str - s1);
    tmp = ft_strnew(d);
    ft_strncpy(tmp, s1, d);
	printf("%s\n", str);
    printf("%s\n", tmp);
	return(0);
}

/*
char	*xtnd_full(c

int		main()
{
    char    *string;
    char    *store;
    t_lst   *full;
    int     argg;

    string = "PRINTTHIS %04.3s PRINTTHIS";
    while (*string)
    {
        if ((store = ft_strchr(string, '%')) != NULL)
        {//STRING
            *store = '\0';
            full = xtnd_full(full, string);
            free(string);
            string = *store + 1;
            argg = 1;
        }
        if (argg == 1)
        {//ARGS
            store = ft_strchr(string, )
            argg = 0;
        }


    }

    //find until % -> conv
    //string append to full
    //verify %string
    //convert %string to real
    //append real to full
    return(0);
}	*/
