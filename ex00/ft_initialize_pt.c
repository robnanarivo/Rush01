/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_pt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:25:59 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 17:57:39 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initialize_pt(int **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}