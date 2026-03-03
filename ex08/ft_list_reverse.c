/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:08:31 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:55:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_reverse(t_list **begin_list)
 * @brief Reverses the sequence of a linked list in-place.
 * @details Employs three tracking pointers (prev, curr, next) to dynamically
 * invert the direction of the next pointers without altering data payloads
 * or reallocating memory.
 * @param begin_list A double pointer to the head of the list.
 */
void	ft_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	if (!begin_list || !*begin_list)
		return ;
	prev = NULL;
	curr = *begin_list;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}
