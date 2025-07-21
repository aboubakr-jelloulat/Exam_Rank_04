// #include <stdio.h>

// void solve(char *str, int pos, int open, int to_remove, char *tmp)
// {
//     if (!str[pos])
//     {
//         if (open == 0 && to_remove == 0)
//         {
//             tmp[pos] = '\0';
//             puts(tmp);
//         }
//         return;
//     }
//     if (to_remove > 0)
//     {   
//         tmp[pos] = ' ';
//         solve(str, pos + 1, open, to_remove - 1, tmp);
//     }






//     if (str[pos] == '(')
//     {
//         tmp[pos] = '(';
//         solve(str, pos + 1, open + 1, to_remove, tmp);
//     }
//     else if (str[pos] == ')')
//     {
//         if (open > 0)
//         {
//             tmp[pos] = ')';
//             solve(str, pos + 1, open - 1, to_remove, tmp);
//         }
//     }




    
//     else
//     {
//         tmp[pos] = str[pos];
//         solve(str, pos + 1, open, to_remove, tmp);
//     }
// }

// int total_removals(char *str)
// {
//     int open = 0;
//     int close = 0;
//     for (int i = 0; str[i]; i++)
//     {
//         if (str[i] == '(')
//             open++;





            
//         else if (str[i] == ')')
//         {
//             if (open > 0)
//                 open--;
//             else
//                 close++;
//         }
//     }
//     return open + close;
// }

// int main(int ac, char *av[])
// {
//     if (ac != 2)
//         return (1);

//     char *str = av[1];
//     int n = 0;
//     while (str[n])
//         n++;

//     char tmp[n + 1];
//     solve(str, 0, 0, total_removals(str), tmp);
// }


#include <unistd.h>

int to_removal(char *str)
{
    int open;
    int close;
    int i;

    open = 0;
    close = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if(open > 0)
            open--;
            else
            close++;
        }
        i++;
    }
    return (open + close);
}

int valid_str(char *str)
{
    int i;
    int b;

    i = 0;
    b = 0;
    while (str[i])
    {
        if (str[i] == '(')
            b++;
        else if (str[i] == ')')
            b--;
        if (b < 0)
            return 1;
        i++;
    }
    if (b != 0)
        return 1;
    return 0;
}

void  gen_valid_strs(char *str, int i, int len, int removals)
{
    if (i == len)
    {
        if (removals == 0 && !valid_str(str))
        {
            write(1, str, len);
            write(1, "\n", 1);
        }
        return ;
    }





    if (str[i] != '(' && str[i] != ')')
    {
        gen_valid_strs(str, i + 1, len, removals);
        return ;
    }




    if (removals > 0)
    {
        char  old = str[i];
        str[i] = ' ';
        gen_valid_strs(str, i + 1, len, removals - 1);
        str[i] = old;
    }
    gen_valid_strs(str, i + 1, len, removals);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;




    int   len;
    len = 0;
    while (av[1][len])
    len++;




    int   removals;
    removals = to_removal(av[1]);
    gen_valid_strs(av[1], 0, len, removals);
    return 0;   
}
