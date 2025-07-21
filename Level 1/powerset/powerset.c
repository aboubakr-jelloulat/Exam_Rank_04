#include <stdio.h>
#include <stdlib.h>


int calc_sum(int *nums, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += nums[i];

    return sum;
}

void display(int *nums, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    printf("\n");
}


void    sumsubsets(int *nums, int target, int size,  int *subset, int sub_len, int level)
{
    if (size == level)
    {
        if (calc_sum(subset, sub_len) == target)
            display(subset, sub_len);
        return ;
    }
    subset[sub_len] = nums[level];

    sumsubsets(nums, target, size, subset, sub_len + 1, level + 1);
    sumsubsets(nums, target, size, subset, sub_len , level + 1);
}

int main(int ac, char **av)
{

    if (ac < 2) return 1;

    int size = ac - 2;

    int target = atoi(av[1]);

    int *subset = (int *)malloc(sizeof(int) * size);
    if (!subset)
        return 1;

    int *nums = (int *)malloc(sizeof(int) * size);
    if (!nums)
        return 1;

    for (int i = 0; i < size; i++)
        nums[i] = atoi(av[i + 2]);
    
    sumsubsets(nums, target, size, subset, 0, 0);

    free (nums);
    free (subset);
}
