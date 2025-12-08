/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:31:27 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/08 17:45:35 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			if ((head->index == -1) 
				&& (!is_min || head->content < min->content))
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
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
