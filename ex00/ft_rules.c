/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:05:47 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 15:46:36 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

#include "ft_print_pt.c"

#include "ft_check_possible_opt.c"

// rule 1: if any viewpoint has the value 4, then, from that viewpoint, an arrangement of "1 2 3 4" is expected

void	ft_exec_rule_1(int **solution, int i, int j)
{
	int n;
	
	n = 1;
	if (i == 0)
	{
		while (n < 5)
		{
			solution[n - 1][j] = n;
			n++;
		}
	}
	else if (i == 1)
	{
		while (n < 5)
		{
			solution[4 - n][j] = n; // 5 - n because we are starting from the last row
			n++;
		}
	}
	else if (i == 2)
	{
		while (n < 5)
		{
			solution[j][n - 1] = n;
			n++;
		}
	}
	else if (i == 3)
	{
		while (n < 5)
		{
			solution[j][4 - n] = n; // same justification as above
			n++;
		}
	}
	else
	{
		write(1, "Invalide input i while executing rule 1!\n", 41);
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

// rule 2: boxes with the same height cannot be on the same row or column
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

// rule 3: number cannot violated the specified rules for the sides

bool	ft_check_col_up(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		max = solution[i][j];
		counter = 1;
		while (i < 4)
		{
			if (i < 3)
			{
				if (solution[i][j] < solution[i + 1][j])
				{
					max = solution[i + 1][j];
					counter++;
				}
			}
			i++;
		}
		if (counter != read_in[0][j])
		{
			return (false);
		}
		i = 0;
		j++;
	}
	return (true);
}

bool	ft_check_col_down(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	i = 3;
	j = 0;
	while (j < 4)
	{
		max = solution[i][j];
		counter = 1;
		while (i >= 0)
		{
			if (i > 0)
			{
				if (solution[i][j] < solution[i - 1][j])
				{
					max = solution[i - 1][j];
					counter++;
				}
			}
			i--;
		}
		if (counter != read_in[1][j])
		{
			return (false);
		}
		i = 0;
		j++;
	}
	return (true);
}

bool	ft_check_row_left(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		max = solution[i][j];
		counter = 1;
		while (j < 4)
		{
			if (j < 3)
			{
				if (solution[i][j] < solution[i][j + 1])
				{
					max = solution[i][j + 1];
					counter++;
				}
			}
			j++;
		}
		if (counter != read_in[2][i])
		{
			return (false);
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	ft_check_row_right(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	i = 0;
	j = 3;
	while (i < 4)
	{
		max = solution[i][j];
		counter = 1;
		while (j >= 0)
		{
			if (j > 0)
			{
				if (solution[i][j] < solution[i][j - 1])
				{
					max = solution[i][j - 1];
					counter++;
				}
			}
			j--;
		}
		if (counter != read_in[3][i])
		{
			return (false);
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	ft_rule_3(int **solution, int read_in[4][4])
{
	if (ft_check_col_down(solution, read_in) && ft_check_col_up(solution, read_in) && ft_check_row_left(solution, read_in) && ft_check_row_right(solution, read_in))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}



