/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:19 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/08 17:50:42 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_to_int(const char *s, int *out)
{
	long long	sign;
	long long	n;
	int			i;

	sign = 1;
	n = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i++] == '-')
			sign = -1;
	}
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		n = n * 10 + (s[i++] - '0');
		if ((sign == 1 && n > INT_MAX) || (sign == -1 && (-n) < INT_MIN))
			return (0);
	}
	*out = (int)(n * sign);
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	int		tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (!ft_str_to_int(args[i], &tmp) || ft_contains(tmp, args, i))
		{
			ft_putendl_fd("Error", 2);
			exit(0);
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
