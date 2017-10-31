/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:38 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 15:10:17 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_setenv(t_shell *shell, char **tkns)
{
	char	*key;
	char	*val;

	key = tkns[1];
	val = tkns[2];
	set_env(shell, key, val, 1);
}

void	set_env(t_shell *shell, char *key, char *val, char ow)
{
	t_env	*env;

	env = shell->env;
	if (!key || !val)
		return ;
	if (get_env_value(env, key))
	{
		if (ow)
		{
			env = get_env_addr(shell->env, key);
			if (env)
				ft_strdel(&env->value);
			env->value = ft_strdup(val);
		}
	}
	else
	{
		env = tenv_new(key, val);
		insert_into_envlist(&shell->env, env);
	}
}
