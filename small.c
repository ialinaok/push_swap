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

int	main(void)
{
	t_list	el1, el2, el3;
	t_list	*head;

	el1.content = 1;
	el2.content = 2;
	el3.content = 3;

	head = &el1;
	el1.next = &el2;
	el2.next = &el3;
	el3.next = NULL;
	printlist(head);
	printf("size: %d\n\n", ft_lstsize(head));
	return (0);
}