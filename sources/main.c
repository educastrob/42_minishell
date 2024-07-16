/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:02:33 by educastro         #+#    #+#             */
/*   Updated: 2024/07/16 18:34:38 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lexing.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	
	while (1)
	{
		line = readline("minishell$ ");
		parser(line);
		printf("line: %s\n", line);
	}
}