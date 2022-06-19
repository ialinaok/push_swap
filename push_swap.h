/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:36 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/19 14:40:53 by apielasz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_intsize
{
	char	max[11];
	char	min[11];
	int		size;
}	t_intsize;

/* push_swap.c */
int		show_error_msg(void);
void	load_a(int argc, char **argv, t_list **head);

/* check_input.c */
int	check_if_number(int argc, char **argv);
int	check_if_too_big(int argc, char **argv);
int	get_size_to_compare(char *argvi, char *argvk);;
int	check_for_duplicates(int argc, char **argv);
int	check_input(int argc, char **argv);

/* check_if_too_big.c */
t_intsize	*check_int_size(t_intsize *val);
int	check_len(char *argv, t_intsize *val);
int	deal_with_both(int i, int k, t_intsize *val, char **argv);
int	deal_with_minus(int i, int k, t_intsize *val, char **argv);
int	deal_with_plus(int i, int k, t_intsize *val, char **argv);

/* linked_ops.c */
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newnode);
void	printlist(t_list *head_a, t_list *head_b);
/* utils.c */
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
int		ft_strlen(const char *s);

#endif