/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:30:15 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/08 17:33:27 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_list **stack)
{
	int	tmp_index;
	int	tmp_content;

	if (!stack || !(*stack) || !((*stack)->next))
		return (-1);
	tmp_content = (*stack)->content;
	tmp_index = (*stack)->index;
	(*stack)->content = (*stack)->next->content;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->content = tmp_content;
	(*stack)->next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	int	sa;
	int	sb;

	sa = swap(stack_a);
	sb = swap(stack_b);
	if (sa == -1 && sb == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}
