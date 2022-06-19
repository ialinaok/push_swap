#include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	printlist(t_list *head)
{
	t_list	*temp = head;

	printf("\nHEAD -> ");
	while (temp != NULL)
	{
		printf("%d -> ", temp->content);
		temp = temp->next;
	}
	printf("NULL\n");
}

void	swap(t_list **head_a)
{
	t_list	*temp;
	int		len;
	t_list	*el1;
	t_list	*el2;

	len = ft_lstsize(*head_a);
	if (len < 2)
		return ;
	el1 = *head_a;
	temp = *head_a;
	el2 = temp->next;
	printf("el1: %d, el2: %d\n", el1->content, el2->content);
	*head_a = el1->next;
	el1->next = el2->next;
	el2->next = temp;
}

void	swap_both(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
}

void	push(t_list **head_to, t_list **head_from)
{
	t_list	*temp;
	t_list	*el1;
	int	lento;

	lento = ft_lstsize(*head_to);
	el1 = *head_from;
	if (ft_lstsize(*head_from) == 0)
		return ;
	temp = *head_from;
	*head_from = el1->next;
	el1->next = *head_to;
	*head_to = temp;
}

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*el1;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	last = ft_lstlast(*head);
	el1 = *head;
	temp = *head;
	*head = el1->next;
	el1->next = last->next;
	last->next = temp;
}

void	rotate_both(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
}

t_list	*ft_one_b4_last(t_list *lst)
{
	t_list	*fwd;
	
	if (lst == NULL)
		return (NULL);
	fwd = lst->next;
	while (fwd->next != NULL)
	{
		lst = lst->next;
		fwd = lst->next;
	}
	return (lst);
}

void	reverse(t_list **head)
{
	t_list	*temp;
	t_list	*one_b4_last;
	t_list	*last;

	if (ft_lstsize(*head) < 2)
		return ;
	one_b4_last = ft_one_b4_last(*head);
	last = ft_lstlast(*head);
	temp = *head;
	*head = one_b4_last->next;
	one_b4_last->next = last->next;
	last->next = temp;
}

void	reverse_both(t_list **head_a, t_list **head_b)
{
	reverse(head_a);
	reverse(head_b);
}

int	main(void)
{
	t_list	el1, el2, el3, el4;
	t_list	n1, n2, n3;
	t_list	*head;
	t_list	*empty;

	el1.content = 1;
	el2.content = 2;
	el3.content = 3;
	el4.content = 4;

	head = &el1;
	el1.next = &el2;
	el2.next = &el3;
	el3.next = &el4;
	el4.next = NULL;

	n1.content = 4;
	n2.content = 5;
	n3.content = 6;

	empty = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = NULL;

	printlist(head);
	printlist(empty);
	reverse_both(&head, &empty);
	// rotate_both(&head, &empty);
	printlist(head);
	printlist(empty);
	// printlist(empty);
	// swap_a(&head);
	// printf("\nafter swapping: ");
	// printlist(head);
	// printf("--------------------pushed\n");
	// push(&head, &empty);

	// printf("from: ");
	// printlist(head);
	// printf("to: ");
	// printlist(empty);
	printf("\nsize: %d\n\n", ft_lstsize(empty));
	return (0);
}