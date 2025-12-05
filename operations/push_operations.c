int	push(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;
	t_list	*head_dest;
	t_list	*head_src;

	if (ft_lstsize(*stack_src) == 0)
		return (-1);
	head_src = *stack_src;
	head_dest = *stack_dest;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dest)
	{
		head_dest = tmp;
		head_dest->next = NULL;
		*stack_dest = head_dest;
	}
	else
	{
		tmp->next = head_dest;
		*stack_dest = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}