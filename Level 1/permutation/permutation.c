#include <stdio.h>


int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

void ft_swap(char *a, char *b)
{
    char    tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_sort(char *str)
{

    for (int i = 0; str[i]; i++)
        for (int c = i + 1;str[c]; c++)
           if (str[i] > str[c])
                ft_swap(&str[i], &str[c]);
        
}


void    permutation(char *str, int left, int right)
{
    if (left == right)   puts(str);

    for (int i = left; i <= right; i++)
    {
        ft_sort(&str[left]);
        ft_swap(&str[left], &str[i]);
        permutation(str, left + 1, right);
        ft_swap(&str[left], &str[i]);
    }

}

int main(int ac, char **av)
{
    if (ac != 2)    return 1;

    permutation(av[1], 0, ft_strlen(av[1]) - 1);

    return (0);
}
