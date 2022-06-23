/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:12:08 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:16:59 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	show_error_msg(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	load_a(int argc, char **argv, t_list **head_a)
{
	int		i;
	int		content;
	t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		content = ft_atoi(argv[i]);
		newnode = ft_lstnew(content);
		if (!newnode)
			return (-1);
		newnode->i = -1;
		ft_lstadd_back(head_a, newnode);
		i++;
	}
	return (0);
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
		while (min->i != -1)
			min = min->next;
		while (temp != NULL)
		{
			if (temp->content < min->content)
			{
				if (temp->i == -1)
					min = temp;
			}
			temp = temp->next;
		}
		min->i = i;
		i++;
	}
}
