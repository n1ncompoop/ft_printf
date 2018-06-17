#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int     check_flags(char *format, int *i, t_var *extn)
{
    if (format[*i] == '-')
    {
        if (extn->flag_zero != 1)
            extn->flag_dash = 1;
        else
        {
            printf("print error message\n");
            return(-1);
        }
        return(1);
    }
    if (format[*i] == '+')
    {
        extn->flag_space = 0;
        extn->flag_sign = 1;
        return(1);
    }
    if (format[*i] == '0')
    {
        if (extn->flag_dash != 1)
            extn->flag_zero = 1;
        else
        {
            printf("print error message\n");
            return(-1);
        }
        return(1);
    }
    if (format[*i] == ' ')
    {
        if (extn->flag_sign != 1)
            extn->flag_space = 1;
        return(1);
    }
    if (format[*i] == '#')
    {
        i++;
        if (format[*i] == 'o')
            extn->flag_sharp = 'c';
        if ((format[*i] == 'x') || (format[*i] == 'X'))
            extn->flag_sharp = 'x';
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

void     find_width_precision(char *format, int *i, t_var *extn)
{
    int     width;
    int     precision;

    width = 0;
    precision = 6; //default value?
    while (ft_isdigit(format[*i]))
    {
        width = (width * 10) + (format[*i] - '0');
    }
    if (format[*i] == '.')
    {
        precision = 0;
        i++;
        while (ft_isdigit(format[*i]))
        {
            precision = (precision * 10) + (format[*i] - '0');
        }
    }
    extn->width = width;
    extn->precision = precision;
}

int    find_length(char *format, int *i, t_var *extn)
{
    if ((format[*i] == 'j' || format[*i] == 'z' || format[*i] == 't' || format[*i] == 'L') )
    {
        extn->length = &format[*i];
        i++;
        return(1);
    }
    else if (format[*i] == 'h')
    {
        i++;
        if (format[*i] == 'h')
        {
            extn->length = "hh";
            i++;
            return(1);
        }
        else
        {
            extn->length = &format[*i];
            return(1);
        }
    }
    else if (format[*i] == 'l')
    {
        i++;
        if (format[*i] == 'l')
        {
            extn->length = "ll";
            i++;
            return(1);
        }
        else
        {
            extn->length = &format[*i];
            return(1);
        }    
    }
    return (0);
}

int     find_conv(char *format, int *i, t_var *extn)
{
    if (format[*i] == 's' || format[*i] == 'p' || format[*i] == 'd' || format[*i] == 'u' || format[*i] == '%' ||
    format[*i] == 'o' || format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'i' || format[*i] == 'c')
    {
        extn->conv = format[*i];
        i++;
        return (1);
    }
    else if (format[*i] == 'S' || format[*i] == 'D' || format[*i] == 'U' || format[*i] == 'C')
    {
        extn->conv = (format[*i] + 32);
        i++;
        return (1);
    }
}

int     find_extension(char *format, int *i, t_var *extn)
{
    int     flg;
    int     ln;
    int     conv;

    while ((flg = check_flags(format, i, extn)))
    {
        if (flg < 0)
        {
            return(-1);
        }
        if (flg == 0)
        {
            flg = 1;
            break;
        }
    }
    find_width_precision(format, i, extn);
    ln = find_length(format, i, extn);
    conv = find_conv(format, i, extn);
    printf("%d%d%d", flg, ln, conv);

    return(1);
}