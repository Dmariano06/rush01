#include "rush01.h"

int ft_error(int **grid, int **sky, int n)
{
	write(1, "Error\n", 6);
	free_grid(sky, 4);
	free_grid(grid, n);
	return (0);
}

int **free_grid(int **res, int n) //liberer la mémoire
{
	int i;

	i = 0;
	if (res)
		while (i < n)
			free(res[i++]);
	free(res);
	return (NULL);
}

int **alloc_grid(int n, int m) // allocation de la mémoire nécessaire pour res ou n = 4 && m = taille ligne
{
	int **res;
	int i;
	int j;

	res = (int **)malloc(sizeof(int *) * n);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = (int *)malloc(sizeof(int) * m);
		if (!res[i])
			return (free_grid(res, n));
		j = 0;
		while (j < m)
			res[i][j++] = 0;   // on remplit la grille avec des 0;
		i++;
	}
	return (res);
}

int ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}