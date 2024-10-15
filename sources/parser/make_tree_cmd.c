/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:43:44 by edcastro          #+#    #+#             */
/*   Updated: 2024/10/10 18:18:36 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static void	tree_inside_parentesis(t_aux_tree *aux_tree)
{
	aux_tree->parenthesis_idx = index_to_close_parenthesis(aux_tree->aux->next);
	if (aux_tree->parenthesis_idx != -1)
	{
		aux_tree->aux2 = token_get_sublist(aux_tree->aux, 0, \
			aux_tree->parenthesis_idx + 1);
		token_join_lists(&aux_tree->args, aux_tree->aux2);
		token_clear_list(&aux_tree->aux2);
		aux_tree->aux = token_get_node_index(aux_tree->aux, \
			aux_tree->parenthesis_idx);
	}
	else
		aux_tree->aux = NULL;
}

// add redirects em redir_list
static void	put_redirect_on_list(t_aux_tree *aux_tree)
{
	add_token_to_list(&aux_tree->redir_list, NULL, aux_tree->aux->token.type);
	if (aux_tree->aux->next)
	{
		add_token_to_list(&aux_tree->redir_list, 
			ft_strdup(aux_tree->aux->next->token.lexeme), 
			aux_tree->aux->next->token.type);

		aux_tree->aux = aux_tree->aux->next;
	}
}

static void	init_values(t_aux_tree *aux_tree, t_token_list *token_list)
{
	ft_bzero(aux_tree, sizeof(t_aux_tree));
	aux_tree->aux = token_list;
}

// cria a árvore de execução de comandos
t_tree	*make_tree_cmd(t_token_list *token_list, t_minishell *data)
{
	t_aux_tree	aux_tree;

	init_values(&aux_tree, token_list);
	while (aux_tree.aux)
	{
		if (aux_tree.aux->token.type == OPEN_PARENTHESIS)
			tree_inside_parentesis(&aux_tree);
		else if (aux_tree.aux->token.type >= REDIRECT_INPUT
			&& aux_tree.aux->token.type <= REDIRECT_OUTPUT_APPEND)
			put_redirect_on_list(&aux_tree);
		else if (aux_tree.aux->token.type != CLOSE_PARENTHESIS)
			add_token_to_list(&aux_tree.args, \
				ft_strdup(aux_tree.aux->token.lexeme), \
				aux_tree.aux->token.type);
		if (aux_tree.aux)
			aux_tree.aux = aux_tree.aux->next;
	}
	if (aux_tree.parenthesis_idx != -1)
		aux_tree.tree = make_tree_cmd_recursive(aux_tree.redir_list, \
							aux_tree.args, data);
	token_clear_list(&aux_tree.args);
	token_clear_list(&aux_tree.redir_list);
	return (aux_tree.tree);
}
