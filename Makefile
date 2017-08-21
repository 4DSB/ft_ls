# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amittal <amittal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/20 17:15:55 by amittal           #+#    #+#              #
#    Updated: 2017/08/20 17:34:58 by amittal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   ft_ls
LIB             =   ./libft/libft.a
_SRC            =   ft_ls.c \
					ft_ls_options.c \
					ft_ls_errors.c \
					ft_ls_free.c \
					getters/ft_ls_getters_size.c \
					getters/ft_ls_getters_types.c \
					show/ft_ls_show_date.c \
					show/ft_ls_show_dir.c \
					show/ft_ls_show_file.c \
					show/ft_ls_show_int.c \
					show/ft_ls_show_rights.c \
					show/ft_ls_show_size.c \
					show/ft_ls_show_str.c \
					ft_ls_read.c \
					ft_ls_sort.c \
					ft_ls_sized.Created

INCLUDES        =   -I./libft/includes/ -I./includes/
SRC             =   $(addprefix srcs/,$(_SRC))
OBJ             =   $(SRC:.c=.0)
CFLAGS          =   -Wall -Wextra -Werror -g -ggdb

all:  $(NAME)

$(NAME):  $(OBJ)
	make -C ./libft/
	@gcc $(CFLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo $(NAME)" COMPILED"


%.o:  %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

.PHONY: clean fclean Created

clean:	clean
	@make fclean -C libft
	@/bin/rm -rf $(NAME)
	@echo "Wiped *.o and *.a"

re: fclean all