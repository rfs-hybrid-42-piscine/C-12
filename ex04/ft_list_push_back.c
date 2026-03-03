/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:14:41 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:53:58 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_push_back(t_list **begin_list, void *data)
 * @brief Appends a new element to the end of a linked list.
 * @details Iterates to find the current tail node and attaches the newly
 * created element to its next pointer. Automatically sets the new node as
 * the head if the list is currently empty.
 * @param begin_list A double pointer to the first element of the list.
 * @param data The data payload for the new node.
 */
void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*curr;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	curr = *begin_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
