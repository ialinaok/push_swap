/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:53:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/23 00:16:26 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	show_error_msg(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

void	load_a(int argc, char **argv, t_list **head_a)
{
	int		i;
	int		content;
	t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		newnode = ft_lstnew(content);
		newnode->index = -1;
		ft_lstadd_back(head_a, newnode);
		i++;
	}
}

void	assign_index(t_list **head, int len)
{
	t_list	*temp;
	t_list	*min;
	int		i;

	i = 0;
	temp = *head;
	while (i < len)
	{
		temp = *head;
		min = temp;
		while (min->index != -1)
			min = min->next;
		while (temp != NULL)
		{
			if (temp->content < min->content)
			{
				if (temp->index == -1)
					min = temp;
			}
			temp = temp->next;
		}
		min->index = i;
		i++;
	}
}

void	choose_sort(t_list **head_a, t_list **head_b, int len)
{
	*head_a = NULL;
	*head_b = NULL;
	if (len == 1)
		return ;
	else if (len == 2)
		sort_two(head_a);
	else if (len == 3)
		sort_three(head_a);
	else if (len == 5)
		sort_five(head_a, head_b);
	else
		radix(head_a, head_b, len - 1);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	int		len;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argc, argv) == -1)
		return (show_error_msg());
	load_a(argc, argv, &head_a);
	len = ft_lstsize(head_a);
	assign_index(&head_a, len);
	if (len == 2)
		sort_two(&head_a);
	else if (len == 3)
		sort_three(&head_a);
	else if (len == 5)
		sort_five(&head_a, &head_b);
	else
		radix(&head_a, &head_b, len - 1);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}
