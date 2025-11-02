/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:23:55 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/02 19:12:46 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list *p_args)
{
	int				count;
	unsigned long long	ptr;

	ptr = (unsigned long long)va_arg(*p_args, void *);
	count = 0;
	count += write(1, "0x", 2);
	if (ptr == 0)
		return (count + write(1, "0", 1));
	ft_puthex(ptr, 'x');
	return (count + ft_hexlen(ptr));
}
