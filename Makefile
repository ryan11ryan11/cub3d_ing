# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 11:16:19 by junhhong          #+#    #+#              #
#    Updated: 2024/12/19 17:37:55 by junhhong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBDIR = libft
LIBFT = libft/libft.a -L minilibx-linux -lmlx_Linux -lX11 -lXext
NAME = cub3d
AR = ar -rcs

SRC = cub3d ./get_next_line/get_next_line utils tester set_info_1 set_info_2 set_info_3 cubfile_check set_map validity_check_1 validity_check_block

all : $(NAME)

SRCOBJ = $(addsuffix .o, $(SRC))

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(SRCOBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(SRCOBJ) $(LIBFT) -o $(NAME)
	$(MAKE) clean

clean:
	rm -rf $(SRCOBJ)
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf ${NAME}

re: fclean all

lib :
	$(MAKE) -C $(LIBDIR)/

libclean :
	$(MAKE) -C $(LIBDIR)/ clean

libfclean :
	$(MAKE) -C $(LIBDIR)/ fclean