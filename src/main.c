#include <stdio.h>
#include "../include/push_swap.h"

void	ft_convert_input(int	argc, char	**argv)
{
	int		i;
	long	temp;
	char	**arg;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (arg[i])
	{
		temp = ft_atoi(arg[i]);
		//check if numeric
		//check ?
		//check if within int range
		i++;
	}

	i = 0;
	while (arg[i])
		printf("%s\n", arg[i++]);
}

int main(int	argc, char	**argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2 || !argv[1])
		return (-1);
	else
		ft_convert_input(argc, argv);

	return (0);
}