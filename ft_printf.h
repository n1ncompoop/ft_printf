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
typedef struct      s_extn
{
    void    *data;
    int     flag_left;
    int     flag_sign;
    int     flag_zero;
    int     flag_space;
    char    flag_hash;
    int     width;
    int     precision;
    int     length;
    char    conv;
}                   t_extn;

# endif
