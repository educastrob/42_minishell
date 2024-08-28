/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 05:11:02 by educastro         #+#    #+#             */
/*   Updated: 2024/08/28 15:22:28 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

// adiciona um novo env
t_env	*add_env(t_list *envs, char *name, char *value)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (env == NULL)
		return (env);
	env->name = ft_strdup(name);
	if (value == NULL)
		env->value = NULL;
	else
		env->value = ft_strdup(value);
	ft_lstadd_back(&envs, ft_lstnew(env));
	return (env);
}

// cria um node contendo name e value separados por '=' (complementa create_envs())
static t_env	*new_env(char *envp)
{
	t_env	*env;
	char	*first_equal;
	
	env = ft_calloc(1, sizeof(t_env));
	first_equal = ft_strchr(envp, '=');
	*first_equal = '\0';
	env->name = ft_strdup(envp);
	env->value = ft_strdup(first_equal + 1);
	return (env);
}

// itera sobre todos o envp e aloca um por um.
t_list	*create_envs(char **envp)
{
	t_list	*envs;
	
	envs = NULL;
	while (*envp != NULL)
	{
		ft_lstadd_back(&envs, ft_lstnew(new_env(*envp)));
		envp++;
	}
	return (envs);
}
