/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 00:03:30 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:02:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
 * int (*cmp)())
 * @brief Gracefully merges two distinct sorted lists into a single sorted
 * chain.
 * @details Implements a recursive approach to zip the nodes together
 * sequentially. Compares the heads of both lists iteratively, weaving their
 * next pointers seamlessly without allocating new memory.
 * @param begin_list1 A double pointer to the first sorted list.
 * @param begin_list2 A pointer to the second sorted list.
 * @param cmp The comparison function.
 */
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*tmp;

	if (!begin_list1 || !begin_list2 || !cmp)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (cmp((*begin_list1)->data, begin_list2->data) > 0)
	{
		tmp = begin_list2->next;
		begin_list2->next = *begin_list1;
		*begin_list1 = begin_list2;
		ft_sorted_list_merge(begin_list1, tmp, cmp);
	}
	else
		ft_sorted_list_merge(&(*begin_list1)->next, begin_list2, cmp);
}
