/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:59:29 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/16 19:11:19 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_pt(int **arr);
void	ft_initialize_arr(int arr[4][4]);
int		ft_check_input_error1(int argc, char *argv[]);
void	ft_read(char *str, int read_in[4][4]);
int		**ft_solve(int read_in[4][4]);

int		main(int argc, char *argv[])
{
	int read_in[4][4];
	int **solution;
	int error_flag;

	ft_initialize_arr(read_in);
	error_flag = 0;
	error_flag = ft_check_input_error1(argc, argv);
	if (error_flag != 0)
		return (0);
	ft_read(argv[1], read_in);
	solution = ft_solve(read_in);
	if (solution[0][0] == 0)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0);
	}
	ft_print_pt(solution);
	write(1, "\n", 1);
	return (0);
}
