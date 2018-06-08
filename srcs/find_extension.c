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

char    *find_length(char *format, int *i, t_var extn)
{

    
}