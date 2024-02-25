#include "./rush01.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int	cnt_words(char *s)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && !is_whitespace(s[i]))
			return (-1);
		if (is_whitespace(s[i]) == 0 && (i == 0 || is_whitespace(s[i - 1])))
			words++;
		i++;
	}
	return words;
}

// output format -> res[0] = col_up, res[1] = col_down, res[2] = row_left, res[3] = row_right
// initialise la grille res avec les contraintes de la chaîne s
int **init_res(int **res, char *s, int n, int i)
{
    int j;
    int k;
    int cur;

    j = 0;
    k = 0;
    cur = 0;
    while (s[++i]) // parcours la chaîne de contraintes
    {
        if (is_whitespace(s[i]) && (i > 0 && !is_whitespace(s[i-1])))
        {
            res[j][k++] = cur; // stock la contrainte dans la grille res
            cur = 0; 
            if (k == n) // si la ligne est finie
            {
                k = 0;
                j++; // on avance a la ligne suivante dans res
            }
            continue;
        }
        cur = cur * 10 + s[i] - '0'; // converti le char en int
    }
    res[j][k] = cur;
    return (res);
}


int check_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((is_whitespace(s[i]) && is_whitespace(s[i+1]))
		 || (is_whitespace(s[i]) && i == 0) 
		 || (is_whitespace(s[i]) && s[i + 1] == 0))
		 	return (0);
		i++;
	}
	return (1);
}

int **parse(char *s, int *n)
{
    int **res; // grille de contraintes

    // verifie si la chaîne s contient des espaces consecutif
    if (!check_space(s))
        return (NULL);
    // compte le nombre de mot dans la chaîne s
    *n = cnt_words(s);
    // verifie plusieur conditions sur le nombre de mots
    if (*n == -1 || *n % 4 || *n / 4 > MAX_N)
        return (NULL);
    *n /= 4; // divise le nombre total de contraintes par 4 pour obtenir la taille de la grille
    // alloue de la mémoire pour stocker les contraintes de la grille dans res
    res = alloc_grid(4, *n);
    if (!res) // verifie si l'allocation de mem a fail
        return (NULL);
    // initialise la grille res avec les contrainte de la chaîne s
    init_res(res, s, *n, -1);
    return (res); // Renvoie la grille de contraintes correctement initialisée
}
