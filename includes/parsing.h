/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:38:39 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/09/03 16:23:13 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "minishell.h"

typedef struct s_token_list t_token_list;

typedef struct s_tree
{
	int				type;
	t_token_list	*command;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

char	*check_syntax(t_token_list *token_list);

#endif