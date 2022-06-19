/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:30:29 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 22:30:57 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	pa(t_list **head_a, t_list **head_b)
{
	write(1, "pa\n", 3);
	push(head_a, head_b);
}

void	pb(t_list **head_b, t_list **head_a)
{
	write(1, "pb\n", 3);
	push(head_b, head_a);
}
