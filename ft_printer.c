/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:41:49 by eschmitz          #+#    #+#             */
/*   Updated: 2024/05/17 13:20:51 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_size(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;
	long	copy_number;

	size = get_size(n);
	copy_number = n;
	if (n < 0)
	{
		size++;
		copy_number *= -1;
	}
	number = (char *)malloc(size + 1);
	if (!number)
		return (NULL);
	number[size] = '\0';
	while ((--size) >= 0 && copy_number >= 0)
	{
		number[size] = ((copy_number % 10) + '0');
		copy_number /= 10;
	}
	if (number[0] == '0' && n != 0)
		number[0] = '-';
	return (number);
}
