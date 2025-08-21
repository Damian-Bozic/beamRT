/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:46 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:09:53 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

static int	is_valid(char c)
{
	return ('-' == c || '+' == c || ft_isdigit(c));
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && is_space(str[i]))
		i++;
	if (!is_valid(str[i]))
		return (0);
	if ('-' == str[i])
		sign *= -1;
	if ('-' == str[i] || '+' == str[i])
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

int	ft_atoi2(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && is_space(str[i]))
		i++;
	while ('-' == str[i] || '+' == str[i])
	{
		if ('-' == str[i])
			sign *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}
