/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbozic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:09:51 by dbozic            #+#    #+#             */
/*   Updated: 2025/04/25 13:09:52 by dbozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

float	determinant(t_matrix *matrix)
{
	unsigned int	col;
	float			det;

	if (2 == matrix->size)
		return ((matrix->vals[0][0] * matrix->vals[1][1])
			- (matrix->vals[0][1] * matrix->vals[1][0]));
	col = 0;
	det = 0.0f;
	while (col < matrix->size)
	{
		det += (matrix->vals[0][col] * cofactor(matrix, 0, col));
		col++;
	}
	return (det);
}

t_matrix	submatrix(t_matrix *matrix, unsigned int row, unsigned int col)
{
	t_matrix		result;
	unsigned int	i;
	unsigned int	j;

	result = create_empty_matrix();
	result.size = matrix->size - 1;
	i = 0;
	while (i < matrix->size)
	{
		if (i != row)
		{
			j = 0;
			while (j < matrix->size)
			{
				if (j != col)
					result.vals[i - (i > row)][j - (j > col)]
						= matrix->vals[i][j];
				j++;
			}
		}
		i++;
	}
	return (result);
}

float	minor_3x3(t_matrix *matrix, unsigned int row, unsigned int col)
{
	t_matrix	tmp;
	float		result;

	tmp = submatrix(matrix, row, col);
	result = determinant(&tmp);
	return (result);
}

float	minor_4x4(t_matrix *matrix, unsigned int row, unsigned int col)
{
	t_matrix	tmp;
	float		result;

	tmp = submatrix(matrix, row, col);
	result = determinant(&tmp);
	return (result);
}

float	cofactor(t_matrix *matrix, unsigned int row, unsigned int col)
{
	float	result;

	if (4 == matrix->size)
		result = minor_4x4(matrix, row, col);
	else
		result = minor_3x3(matrix, row, col);
	if (1 == (row + col) % 2)
		result *= -1;
	return (result);
}
