/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:47:12 by rkwon             #+#    #+#             */
/*   Updated: 2018/05/22 17:49:43 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
typedef struct      s_var
{
    int     flag_dash;
    int     flag_sign;
    int     flag_space;
    char    flag_sharp;
    int     flag_zero;
    int     width;
    int     precision;
    char    *length
    char    conv;
}                   t_var;

# endif
