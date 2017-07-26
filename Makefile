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

NAME = shared.a

SRCS_NAME =		error_quit.c			\
				ft_str_append.c			\
				ft_swap_str.c			\
				sock_gnl.c				\
				valid_command.c			\
				write_msg_to_sock.c		\

HEADER_NAMES =	shared.h				\

ifeq ($(shell uname -s), Darwin) # Changes rules for MAC and Linux
SYS = OSX
else
SYS = LINUX
endif

CFLAGS =	-Wall -Wextra -Werror -fPIC -O3

ifeq ($(SYS), OSX) 

CFLAGS2 = 	-Wall -Wextra -Werror -O3
else

CFLAGS2 =	-Wall -Wextra -Werror

endif

CC = gcc

INCLUDES_PATH = includes/

SRCS_PATH = shared_files/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

ifeq ($(SYS), OSX)

LIBRARY = -L libft/ -lft
 
INCLUDES = -I $(INCLUDES_PATH) -I libft/includes

else

LIBRARY = -L libft/ -lft

INCLUDES = -I $(INCLUDES_PATH) -I libft/includes

endif

HEADER = $(addprefix $(INCLUDES_PATH), $(HEADER_NAMES))

all:
	@make odir
	@make $(NAME)

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
	@make qme
	@$(call colourecho, " - Making $(NAME)")
	@make -C libft
	# @$(CC) $(CFLAGS2) -o $(NAME) $^ $(LIBRARY) $(INCLUDES) -I$(INCLUDES_PATH)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@make server
	@make client
	@clear
	@$(call colourecho, "Make Done!")

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(call colourecho, " - Compiling $<")
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)
	@$(call colourecho, "Compiling Done!")

odir:
	@mkdir -p $(OBJS_PATH)

server: del_server
	@make -C server_files
	@mv server_files/server .

client: del_client
	@make -C client_files
	@mv client_files/client .

quick:
	@make server
	@make client

del_server:
	@if [ -f server ]; then \
		rm server;	\
	fi

del_client:
	@if [ -f client ]; then \
		rm client;	\
	fi

clean:
	@$(call colourecho, " - Clearing object files")
	@rm -f $(OBJS)
	@make clean -C libft
	@make clean -C client_files
	@make clean -C server_files
	@$(call colourecho, "clean done!")

fclean: clean del_server del_client
	@$(call colourecho, "Clearing executable files")
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C client_files
	@make fclean -C server_files
	@$(call colourecho, "fclean done")

re: fclean all
	@$(call colourecho, "re Done!")

format: norme me

norme: norm

norm:
	@$(call colourecho2, "Norminette:")
	@norminette $(SRCS)
	@norminette $(HEADER)
	@make norme -C client_files
	@make norme -C server_files

fnorm: fnorme

fnorme:
	@$(call colourecho2, "Norminette:")
	@find $(SRCS_PATH) -name "*.c" -maxdepth 1 -type f -exec norminette  {} \;
	@find $(INCLUDES_PATH) -name "*.h" -maxdepth 1 -type f -exec norminette  {} \;
	@make fnorme -C client_files
	@make fnorme -C server_files

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
