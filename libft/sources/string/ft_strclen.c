/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:58:28 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 18:58:31 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(char *str, char c)
{
	size_t	len;

	len = 0;
	if (!*str || !str)
		return (len);
	while (str[len] != c && str[len])
		len++;
	return (len);
}
