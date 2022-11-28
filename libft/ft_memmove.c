/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:05:12 by fefernan          #+#    #+#             */
/*   Updated: 2022/01/07 18:19:51 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (!src && !dst)
		return (00);
	if (src < dst)
	{
		while (len--)
			cdst[len] = csrc[len];
	}
	else
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
