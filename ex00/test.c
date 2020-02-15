#include <unistd.h>
// #include "ft_solve.c"
#include "ft_print.c"
#include "ft_initialize.c"


int main()
{
	int arr[4][4] =
	{
		{1, 2, 3, 4},
		{0, 2, 4, 3},
		{3, 2, 1, 4},
		{0, 1, 3, 2}
	};
	ft_print(arr);
	ft_initialize(arr);
	write(1, "\n", 1);
	ft_print(arr);
	// ft_possible(arr, 0, 0);
}