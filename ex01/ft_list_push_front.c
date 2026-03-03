/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 04:35:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:52:41 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_push_front(t_list **begin_list, void *data)
 * @brief Adds a new element to the beginning of a linked list.
 * @details Creates a new node using ft_create_elem. Sets its next pointer
 * to the current head of the list, then updates the head pointer to securely
 * prepend the new node.
 * @param begin_list A double pointer to the first element of the list.
 * @param data The data payload for the new node.
 */
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	new->next = *begin_list;
	*begin_list = new;
}
