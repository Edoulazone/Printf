/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:10 by eschmitz          #+#    #+#             */
/*   Updated: 2024/05/17 13:15:08 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	ptr_check;
	int				res;

	ptr_check = (unsigned long)ptr;
	res = 0;
	if (ptr_check >= 16)
		res += ft_putptr((void *)(ptr_check / 16));
	res += ft_putchar("0123456789abcdef"[ptr_check % 16]);
	return (res);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

char	*ft_convert(unsigned int num, char *set)
{
	static char	buffer[100];
	char		*ptr;
	int			base;

	base = ft_strlen(set);
	ptr = &buffer[99];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	return (ptr);
}

int	check_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789")));
	else if (c == 'x')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789abcdef")));
	else if (c == 'X')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789ABCDEF")));
	else if (c == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = -1;
	length = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			length += check_format(str[++i], args);
		else if (str [i] != '%' || str[i + 1])
			length += ft_putchar(str[i]);
	}
	va_end (args);
	return (length);
}
