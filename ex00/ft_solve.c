/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:53:04 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 18:09:01 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_initialize_pt.c"
#include "ft_rules.c"

void	ft_get_solution(int read_in[4][4], int **solution)
{
	ft_rule_1(read_in, solution);
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
	ft_get_solution(read_in, solution);
	return (solution);
}
