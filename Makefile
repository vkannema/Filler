# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/25 20:28:29 by vkannema          #+#    #+#              #
#    Updated: 2017/03/06 19:34:53 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_vkannema

C_DIR = src
O_DIR = objects
INCLUDES = -I ../includes -I ../Libft/includes
LIB = -L../Libft/ -lftprintf
C_FILES = $(shell find $(C_DIR) -type f | grep "\.c")

O_FILES = $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(O_FILES)
	make -C ../Libft
	@gcc $(FLAGS) $(LIB) $(O_FILES) -o $(NAME)
	@printf "\033[0;31m FINISHED !\033[0;0m\n"

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $< \
	 && printf "\033[0;0m%-34s\033[1;30m -->>\t\033[0;32m$@\033[0;0m\n" "$<"
clean :
	@rm -rf $(O_DIR)
	@make clean -C ../Libft
	@echo "Objects cleaned"

fclean : clean
	@make fclean -C ../Libft
	@rm -f $(NAME)
	@echo "Deleted exec"

re : fclean all
