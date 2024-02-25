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
            c = '0' + grid[i][j]; // Convertit le nombre en caractère
            write(1, &c, 1); // Écrit le caractère dans la sortie standard
            if (j < m - 1)
                write(1, " ", 1); // Ajoute un espace entre chaque nombre sauf pour le dernier
            j++;
        }
        write(1, "\n", 1); // Passage à la ligne suivante
        i++;
    }
    return (42); // Retourne un code de réussite arbitraire
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
// Parcours récursif de la grille pour résoudre le puzzle de skyline
int dfs(int ***s_g, int n, int i, int j)
{
    int k;
    int **grid;
    
    grid = s_g[1]; // Récupère la grille de jeu à partir de s_g
    k = 1;
    if (i == n)
        return (print_solution(s_g[1], n, n)); // Si on a atteint la fin de la grille, affiche la solution
    while (k <= n)
    {
        grid[i][j] = k; // Place un bâtiment de hauteur k à la position (i, j) dans la grille
        if (check(s_g, i, j, n)) // Vérifie si les contraintes sont respectées
            if (dfs(s_g,n, i + (j == n - 1), (j + 1) % n)) // j(index donc size - 1) récursif explorer cases suivantes j == n - 1 derniere col
                return (1); // Si une solution est trouvée, retourne 1
        k++; // Passe à la hauteur suivante pour essayer toutes les possibilités
    }
    grid[i][j] = 0; // aucune solution trouve, reinitialise case à 0
    return (0); // return 0 si aucune solution trouvée pour cette branche
}

// Résout le puzzle de skyline en utilisant les contraintes dans sky
int solve(int **sky, int n)
{
    int **grid;
    int **s_g[2];

    grid = alloc_grid(n, n); // Alloue de la mémoire pour la grille de jeu
    s_g[0] = sky; // Stocke les contraintes de la grille de jeu
    s_g[1] = grid; // Stocke la grille de jeu
    if (!grid) // Vérifie si l'allocation de mémoire a échoué
        return (0);
    if (!dfs(s_g, n, 0, 0)) // Appelle la fonction de résolution du puzzle
        write(2, "Error\n", 7); // Affiche une erreur si aucune solution n'est trouvée
    free_grid(grid, n); // Libère la mémoire allouée pour la grille de jeu
    return (0);
}
