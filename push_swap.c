/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialinaok <ialinaok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:53:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/22 16:24:41 by ialinaok         ###   ########.fr       */
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
		// ft_lstadd_back(head_a, ft_lstnew(ft_atoi(argv[i])));
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

// void	choose_sort(t_list **head_a, t_list **head_b, int len)
// {
// 	if (len == 2)
// 		sort_two(head_a);
// 	if (len == 3)
// 		sort_three(head_a);
// }

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
	printf("len in main: %d\n", len);
	assign_index(&head_a, len);
	printlist(head_a, head_b);
	// choose_sort(&head_a, &head_b, len);
	radix(&head_a, &head_b, len);
	printlist(head_a, head_b);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}
