/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:23:55 by lwillis           #+#    #+#             */
/*   Updated: 2025/04/07 13:15:24 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
	Converts a str to its float representation
*/
float	ft_strtof(char *str)
{
	char	**split;
	int		whole;
	float	rest;
	float	value;
	int		is_minus;

	split = ft_split(str, '.');
	if (!split[1])
	{
		ft_free_stringlist(split);
		return ((float)ft_atoi(str));
	}
	whole = ft_atoi(split[0]);
	is_minus = 0;
	if ('-' == str[0])
	{
		whole *= -1;
		is_minus = 1;
	}
	rest = ft_atoi(split[1]) * 1.0f;
	value = whole + (rest / ft_pow(10, ft_strlen(split[1])));
	ft_free_stringlist(split);
	if (1 == is_minus)
		value *= -1;
	return (value);
}
