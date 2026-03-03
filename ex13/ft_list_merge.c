/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:09:30 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:00:45 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
 * @brief Concatenates two linked lists.
 * @details Finds the tail node of the first list and points its next attribute
 * to the head of the second list. If the first list is empty, it assigns the
 * head of the second list as the new start.
 * @param begin_list1 A double pointer to the head of the first list.
 * @param begin_list2 A pointer to the head of the list to append.
 */
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*curr;

	if (!begin_list1)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	curr = *begin_list1;
	while (curr->next)
		curr = curr->next;
	curr->next = begin_list2;
}
