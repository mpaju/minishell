/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:11 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 14:36:01 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_cd_errors(char *path)
{
	if (access(path, F_OK))
		ft_putendl_fd("cd: no such file or directory", 2);
	else if (!(ft_strequ(ft_get_filetype(path), "DIR") || \
		ft_strequ(ft_get_filetype(path), "LNK")))
		ft_putendl_fd("cd: not a directory", 2);
	else if (access(path, X_OK))
		ft_putendl_fd("cd: permission denied", 2);
	else if (chdir(path))
		ft_putendl_fd("chdir error ", 2);
	else
		return (0);
	return (-1);
}

void	builtin_cd(t_shell *shell, char **args)
{
	char	*tmppath;
	char	*path;

	path = args[1];
	if (!path)
		path = get_env_value(shell->env, "HOME");
	if (ft_strequ(path, "-"))
	{
		path = get_env_value(shell->env, "OLDPWD");
		ft_putendl(path);
	}
	if (check_cd_errors(path))
		return ;
	else
	{
		set_env(shell, "OLDPWD", get_env_value(shell->env, "PWD"), 1);
		tmppath = getcwd(NULL, 0);
		set_env(shell, "PWD", tmppath, 1);
		ft_strdel(&tmppath);
	}
}
