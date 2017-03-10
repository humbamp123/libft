/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:58:36 by apineda           #+#    #+#             */
/*   Updated: 2017/03/09 21:58:40 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_nbrlen_base(uintmax_t num, short base)
{
	int		flag;

	if (num == 0)
		return (1);
	flag = num < 0 ? 1 : 0;
	while (num != 0)
	{
		num = num / 10;
		++flag;
	}
	return (flag);
}

char		*ft_itoa_base(uintmax_t nbr, short base)
{
	char	*str;
	int		len;
	int		flag;
	char	hex[16];

	hex = "0123456789ABCDEF";
	len = ft_nbrlen(nbr);
	if (!(str = ft_strnew(len)))
		return (NULL);
	flag = nbr < 0 ? 1 : 0;
	nbr = flag ? -nbr : nbr;
	while (--len)
	{
		str[len] = hex[nbr % base];
		nbr = nbr / base;
	}
	str[len] = hex[nbr % base];
	return (str);
}
