/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:21:57 by mpaju             #+#    #+#             */
/*   Updated: 2016/11/16 19:14:24 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!str1)
		return ((int)*str2);
	else if (!str2)
		return ((int)*str1);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == *s2 && (*(s1 + 1) != '\0' || *(s2 + 1) != '\0'))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
