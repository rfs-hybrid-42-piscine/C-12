/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:35:20 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:59:28 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_foreach(t_list *begin_list, void (*f)(void *))
 * @brief Applies a function to the data of every node in the list.
 * @details Traverses the linked list sequentially and passes the void pointer
 * data payload of each node into the provided function pointer.
 * @param begin_list A pointer to the first element of the list.
 * @param f A pointer to the function to apply to each node's data.
 */
void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	if (!f)
		return ;
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
