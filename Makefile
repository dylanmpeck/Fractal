# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 18:25:31 by dpeck             #+#    #+#              #
#    Updated: 2018/12/18 15:35:11 by dpeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src/
INC_PATH = includes/
OBJ_PATH = obj/

SRC = main.c \
	  color.c \
	  draw.c \
	  fract_functs.c \
	  image.c \
	  key_hooks.c \
	  mouse.c \
	  setup_fractal.c \
	  utils.c

HEADER = includes/fractol.h
LIBFT = includes/libft/
MINILIBX = minilibx_macos -lmlx -framework OpenGl -framework Appkit
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LFT = $(addprefix -I, includes/libft/)
INC_MLX = $(addprefix -I, minilibx_macos)

OBJ_NAME = $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/libft/
	make -C minilibx_macos
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L includes/libft/ -lft -L minilibx_macos -lmlx -framework OpenGl -framework Appkit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc -Wall -Wextra -Werror $(INC) $(INC_LFT) $(INC_MLX) -o $@ -c $<

test: $(OBJ)
	gcc -o $(NAME) $(OBJ) -L includes/libft/ -lft $(MINILIBX)

clean:
	make -C includes/libft/ clean
	make -C minilibx_macos clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make -C includes/libft/ fclean
	make -C minilibx_macos clean
	/bin/rm -f $(NAME)

re: fclean all
