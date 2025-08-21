/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:12:49 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:12:50 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

/*
	Checks whether there are only digits in the string
*/
int	check_positive_ints(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (BAD_INPUT);
	return (0);
}

/*
	Checks whether there are only digits, -, and . in the string
*/
int	check_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && '-' != str[i] && '.' != str[i])
			return (BAD_INPUT);
	return (0);
}

int	check_coordinates(char *str)
{
	int		i;
	char	**split;
	int		error_code;

	split = ft_split(str, ',');
	if (3 != ft_count_array(split))
	{
		ft_free_stringlist(split);
		return (BAD_INPUT);
	}
	error_code = 0;
	i = -1;
	while (split[++i])
		if (BAD_INPUT == check_numbers(split[i]))
			error_code = BAD_INPUT;
	ft_free_stringlist(split);
	return (error_code);
}

int	check_float_range(char *str, int min, int max)
{
	int		i;
	float	value;
	char	**split;
	int		error_code;

	split = ft_split(str, ',');
	if (3 != ft_count_array(split))
	{
		ft_free_stringlist(split);
		return (BAD_INPUT);
	}
	i = -1;
	error_code = 0;
	while (split[++i])
	{
		if (BAD_INPUT == check_numbers(split[i]))
			error_code = BAD_INPUT;
		value = ft_strtof(split[i]);
		if (value < min || value > max)
			error_code = BAD_INPUT;
	}
	ft_free_stringlist(split);
	return (error_code);
}
