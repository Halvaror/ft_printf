/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:07:14 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/27 16:27:40 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<ctype.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdarg.h>
# include<string.h>

# define UPPER_HEX "0123456789ABCDEF"
# define LOWER_HEX "0123456789abcdef"

int ft_printf(const char *argv, ...);
int ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n, int check);
int	ft_putnbr_hex(unsigned int nbr, char *base, int check);
int	ft_putnbr_u(unsigned int n, int check);
int ft_ptraddress(void *ptr, char *base);
int	ft_putnbr_ptr(unsigned long nbr, char *base, int check);

#endif