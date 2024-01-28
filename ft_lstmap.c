/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:58:06 by tyavroya          #+#    #+#             */
/*   Updated: 2024/01/28 20:13:03 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list	*current;
	t_list	*succ_node;

	current = (t_list *)malloc(sizeof(t_list));
	while (lst)
	{
		succ_node = f(lst->content);
		if (succ_node)
		{
			current->next = (t_list *)malloc(sizeof(t_list));
			current->content = succ_node->content;
		}
		else
		{
			
		}
		lst = lst->next;
	}
}
