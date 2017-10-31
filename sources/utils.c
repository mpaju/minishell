/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:39:06 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 17:08:04 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	increase_shlvl(t_env **envlist)
{
	t_env	*env;
	int		lvl;

	env = get_env_addr(*envlist, "SHLVL");
	if (env)
	{
		lvl = ft_atoi(env->value);
		lvl++;
		ft_strdel(&env->value);
		env->value = ft_itoa(lvl);
	}
	else
	{
		env = tenv_new("SHLVL", "1");
		insert_into_envlist(envlist, env);
	}
}

t_shell		*start_shell(t_shell *shell, char **env)
{
	if (!(shell = (t_shell *)ft_memalloc(sizeof(shell))))
		return (NULL);
	shell->environ = env;
	get_env_list(&shell, env);
	increase_shlvl(&shell->env);
	return (shell);
}

void		free_split(char **str)
{
	char	**tmp;
	char	**tmp2;

	tmp2 = str;
	while (*tmp2)
	{
		tmp = tmp2 + 1;
		ft_strdel(tmp2);
		tmp2 = tmp;
	}
	free(str);
}

void		print_env(t_shell *shell)
{
	t_env	*env;

	env = shell->env;
	while (env)
	{
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putendl(env->value);
		env = env->next;
	}
}

void		prompt(t_shell *shell)
{
	char	*freeable;

	ft_putstr("\e[0m\e[38;40m ");
	ft_putstr(get_env_value(shell->env, "USER"));
	ft_putstr(" \e[30;47m\ue0b0 ");
	ft_putstr((freeable = getcwd(NULL, 0)));
	ft_putstr(" \e[0m\e[37m\ue0b0\e[0m ");
	ft_strdel(&freeable);
}
