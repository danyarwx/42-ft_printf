/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:23:55 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/02 20:07:44 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef __APPLE__
# define NULL_PTR "0x0"
# define NULL_PTR_LEN 3
#else
# define NULL_PTR "(nil)"
# define NULL_PTR_LEN 5
#endif

int	ft_putptr(va_list *p_args)
{
	int					count;
	unsigned long long	ptr;

	ptr = (unsigned long long)va_arg(*p_args, void *);
	count = 0;
	if (!ptr)
		return (write(1, NULL_PTR, NULL_PTR_LEN));
	count += write(1, "0x", 2);
	ft_puthex(ptr, 'x');
	return (count + ft_hexlen(ptr));
}
