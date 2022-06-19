/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:58:17 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 14:46:19 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*last;

	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = newnode;
	}
	else
		*lst = newnode;
}

void	printlist(t_list *head_a, t_list *head_b)
{
	t_list	*temp_a = head_a;
	t_list	*temp_b = head_b;
	
	while (temp_a != NULL)
	{
		printf("%d\n", temp_a->content);
		if (temp_b != NULL)
		{
			printf("%d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	printf("_\t_\na\tb\n");
}