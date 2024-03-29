# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggroener <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 11:16:22 by ggroener          #+#    #+#              #
#    Updated: 2016/12/09 16:35:20 by khansman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

SRCS_NAME =		client_loop.c				\
				connect_to_server.c			\
				main.c						\
				do_connect.c				\
				read_from_socket.c			\
				write_to_socket.c			\

HEADER_NAMES =	client.h					\

ifeq ($(shell uname -s), Darwin) # Changes rules for MAC and Linux
SYS = OSX
else
SYS = LINUX
endif

CFLAGS =	-Wall -Wextra -Werror -O3

ifeq ($(SYS), OSX) 

CFLAGS2 = 	-Wall -Wextra -Werror -O3
else

CFLAGS2 =	-Wall -Wextra -Werror -O3

endif

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

ifeq ($(SYS), OSX)

LIBRARY = -L ../libft/ -lft
 
INCLUDES = -I includes/ -I ../libft/includes

else

LIBRARY = -L ../libft/ -lft

INCLUDES = -I includes/ -I ../libft/includes

endif

HEADER = $(addprefix $(INCLUDES_PATH), $(HEADER_NAMES))

all: qme odir $(NAME)

define colourecho
	@tput setaf 14
	@echo $1
	@tput sgr0
endef

define colourecho2
	@tput setaf 2
	@echo $1
	@tput sgr0
endef

$(NAME): $(OBJS)
	@$(call colourecho, " - Making $(NAME)")
	@clear
	@$(CC) $(CFLAGS2) -o $(NAME) $^ ../shared.a $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@$(call colourecho, "clean done!")

fclean: clean
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

run: $(NAME)
	./$(NAME)

qre:
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@$(call colourecho, "clean done!")
	@make odir
	@make $(NAME)

format: norme me

norme: norm

norm:
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)

fnorm: fnorme

fnorme:
	@$(call colourecho2, "Norminette:")
	@find $(SRCS_PATH) -name "*.c" -maxdepth 1 -type f -exec norminette  {} \;
	@find $(INCLUDES_PATH) -name "*.h" -maxdepth 1 -type f -exec norminette  {} \;

qme:
	@if [ ! -f author ]; then \
		whoami > author; \
	fi
	
me: qme
	cat -e author

submodule:
	git submodule init libft
	git submodule update
	git submodule sync -- libft

.PHONY: clean fclean re odir
