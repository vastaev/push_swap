#include "push_swap.h"
#include "limits.h"

static void check_for_number(char *str);
static void	treat_array_of_args(t_stack *stack, int argc, char **argv);
static void	treat_args_in_str(t_stack *stack, char **argv);
static void	index_elements(t_stack *stack, int *arrayOfNumbers);

t_stack	*validation_of_args(int argc, char **argv)
{
	t_stack	*stackA;

	stackA = (t_stack *)malloc(sizeof(t_stack));
	if (stackA == NULL)
		return (error_msg());
	stackA->head = NULL;
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
	if (arrayOfNumbers == NULL)
		error_msg();
	while (j < i)
	{
		check_for_number(argv[j]);
		arrayOfNumbers[j] = (int)ft_atoi(argv[j]);
		add_to_end_of_stack(stack, create_new_element(arrayOfNumbers[j]));
		j++;
	}
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
		error_msg();
	while (i < argc)
	{
		check_for_number(argv[i]);
		arrayOfNumbers[i - 1] = (int)ft_atoi(argv[i]);
		add_to_end_of_stack(stack, create_new_element(arrayOfNumbers[i - 1]));
		i++;
	}
	bubble_sort(arrayOfNumbers, i - 1);
	index_elements(stack, arrayOfNumbers);
}

static void	index_elements(t_stack *stack, int *arrayOfNumbers)
{
	t_stack_elem	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		ptr->order = find_index_of_num(ptr->value, arrayOfNumbers);
		ptr = ptr->next;
	}
}

static void check_for_number(char *str)
{
	long long	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		error_msg();
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return ;
	else
		error_msg();
}
