/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:32:05 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/24 00:28:08 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	count;

	i = 0;
	sign = 1;
	count = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		sign = 44;
		sign = sign - nptr[i];
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		count = count * 10 + (nptr[i] - '0');
		i++;
	}
	return (count * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if ((*s1 == '\0') || (*s2 == '\0'))
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (dst_size > 0)
	{
		dst_size--;
		while (i < dst_size && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	else
		return (0);
}
