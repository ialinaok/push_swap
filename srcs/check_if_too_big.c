/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_too_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:12:25 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/18 23:22:38 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_intsize	*check_int_size(t_intsize *val)
{
	if (sizeof(int) == 4)
	{
		ft_strlcpy(val->max, "2147483647", 11);
		ft_strlcpy(val->min, "2147483648", 11);
		val->size = 10;
	}
	else if (sizeof(int) == 2)
	{
		ft_strlcpy(val->max, "32767", 11);
		ft_strlcpy(val->min, "32768", 11);
		val->size = 5;
	}
	return (val);
}

int	check_len(char *argv, t_intsize *val)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(&argv[i]);
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (len > val->size + 1)
			return (-1);
		else if (len == val->size + 1)
		{
			val->size = val->size + 1;
			return (val->size);
		}
	}
	else
	{
		if (len > val->size)
			return (-1);
		else if (len == val->size)
			return (val->size);
	}
	return ((int)len);
}

int	deal_with_both(int i, int k, t_intsize *val, char **argv)
{
	if (argv[i][k] == '-')
	{
		if (deal_with_minus(i, k, val, argv) == -1)
			return (-1);
	}
	else if (argv[i][k] == '+')
		k++;
	else if (deal_with_plus(i, k, val, argv) == -1)
		return (-1);
	return (0);
}

int	deal_with_minus(int i, int k, t_intsize *val, char **argv)
{
	k++;
	if (ft_strncmp(&argv[i][k], val->min, ft_strlen(&argv[i][k])) > 0)
		return (-1);
	return (0);
}

int	deal_with_plus(int i, int k, t_intsize *val, char **argv)
{
	if (ft_strncmp(&argv[i][k], val->max, ft_strlen(&argv[i][k])) > 0)
		return (-1);
	return (0);
}
