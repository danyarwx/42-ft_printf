/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:22:23 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/02 19:06:25 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

void	ft_puthex(unsigned long long n, char upper)
{
	char	*base;
	char	c;

	if (upper == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16, upper);
	c = base[n % 16];
	write(1, &c, 1);
}

// int	main(void)
// {
// 	unsigned int nums[] = {0, 1, 9, 10, 15, 16, 42, 255, 4096, 4294967295};
// 	int i;

// 	for (i = 0; i < 10; i++)
// 	{
// 		unsigned int n = nums[i];

// 		printf("number: %u\n", n);

// 		write(1, "ft_puthex (x): ", 15);
// 		ft_puthex(n, 'x');
// 		write(1, "\n", 1);

// 		write(1, "ft_puthex (X): ", 15);
// 		ft_puthex(n, 'X');
// 		write(1, "\n", 1);

// 		printf("printf %%x: %x\n", n);
// 		printf("printf %%X: %X\n\n", n);
// 	}
// 	return (0);
// }
