/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:21:23 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 22:27:20 by apielasz         ###   ########.fr       */
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

void	sa(t_list **head)
{
	write(1, "sa\n", 3);
	swap(head);
}

void	sb(t_list **head)
{
	write(1, "sb\n", 3);
	swap(head);
}

void	swap_both(t_list **head_a, t_list **head_b)
{
	write(1, "ss\n", 3);
	swap(head_a);
	swap(head_b);
}
