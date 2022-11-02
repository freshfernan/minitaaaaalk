/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:54:35 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/24 17:44:11 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*csrc;

	csrc = (char *)src;
	i = ft_strlen(dst);
	k = ft_strlen(src);
	j = i;
	if (dstsize <= i)
		return (dstsize + k);
	while (*csrc && (i + 1 < dstsize))
		*(dst + i++) = *csrc++;
	dst[i] = 00;
	return (k + j);
}
