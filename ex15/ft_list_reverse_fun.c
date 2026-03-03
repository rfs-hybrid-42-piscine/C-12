/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:36:40 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:03:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn static int ft_list_size(t_list *begin_list)
 * @brief Computes the total number of nodes to define the halfway iteration
 * point.
 * @details Iterates through the linked list sequentially until the NULL
 * terminator is reached, incrementing a size counter at each valid node.
 * @param begin_list A pointer to the head of the list.
 * @return The integer size of the list.
 */
static int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

/**
 * @fn void ft_list_reverse_fun(t_list *begin_list)
 * @brief Reverses the sequence of a list by swapping payloads.
 * @details Unlike ft_list_reverse, this function leaves the next pointers
 * strictly untouched. It traverses the first half of the list, identifying
 * the mirroring counterpart node in the second half, and physically trades
 * their void *data payloads.
 * @param begin_list A pointer to the head of the list.
 */
void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*tmp;
	void	*swap;
	int		size;
	int		i;
	int		j;

	size = ft_list_size(begin_list);
	i = -1;
	while (++i < size / 2)
	{
		tmp = begin_list->next;
		j = i;
		while (++j < size - i - 1)
			tmp = tmp->next;
		swap = tmp->data;
		tmp->data = begin_list->data;
		begin_list->data = swap;
		begin_list = begin_list->next;
	}
}
