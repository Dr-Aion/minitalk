/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:01:00 by aiganymmold       #+#    #+#             */
/*   Updated: 2025/01/09 13:01:41 by aiganymmold      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del || !(*lst))
		return ;
	while (lst && (*lst))
	{
		current = (*lst)-> next;
		ft_lstdelone((*lst), del);
		*lst = current;
	}
}
