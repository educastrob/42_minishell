/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:37:12 by educastro         #+#    #+#             */
/*   Updated: 2024/10/09 17:53:26 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

// libs
# include "minishell.h"
# include "parsing.h"
# include "tokenizer.h"
# include "expander.h"
# include "executor.h"
# include "../libft/libft.h"

typedef struct s_minishell t_minishell;
typedef struct s_env t_env;

// structs
typedef struct	s_env
{
	char		*name;
	char		*value;
}				t_env;

// env_func1.c
t_env	*add_env(t_list *envs, char *name, char *value);
t_list	*create_envs(char **envp);
t_env	*update_env(t_list *envs, char *name, char *value);
t_env	*export_env(t_minishell *minishell, char *name, char *value);

// env_func2.c
t_env	*find_env(t_list *envs, char *name);
char	*find_env_value(t_list *envs, char *name);
t_list	*find_env_element(t_list *envs, char *name);
void	uptade_pwd_env(t_list *envs);
enum e_bool	delete_env(t_minishell *minishell, char *name);

// utils.c
void	del_env(void *content);

#endif
