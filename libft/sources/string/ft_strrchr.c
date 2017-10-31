/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:33:12 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 18:57:42 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		len;
	char	c2;

	if (!*str)
		return (0);
	len = ft_strlen(str);
	len--;
	c2 = (char)c;
	while (str[len] != c2 && len >= 0)
		len--;
	if (len < 0)
		return (NULL);
	return (&(str[len]));
}
