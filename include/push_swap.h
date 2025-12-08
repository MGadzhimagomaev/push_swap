/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgadzhim <mgadzhim@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:28:36 by mgadzhim          #+#    #+#             */
/*   Updated: 2025/12/08 18:11:17 by mgadzhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
int			swap(t_list **stack);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);
int			push(t_list **stack_dest, t_list **stack_src);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);
int			rotate(t_list **stack);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);
int			reverse_rotate(t_list **stack);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);
void		ft_check_args(int argc, char **argv);
void		index_stack(t_list **stack);
void		print_list(t_list *list);
int			is_sorted(t_list **stack);
void		ft_free(char **str);
int			get_distance(t_list **stack, int index);
void		free_stack(t_list **stack);
void		sort_simple(t_list **stack_a, t_list **stack_b);
void		sort_radix(t_list **stack_a, t_list **stack_b);

#endif