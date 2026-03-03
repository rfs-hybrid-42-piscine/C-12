/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 04:11:30 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:52:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn t_list *ft_create_elem(void *data)
 * @brief Allocates and initializes a new linked list element.
 * @details Safely reserves memory for a t_list struct, assigns the provided
 * data payload, and initializes the next pointer to NULL to signify it as
 * an unlinked node.
 * @param data A void pointer to the data to be stored in the node.
 * @return A pointer to the newly allocated list element, or NULL if malloc
 * fails.
 */
t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
