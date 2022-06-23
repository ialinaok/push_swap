/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:53:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:27:53 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_list **head_a)
{
	t_list	*temp;
	t_list	*next;

	temp = *head_a;
	while (temp != NULL)
	{
		next = temp->next;
		if (next != NULL && temp->i > next->i)
		{
			return (-1);
		}
		temp = temp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argc, argv) == -1)
		return (show_error_msg());
	if (load_a(argc, argv, &head_a) == -1)
		return (0);
	assign_index(&head_a, argc - 1);
	if (check_stack(&head_a) == 0)
		return (0);
	if (argc - 1 == 2)
		sort_two(&head_a);
	else if (argc - 1 == 3)
		sort_three(&head_a);
	else if (argc - 1 == 5)
		sort_five(&head_a, &head_b);
	else
		radix(&head_a, &head_b, argc - 2);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}
