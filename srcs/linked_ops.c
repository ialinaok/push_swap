/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:58:17 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:25:41 by apielasz         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*first;
	t_list	*next;

	if (lst && *lst)
	{
		next = *lst;
		while (next != NULL)
		{
			first = next;
			next = next->next;
			free(first);
		}
		*lst = NULL;
	}
}
