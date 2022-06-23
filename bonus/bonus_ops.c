/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:14:18 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:21:32 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_both_bonus(t_list **head_a, t_list **head_b)
{
	reverse(head_a);
	reverse(head_b);
}

void	rotate_both_bonus(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

void	swap_both_bonus(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
}
