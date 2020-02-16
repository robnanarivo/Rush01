/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 10:59:29 by xqiu              #+#    #+#             */
/*   Updated: 2020/02/15 19:31:22 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_initialize_arr.c"
#include "ft_print_arr.c"

int		main(int argc, char *argv[])
{
	int read_in[4][4];
	int to_print[4][4];
	int error_flag;
	
	error_flag = 0;
	ft_initialize(read_in);
	ft_initialize(to_print);
	// ft_read(int argc, char *argv[]); // changes read_in
	// ft_solve(int read_in[][]); // changes to_print
	ft_print(read_in);
	return (0);
}
