#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

/*
#include <stdlib.h>
#include <stdio.h>

t_list *create_node(void *data)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->next = NULL;
}

int	main(void)
{
	t_list *node1 = create_node("1");
	t_list *node2 = create_node("2");
	t_list *node3 = create_node("3");
	t_list *node4 = create_node("3");

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	int len = ft_list_size(node1);
	printf("%d\n", len);
}*/