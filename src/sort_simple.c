/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:30:45 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/08 18:50:36 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	sort_3(t_list **stack_a, t_list *head)
{
	if (head->index == get_min(stack_a, -1) 
		&& head->next->index != get_min(stack_a, get_min(stack_a, -1)))
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == get_min(stack_a, get_min(stack_a, -1)))
	{
		if (head->next->index == get_min(stack_a, -1))
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == get_min(stack_a, -1))
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a, *stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	list_size;
	int	min;
	int	next_min;

	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	list_size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a) || list_size <= 1)
		return ;
	if (list_size == 2)
		sa(stack_a);
	else if (list_size == 3)
		sort_3(stack_a, *stack_a);
	else if (list_size == 4)
		sort_4(stack_a, stack_b);
	else if (list_size == 5)
		sort_5(stack_a, stack_b);
}
