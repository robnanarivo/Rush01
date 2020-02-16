/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:53:04 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 15:48:40 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

// #include "ft_print_pt.c"

#include "ft_initialize_pt.c"
#include "ft_rules.c"

bool	ft_filled(int **solution, int *pt_i, int *pt_j) // check whether the board is filled
{
	*pt_i = 0;
	*pt_j = 0;

	char i;
	while (*pt_i < 4)
	{
		while (*pt_j < 4)
		{
			if (solution[*pt_i][*pt_j] == 0)
			{
				
				i = *pt_i + '0';
				return (false);
			}
			*pt_j = *pt_j + 1;
		}
		*pt_j = 0;
		*pt_i = *pt_i + 1;
	}
	return (true);
}

bool	ft_check_valid (int **solution, int i, int j, int n)
{
	if (ft_rule_2(solution, i, j, n)) // rule 2 or rule 3 is not violated, return true
	{
		return (true);
	}
	else // otherwise, return false
	{
		return (false);
	}
}


bool	ft_get_solution(int read_in[4][4], int **solution) // the backtraking algorithm here!
{
	int n;
	int i;
	int j;

	n = 1;
	if (ft_filled(solution, &i, &j)) // return true if filled; otherwise changes i,j to the first unfilled location
	{
		return (true);
	}
	while (n < 5)
	{
		if (ft_check_valid(solution, i, j, n))
		{
			solution[i][j] = n;
			if (ft_get_solution(read_in, solution))
			{
				if (ft_rule_3(solution, read_in))
				{
					return (true);
				}
			}
			solution[i][j] = 0;
		}
		n++;
	}
	return (false);
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
	if (ft_get_solution(read_in, solution))
	{
		return (solution);
	}
	else
	{
		ft_initialize_pt(solution);
		return (solution);
	}
}
