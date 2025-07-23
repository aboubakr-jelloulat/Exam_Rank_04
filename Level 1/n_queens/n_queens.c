#include <stdio.h>
#include <stdlib.h>

void ft_memset(int *board, int n)
{
    for (int i = 0; i < n; i++)
        board[i] = 0;
}


int ab_s(int n)
{
    return (n > 0) ? n : -n;
}


void display_board(int *board, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(stdout, "%d", board[i]);
        if (i < n - 1)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}


int is_valid(int *board, int col, int row)
{
    for (int i = 0; i < col; i++)
    {
        if (row == board[i]) // Same row conflict
            return 0;

        if (col - i == ab_s(board[i] - row)) // Diagonal conflict
            return 0;
    }
    return 1;
}


void n_queens(int *board, int col, int n)
{
    if (col == n)
    {
        display_board(board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (is_valid(board, col, row))
        {
            board[col] = row; // Place queen
            n_queens(board, col + 1, n); // Recurse
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    int n = atoi(av[1]);

    if (n <= 0)
        return 1;

    int *board = (int *)malloc(sizeof(int) * n);
    if (!board)
        return 1;

    ft_memset(board, n);

    n_queens(board, 0, n);

    free(board);

    return 0;
}
