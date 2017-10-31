/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:56:24 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/27 15:25:12 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <term.h>
# include <curses.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef	struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_tkn
{
	char			*data;
	int				key;
	struct s_tkn	*left;
	struct s_tkn	*right;
}					t_tkn;

typedef struct		s_shell
{
	char			*name;
	char			**environ;
	int				exit;
	struct s_env	*env;
	char			*buff;
	char			**tokens;
}					t_shell;

void				builtin_cd(t_shell *shell, char **args);
void				builtin_echo(t_shell *shell, char **tkns);
void				builtin_exit(t_shell *shell);
void				builtin_setenv(t_shell *shell, char **tkns);
void				builtin_unsetenv(t_shell *shell, char **tkns);
void				set_env(t_shell *shell, char *key, char *val, char ow);
t_env				*get_env_addr(t_env *env, char *key);
void				get_env_list(t_shell **shell, char **env);
char				*get_env_value(t_env *envlist, char *key);
void				insert_into_envlist(t_env **env_list, t_env *new_env);
void				print_env(t_shell *shell);
void				prompt(t_shell *shell);
t_env				*tenv_new(char *key, char *value);
t_shell				*start_shell(t_shell *shell, char **env);
void				check_and_exec_if_valid(t_shell *shell);
void				free_split(char **str);
void				parse_input(t_shell *shell);

#endif
