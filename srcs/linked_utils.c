/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:25:15 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:28:55 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	printlist(t_list *head_a, t_list *head_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = head_a;
	temp_b = head_b;
	while (temp_a != NULL)
	{
		printf("%d  ", temp_a->i);
		printf("%d\n", temp_a->content);
		if (temp_b != NULL)
		{
			printf("%d  ", temp_b->i);
			printf("%d\n", temp_b->content);
			temp_b = temp_b->next;
		}
		temp_a = temp_a->next;
	}
	printf("_\t_\na\tb\n\n");
}

t_list	*get_nth_el(t_list *head, int n)
{
	t_list	*temp;

	temp = head;
	if (temp == NULL)
		return (NULL);
	if (n == 0)
		return (temp);
	return (get_nth_el(temp->next, n - 1));
}
