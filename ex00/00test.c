#include <unistd.h>
#include <stdio.h>

#include <stdlib.h>

#include "ft_solve.c"
#include "ft_print_arr.c"
#include "ft_print_pt.c"
#include "ft_initialize_arr.c"



int main()
{
	// // int **possible;
	// int arr[4][4] =
	// {
	// 	{1, 2, 3, 4},
	// 	{0, 2, 4, 3},
	// 	{3, 2, 1, 4},
	// 	{0, 1, 3, 2}
	// };
	// ft_print_arr(arr);
	// ft_initialize_arr(arr);
	// write(1, "\n", 1);
	// write(1, "\n", 1);
	// ft_print_arr(arr);
	// // possible = ft_possible(arr, 3, 3);
	
	// // int i = 0;
	// // int j = 0;
	// // while (i < 2)
	// // {
	// // 	while (j < 4)
	// // 	{
	// // 		printf("%d ", possible[i][j]);
	// // 		j++;
	// // 	}
	// // 	printf("\n");
	// // 	j = 0;
	// // 	i++;
	// // }
	// write(1, "\n", 1);
	// write(1, "\n", 1);
	
	// int **solution;
	// int i;

	// i = 0;
	// solution = malloc(4 * 8);
	// while (i < 4)
	// {
	// 	solution[i] = malloc(4 * 4);
	// 	i++;
	// }
	// ft_print_pt(solution);
	// write(1, "\n", 1);
	// write(1, "\n", 1);
	// ft_initialize_pt(solution);
	// ft_print_pt(solution);

	int read_in[4][4] =
	{
		{4, 3, 2, 1},
		{1, 2, 2, 2},
		{4, 3, 2, 1},
		{1, 2, 2, 2}
	};
	ft_print_arr(read_in);
	write(1, "\n", 1);
	write(1, "\n", 1);
	int **solution;
	solution = ft_solve(read_in);
	ft_print_pt(solution);
}