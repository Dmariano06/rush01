#include "rush01.h"
int main(int ac, char **av)
{
	int **sky;
	int n;

	if (ac != 2)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	sky = parse(av[1], &n);
	if (!sky)
	{
		write(2, "Error\n", 7);
		return (0);
	}
	solve(sky, n);
	free_grid(sky, n);
	return (0);
}