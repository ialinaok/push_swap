/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:05:38 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/23 00:55:23 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_or_pb(t_list **head_a, t_list **head_b, int max_shift)
{
	t_list	*top;
	t_list	*temp;
	int		i;

	i = 0;
	top = *head_a;
	temp = top;
	while (temp != NULL)
	{
		if (((temp->i >> max_shift) & 1) == 0)
			i++;
		temp = temp->next;
	}
	if (((top->i >> max_shift) & 1) == 1)
		ra(head_a);
	else
		pb(head_b, head_a);
}

t_list	*back_to_a(t_list **head_a, t_list **head_b)
{
	pa(head_a, head_b);
	return (*head_b);
}

void	radix(t_list **head_a, t_list **head_b, int max_el)
{
	int		max_shift;
	int		j;
	t_list	*temp;

	max_shift = 0;
	temp = *head_b;
	while ((max_el >> max_shift) != 0)
	{
		j = 0;
		while (j < max_el + 1)
		{
			ra_or_pb(head_a, head_b, max_shift);
			j++;
		}
		temp = *head_b;
		while (temp != NULL)
			temp = back_to_a(head_a, head_b);
		max_shift++;
	}
}
