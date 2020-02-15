/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:53:04 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 16:07:17 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

// give a row index and a number, this function checks whether the number appears on the row
// returns true if the number does appear, false if the number does not appear

bool	ft_check_row(int solution[4][4], int row, int n)
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

// give a column index and a number, this function checks whether the number appears on the column
// returns true if the number does appear, false if the number does not appear

bool	ft_check_col(int solution[4][4], int col, int n)
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

// row and col start from index 0!!!
// n starts from 1 and ranges between 1 and 4
// ft_possible returns a 2*4 array possible: possible[x][0] - possible[x][3] denotes whether number 1-4 is used on the same row or column
// possible[0] lists whether the numbers are used on the same row, while possible[1] lists whether the numbers are used on the same column
// 0 means the number is used, while 1 means the number is not used

int		**ft_possible(int solution[4][4], int row, int col)
{
	int possible[2][4];
	int n;

	n = 1;
	while (n < 5)
	{
		if (ft_check_row(solution, row, n))
		{
			possible[0][n - 1] = 0;
		}
		else
		{
			possible[0][n - 1] = 1;
		}
		if (ft_check_col(solution, col, n))
		{
			possible[1][n - 1] = 0;
		}
		else
		{
			possible[1][n - 1] = 1;
		}
		n++;
	}
	return (possible);
}

// int		**ft_solve(int read_in[4][4])
// {
// 	int solution[4][4];

// 	ft_initialize(solution);
	
	
	
	
	
	
// 	return (solution);
// }
