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

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

/*char    *xtnd_buf(int width, char *cur, char *new)
{
    char    *str;

    str = ft_strjoin(cur, new);
    free(cur);
    free(new);
    return(str);
}
*/

void    init_t_var(t_var *temp)
{
    temp->flag_dash = 0;
    temp->flag_sign = 0;
    temp->flag_space = 0;
    temp->flag_sharp = NULL;
    temp->flag_zero = 0;
    temp->width = 0;
    temp->precision = 6;
    temp->*length = NULL;
    temp->conv = NULL;
}

t_var         ft_printf(const char *format) //...)
{
//    va_list     vars;
    t_var       /*star*/*temp;
    //char        *str;
    int         *i;
    int         cnt;

    i = 0;
    cnt = 0;
    init_t_var(temp);
//    va_start(vars, format);
    while (format[*i] != '\0')
    {
        if (format[*i] == '%')
        {
            i++;
            if (format[*i] == '%')
                //print
                printf("%%");
            else
            {
                //arg = va_arg(vars, int);
                find_extension(format, i, /*ad*/temp);
                print_var_data(temp);
                //store_magic();
            }
        }
        else
        {
            printf("w");
            //find_next_%
            //store_in; //print
        }
        i++;
    }
    return (*temp);
}

void    print_var_data(t_var *temp)
{
    printf("%d dash\n %d sign\n", temp->flag_dash, temp->flag_sign);
    printf("%d space\n %c sharp\n", temp->flag_space, temp->flag_sharp);
    printf("%d zero\n %d width\n", temp->flag_zero, temp->width);
    printf("%d precision\n %s length\n %c conv\n", temp->precision, temp->length, temp->conv);
}

int     main()
{
    t_var   poop;

    poop = ft_printf("%0+scsdkjnc%%");
    return(0);
}