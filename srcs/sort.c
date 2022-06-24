/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:33:34 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 14:52:57 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_list **head_a)
{
	t_list	*first;
	t_list	*second;

	first = *head_a;
	second = first->next;
	if (first->i > second->i)
		sa(head_a);
	else
		return ;
}

void	sort_three(t_list **head_a)
{
	t_list	*top;
	t_list	*mid;
	t_list	*bot;

	top = *head_a;
	mid = top->next;
	bot = mid->next;
	if (top->i > mid->i && mid->i > bot->i && top->i > bot->i)
	{
		sa(head_a);
		rra(head_a);
	}
	else if (top->i > mid->i && mid->i < bot->i && top->i < bot->i)
		sa(head_a);
	else if (top->i < mid->i && mid->i > bot->i && top->i < bot->i)
	{
		sa(head_a);
		ra(head_a);
	}
	else if (top->i < mid->i && mid->i > bot->i && top->i > bot->i)
		rra(head_a);
	else if (top->i > mid->i && mid->i < bot->i && top->i > bot->i)
		ra(head_a);
}

void	rotate_or_reverse(t_list **head_a)
{
	t_list	*temp;
	int		i;

	temp = *head_a;
	i = 0;
	while (temp != NULL)
	{
		if (temp->i < temp->i)
	}
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	t_list	*top;

	top = *head_a;
	*head_b = NULL;
	while (top->i != 0)
	{
		ra(head_a);
		top = *head_a;
	}
	pb(head_b, head_a);
	top = *head_a;
	while (top->i != 1)
	{
		ra(head_a);
		top = *head_a;
	}
	pb(head_b, head_a);
	sort_three(head_a);
	pa(head_a, head_b);
	pa(head_a, head_b);
}
