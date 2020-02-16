/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:30:31 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 17:41:37 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_check_col_down(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		max = solution[i][j];
		counter = 1;
		while (i < 4)
		{
			if (i < 3 && max < solution[i + 1][j])
			{
				max = solution[i + 1][j];
				counter++;
			}
			i++;
		}
		if (counter != read_in[0][j])
			return (false);
		j++;
	}
	return (true);
}

bool	ft_check_col_up(int **solution, int read_in[4][4])
{
	int max;
	int counter;
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 3;
		max = solution[i][j];
		counter = 1;
		while (i >= 0)
		{
			if (i > 0 && max < solution[i - 1][j])
			{
				max = solution[i - 1][j];
				counter++;
			}
			i--;
		}
		if (counter != read_in[1][j])
			return (false);
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
	while (i < 4)
	{
		j = 0;
		max = solution[i][j];
		counter = 1;
		while (j < 4)
		{
			if (j < 3 && max < solution[i][j + 1])
			{
				max = solution[i][j + 1];
				counter++;
			}
			j++;
		}
		if (counter != read_in[2][i])
			return (false);
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
	while (i < 4)
	{
		j = 3;
		max = solution[i][j];
		counter = 1;
		while (j >= 0)
		{
			if (j > 0 && max < solution[i][j - 1])
			{
				max = solution[i][j - 1];
				counter++;
			}
			j--;
		}
		if (counter != read_in[3][i])
			return (false);
		i++;
	}
	return (true);
}

bool	ft_rule_3(int **solution, int read_in[4][4])
{
	if (ft_check_col_down(solution, read_in) &&
	ft_check_col_up(solution, read_in) &&
	ft_check_row_left(solution, read_in) &&
	ft_check_row_right(solution, read_in))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
