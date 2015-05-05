# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/09 14:23:06 by eboeuf            #+#    #+#              #
#    Updated: 2015/04/24 10:41:07 by eboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S		=	server

NAME_C		=	client

SRC 		=	srcs/

SRC_S       =   $(SRC)server/server.c \
				$(SRC)server/ft_get.c \
				$(SRC)server/ft_receive_client.c \
				$(SRC)server/error_server.c \
				$(SRC)server/ft_cd.c \
				$(SRC)server/ft_ls.c \
				$(SRC)server/ft_pwd.c

SRC_C       =   $(SRC)client/client.c \
				$(SRC)client/ft_put.c \
				$(SRC)client/ft_receive_serv.c \
				$(SRC)client/error_client.c

OBJ_S 		=	$(SRC_S:.c=.o)

OBJ_C		=	$(SRC_C:.c=.o)

LIBDIR		=	libft/

LIB			=	$(LIBDIR)libft.a

LIB_COMP	=	-L ./$(LIBDIR) -lft

CC 			= clang

RM 			= rm -f

FLAGS 		= -Wall -Wextra -Werror

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME_S) $(NAME_C)

$(LIB):
			@$(MAKE) -C $(LIBDIR)

$(NAME_S): $(LIB) $(OBJ_S)
			@$(CC) -o $(NAME_S) $(FLAGS) $^ $(LIB_COMP)
			@$(RM) $(DEP).gch
			@echo "[$(GREEN)Compilation $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"

$(NAME_C): $(LIB) $(OBJ_C)
			@$(CC) -o $(NAME_C) $(FLAGS) $^ $(LIB_COMP)
			@$(RM) $(DEP).gch
			@echo "[$(GREEN)Compilation $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

%.o: %.c
			@$(CC) -c -o $@ $(FLAGS) $^

clean:
		@cd $(LIBDIR) && $(MAKE) $@
		@$(RM) $(OBJ_S)
		@$(RM) $(OBJ_C)
		@echo "[$(RED)Suppression des .o de $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"
		@echo "[$(RED)Suppression des .o de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

fclean: clean
			@cd $(LIBDIR) && $(MAKE) $@
			@$(RM) $(NAME_S)
			@$(RM) $(NAME_C)
			@echo "[$(RED)Suppression de $(BLUE)$(NAME_S) $(GREEN)ok$(RESET)]"
			@echo "[$(RED)Suppression de $(BLUE)$(NAME_C) $(GREEN)ok$(RESET)]"

re: fclean all

