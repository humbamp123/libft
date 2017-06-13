/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:28:57 by apineda           #+#    #+#             */
/*   Updated: 2017/06/13 15:25:22 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_front_white(char const *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static	int		ft_back_white(char const *str)
{
	int		i;
	int		j;

	j = ft_strlen(str) - 1;
	i = 0;
	while (j)
	{
		if (str[j] == ' ' || str[j] == '\n' || str[j] == '\t'
				|| str[j] == '\v' || str[j] == '\f' || str[j] == '\r')
			i++;
		else
			break ;
		j--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		size;
	int		start;
	int		back;

	str = NULL;
	if (!s)
		return (NULL);
	start = ft_front_white(s);
	back = ft_back_white(s);
	if ((start == 0 && back == 0))
	{
		str = ft_strdup(s);
		return (str);
	}
	size = ft_absval(ft_strlen(&s[start]) - back);
	str = ft_strsub(s, start, size);
	return (str);
}
