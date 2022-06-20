/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:14:24 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 22:32:22 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ra(t_list **head)
{
	write(1, "ra\n", 3);
	rotate(head);
}

void	rb(t_list **head)
{
	write(1, "rb\n", 3);
	rotate(head);
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	write(1, "rr\n", 3);
	rotate(head_a);
	rotate(head_b);
}
