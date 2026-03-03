/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 22:22:07 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 01:00:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn void ft_list_sort(t_list **begin_list, int (*cmp)())
 * @brief Sorts a linked list dynamically.
 * @details Employs a bubble sort approach. Rather than detaching and re-linking
 * memory pointers (which risks chain fragmentation), it safely swaps the void
 * data payloads of the nodes when cmp evaluates an out-of-order sequence.
 * @param begin_list A double pointer to the head of the list.
 * @param cmp A pointer to the evaluation function.
 */
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*curr;
	t_list	*tmp;
	void	*swap;

	if (!begin_list || !cmp)
		return ;
	curr = *begin_list;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (cmp(curr->data, tmp->data) > 0)
			{
				swap = tmp->data;
				tmp->data = curr->data;
				curr->data = swap;
			}
			tmp = tmp->next;
		}
		curr = curr->next;
	}
}
