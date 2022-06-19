/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:23:19 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 12:44:57 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_if_number(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		// printf("i: %d, number: %s\n", i, argv[i]);
		k = 0;
		while (k < ft_strlen(argv[i]))
		{
			if (argv[i][k] == '-' || argv[i][k] == '+')
				k++;
			while ((argv[i][k] >= '0' && argv[i][k] <= '9') \
			&& k < ft_strlen(argv[i]))
				k++;
			if (k != ft_strlen(argv[i]))
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_if_too_big(int argc, char **argv)
{
	int			i;
	int			k;
	int			len;
	t_intsize	val;

	check_int_size(&val);
	i = 1;
	while (argc > i)
	{
		len = check_len(argv[i], &val);
		if (len == -1)
			return (-1);
		if (len == val.size)
		{
			k = 0;
			if (deal_with_both(i, k, &val, argv) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	get_size_to_compare(char *argvi, char *argvk)
{
	int	n;
	int	leni;
	int	lenk;

	leni = ft_strlen(argvi);
	lenk = ft_strlen(argvk);
	if (leni > lenk)
		n = leni;
	else
		n = lenk;
	return(n);
}

int	check_for_duplicates(int argc, char **argv)
{
	int	i;
	int	k;
	int	n;

	i = 1;
	while (i < argc)
	{
		k = i + 1;
		while (k < argc)
		{
			n = get_size_to_compare(argv[i], argv[k]);
			if (ft_strncmp(argv[i], argv[k], n) == 0)
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	if (check_if_number(argc, argv) == -1)
		return (-1);
	else if (check_if_too_big(argc, argv) == -1)
		return (-1);
	else if (check_for_duplicates(argc, argv) == -1)
		return (-1);
	return (0);
}
