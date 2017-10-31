/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:20 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 15:09:55 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **tkns)
{
	char	**tkn;

	tkn = tkns;
	if (!*tkn)
		return ;
	while (*tkn)
	{
		ft_putstr(*tkn);
		tkn++;
		if (*tkn)
			ft_putstr(" ");
	}
}

void		builtin_echo(t_shell *shell, char **tkns)
{
	char	**tkn;
	int		flag;

	tkn = &tkns[1];
	flag = 0;
	if (ft_strequ(*tkn, "-n"))
	{
		flag = 1;
		tkn++;
	}
	print_echo(tkn);
	flag ? (0) : ft_putchar('\n');
	shell->exit = 0;
}
