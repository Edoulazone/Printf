/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:21:27 by eschmitz          #+#    #+#             */
/*   Updated: 2024/05/17 13:28:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*ft_itoa(int n);
int		get_size(int n);
int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
char	*ft_convert(unsigned int num, char *set);
int		check_format(const char c, va_list args);
size_t	ft_strlen(const char *s);

#endif