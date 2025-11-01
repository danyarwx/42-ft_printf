/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:22:23 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 22:22:54 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long n)
{
	int	count;

	count = 1;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

void	ft_puthex(unsigned long n, char upper)
{
	char	*base;
	char	c;

	if (upper == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, upper);
	}
	c = base[n % 16];
	write(1, &c, 1);
}
