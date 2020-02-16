/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xqiu <xqiu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:24:26 by hinoue            #+#    #+#             */
/*   Updated: 2020/02/16 18:38:43 by xqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_input_error2(char *str, char *input);

int		ft_check_input_error1(int argc, char *argv)
{
	char input[17];

	if (argc != 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	if (ft_check_input_error2(&argv[1], input) == 1)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int		ft_check_input_error2(char *str, char *input)
{
	int cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '4')
			input[cnt++] = *str;
		else
			return (0);
		str++;
		if (cnt == 16)
		{
			if (*str == '\0')
			{
				input[16] = '\0';
				return (1);
			}
			else
				return (0);
		}
		if (*str != ' ')
			return (0);
		str++;
	}
	return (0);
}
