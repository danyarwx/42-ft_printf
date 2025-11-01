/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:16:33 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 17:47:36 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar_arg(va_list *p_args)
{
	char	c;

	c = va_arg(*p_args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_arg(va_list *p_args)
{
	char	*s;
	int		i;

	s = va_arg(*p_args, char *);
	i = 0;
	while (s[i])
		write(1, &(s[i++]), 1);
	return (i);
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


int	ft_putptr(va_list *p_args)
{
	int count;
	void * ptr;

	ptr = va_arg(*p_args, void *);

	count = write(1, "0x", 2);

	ft_puthex(ptr, 'x');

	return (count + ft_hexlen(ptr));
}


int	ft_switch(char c, va_list *p_args)
{
	long	n;

	if (c == 'c')
		return (ft_putchar_arg(p_args));
	else if (c == 's')
		return (ft_putstr_arg(p_args));
	else if (c == 'p')
		return (ft_putptr(p_args));
	else if (c == 'd' || c == 'i')
	{
		n = va_arg(*p_args, int);
		return (ft_putnbr_arg(n), ft_intlen(n));
	}
	else if (c == 'u' || c == 'x' || c == 'X')
	{
		n = va_arg(*p_args, unsigned int);
		if (c == 'x' || c == 'X')
			return (ft_puthex(n, c), ft_hexlen(n));
		else
			return (ft_putnbr_arg(n), ft_intlen(n));
	}
	else if (c == '%')
		return (write(1, "%", 1));
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		total;
	va_list	args;

	va_start(args, s);
	total = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			total++;
		}
		else
		{
			total += ft_switch(s[++i], &args);
			// pass s[i] and va_arg to the other function
			// decide based on the type cspdiuxX%
		}
		i++;
	}
	return (va_end(args), total);
}

#include <stdio.h>

// int sum(int a, ...)
// {
// 	va_list args;
// 	va_start(args, a); // Put the function parameters in the stack

// 	int i = 0;
// 	int s = a;
// 	int x = va_arg(args, int);	// Go to the next element in the stack
// 	while (x != 0)
// 	{
// 		s += x;
// 		x = va_arg(args, int);
// 	}
// 	va_end(args); // Free the stack after usage
// 	return (s);
// }

int	main(void)
{
	unsigned int	n;
	void * ptr;
	char			str[] = "hello world";
	int result;

	n = 123;
	ptr = &n;

	printf("The printf result is : %p\n", ptr);
	// printf("The printf result is : %X\n", n);
	result = ft_printf("My result is : %p\n", ptr);
	// ft_printf("My result is : %X\n", n);
	ft_printf("Function printed %d characters.", result);
	return (0);
}
