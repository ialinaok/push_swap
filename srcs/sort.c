/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:33:34 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/25 15:08:39 by ialinaok         ###   ########.fr       */
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

int	rotate_or_reverse(t_list **head_a)
{
	t_list	*temp;
	t_list	*min;
	int		i;

	temp = *head_a;
	min = temp;
	i = 0;
	while (temp != NULL)
	{
		if (temp->i < min->i)
			min = temp;
		temp = temp->next;
	}
	temp = *head_a;
	while (i < 5)
	{
		if (temp->i == min->i)
			break ;
		i++;
	}
	if (i < 2)
		return (e_ra);
	else
		return (e_rra);
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	t_list	*top;
	void	(*fun_ptr)(t_list **);

	top = *head_a;
	*head_b = NULL;
	if (rotate_or_reverse(head_a) == e_ra)
		fun_ptr = &ra;
	else if (rotate_or_reverse(head_a) == e_rra)
		fun_ptr = &rra;
	while (top->i != 0)
	{
		fun_ptr(head_a);
		top = *head_a;
	}
	pb(head_b, head_a);
	top = *head_a;
	while (top->i != 1)
	{
		fun_ptr(head_a);
		top = *head_a;
	}
	pb(head_b, head_a);
	sort_three(head_a);
	pa(head_a, head_b);
	pa(head_a, head_b);
}
