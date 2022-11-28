/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:56:09 by fefernan          #+#    #+#             */
/*   Updated: 2021/11/10 18:24:52 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*cs;
	int		i;

	cs = (char *)s;
	cc = c;
	i = 0;
	while (cs[i] != 00)
		i++;
	while (cs[i] != cc && i > 0)
		i--;
	if (s[i] == cc)
		return ((char *)cs + i);
	return (0);
}
