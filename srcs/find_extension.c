int     check_flags(char *format, int *i)
{
    if (format[i] == '-')
        extn.dash = 1;
    if (format[i] == '+')
        extn.sign = 1;
    if (format[i] == '0')
        if (extn.dash != 1)
            extn.zero = 1;
    if (format[i] == ' ')
        if (extn.sign != 1)
            extn.space = 1;
    if (format[i] == '#')
    {
        i++;
        if (format[i] == 'o')
            extn.hash = o;
        if (format[i] == 'x') || (format[i] == 'X')
            extn.hash = x;
    }
}

                    var.flag = check_flags(format, &i);
                    var.width = check_width(format, &i);
                    var.precision = check_precision(format, &i);
                    var.length = check_length(format, &i);
                    var.conv = check_conv(format, &i)