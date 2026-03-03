/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:24:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/03 00:54:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/**
 * @fn t_list *ft_list_push_strs(int size, char **strs)
 * @brief Converts an array of strings into a linked list.
 * @details Traverses the array, pushing elements continuously to the front
 * of the new list. This naturally results in the first element of the array
 * becoming the final node in the list.
 * @param size The number of strings in the array.
 * @param strs The array of strings.
 * @return A pointer to the head of the newly created list, or NULL on failure.
 */
t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*new;
	int		i;

	if (!strs || size <= 0)
		return (NULL);
	list = ft_create_elem(*strs);
	if (!list)
		return (NULL);
	i = 0;
	while (++i < size)
	{
		new = ft_create_elem(strs[i]);
		if (!new)
			return (NULL);
		new->next = list;
		list = new;
	}
	return (list);
}
