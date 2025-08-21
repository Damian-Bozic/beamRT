/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:36 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:58 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_digits(long n)
{
	int	len;

	if (n < 10)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*convert_positive(long num)
{
	int		i;
	int		len;
	char	*result;

	len = count_digits(num);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}

static char	*convert_negative(long num)
{
	int		i;
	int		len;
	char	*result;

	len = count_digits(num);
	result = malloc(len + 2);
	if (!result)
		return (NULL);
	i = len;
	result[0] = '-';
	while (i > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	result[len + 1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		return (convert_negative(num));
	}
	return (convert_positive(n));
}
