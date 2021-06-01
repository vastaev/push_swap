#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>

typedef struct s_listp
{
	int				value;
	struct s_list	*next;

}				 t_listp;

int		*validation_of_args(int argc, char **argv);
int		error_msg(void);

#endif //PUSH_SWAP_PUSH_SWAP_H
