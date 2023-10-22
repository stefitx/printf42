/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:28:41 by atudor            #+#    #+#             */
/*   Updated: 2023/10/01 00:28:45 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_of_num(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	check_sign(long long int *n)
{
	if (*n < 0)
	{
		*n = *n * -1;
		return (-1);
	}
	return (0);
}

int	ft_numbers(long long int n)
{
	char	c;
	char	number_string[13];
	int		len;
	int		sign;

	if (n == 0)
		return (write(1, "0", 1));
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	len = len_of_num(n);
	sign = check_sign(&n);
	number_string[len] = '\0';
	while (n != 0)
	{
		c = n % 10 + '0';
		number_string[len - 1] = c;
		len--;
		n = n / 10;
	}
	if (sign < 0)
		number_string[0] = '-';
	return (ft_putstr(number_string));
}

int	ft_num(unsigned int n)
{
	char			c;
	int				count;
	unsigned int	temp;

	if (n == 0)
		return (write(1, "0", 1));
	temp = n;
	count = len_of_num(temp);
	if (n > 9)
	{
		if (ft_num(n / 10) == -1)
			return (-1);
		if (ft_num(n % 10) == -1)
			return (-1);
	}
	else
	{
		c = n + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (count);
}
