/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <lwillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:51:05 by lwillis           #+#    #+#             */
/*   Updated: 2025/02/26 12:10:10 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
Applies the function ’f’ on each character of the string passed as argument,
passing its index as first argument. Each character is passed by
address to ’f’ to be modified if necessary.

Quits if either parameter is missing.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
