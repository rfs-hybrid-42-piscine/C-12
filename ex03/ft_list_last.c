/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:08:44 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:53:36 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn t_list *ft_list_last(t_list *begin_list)
 * @brief Retrieves the final element of a linked list.
 * @details Safely handles empty lists, then loops continuously checking if
 * the next pointer exists, terminating execution exactly on the tail node.
 * @param begin_list A pointer to the first element of the list.
 * @return A pointer to the last element, or NULL if the list is empty.
 */
t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
