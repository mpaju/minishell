/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:39:39 by mpaju             #+#    #+#             */
/*   Updated: 2017/09/03 14:39:41 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp_list;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	tmp_list = tmp;
	while (1)
	{
		if (!(tmp->next = f(lst->next)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
		if (lst->next == NULL)
			return (tmp_list);
	}
	return (NULL);
}
