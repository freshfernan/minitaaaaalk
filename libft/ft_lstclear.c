/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:08:17 by fefernan          #+#    #+#             */
/*   Updated: 2022/01/12 14:08:50 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;

	if (del && lst)
	{
		while (*lst)
		{
			new = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = new;
		}
	}
	lst = NULL;
}
