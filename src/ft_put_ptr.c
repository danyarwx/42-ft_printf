/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:23:55 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 23:40:10 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list *p_args)
{
	int count;
	unsigned long long ptr;

	ptr = va_arg(*p_args, unsigned long long);

	count = write(1, "0x", 2);

	ft_puthex(ptr, 'x');

	return (count + ft_hexlen(ptr));
}
