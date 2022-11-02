/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:48:21 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/26 17:59:33 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (00);
	return (ft_memcpy(dest, s1, (ft_strlen(s1) + 1)));
}
