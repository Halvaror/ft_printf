/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:07:14 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/23 21:47:01 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<ctype.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>

# define UPPER_HEX "0123456789ABCDF"
# define LOWER_HEX "0123456789abcdf"

int ft_printf(const char *argv, ...);
int ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n, int check);
int	ft_putnbr_hex(int nbr, char *base, int check);

#endif