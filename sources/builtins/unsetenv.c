/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:43 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 14:35:43 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env(t_env *env)
{
	if (!env)
		return ;
	ft_strdel(&env->key);
	ft_strdel(&env->value);
	env->next = NULL;
	free(env);
	env = NULL;
}

t_env		**get_envlink_addr(t_shell *shell, char *key)
{
	t_env **link;

	link = &shell->env;
	if (!link)
		return (NULL);
	if (!ft_strcmp((*link)->key, key))
		return (link);
	(*link)->next ? link = &((*link)->next) : NULL;
	while (*link)
	{
		if (!ft_strcmp((*link)->key, key))
			return (link);
		link = &(*link)->next;
	}
	return (NULL);
}

void		builtin_unsetenv(t_shell *shell, char **tkns)
{
	char	**envs;
	t_env	**env;
	t_env	*tmp;

	envs = &tkns[1];
	while (*envs)
	{
		if ((env = get_envlink_addr(shell, *envs)))
		{
			tmp = *env;
			*env = (*env)->next;
			free_env(tmp);
		}
		envs++;
	}
	shell->exit = 0;
}
