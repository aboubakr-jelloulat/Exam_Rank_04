#include <unistd.h>
#include <stdlib.h>

int	len(char *str){int i = 0;while (str[i])i++;return i;}
int	to_remove_func(char *str){int open = 0, close = 0;for (int i = 0; i < len(str); i++){if (str[i] == '(')open ++;if (str[i] == ')')if (open)open--;close++;}return open + close;}
int	is_balanced(char *str){int balanced = 0;for (int i = 0; i < len(str); i++){if (str[i] == '(')balanced++;else if (str[i] == ')'){if (!balanced)	return 0;else balanced--;}}return balanced == 0;}
void	display(char *str){while (*str)write (1, str++, 1);write(1, "\n", 1);}

void	RemoveInvalidPara(char *str, int level, int to_remove, int removed, char *cur, int pos)
{
	if (str[level])
	{
		cur = 0;
		if (to_remove == removed && is_balanced(cur))
			display(cur);
		return ;
	}
	if (str[level] == ')' || str[level] == '(')
	{
		// 1 removed 

		cur[pos] = '_';
		RemoveInvalidPara(str, level ++, to_remove, removed++, cur, pos++);

		// 2 keep 

		cur[pos] = str[level];
		RemoveInvalidPara(str, level ++, to_remove, removed, cur, pos++);
	}
	else // space 
	{
		cur[pos] = str[level];
		RemoveInvalidPara(str, level ++, to_remove, removed, cur, pos++);
	}

}

int main(int ac, char **av)
{
	if (ac != 2 || av[1])	return 1;
	
	char cur[len(av[1] + 1)];

	RemoveInvalidPara(av[1], 0, to_remove_func(av[1]), 0, cur, 0);
	

	return 0;
}
