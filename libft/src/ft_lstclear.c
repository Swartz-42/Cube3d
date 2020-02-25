/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:33:50 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:33:52 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	clear(t_list *lst, void (*del)(void*))
{
	if (lst->next)
		clear(lst->next, del);
	ft_lstdelone(lst, del);
}

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst)
		return ;
	clear(*lst, del);
	*lst = 0;
}
