#include "../include/push_swap.h"

static int	get_min(t_list **stack, int idx)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != idx)
			min = head->index;
	}
	return (min);
}

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		is_min;

	is_min = 0;
	min = NULL;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!is_min || head->content < min->content))
			{
				is_min = 1;
				min = head;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while(head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}