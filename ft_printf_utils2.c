/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:18:13 by alopez-b          #+#    #+#             */
/*   Updated: 2021/11/25 21:02:46 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_u(unsigned int n, int check)
{
	unsigned int	res;
	static int count = 0;

	if (check ==0)
		count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		res = (n * -1);
		count++;
	}
	else
		res = n;
	if (res >= 10)
		ft_putnbr_u(res / 10, 1);
	count += ft_putchar((char)(res % 10 + 48));
	return(count);
}