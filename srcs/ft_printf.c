/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:46:11 by rkwon             #+#    #+#             */
/*   Updated: 2018/05/22 19:07:07 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int         ft_printf(const char *format, ...)
{
    va_list     vars;
    int         i;
    int         cnt;

    i = 0;
    cnt = 0;
    va_start(vars, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
                store_in; //print
            else
            {
                find extension
                {
                    var.flag = check_flags(format, &i);
                    var.width = check_width(format, &i);
                    var.precision = check_precision(format, &i);
                    var.length = check_length(format, &i);
                    var.conv = check_conv(format, &i)
                }
                find conversion
                {
                    get_var;
                    change_var;
                    store_in; //print
                }
            }
        }
        else if (format[i] != '%')
        {
            find_next_%
            store_in; //print
        }
        i++;
    }
    return (cnt);
}

get_cnt
    malloc_cnt
    print_in;
