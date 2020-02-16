/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:53:04 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 21:05:45 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ft_initialize_pt.c"
#include "ft_rules.c"

bool	ft_filled(int **solution) // check whether the board is filled
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (solution[i][j] == 0)
			{
				return (false);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	ft_check_valid (int **solution, int n, int i, int j)
{
	if (solution[i][j] != 0 || !ft_rule_2() || !ft_rule_3()) // if the position is not empty, or rule 2 or rule 3 is violated, return false
	{
		return (false);
	}
	else // otherwise, return true
	{
		return (true);
	}
	
}


int		**ft_get_solution(int read_in[4][4], int **solution, int i, int j) // the backtracing algorithm here!
{
	int n;
	
	n = 1;
	if (i == 4) // reaches the end of the board -- terminating condition for the recursion
	{
		return (solution);
	}
	while (n < 5)
	{
		if (ft_check_valid(solution, n, i, j))
		{
			solution[i][j] = n;
		}
		if (j < 4)
		{
			return (ft_get_solution(read_in, solution, i, j + 1));
		}
		else
		{
			return (ft_get_solution(read_in, solution, i + 1, 0));
		}
		n++;
	}
	// out of the loops means no solution after trying all possible numbers
	ft_initialize_pt(solution);
	return (solution);
}




int		**ft_solve(int read_in[4][4])
{
	int **solution;
	int i;

	i = 0;
	solution = malloc(4 * 8);
	while (i < 4)
	{
		solution[i] = malloc(4 * 4);
		i++;
	}
	ft_initialize_pt(solution);
	ft_rule_1(read_in, solution);
	solution = ft_get_solution(read_in, solution, 0, 0);
	if (ft_filled(solution)) // if the board is filled, return solution
	{
		return (solution);
	}
	else // otherwise, return the zero matrix
	{
		ft_initialize_pt(solution);
		return (solution);
	}
}
