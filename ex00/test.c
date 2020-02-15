// #include <unistd.h>
#include <stdio.h>
#include "ft_solve.c"
#include "ft_print.c"
#include "ft_initialize.c"


int main()
{
	int **possible;
	int arr[4][4] =
	{
		{1, 2, 3, 4},
		{0, 2, 4, 3},
		{3, 2, 1, 4},
		{0, 1, 3, 2}
	};
	// ft_print(arr);
	possible = ft_possible(arr, 3, 3);
	
	int i = 0;
	int j = 0;
	while (i < 2)
	{
		while (j < 4)
		{
			printf("%d ", possible[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}