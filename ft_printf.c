/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:59:31 by atudor            #+#    #+#             */
/*   Updated: 2023/10/14 22:58:01 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list args, char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (s == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (s == '%')
		count = ft_putchar('%');
	if (s == 'd' || s == 'i')
		count = ft_numbers(va_arg(args, int));
	if (s == 'u')
		count = ft_num(va_arg(args, unsigned int));
	if (s == 'x')
		count = ft_hexlow(va_arg(args, unsigned int));
	if (s == 'X')
		count = ft_hexup(va_arg(args, unsigned int));
	if (s == 'p')
		count = ft_ptr(va_arg(args, unsigned long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (!str)
		return (0);
	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += check(args, *str);
		}
		else
			len += ft_putchar(*str);
		str++;
		if (len == -1)
			return (-1);
	}
	va_end(args);
	return (len);
}

/*#include <stdio.h>
 int main()
 {
 	int a, b;
 	 //char c = 'A';
 	 //char *s = "hiii";
 	//a = printf("rl printf: %p\n", (void *)-ULONG_MAX);
 	//b = ft_printf("my printf: %p\n", (void *)-ULONG_MAX);
 	a = printf("%p\n", "");
 	b = ft_printf("%p\n", "");
 	printf( "%d\n", a);
 	printf( "%d\n", b);
 	//printf( "%d\n", printf("%s\n", s));

 	return 0;
 }*/
