#ifndef RUSH01_H
#define RUSH01_H

#include <stdlib.h>
#include <unistd.h>

# define MAX_N 9

int **parse(char *s, int *n);
int solve(int **sky, int n);
int **free_grid(int **res, int n);
int	**alloc_grid(int n, int m);
int ft_min(int a, int b);
void ft_swap(int *a, int *b);
int	ft_error(int **grid, int **sky, int n);
int check(int ***s_g, int x, int y, int size) ;
int check_row(int *row, int size);
int check_col(int **grid, int col_index, int size);
int check_row_reverse(int *row, int target, int size);
int check_col_reverse(int **grid, int col_index, int target, int size);
int	check_doublon_row(int *row, int size);
int	check_doublon_col(int **grid, int col_index, int size);
#endif