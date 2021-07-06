#include "push_swap.h"
#include "limits.h"

static int	check_for_number(char *str);
static void	treat_array_of_args(t_stack *stack, int argc, char **argv);
static void	treat_args_in_str(t_stack *stack, char **argv);
static void	index_elements(t_stack *stack, int *arrayOfNumbers);

t_stack	*validation_of_args(int argc, char **argv, t_stack *stackA)
{
	stackA->head = NULL;
	stackA->tail = NULL;
	stackA->size = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		treat_args_in_str(stackA, argv);
		free_split(argv);
	}
	else
		treat_array_of_args(stackA, argc, argv);
	return (stackA);
}

static void	treat_args_in_str(t_stack *stack, char **argv)
{
	int				i;
	int				j;
	int				*arrayOfNumbers;

	j = 0;
	i = split_len(argv);
	arrayOfNumbers = (int *)malloc(sizeof(int) * i);
	if (NULL == arrayOfNumbers)
	{
		free_stack(stack);
		error_msg();
	}
	while (j < i)
	{
		if (check_for_number(argv[j]) == 1)
			free_stack_and_array(stack, arrayOfNumbers, 1);
		arrayOfNumbers[j] = (int)ft_atoi(argv[j]);
		add_to_stack(stack, create_new_element(arrayOfNumbers[j++]));
	}
	if (check_duplicates(arrayOfNumbers, i) == 1)
		free_stack_and_array(stack, arrayOfNumbers, 1);
	if (is_sorted(arrayOfNumbers, i) == 1)
		free_stack_and_array(stack, arrayOfNumbers, 0);
	bubble_sort(arrayOfNumbers, i);
	index_elements(stack, arrayOfNumbers);
}

static void	treat_array_of_args(t_stack *stack, int argc, char **argv)
{
	int				i;
	int				*arrayOfNumbers;

	i = 1;
	arrayOfNumbers = (int *)malloc(sizeof(int) * (argc - 1));
	if (NULL == arrayOfNumbers)
	{
		free_stack(stack);
		error_msg();
	}
	while (i < argc)
	{
		if (check_for_number(argv[i]) == 1)
			free_stack_and_array(stack, arrayOfNumbers, 1);
		arrayOfNumbers[i - 1] = (int)ft_atoi(argv[i]);
		add_to_stack(stack, create_new_element(arrayOfNumbers[i - 1]));
		i++;
	}
	i--;
	if (check_duplicates(arrayOfNumbers, i) == 1)
		free_stack_and_array(stack, arrayOfNumbers, 1);
	if (is_sorted(arrayOfNumbers, i) == 1)
		free_stack_and_array(stack, arrayOfNumbers, 0);
	bubble_sort(arrayOfNumbers, i);
	index_elements(stack, arrayOfNumbers);
}

static void	index_elements(t_stack *stack, int *arrayOfNumbers)
{
	t_stack_elem	*ptr;
	int				i;

	ptr = stack->head;
	i = 0;
	while (i < stack->size)
	{
		ptr->order = find_index_of_num(ptr->value, arrayOfNumbers);
		ptr = ptr->next;
		i++;
	}
	free(arrayOfNumbers);
}

static int	check_for_number(char *str)
{
	long long	num;

	if (!str)
		return (0);
	if (ft_strlen(str) > 13)
		return (1);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (0);
	else
		return (1);
}
