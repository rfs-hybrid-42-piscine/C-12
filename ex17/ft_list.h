/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 04:17:03 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 03:18:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

/**
 * @struct s_list
 * @brief The standard 42 linked list node structure.
 * @details Contains a generic void pointer for data payload and a pointer
 * to the next node in the chain.
 * @param next A pointer to the next node in the linked list.
 * @param data A generic void pointer storing the node's data payload.
 */
typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);

#endif
