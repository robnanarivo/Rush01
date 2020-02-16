/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_possible_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:07:29 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 17:20:55 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	ft_check_row(int **solution, int row, int n)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (solution[row][j] == n)
		{
			return (true);
		}
		j++;
	}
	return (false);
}

bool	ft_check_col(int **solution, int col, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (solution[i][col] == n)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

int		**ft_possible(int **solution, int row, int col)
{
	int **possible;
	int n;

	possible = malloc(2 * 8);
	possible[0] = malloc(4 * 4);
	possible[1] = malloc(4 * 4);
	n = 1;
	while (n < 5)
	{
		if (ft_check_row(solution, row, n))
			possible[0][n - 1] = 0;
		else
			possible[0][n - 1] = 1;
		if (ft_check_col(solution, col, n))
			possible[1][n - 1] = 0;
		else
			possible[1][n - 1] = 1;
		n++;
	}
	return (possible);
}
