/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:20:03 by ialinaok          #+#    #+#             */
/*   Updated: 2022/06/19 21:53:03 by ialinaok         ###   ########.fr       */
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

void	reverse_both(t_list **head_a, t_list **head_b)
{
	reverse(head_a);
	reverse(head_b);
}
