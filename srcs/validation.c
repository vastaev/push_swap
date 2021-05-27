#include "../includes/push_swap.h"

int			check_for_number(char *str);

int	validation_of_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 2)
	{

	}
	while (i < argc)
	{
		if (check_for_number(argv[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}
// −9,223,372,036,854,775,807
int error_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	check_for_number(char *str)
{

	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (error_msg());
}


//Проходить по каждой строке
//1)Пропускать разделители чисел(табы или пробелы)
//2)Проверка числа
// 1)Знак + или -
// 2)Только цифры (меньше 27)
