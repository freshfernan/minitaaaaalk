/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:57:41 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/10 19:38:38 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cb;
	size_t	n;

	cb = (void *)b;
	n = 0;
	while (n < len)
	{
		cb[n] = c;
		n++;
	}
	return (b);
}
