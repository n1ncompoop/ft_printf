int     check_flags(char *format, int *i, t_var extn)
{
    if (format[i] == '-')
    {
        if (extn.zero != 1)
            extn.dash = 1;
        else
        {
            printf("print error message\n");
            return(-1);
        }
        return(1);
    }
    if (format[i] == '+')
    {
        extn.space = 0;
        extn.sign = 1;
        return(1);
    }
    if (format[i] == '0')
    {
        if (extn.dash != 1)
            extn.zero = 1;
        else
        {
            printf("print error message\n");
            return(-1);
        }
        return(1);
    }
    if (format[i] == ' ')
    {
        if (extn.sign != 1)
            extn.space = 1;
        return(1);
    }
    if (format[i] == '#')
    {
        i++;
        if (format[i] == 'o')
            extn.hash = o;
        if (format[i] == 'x') || (format[i] == 'X')
            extn.hash = x;
        else
        {
            printf("the hash given is not supported %c", format[i]);
            return(-1);
        }
        //add more #_flag functions
        return(1);
    }
    return(0);
}

int     find_width_precision(char *format, int *i, t_var *extn)
{
    int     width;
    int     precision;

    width = 0;
    precision = 6;
    while (ft_isdigit(format[i]))
    {
        width = (width * 10) + (format[i] - '0');
    }
    if (format[i] == '.')
    {
        precision = 0;
        i++;
        while (ft_isdigit(format[i]))
        {
            precision = (precision * 10) + (format[i] - '0');
        }
    }
    return(1);
}

int    find_length(char *format, int *i, t_var extn)
{
    if ((format[i] == 'j' || format[i] == 'z' || format[i] == 't' || format[i] == 'L') && !(extn.length))
    {
        extn.length = format[i];
        i++;
        return(1);
    }
    else if (format[i] == 'h')
    {
        i++;
        if (format[i] == 'h')
        {
            extn.length = 'hh';
            i++;
            return(1);
        }
        else
        {
            extn.length = format[i];
            return(1);
        }
    }
    else if (format[i] == 'l')
    {
        i++;
        if (format[i] == 'l')
        {
            extn.length = 'll';
            i++;
            return(1);
        }
        else
        {
            extn.length = format[i];
            return(1);
        }    
    }
    return (0);
}

int     find_conv(char *format, int *i, t_var extn)
{
    if (format[i] == 's' || format[i] == 'p' || format[i] == 'd' || format[i] == 'u' || format[i] == '%' ||
    format[i] == 'o' || format[i] == 'x' || format[i] == 'X' || format[i] == 'i' || format[i] == 'c')
    {
        extn.conv = format[i]
        i++;
        return (1);
    }
    else if (format[i] == 'S' || format[i] == 'D' || format[i] == 'U' || format[i] == 'C')
    {
        extn.conv = (format[i] + 32)
        i++;
        return (1);
    }
}