/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atudor <atudor@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 05:41:19 by atudor            #+#    #+#             */
/*   Updated: 2023/10/14 22:51:58 by atudor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_putchar(char s);
int	ft_printf(char const *str, ...);
int	ft_putstr(char *s);
int	ft_strlen(char *s);
int	ft_numbers(long long int n);
int	ft_num(unsigned int n);
int	ft_hexlow(unsigned int n);
int	ft_hexup(unsigned int n);
int	ft_ptr(unsigned long n);

#endif
