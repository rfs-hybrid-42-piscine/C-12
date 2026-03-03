/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:44:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:00:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
 * @brief Locates the first node that matches a specific condition.
 * @details Traverses the list and uses the cmp function to evaluate each node.
 * Immediately returns the first node that yields a 0 from cmp.
 * @param begin_list A pointer to the first element of the list.
 * @param data_ref The reference data to search for.
 * @param cmp The comparison function used to evaluate matches.
 * @return A pointer to the matched node, or NULL if no match is found.
 */
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!cmp)
		return (NULL);
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}
