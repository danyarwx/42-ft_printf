/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:19:42 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 22:21:39 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int n)
{
	int	count;

	if (n == -2147483648)
		return (11);
	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_arg(long long n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
	}
	if (n > 9)
	{
		ft_putnbr_arg(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}
