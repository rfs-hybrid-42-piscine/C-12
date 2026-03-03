/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:02:56 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:53:24 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn int ft_list_size(t_list *begin_list)
 * @brief Calculates the total number of elements in a linked list.
 * @details Iterates through the list sequentially until the NULL terminator
 * is reached, incrementing a size counter at each valid node.
 * @param begin_list A pointer to the first element of the list.
 * @return The integer count of total nodes in the list.
 */
int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}
