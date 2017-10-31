/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 05:35:48 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/25 15:09:50 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*ret;
	char	*str;

	if (!s1 || !s2 || !s3)
		return (0);
	str = ft_strjoin(s2, s3);
	ret = ft_strjoin(s1, str);
	ft_strdel(&str);
	return (ret);
}
