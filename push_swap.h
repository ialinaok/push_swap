/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apielasz <apielasz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:36 by apielasz          #+#    #+#             */
/*   Updated: 2022/06/23 00:18:31 by apielasz         ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_intsize
{
	char	max[11];
	char	min[11];
	int		size;
}	t_intsize;

/* push_swap.c */
int			show_error_msg(void);
void		load_a(int argc, char **argv, t_list **head);
void		assign_index(t_list **head, int len);

/* check_input.c */
int			check_if_number(int argc, char **argv);
int			check_if_too_big(int argc, char **argv);
int			get_size_to_compare(char *argvi, char *argvk);;
int			check_for_duplicates(int argc, char **argv);
int			check_input(int argc, char **argv);

/* check_if_too_big.c */
t_intsize	*check_int_size(t_intsize *val);
int			check_len(char *argv, t_intsize *val);
int			deal_with_both(int i, int k, t_intsize *val, char **argv);
int			deal_with_minus(int i, int k, t_intsize *val, char **argv);
int			deal_with_plus(int i, int k, t_intsize *val, char **argv);

/* linked_ops.c */
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);
void		printlist(t_list *head_a, t_list *head_b);
t_list		*get_nth_el(t_list *head, int n);

/* utils.c */
int			ft_atoi(const char *nptr);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_size);
int			ft_strlen(const char *s);

/* swapping.c */
void		swap(t_list **head);
void		sa(t_list **head);
void		sb(t_list **head);
void		swap_both(t_list **head_a, t_list **head_b);

/* pushing.c */
void		push(t_list **head_to, t_list **head_from);
void		pa(t_list **head_a, t_list **head_b);
void		pb(t_list **head_b, t_list **head_a);

/* rotating.c */
void		rotate(t_list **head);
void		ra(t_list **head);
void		rb(t_list **head);
void		rotate_both(t_list **head_a, t_list **head_b);

/* reversing.c */
t_list		*ft_one_b4_last(t_list *lst);
void		reverse(t_list **head);
void		rra(t_list **head);
void		rrb(t_list **head);
void		reverse_both(t_list **head_a, t_list **head_b);

/* radix.c */
void		ra_or_pb(t_list **head_a, t_list **head_b, int max_shift);
t_list		*back_to_a(t_list **head_a, t_list **head_b);
void		radix(t_list **head_a, t_list **head_b, int max_el);

/* sort.c */
void		sort_two(t_list **head_a);
void		sort_three(t_list **head_a);
void		sort_five(t_list **head_a, t_list **head_b);

#endif