/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 01:09:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:12:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_list.h"

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX00
# define EX01
# define EX02
# define EX03
# define EX04
# define EX05
# define EX06
# define EX07
# define EX08
# define EX09
# define EX10
# define EX11
# define EX12
# define EX13
# define EX14
# define EX15
# define EX16
# define EX17
#endif

/* --- Prototypes --- */
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_push_back(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

/* --- Custom Helper Functions for Testing --- */
t_list	*build_test_list(int size, char **strs)
{
	t_list	*head = NULL;
	t_list	*curr = NULL;
	for (int i = 0; i < size; i++)
	{
		t_list *new = malloc(sizeof(t_list));
		new->data = strs[i];
		new->next = NULL;
		if (!head)
			head = new;
		else
			curr->next = new;
		curr = new;
	}
	return (head);
}

void	print_list_str(t_list *list)
{
	while (list)
	{
		printf("[%s] -> ", (char *)list->data);
		list = list->next;
	}
	printf("NULL\n");
}

void	print_str(void *data)
{
	printf("[%s] ", (char *)data);
}

int		cmp_str(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

void	dummy_free(void *data)
{
	/* We use string literals for testing, so we don't actually call free() here to prevent crashes.
	 * We just print to prove the function was routed correctly! */
	printf("(freed: %s) ", (char *)data);
}

/* --- Main Testing Function --- */
int	main(void)
{
#ifdef EX00
	printf("--- EX00: ft_create_elem ---\n");
	t_list *elem = ft_create_elem("Node 1");
	printf("Expected: [Node 1] -> NULL\nResult  : ");
	if (elem)
	{
		printf("[%s] -> %s\n", (char *)elem->data, elem->next == NULL ? "NULL" : "ERR");
		free(elem);
	}
	printf("\n");
#endif

#ifdef EX01
	printf("--- EX01: ft_list_push_front ---\n");
	char *strs1[] = {"Node 1"};
	t_list *list1 = build_test_list(1, strs1);
	ft_list_push_front(&list1, "Front Node");
	printf("Expected: [Front Node] -> [Node 1] -> NULL\nResult  : ");
	print_list_str(list1);
	printf("\n");
#endif

#ifdef EX02
	printf("--- EX02: ft_list_size ---\n");
	char *strs2[] = {"A", "B", "C"};
	t_list *list2 = build_test_list(3, strs2);
	printf("Expected: 3\nResult  : %d\n\n", ft_list_size(list2));
#endif

#ifdef EX03
	printf("--- EX03: ft_list_last ---\n");
	char *strs3[] = {"A", "B", "Tail Node"};
	t_list *list3 = build_test_list(3, strs3);
	t_list *last = ft_list_last(list3);
	printf("Expected: Tail Node\nResult  : %s\n\n", last ? (char *)last->data : "NULL");
#endif

#ifdef EX04
	printf("--- EX04: ft_list_push_back ---\n");
	char *strs4[] = {"Head"};
	t_list *list4 = build_test_list(1, strs4);
	/* Note: This test relies on ft_create_elem being available during compilation */
	ft_list_push_back(&list4, "Back Node");
	printf("Expected: [Head] -> [Back Node] -> NULL\nResult  : ");
	print_list_str(list4);
	printf("\n");
#endif

#ifdef EX05
	printf("--- EX05: ft_list_push_strs ---\n");
	char *strs5[] = {"First", "Second", "Third"};
	/* Note: This test relies on ft_create_elem being available during compilation */
	t_list *list5 = ft_list_push_strs(3, strs5);
	printf("Expected: [Third] -> [Second] -> [First] -> NULL\nResult  : ");
	print_list_str(list5);
	printf("\n");
#endif

#ifdef EX06
	printf("--- EX06: ft_list_clear ---\n");
	char *strs6[] = {"A", "B"};
	t_list *list6 = build_test_list(2, strs6);
	printf("Expected to print free logs for A and B:\nResult  : ");
	ft_list_clear(list6, dummy_free);
	printf("\n\n");
#endif

#ifdef EX07
	printf("--- EX07: ft_list_at ---\n");
	char *strs7[] = {"Index 0", "Index 1", "Index 2"};
	t_list *list7 = build_test_list(3, strs7);
	t_list *at_node = ft_list_at(list7, 1);
	printf("Expected: Index 1\nResult  : %s\n\n", at_node ? (char *)at_node->data : "NULL");
#endif

#ifdef EX08
	printf("--- EX08: ft_list_reverse ---\n");
	char *strs8[] = {"1", "2", "3"};
	t_list *list8 = build_test_list(3, strs8);
	ft_list_reverse(&list8);
	printf("Expected: [3] -> [2] -> [1] -> NULL\nResult  : ");
	print_list_str(list8);
	printf("\n");
#endif

#ifdef EX09
	printf("--- EX09: ft_list_foreach ---\n");
	char *strs9[] = {"Do", "Re", "Mi"};
	t_list *list9 = build_test_list(3, strs9);
	printf("Expected: [Do] [Re] [Mi]\nResult  : ");
	ft_list_foreach(list9, print_str);
	printf("\n\n");
#endif

#ifdef EX10
	printf("--- EX10: ft_list_foreach_if ---\n");
	char *strs10[] = {"Apple", "Banana", "Apple", "Cherry"};
	t_list *list10 = build_test_list(4, strs10);
	printf("Expected: [Apple] [Apple]\nResult  : ");
	ft_list_foreach_if(list10, print_str, "Apple", cmp_str);
	printf("\n\n");
#endif

#ifdef EX11
	printf("--- EX11: ft_list_find ---\n");
	char *strs11[] = {"Cat", "Dog", "Bird"};
	t_list *list11 = build_test_list(3, strs11);
	t_list *found = ft_list_find(list11, "Dog", cmp_str);
	printf("Expected: Dog\nResult  : %s\n\n", found ? (char *)found->data : "NULL");
#endif

#ifdef EX12
	printf("--- EX12: ft_list_remove_if ---\n");
	char *strs12[] = {"Keep", "Remove", "Keep"};
	t_list *list12 = build_test_list(3, strs12);
	ft_list_remove_if(&list12, "Remove", cmp_str, dummy_free);
	printf("\nExpected: [Keep] -> [Keep] -> NULL\nResult  : ");
	print_list_str(list12);
	printf("\n");
#endif

#ifdef EX13
	printf("--- EX13: ft_list_merge ---\n");
	char *strs13_1[] = {"A", "B"};
	char *strs13_2[] = {"C", "D"};
	t_list *list13_1 = build_test_list(2, strs13_1);
	t_list *list13_2 = build_test_list(2, strs13_2);
	ft_list_merge(&list13_1, list13_2);
	printf("Expected: [A] -> [B] -> [C] -> [D] -> NULL\nResult  : ");
	print_list_str(list13_1);
	printf("\n");
#endif

#ifdef EX14
	printf("--- EX14: ft_list_sort ---\n");
	char *strs14[] = {"Zebra", "Apple", "Mango"};
	t_list *list14 = build_test_list(3, strs14);
	ft_list_sort(&list14, cmp_str);
	printf("Expected: [Apple] -> [Mango] -> [Zebra] -> NULL\nResult  : ");
	print_list_str(list14);
	printf("\n");
#endif

#ifdef EX15
	printf("--- EX15: ft_list_reverse_fun ---\n");
	char *strs15[] = {"1", "2", "3", "4"};
	t_list *list15 = build_test_list(4, strs15);
	ft_list_reverse_fun(list15);
	printf("Expected: [4] -> [3] -> [2] -> [1] -> NULL\nResult  : ");
	print_list_str(list15);
	printf("\n");
#endif

#ifdef EX16
	printf("--- EX16: ft_sorted_list_insert ---\n");
	char *strs16[] = {"Apple", "Cherry"};
	t_list *list16 = build_test_list(2, strs16);
	/* Note: This test relies on ft_create_elem being available */
	ft_sorted_list_insert(&list16, "Banana", cmp_str);
	printf("Expected: [Apple] -> [Banana] -> [Cherry] -> NULL\nResult  : ");
	print_list_str(list16);
	printf("\n");
#endif

#ifdef EX17
	printf("--- EX17: ft_sorted_list_merge ---\n");
	char *strs17_1[] = {"A", "C", "E"};
	char *strs17_2[] = {"B", "D", "F"};
	t_list *list17_1 = build_test_list(3, strs17_1);
	t_list *list17_2 = build_test_list(3, strs17_2);
	ft_sorted_list_merge(&list17_1, list17_2, cmp_str);
	printf("Expected: [A] -> [B] -> [C] -> [D] -> [E] -> [F] -> NULL\nResult  : ");
	print_list_str(list17_1);
	printf("\n");
#endif

	return (0);
}
