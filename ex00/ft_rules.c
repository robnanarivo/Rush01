/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:05:47 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 18:35:03 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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


// rule 2: 





