#include "rush01.h"

// size taille de la grille (same for row and col)
int check(int ***s_g, int x, int y, int size)
{
	int res;
	int **sky;
	int **grid;

	sky = s_g[0];
	grid = s_g[1];
	if (check_doublon_row(grid[x], size) == 0)
		return (0);
	if (check_doublon_col(grid, y, size) == 0)
		return (0);
	res = check_row(grid[x], size);
	if (res > sky[2][x] || (y == size - 1 && res != sky[2][x])) // onv part de gauche car on part du début 
		return (0);
	res = check_col(grid, y, size);
	if (res > sky[0][y] || (x == size - 1 && res != sky[0][y])) // ligne du haut
		return (0);
	if (y == size - 1)
		if (check_row_reverse(grid[x], sky[3][x], size) > sky[3][x]) // colone de droite
			return (0);
	if (x == size - 1)
		if (check_col_reverse(grid, y, sky[1][y], size) > sky[1][y])// ligne du bas
			return (0);
	return (1);
}

int check_row(int *row, int size)
{
	int res;
	int mx;
	int i;

	res = 0;
	mx = 0;
	i = 0;
	while (i < size)
	{
		if (row[i] > mx)
		{
			mx = row[i];
			res++;
		}
		i++;
	}
	return (res);
}

int check_col(int **grid, int col_index, int size)
{
	int res;
	int mx;
	int i;

	res = 0; // Initialisation du nombre de bâtiments visibles
	mx = 0; // Initialisation de la hauteur maximale vue jusqu'à présent
	i = 0;
	while (i < size)
	{
		if (grid[i][col_index] > mx)
		{
			mx = grid[i][col_index]; // Met à jour la hauteur maximale vue
			res++; // Incrémente le nombre de bâtiments visibles
		}
		i++;
	}
	// Renvoie le nombre de bâtiments visibles dans la colonne
	return (res);
}

// (target is the number of block we should see and it's taken from sky)
int check_row_reverse(int *row, int target, int size)
{
	int res;
	int mx;
	int i;

	res = 0;
	mx = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (row[i] > mx)
		{
			mx = row[i];
			res++;
		}
		i--;
	}
	if (res != target)
		return (MAX_N + 1);
	return (res);
}

int check_col_reverse(int **grid, int col_index, int target, int size)
{
	int res;
	int mx;
	int i;

	res = 0;	
	mx = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (grid[i][col_index] > mx)
		{
			mx = grid[i][col_index];
			res++;
		}
		i--;
	}
	if (res != target)
		return (MAX_N + 1);
	return (res);
}