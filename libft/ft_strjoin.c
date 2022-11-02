/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:47:20 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/28 13:26:54 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (00);
	dest = (char *)malloc(sizeof (char) * (ft_strlen (s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (00);
	ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	ft_strlcat(&dest[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (dest);
}
