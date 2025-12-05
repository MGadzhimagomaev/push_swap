#include "../include/push_swap.h"

int	swap(t_list **stack)
{
	int	tmp_index;
	int	tmp_val;

	if (!stack || !(*stack) || !((*stack)->next))
		return (-1);
	tmp_val = (*stack)->val;
	tmp_index = (*stack)->index;
	(*stack)->val = (*stack)->next->val;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->val = tmp_val;
	(*stack)->next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return(0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return(0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	int sa = swap(stack_a);
	int sb = swap(stack_b);

	if (sa == -1 && sb == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
    return(0);
}