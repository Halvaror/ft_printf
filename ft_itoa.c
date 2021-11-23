/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-b <alopez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:36:27 by alopez-b          #+#    #+#             */
/*   Updated: 2021/09/04 18:31:35 by alopez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	checklength(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*minnum(int n, int i)
{
	char	*num;

	num = ft_calloc(i + 2, 1);
	if (!num)
		return (NULL);
	num[0] = '-';
	num[1] = '2';
	n = 147483648;
	while (i > 1)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

static char	*negnum(int n, int i)
{
	char	*num;

	num = ft_calloc(i + 2, 1);
	if (!num)
		return (NULL);
	num[0] = '-';
	n = -n;
	while (i > 0)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

static char	*posnum(int n, int i)
{
	char	*num;

	num = ft_calloc(i + 1, 1);
	if (!num)
		return (NULL);
	i = i - 1;
	while (i >= 0)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;

	i = checklength(n);
	if (n == 0)
		i = 1;
	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	if (n == -2147483648)
	{
		num = minnum(n, i);
		return (num);
	}
	if (n < 0)
		num = negnum(n, i);
	else
		num = posnum(n, i);
	return (num);
}
