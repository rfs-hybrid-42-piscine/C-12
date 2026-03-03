/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:50:48 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:00:22 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
 * void (*free_fct)(void *))
 * @brief Destroys nodes from a list based on a condition without breaking the
 * chain.
 * @details Manipulates pointers to bridge the gap left by a removed node,
 * then safely executes the provided free function on the data payload before
 * freeing the node itself.
 * @param begin_list A double pointer to the head of the list.
 * @param data_ref The reference data to trigger removal.
 * @param cmp The comparison function.
 * @param free_fct The function utilized to safely free the node's payload.
 */
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	if (!begin_list || !cmp || !free_fct)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		if (!cmp(curr->data, data_ref))
		{
			if (!prev)
				*begin_list = next;
			else
				prev->next = next;
			free_fct(curr->data);
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
}
