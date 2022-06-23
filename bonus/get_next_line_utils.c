/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 02:05:56 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:21:52 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *str, int n)
{
	unsigned char	*put;

	put = str;
	while (n > 0)
	{
		*put++ = '\0';
		n--;
	}
}

char	*ft_strchr(char const *str, int c)
{
	char	*ptr;

	ptr = (char *) str;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
