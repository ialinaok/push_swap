/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:14:24 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 21:19:41 by ialinaok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **head)
{
	t_list	*temp;
	t_list	*el1;
	t_list	*el2;

	if (ft_lstsize(*head) < 2)
		return ;
	el1 = *head;
	temp = *head;
	el2 = temp->next;
	*head = el1->next;
	el1->next = el2->next;
	el2->next = temp;
}

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
}

void	push(t_list **head_to, t_list **head_from)
{
	t_list	*temp;
	t_list	*el1;
	int	lento;

	lento = ft_lstsize(*head_to);
	el1 = *head_from;
	if (ft_lstsize(*head_from) == 0)
		return ;
	temp = *head_from;
	*head_from = el1->next;
	el1->next = *head_to;
	*head_to = temp;
}

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*el1;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	last = ft_lstlast(*head);
	el1 = *head;
	temp = *head;
	*head = el1->next;
	el1->next = last->next;
	last->next = temp;
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
}
