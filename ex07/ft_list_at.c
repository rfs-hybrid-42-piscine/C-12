/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:59:16 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:55:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
 * @brief Retrieves a node at a specified index in the list.
 * @details Iterates through the list exactly 'nbr' times. Treats the head
 * as index 0. Safeguards against out-of-bounds indices by breaking early.
 * @param begin_list A pointer to the first element of the list.
 * @param nbr The unsigned integer index representing the desired node.
 * @return A pointer to the requested node, or NULL if it does not exist.
 */
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
