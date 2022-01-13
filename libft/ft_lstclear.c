/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:57:13 by mbarra            #+#    #+#             */
/*   Updated: 2021/10/18 18:19:39 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*nexta;

	list = *lst;
	while (list)
	{
		nexta = list->next;
		if (del)
			del(list->content);
		free(list);
		list = nexta;
	}
	*lst = NULL;
}
