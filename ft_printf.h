/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:07:14 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/17 21:08:19 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<ctype.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

int ft_printf(const char *argv, ...);
int ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif