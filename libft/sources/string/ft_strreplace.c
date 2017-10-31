/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:56:48 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 18:58:08 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *strin, char *strout)
{
	int		len;
	char	*ret;
	char	*fstrin;

	if (!strin || !strout)
		return (str);
	ret = str;
	len = ft_strlen(strin);
	if ((fstrin = ft_strstr(str, strin)))
	{
		*fstrin = '\0';
		fstrin = &fstrin[len];
	}
	else
		return (NULL);
	ret = ft_str3join(str, strout, fstrin);
	return (ret);
}
