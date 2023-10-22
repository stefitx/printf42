/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_and_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:53:39 by atudor            #+#    #+#             */
/*   Updated: 2023/10/14 22:49:11 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlow(unsigned int n)
{
	int			i;
	int			j;
	char		number_string[16];
	const char	*hexa;

	hexa = "0123456789abcdef";
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		j = (n % 16);
		number_string[i] = hexa[j];
		n = (n / 16);
		i++;
	}
	number_string[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		if (write (1, &number_string[i], 1) == -1)
			return (-1);
		i--;
	}
	return (ft_strlen(number_string));
}

int	ft_hexup(unsigned int n)
{
	int			i;
	int			j;
	char		number_string[16];
	const char	*hexa = "0123456789ABCDEF";

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		j = (n % 16);
		number_string[i] = hexa[j];
		n = (n / 16);
		i++;
	}
	number_string[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		if (write (1, &number_string[i], 1) == -1)
			return (-1);
		i--;
	}
	return (ft_strlen(number_string));
}

int	ft_ptr(unsigned long n)
{
	int			i;
	int			j;
	char		number_string[120];
	const char	*hexa = "0123456789abcdef";

	i = 0;
	if (n == 0)
		return (write(1, "0x0", 3));
	while (n > 0)
	{
		j = (n % 16);
		number_string[i] = hexa[j];
		n = (n / 16);
		i++;
	}
	number_string[i] = 'x';
	number_string[++i] = '0';
	number_string[i + 1] = '\0';
	while (i >= 0)
	{
		if (write (1, &number_string[i], 1) == -1)
			return (-1);
		i--;
	}
	return (ft_strlen(number_string));
}
