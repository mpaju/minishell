/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:39:02 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 15:09:22 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*get_addr(char *str, t_shell *shell)
{
	char	*key;
	t_env	*envlist;
	t_env	*ret;

	key = NULL;
	ret = NULL;
	envlist = shell->env;
	while (envlist)
	{
		if (ft_strnequ(str, envlist->key, ft_strlen(envlist->key)) && \
			ft_strlen(key) < ft_strlen(envlist->key))
			key = ft_strdup(envlist->key);
		envlist = envlist->next;
	}
	if (key)
		ret = get_env_addr(shell->env, key);
	ft_strdel(&key);
	return (ret);
}

static void		change_buff(char **ret, char **buff)
{
	if (*ret)
	{
		ft_strdel(buff);
		*buff = *ret;
		*ret = NULL;
	}
}

static void		replace_dollars(t_shell *shell)
{
	char	*dollar_key;
	char	*ret;
	t_env	*env;
	int		c;

	ret = NULL;
	c = 0;
	while (shell->buff[c])
	{
		if (shell->buff[c] == '$' && shell->buff[c + 1])
		{
			env = get_addr(&shell->buff[c + 1], shell);
			if (env)
			{
				dollar_key = ft_strjoin("$", env->key);
				ret = ft_strreplace(shell->buff, dollar_key, env->value);
				ft_strdel(&dollar_key);
			}
		}
		change_buff(&ret, &shell->buff);
		c++;
	}
}

static void		remove_tabs_and_replace_tilde(t_shell *shell)
{
	char	*str;

	str = shell->buff;
	while (*str)
	{
		if (*str == '\t')
			*str = ' ';
		str++;
	}
	str = ft_strreplace(shell->buff, "~", get_env_value(shell->env, "HOME"));
	if (str && str != shell->buff)
	{
		ft_strdel(&shell->buff);
		shell->buff = str;
	}
}

void			parse_input(t_shell *shell)
{
	remove_tabs_and_replace_tilde(shell);
	replace_dollars(shell);
	shell->tokens = ft_strsplit(shell->buff, ' ');
}
