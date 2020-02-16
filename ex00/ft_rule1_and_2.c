/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule1_and_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:05:47 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 17:31:59 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		**ft_possible(int **solution, int row, int col);

void	ft_exec_rule_1(int **solution, int i, int j)
{
	int n;

	n = 1;
	while (n < 5)
	{
		if (i == 0)
			solution[n - 1][j] = n;
		else if (i == 1)
			solution[4 - n][j] = n;
		else if (i == 2)
			solution[j][n - 1] = n;
		else if (i == 3)
			solution[j][4 - n] = n;
		n++;
	}
}

void	ft_rule_1(int read_in[4][4], int **solution)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (read_in[i][j] == 4)
			{
				ft_exec_rule_1(solution, i, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

bool	ft_rule_2(int **solution, int row, int column, int n)
{
	int **possible;

	possible = ft_possible(solution, row, column);
	if (possible[0][n - 1] == 1 && possible[1][n - 1] == 1)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
