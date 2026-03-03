/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:47:34 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:54:53 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
 * @brief Completely erases and frees an entire linked list.
 * @details Safely stores the next pointer before applying the provided
 * function to free the node's data payload, and subsequently freeing
 * the node itself to prevent memory leaks.
 * @param begin_list A pointer to the first element of the list.
 * @param free_fct A function pointer used to cleanly free the void *data.
 */
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next;

	if (!free_fct)
		return ;
	while (begin_list)
	{
		next = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = next;
	}
}
