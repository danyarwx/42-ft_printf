/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:18:00 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 22:18:46 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
