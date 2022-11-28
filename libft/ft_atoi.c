/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefernan <fefernan@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:40:10 by fefernan          #+#    #+#             */
/*   Updated: 2022/01/07 19:17:02 by fefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		neg;
	char	*cstr;

	neg = 1;
	num = 0;
	i = 0;
	cstr = (char *)str;
	while ((cstr[i] >= 9 && cstr[i] <= 13) || cstr[i] == 32)
		i++;
	if (cstr[i] == '+' || cstr[i] == '-')
	{
		if (cstr[i] == '-')
			neg = -neg;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		num = (cstr[i] - '0') + (num * 10);
		if ((num * neg < -2147483648) || (num * neg > 2147483647))
			return ((num * neg < -2147483648) - 1);
		i++;
	}
	return (num * neg);
}
