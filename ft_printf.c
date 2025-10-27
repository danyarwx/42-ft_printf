/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:16:33 by dzhukov           #+#    #+#             */
/*   Updated: 2025/10/27 21:39:49 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdarg.h>

int	ft_printf(const char *s, ...)
{
	size_t	i;
	size_t	total;
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
			// pass s[i] and va_arg to the other function
			// decide based on the type cspdiuxX%
		}
		i++;
	}
	return (va_end(args), total);
}













// #include <stdio.h>

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

// int main()
// {
// 	printf("The sum is %d\n", sum(5, 2, 3, 2, 4, 3, 5, 0));

// 	return (0);
// }
