#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*get_nth_el(t_list *head, int	n)
{
	int	i;
	t_list	*temp;

	i = 0;
	temp = head;
	if (temp == NULL)
		return (NULL);
	if (n == 0)
		return (temp);
	return (get_nth_el(temp->next, n - 1));
}

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

void	assign_index(t_list **head)
{
	t_list	*min;
	t_list	*temp;
	int		i;
	int		len;

	i = 0;
	temp = *head;
	min = temp;
	len = ft_lstsize(*head);
	while (i < len)
	{
		temp = *head;
		min = temp->next;
		while (temp != NULL)
		{
			printf(".......\n");
			printf("temp->next %d\n", temp->content);
			if (min->content > temp->content)
			{
				printf("-----------\n");
				if (temp->index == -1)
					min = temp;
			}
			temp = temp->next;
		}
		min->index = i;
		i++;
	}
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

int	main(int argc, char **argv)
{
	t_list	el1, el2, el3, el4;
	t_list	*head;
	t_list	*nth;
	t_list	*test;

	el1.content = -8;
	el2.content = 19;
	el3.content = 7;
	el4.content = -5;

	el1.index = -1;
	el2.index = -1;
	el3.index = -1;
	el4.index = -1;

	head = &el1;
	el1.next = &el2;
	el2.next = &el3;
	el3.next = &el4;
	el4.next = NULL;

	printlist(head);
	assign_index(&head);
	int	i = 0;
	while (i < ft_lstsize(head))
	{
		nth = get_nth_el(head, i);
		printf("nth: %d\n", nth->content);
		test = get_nth_el(head, i);
		printf("the index: %d\n", test->index);
		i++;
	}
	return (0);
}