#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}

int	show_error_msg(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

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
		printf("nptr[i]: %d\nsign: %d\n", nptr[i], sign);
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		count = count * 10 + (nptr[i] - '0');
		i++;
	}
	return (count * sign);
}

typedef struct s_intsize
{
	char	max[11];
	char	min[11];
	int		size;
}	t_intsize;

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

int	main(int argc, char **argv)
{
	int	n = 0;
	int m = 0;

	// while (n < argc)
	// {
	// 	printf("argv[%d]: %s\n", n, argv[n]);
	// 	n++;
	// }
	// char arr[] = "0";
	// m = ft_atoi(arr);
	// printf("ret: %d\n", m);
	// n = check_if_number(argc, argv);
	n = check_for_duplicates(argc, argv);
	printf("this is check: %d\n", n);
	printf("sizeof int: %zu\n", sizeof(int));
	return (0);
}