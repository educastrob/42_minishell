# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:58:43 by fcaldas-          #+#    #+#              #
#    Updated: 2024/09/25 18:51:48 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3
BIN			:= ./bin/
SRCS		:= $(addprefix ./sources/, main.c) \
				$(addprefix ./sources/tokenizer/, tokenizer.c utils.c get_states.c token_states_1.c token_states_2.c token_tests.c) \
				$(addprefix ./sources/environment/, env_func1.c env_func2.c utils.c) \
				$(addprefix ./sources/parser/, get_tree.c make_tree.c make_tree_cmd.c here_doc.c) \
				$(addprefix ./sources/builtin/, env.c pwd.c) \
				$(addprefix ./sources/expander/, expand_heredoc.c utils.c) 
OBJS		:= $(patsubst ./sources/%.c,$(BIN)%.o,$(SRCS))
LIB			:= ./libft/libft.a
INCLUDES	:= -I ./includes/ -I ./libft


# RULES

all: libft/libft.a $(BIN) $(NAME)

libft/libft.a:
	@make -sC ./libft 

$(BIN)%.o: ./sources/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(HEADERS) -o $(NAME) $(LIB) -lreadline

$(BIN):
	@mkdir -p $(BIN)


clean:
	rm -rf $(BIN)
	@make clean -sC ./libft 

fclean: clean
	rm -rf $(NAME) 
	rm -rf ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re