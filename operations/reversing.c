/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reversing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:20:03 by ialinaok          #+#    #+#             */
/*   Updated: 2022/06/19 22:33:39 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_one_b4_last(t_list *lst)
{
	t_list	*fwd;
	
	if (lst == NULL)
		return (NULL);
	fwd = lst->next;
	while (fwd->next != NULL)
	{
		lst = lst->next;
		fwd = lst->next;
	}
	return (lst);
}

void	reverse(t_list **head)
{
	t_list	*temp;
	t_list	*one_b4_last;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	one_b4_last = ft_one_b4_last(*head);
	last = ft_lstlast(*head);
	temp = *head;
	*head = one_b4_last->next;
	one_b4_last->next = last->next;
	last->next = temp;
}

void	rra(t_list **head)
{
	write(1, "rra\n", 4);
	reverse(head);
}

void	rrb(t_list **head)
{
	write(1, "rrb\n", 4);
	reverse(head);
}

void	reverse_both(t_list **head_a, t_list **head_b)
{
	write(1, "rrr\n", 4);
	reverse(head_a);
	reverse(head_b);
}
