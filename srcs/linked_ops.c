/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:58:17 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/22 15:41:42 by ialinaok         ###   ########.fr       */
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

	if (lst)
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

void	printlist(t_list *head_a, t_list *head_b)
{
	t_list	*temp_a = head_a;
	t_list	*temp_b = head_b;
	
	while (temp_a != NULL)
	{
		printf("%d  ", temp_a->index);
		printf("%d\n", temp_a->content);
		if (temp_b != NULL)
		{
			printf("%d  ", temp_b->index);
			printf("%d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	printf("_\t_\na\tb\n\n");
}

t_list	*get_nth_el(t_list *head, int n)
{
	int	i;
	t_list	*temp;

	i = 0;
	temp = head;
	if (temp == NULL)
		return (NULL);
	if (n == 0)
		return (temp);
	return (get_nth_el(temp->next, n - 1));
}