/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:44:38 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:21:43 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_the_ops(t_list **head_a, t_list **head_b, char *op)
{
	if (ft_strncmp("pa\n", op, 3) == 0)
		push(head_a, head_b);
	else if (ft_strncmp("pb\n", op, 3) == 0)
		push(head_b, head_a);
	else if (ft_strncmp("rra\n", op, 4) == 0)
		reverse(head_a);
	else if (ft_strncmp("rrb\n", op, 4) == 0)
		reverse(head_b);
	else if (ft_strncmp("rrr\n", op, 4) == 0)
		reverse_both_bonus(head_a, head_b);
	else if (ft_strncmp("ra\n", op, 3) == 0)
		rotate(head_a);
	else if (ft_strncmp("rb\n", op, 3) == 0)
		rotate(head_b);
	else if (ft_strncmp("rr\n", op, 3) == 0)
		rotate_both_bonus(head_a, head_b);
	else if (ft_strncmp("sa\n", op, 3) == 0)
		swap(head_a);
	else if (ft_strncmp("sb\n", op, 3) == 0)
		swap(head_b);
	else if (ft_strncmp("ss\n", op, 3) == 0)
		swap_both_bonus(head_a, head_b);
	else
		return (-1);
	return (0);
}

void	check_stacks(t_list **head_a, t_list *head_b)
{
	t_list	*temp;
	t_list	*next;

	temp = *head_a;
	if (head_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (temp != NULL)
	{
		next = temp->next;
		if (next != NULL && temp->i > next->i)
		{
			write(1, "KO\n", 3);
			return ;
		}
		temp = temp->next;
	}
	write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	*op;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (check_input(argc, argv) == -1)
		return (show_error_msg());
	if (load_a(argc, argv, &head_a) == -1)
		return (0);
	assign_index(&head_a, argc - 1);
	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break ;
		if (do_the_ops(&head_a, &head_b, op) == -1)
			return (show_error_msg());
	}
	check_stacks(&head_a, head_b);
	ft_lstclear(&head_a);
	ft_lstclear(&head_b);
	return (0);
}
