/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:53:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 15:58:41 by apielasz         ###   ########.fr       */
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
	int	i;
	// int	content;
	// t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		// content = ft_atoi(argv[i]);
		// newnode = ft_lstnew(content);
		// ft_lstadd_back(head, newnode);
		ft_lstadd_back(head_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
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
		return(show_error_msg());
	load_a(argc, argv, &head_a);
	printlist(head_a, head_b);
	return (0);
}
