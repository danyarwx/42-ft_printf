/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:23:55 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/02 19:49:12 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list *p_args)
{
	int				count;
	unsigned long long	ptr;

	ptr = (unsigned long long)va_arg(*p_args, void *);
	count = 0;
	if (!ptr)
	{
		#ifdef __APPLE__
			return (write(1, "0x0", 3));
		#else
			return (write(1, "(nil)", 5));
		#endif
	}
	count += write(1, "0x", 2);
	ft_puthex(ptr, 'x');
	return (count + ft_hexlen(ptr));
}
