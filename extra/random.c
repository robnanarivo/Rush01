int **ft_get_solution(int read_in[4][4], int **solution, int i, int j)
{
	int n;

	n = 1;
	if (i == 4) // reaches the end of the board -- terminating condition for the recursion
	{
		return (solution);
	}





	
	if (solution[i][j] == 0)
	{
		while (n < 5)
		{
			if (ft_check_valid(n, i, j))
			{
				solution[i][j] = n;
			}
		}
	}
	if (j < 4)
	{
		j++;
		return (ft_getsolution(read_in, solution, i, j));
	}
	else
	{
		j = 0;
		i++;
		return (ft_getsolution(read_in, solution, i, j));
	}
}