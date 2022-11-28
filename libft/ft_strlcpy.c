/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:13:30 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/10 18:29:35 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			j;
	char			*csrc;

	csrc = (char *)src;
	i = 0;
	j = 0;
	while (csrc[i] != 00)
		i++;
	if (dstsize != 0)
	{
		while (csrc[j] != 00 && j < (dstsize - 1))
		{
			dst[j] = csrc[j];
			j++;
		}
		dst[j] = 00;
	}	
	dstsize = i;
	return (dstsize);
}
