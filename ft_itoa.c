/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:14:38 by exam              #+#    #+#             */
/*   Updated: 2016/10/17 14:42:05 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nbr(int nbr, int len, char *str)
{
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}

static int	ft_nbrlen(int num)
{
	int		flag;

	flag = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		if (num == -2147483648)
			return (11);
		flag += 1;
		num = -num;
	}
	while (num)
	{
		if (num >= 10)
			flag += 1;
		else
			flag += 1;
		num = num / 10;
	}
	return (flag);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		end;
	int		flag;

	flag = 0;
	len = ft_nbrlen(nbr);
	end = len;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (ft_strdup("-2147483648"));
		flag = 1;
		nbr = ft_absval(nbr);
	}
	ft_nbr(nbr, len, str);
	if (flag)
		str[0] = '-';
	str[end] = '\0';
	return (str);
}
