/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:23:55 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 22:24:30 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(va_list *p_args)
{
	int count;
	void * ptr;

	ptr = va_arg(*p_args, void *);

	count = write(1, "0x", 2);

	ft_puthex(ptr, 'x');

	return (count + ft_hexlen(ptr));
}
