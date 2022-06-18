/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:53:01 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/18 23:47:16 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	show_error_msg(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int n = check_input(argc, argv);
	if (n == -1)
		printf("if number\n");
	if (n == -2)
		printf("too big\n");
	if (n == -3)
		printf("duplicates\n");
	return (0);
}
