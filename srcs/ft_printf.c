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

char    *xtnd_buf(int width, char *cur, char *new)
{
    char    *str;

    str = ft_strjoin(cur, new);
    free(cur);
    free(new);
    return(str);
}

int         ft_printf(const char *format, ...)
{
    va_list     vars;
    t_var       *temp;
    char        *str;
    int         *i;
    int         cnt;

    i = 0;
    cnt = 0;
    va_start(vars, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '%')
                store_in; //print
            else
            {
                //arg = va_arg(vars, int);
                find_extension(format, &i, &temp);
                if (
                //store_magic();
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

int     main()
{
    char    *str = "asdf";
    ft_printf("%0+s", str);
    return(0);
}