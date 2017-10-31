/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:38:52 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 15:00:06 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	envlen(t_env *envlist)
{
	int	ret;

	ret = 0;
	while (envlist)
	{
		ret++;
		envlist = envlist->next;
	}
	return (ret);
}

static char	**get_environ(t_env *envlist)
{
	int		len;
	char	**ret;
	char	**tmp;

	len = envlen(envlist);
	ret = (char **)ft_memalloc(sizeof(char *) * (len + 1));
	tmp = ret;
	while (len--)
	{
		*tmp = ft_str3join(envlist->key, "=", envlist->value);
		tmp++;
		envlist = envlist->next;
	}
	return (ret);
}

void		mysh_launch(t_shell *shell, char *exec)
{
	pid_t	pid;
	pid_t	wpid;
	char	**env;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		env = get_environ(shell->env);
		if (execve(exec, shell->tokens, env) == -1)
			ft_putendl_fd("SHELL : execve : Unable to execute", 2);
		free_split(env);
		exit(0);
	}
	else
	{
		wpid = waitpid(pid, &status, 0);
		shell->exit = WEXITSTATUS(status);
	}
}

char		*check_exec(t_shell *shell)
{
	char	**tmp;
	char	*fullexec;
	char	**path;

	if (!access(shell->tokens[0], F_OK))
		return (ft_strdup(shell->tokens[0]));
	else
	{
		if (!(path = ft_strsplit(get_env_value(shell->env, "PATH"), ':')))
			return (NULL);
		tmp = path;
		while (*path)
		{
			fullexec = ft_str3join(*path, "/", shell->tokens[0]);
			if (!access(fullexec, F_OK))
			{
				free_split(tmp);
				return (fullexec);
			}
			ft_strdel(&fullexec);
			path++;
		}
		free_split(tmp);
	}
	return (NULL);
}

void		check_and_exec_if_valid(t_shell *shell)
{
	char	*executable;

	executable = check_exec(shell);
	if (executable)
		mysh_launch(shell, executable);
	else
	{
		ft_putstr_fd("SHELL: command not found: ", 2);
		ft_putendl_fd(shell->tokens[0], 2);
		shell->exit = 127;
	}
	ft_strdel(&executable);
}
