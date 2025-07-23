#include <unistd.h>

int ft_strlen(char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return len;
}

int to_remove(char *str)
{
    int open = 0, close = 0, i = 0;

    while (str[i])
    {
        if (str[i] == '(')   
            open ++;

        else if (str[i] == ')')
        {
            if (open)
                open --;
            else
                close ++;
        }
        
        i++;
    }
    return open + close;
}

int isBalanced(char *str)
{
    int balanced = 0, i = 0;

    while (str[i])
    {
        if (str[i] == '(')
            balanced ++;

        else if (str[i] == ')')
        {
            if (!balanced)
                return 0;
            balanced--;
        }
        i++;
    }
    return balanced == 0;
}


void    rip(char *str, int i, int len, int to_remove)
{
    if (i == len)
    {
        if (!to_remove  && isBalanced(str))
        {
            write(1, str, len);
            write(1, "\n", 1);
        }
        return ;
    }

    if (str[i] != '(' && str[i] != ')')
    {
        rip(str, i + 1, len, to_remove);
        return ;
    }

    if (to_remove)
    {
        char old = str[i];
        str[i] = ' ';
        rip(str, i + 1, len, to_remove - 1);
        str[i] = old;
    }
    rip(str, i + 1, len, to_remove);
}

int main(int ac, char **av)
{
    if (ac != 2)    return (1);

    rip(av[1], 0, ft_strlen(av[1]), to_remove(av[1]));
    
    return (0);
}
