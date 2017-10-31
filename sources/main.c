/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:38:57 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 14:40:16 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command(t_shell *shell)
{
	if (!shell->tokens || !shell->tokens[0])
		return ;
	else if (!ft_strcmp(shell->tokens[0], "cd"))
		builtin_cd(shell, shell->tokens);
	else if (!ft_strcmp(shell->tokens[0], "setenv"))
		builtin_setenv(shell, shell->tokens);
	else if (!ft_strcmp(shell->tokens[0], "unsetenv"))
		builtin_unsetenv(shell, shell->tokens);
	else if (!ft_strcmp(shell->tokens[0], "env"))
		print_env(shell);
	else if (!ft_strcmp(shell->tokens[0], "echo"))
		builtin_echo(shell, shell->tokens);
	else if (!ft_strcmp(shell->tokens[0], "exit"))
		builtin_exit(shell);
	else
		check_and_exec_if_valid(shell);
}

void		get_input(t_shell *shell)
{
	char	*str;

	if (get_next_line(0, &str) == 0)
		exit(0);
	shell->buff = ft_strdup(str);
	ft_strdel(&str);
}

void		mysh_loop(t_shell *shell)
{
	while (1)
	{
		prompt(shell);
		get_input(shell);
		if (!shell->buff)
			continue ;
		parse_input(shell);
		execute_command(shell);
		ft_strdel(&shell->buff);
		free_split(shell->tokens);
	}
}

int			main(int ac, const char **av, char **env)
{
	t_shell	*shell;

	(void)ac;
	(void)av;
	shell = NULL;
	shell = start_shell(shell, env);
	mysh_loop(shell);
	return (0);
}
