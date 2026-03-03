/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:38:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:59:46 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
 * void *data_ref, int (*cmp)())
 * @brief Applies a function to node data conditionally.
 * @details Evaluates each node's data against data_ref using the cmp function.
 * If cmp returns 0 (indicating a match), the function f is applied to the data.
 * @param begin_list A pointer to the first element of the list.
 * @param f The function to apply on a successful match.
 * @param data_ref The reference data to compare against.
 * @param cmp The comparison function.
 */
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *data_ref, int (*cmp)())
{
	if (!f || !cmp)
		return ;
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
