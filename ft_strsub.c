/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 09:18:57 by apineda           #+#    #+#             */
/*   Updated: 2017/02/21 20:37:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len)
	{
		str = ft_strnew(len + 1);
		*str = '\0';
		return (str);
	}
	str = ft_strnew(len);
	if (!s)
		return (NULL);
	if (str)
		ft_strncpy(str, &s[start], len);
	return (str);
}
