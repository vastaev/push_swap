#include "push_swap.h"

void	validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (check_argv_dups(argc, argv) == 1)
		error_msg();
	while (i < argc)
	{
		if (check_for_number(argv[i]) == 1)
			error_msg();
		i++;
	}
}

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stackA;
	int		i;

	i = 1;
	stackA = (t_stack *)malloc(sizeof(t_stack));
	stackA->size = 0;
	stackA->head = NULL;
	stackA->tail = NULL;
	while (i < argc)
	{
		add_to_stack(stackA, create_new_element((int)ft_atoi(argv[i])));
		i++;
	}
	return (stackA);
}

void	do_commands(t_stack *stackA, t_stack *stackB, char *command,
					t_command_list *list)
{
	if (ft_strcmp(command, "sa") == 0)
		sn(stackA, "sa", list);
	else if (ft_strcmp(command, "sb") == 0)
		sn(stackB, "sb", list);
	else if (ft_strcmp(command, "ss") == 0)
		ss(stackA, stackB, "ss", list);
	else if (ft_strcmp(command, "ra") == 0)
		rn(stackA, "ra", list);
	else if (ft_strcmp(command, "rb") == 0)
		rn(stackB, "rb", list);
	else if (ft_strcmp(command, "rr") == 0)
		rr(stackA, stackB, "rr", list);
	else if (ft_strcmp(command, "rra") == 0)
		rrn(stackA, "rra", list);
	else if (ft_strcmp(command, "rrb") == 0)
		rrn(stackB, "rrb", list);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(stackA, stackB, "rrr", list);
	else if (ft_strcmp(command, "pa") == 0)
		pn(stackA, stackB, "pa", list);
	else if (ft_strcmp(command, "pb") == 0)
		pn(stackB, stackA, "pb", list);
	else
	{
		free_all(stackA, stackB, list);
		error_msg();
	}
}

void	read_commands(t_stack *stackA)
{
	char			*line;
	t_command_list	*list;
	t_stack			*stackB;

	list = (t_command_list *)malloc(sizeof(t_command_list));
	list->head = NULL;
	list->size = 0;
	line = NULL;
	stackB = (t_stack *)malloc(sizeof(t_stack));
	stackB->size = 0;
	stackB->head = NULL;
	stackB->tail = NULL;
	while (get_next_line(0, &line))
	{
		do_commands(stackA, stackB, line, list);
		free(line);
	}
	free(line);
	free_stack(stackB);
	free_commands(list);
}

int	main(int argc, char **argv)
{
	t_stack	*stackA;

	if (argc < 2)
		return (0);
	validation(argc, argv);
	stackA = fill_stack(argc, argv);
	read_commands(stackA);
	if (is_list_sorted(stackA) == TRUE)
		ft_putstrnewline("OK");
	else
		ft_putstrnewline("KO");
	free_stack(stackA);
	return (0);
}
