/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:28:45 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 15:02:56 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_ntoi(int n)
{
	char asc_val;

	asc_val = n + '0';
	return (asc_val);
}

void	ft_print(int arr[4][4])
{
	int		i;
	int		j;
	char	to_print;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			to_print = ft_ntoi(arr[i][j]);
			write(1, &to_print, 1);
			if (j < 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		if (i < 3)
		{
			write(1, "\n", 1);
		}
		j = 0;
		i++;
	}
}
