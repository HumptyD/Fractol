# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 14:33:53 by jlucas-l          #+#    #+#              #
#    Updated: 2019/01/18 18:51:24 by jlucas-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OBJ_D = objs
INC = -I ./libft/includes -I ./includes -I ./minilibx_macos
LIB = -L./libft/ -lft 
MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
OCL = -framework OpenCL

GCCFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
	   hook.c \
	   put_set.c \
	   image.c \
	   init.c \
	   secondary.c \
	   ocl_init.c \
	   enter_data.c \
	   thread.c

OBJS = $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME):
		make -C ./libft
		make -C ./minilibx_macos
		gcc $(GCCFLAGS) -c $(SRCS) $(INC)
		mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)/
		gcc $(GCCFLAGS) -o $(NAME) $(OBJS) $(LIB) $(MLX) $(INC) $(OCL)

clean:
		make clean -C ./libft
		make clean -C ./minilibx_macos
		rm -rf $(OBJ_D)

fclean: clean
		make fclean -C ./libft
		make clean -C ./minilibx_macos
		rm -rf $(NAME)

re: fclean all
