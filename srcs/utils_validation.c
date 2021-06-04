#include "push_swap.h"

int	find_index_of_num(int num, const int *sortedArray)
{
	int	i;

	i = 0;
	while (num != sortedArray[i])
		i++;
	return (i);
}

int	split_len(char **s)
{
	int	counter;

	counter = 0;
	while (s[counter] != NULL)
		counter++;
	return (counter);
}

void	free_split(char **s)
{
	int	len;

	len = split_len(s);
	while (len--)
	{
		free(s[len]);
		s[len] = NULL;
	}
	free(s);
	s = NULL;
}

int	*bubble_sort(int *arrayOfNumbers, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < size - 1)
	{
		while (j > i)
		{
			if (arrayOfNumbers[j - 1] > arrayOfNumbers[j])
			{
				tmp = arrayOfNumbers[j];
				arrayOfNumbers[j] = arrayOfNumbers[j - 1];
				arrayOfNumbers[j - 1] = tmp;
			}
			j--;
		}
		j = size - 1;
		i++;
	}
	return (arrayOfNumbers);
}
