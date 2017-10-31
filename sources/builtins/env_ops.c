/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:35:25 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 14:38:00 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*tenv_new(char *key, char *value)
{
	t_env	*new_env;

	if (!key || !value)
		return (NULL);
	if (!(new_env = (t_env *)ft_memalloc(sizeof(new_env))))
		return (NULL);
	new_env->key = ft_strdup(key);
	new_env->value = ft_strdup(value);
	return (new_env);
}

void	insert_into_envlist(t_env **env_list, t_env *new_env)
{
	t_env	*current;

	if (!new_env)
		return ;
	if (!(*env_list))
	{
		*env_list = new_env;
		return ;
	}
	current = *env_list;
	while (current->next)
		current = current->next;
	current->next = new_env;
}

t_env	*get_env_addr(t_env *env, char *key)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	get_env_list(t_shell **shell, char **env)
{
	t_env	*new_env;
	char	**curr;
	char	**tmp;

	curr = env;
	while (*curr)
	{
		tmp = ft_strsplit(*curr, '=');
		new_env = tenv_new(tmp[0], tmp[1]);
		free_split(tmp);
		insert_into_envlist(&(*shell)->env, new_env);
		curr++;
	}
}

char	*get_env_value(t_env *envlist, char *key)
{
	while (envlist)
	{
		if (!ft_strcmp(envlist->key, key))
			return (envlist->value);
		envlist = envlist->next;
	}
	return (NULL);
}
