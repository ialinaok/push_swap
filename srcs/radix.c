/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:05:38 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/21 00:56:41 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix(t_list **head_a, t_list **head_b, int len)
{
	int	max_el;
	int	max_shift;
	int	i;
	int	j;
	t_list	*top;
	t_list	*temp;

	// top = *head_a;

	max_el = len - 1;
	max_shift = 0;
	temp = *head_b;
	printf("len: %d, max_el: %d, max_shift: %d\n", len, max_el, max_shift);
	while ((max_el>>max_shift) != 0)
	{
		i = 0;
		while (i < max_shift)
		{
			j = 0;
			while (j < len)
			{
				top = *head_a;
				if (((top->index>>i)&1) == 1)
					ra(head_a);
				else
					pb(head_b, head_a);
				j++;
			}
			temp = *head_b;
			while (temp != NULL)
			{
				pa(head_a, head_b);
				temp = *head_b;
			}
			i++;
		}
		printlist(*head_a, *head_b);
		max_shift++;
	}
}