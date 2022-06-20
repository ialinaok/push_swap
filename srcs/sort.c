/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:33:34 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/21 01:58:06 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_list **head_a)
{
	t_list	*first;
	t_list	*second;

	first = *head_a;
	second = first->next;
	if (first->index > second->index)
		sa(head_a);
	else
		return ;
}

void	sort_three(t_list **head_a)
{
	t_list	*top;
	t_list	*middle;
	t_list	*bottom;

	top = *head_a;
	middle = top->next;
	bottom = middle->next;
	if (top->index > middle->index && middle->index > bottom->index)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (top->index > middle->index && top->index < bottom->index)
		sa(head_a);
	else if (top->index < middle->index && middle->index > bottom->index)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (top->index < middle->index && top->index > bottom->index)
		rra(head_a);
	else if (top->index > bottom->index && middle->index < bottom->index)
		ra(head_a);
}
