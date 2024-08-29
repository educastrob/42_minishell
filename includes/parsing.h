/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:00 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/08/28 20:20:38 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "lexing.h"

# define TRUE 1
# define FALSE 0

char	*check_syntax(t_token_list *token_list);

typedef struct s_command
{
	char				*name;
	char				**argv;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

#endif