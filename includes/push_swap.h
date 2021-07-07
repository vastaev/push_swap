#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define R 1
# define RR 0
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 1

# include "libft.h"

typedef struct s_stack_elem
{
	int					order;
	int					value;
	struct s_stack_elem	*next;
	struct s_stack_elem	*previous;
}				t_stack_elem;

typedef struct s_stack
{
	int				size;
	t_stack_elem	*head;
	t_stack_elem	*tail;
}				t_stack;

typedef struct s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct s_command_list
{
	size_t				size;
	t_command			*head;
}						t_command_list;

typedef struct s_steps_info
{
	t_stack_elem	*elemB;
	int				directionB;
	t_stack_elem	*elemA;
	int				directionA;
	int				steps;
	int				isSet;
}				t_steps_info;

typedef struct s_alg_vars
{
	int		mid;
	int		max;
}			t_alg_vars;

//validation and indexing
t_stack			*validation_of_args(int argc, char **argv, t_stack *stackA);
int				split_len(char **s);
void			free_split(char **s);
int				*bubble_sort(int *arrayOfNumbers, int size);
int				find_index_of_num(int num, const int *sortedArray);
int				check_duplicates(const int *arrayOfNumbers, int size);
int				is_sorted(const int *array, int size);

//solving
void			small_sort(t_stack *stackA, t_stack *stackB,
					t_command_list *list);
void			solve(t_stack *stackA, t_stack *stackB, t_command_list *list);
void			calc_steps(t_stack *stackA, t_stack *stackB,
					t_alg_vars *algVars, t_steps_info *minInfo);
int				to_compare(int num1, int num2);
void			finish_sort_a(t_stack *stackA, t_alg_vars *algVars,
					t_command_list *list);

//lists
t_stack_elem	*create_new_element(int value);
void			add_to_stack(t_stack *stack, t_stack_elem *elem);

//actions
void			sn(t_stack *stack, const char *name, t_command_list *list);
void			ss(t_stack *a,
					t_stack *b,
					const char *name,
					t_command_list *list);
void			rn(t_stack *stack, const char *name, t_command_list *list);
void			rr(t_stack *stackA, t_stack *stackB, const char *name,
					t_command_list *list);
void			rrn(t_stack *stack, const char *name, t_command_list *list);
void			rrr(t_stack *stackA, t_stack *stackB, const char *name,
					t_command_list *list);
void			pn(t_stack *to, t_stack *from, const char *name,
					t_command_list *list);

//commands
void			add_command_to_list(t_command_list *list, t_command *command);
void			print_commands(t_command_list *list);
t_command		*create_command(const char *name);

//freeing
void			free_stack(t_stack *stack);
void			free_commands(t_command_list *list);
void			free_stack_and_array(t_stack *stack, int *array, int flag);

//utils
void			*error_msg(void);

//checker
int				get_next_line(int fd, char **line);
int				get_ft_strchr(const char *s, int c);
size_t			get_ft_strlen(const char *s);
char			*get_ft_strdupchr(const char *s1, unsigned char c);
char			*get_ft_strjoin(char const *s1, char const *s2);
int				check_for_number(char *str);
int				check_argv_dups(int argc, char **argv);
void			free_all(t_stack *stackA, t_stack *stackB,
					t_command_list *list);
int				is_list_sorted(t_stack *stackA);

#endif
