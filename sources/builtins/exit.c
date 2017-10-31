/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:33 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 14:38:34 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		split_len(char **splitstr)
{
	int	count;

	count = 0;
	while (*splitstr)
	{
		count++;
		splitstr++;
	}
	return (count);
}

int		check_numeric(char *str)
{
	if (!*str)
		return (0);
	if (*str == '-')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

void	builtin_exit(t_shell *shell)
{
	int	exitcode;
	int	tokenlen;

	exitcode = 0;
	tokenlen = split_len(shell->tokens);
	if (tokenlen > 2)
		exitcode = 1;
	else if (tokenlen == 2)
	{
		if (check_numeric(shell->tokens[1]))
			exitcode = 255;
		else
			shell->exit = ft_atoi(shell->tokens[1]);
	}
	exitcode ? (shell->exit = exitcode) : (0);
	if (exitcode == 1)
		ft_putendl_fd("too many arguments", 2);
	else if (exitcode == 255)
		ft_putendl_fd("not numeric", 2);
	else
	{
		exitcode = shell->exit % 256;
		exit(exitcode);
	}
}
