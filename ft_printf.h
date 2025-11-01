/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzhukov <dzhukov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:39:37 by dzhukov           #+#    #+#             */
/*   Updated: 2025/11/01 21:42:53 by dzhukov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar_arg(va_list *p_args);
int		ft_putstr_arg(va_list *p_args);
void	ft_putnbr_arg(long long n);
int		ft_intlen(int n);
int		ft_hexlen(unsigned long n);
void	ft_puthex(unsigned long n, char upper);
int		ft_putptr(va_list *p_args);
int		ft_switch(char c, va_list *p_args);
int		ft_printf(const char *s, ...);

#endif
