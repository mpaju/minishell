/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:58:39 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 18:58:40 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, size_t num)
{
	char	*ret;

	if (!str || !(*str) || !num)
		return (NULL);
	if ((unsigned int)ft_strlen(str) <= num)
		ret = ft_strdup(str);
	else
	{
		ret = (char *)ft_memalloc((num + 1) * sizeof(char));
		while (*str && num)
		{
			ret[num - 1] = str[num - 1];
			num--;
		}
	}
	return (ret);
}
