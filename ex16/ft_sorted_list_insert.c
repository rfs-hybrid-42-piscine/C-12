/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 23:22:00 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:01:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
 * @brief Injects a new node into a sorted list while maintaining strict order.
 * @details Navigates the sorted chain until the exact insertion point is found.
 * Smoothly splices the new node into the sequence, handling front, middle,
 * or trailing insertions accurately.
 * @param begin_list A double pointer to the head of the sorted list.
 * @param data The payload for the newly inserted node.
 * @param cmp The comparison function used to evaluate order.
 */
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*curr;
	t_list	*prev;

	if (!begin_list || !cmp)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr && cmp(curr->data, new->data) <= 0)
	{
		prev = curr;
		curr = curr->next;
	}
	new->next = curr;
	if (!prev)
		*begin_list = new;
	else
		prev->next = new;
}
