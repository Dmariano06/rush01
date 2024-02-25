#include "rush01.h"

// Affiche la solution de la grille
int print_solution(int **grid, int n, int m)
{
    int i;
    int j;
    char c;

    i = 0;
    while (i < n)
    {  
        j = 0;
        while (j < m)
        {
            c = '0' + grid[i][j]; // convert le nombre en char
            write(1, &c, 1); // ecrit le char dans la sortie standard
            if (j < m - 1)
                write(1, " ", 1); // Ajt un espace entre chaque nombre sauf pour le dernier
            j++;
        }
        write(1, "\n", 1); // Passage à la ligne suivante
        i++;
    }
    return (42); // return 42 reussi
}


int check_doublon_row(int *row, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (row[i] == row[j] && row[i] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_doublon_col(int **grid, int col_index, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (grid[col_index][i] == grid[col_index][j] && grid[col_index][i] != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// backtracking starting at 0 0 and recursively goes to n-1 n-1
// parcours récursif de la grid pour résoudre le sky
int dfs(int ***s_g, int n, int i, int j)
{
    int k;
    int **grid;
    
    grid = s_g[1]; // recup la grid de jeu à partir de s_g
    k = 1;
    if (i == n)
        return (print_solution(s_g[1], n, n)); // Si on a atteint la fin de la grille, affiche la solution
    while (k <= n)
    {
        grid[i][j] = k; // place un bât de hauteur k à la position (i, j) dans la grid
        if (check(s_g, i, j, n)) // verif si les contraintes sont respectées
            if (dfs(s_g,n, i + (j == n - 1), (j + 1) % n)) // j(index donc size - 1) récursif explorer cases suivantes j == n - 1 derniere col
                return (1); // Si une solution est trouver, return 1
        k++; // passe à la hauteur suivante pour essayer toutes les possibilités
    }
    grid[i][j] = 0; // aucune solution trouve, reinitialise case à 0
    return (0); // return 0 si aucune solution trouvée pour cette branche
}

// Résout le puzzle de skyline en utilisant les contraintes dans sky
int solve(int **sky, int n)
{
    int **grid;
    int **s_g[2];

    grid = alloc_grid(n, n); // alloue de la memoire pour la grid
    s_g[0] = sky; // stock les contraintes de la grid 
    s_g[1] = grid; // Stock la grille de jeu
    if (!grid) //  verifie si l'allocation de mémoire a échoué
        return (0);
    if (!dfs(s_g, n, 0, 0)) // appl la fonction de resolution du puzzle
        write(2, "Error\n", 7); // Aff une error si aucune solut n'est trouve
    free_grid(grid, n); // libère la mémoire allouee pour la grid
    return (0);
}
