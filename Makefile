# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 13:35:31 by wgorold           #+#    #+#              #
#    Updated: 2019/05/08 16:39:00 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" \
# 	| while read x ; do echo "$x.o:\n\t\$(CC) \$(CFLAGS) $x.c" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" \
# 	| tr '\n' ' '
#

NAME=fillit

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

SRC=	fillit_1_init.o fillit_2_read_fig.o fillit_3_valid.o fillit_4_mat.o \
			fillit_5_fig_mat_helper.o fillit_6_fig_mat.o fillit_7_rec_fig.o \
			fillit_8_rec_pos_helper.o fillit_9_rec_pos.o main.o

all: $(NAME) libft_all

$(NAME): libft_all $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -L./libft -lft

libft_all:
	make -C./libft

libft_clean:
	@make -C./libft clean

libft_fclean:
	make -C./libft fclean

main.o:
	$(CC) $(CFLAGS) main.c
fillit_1_init.o:
	$(CC) $(CFLAGS) fillit_1_init.c
fillit_2_read_fig.o:
	$(CC) $(CFLAGS) fillit_2_read_fig.c
fillit_3_valid.o:
	$(CC) $(CFLAGS) fillit_3_valid.c
fillit_4_mat.o:
	$(CC) $(CFLAGS) fillit_4_mat.c
fillit_5_fig_mat_helper.o:
	$(CC) $(CFLAGS) fillit_5_fig_mat_helper.c
fillit_6_fig_mat.o:
	$(CC) $(CFLAGS) fillit_6_fig_mat.c
fillit_7_rec_fig.o:
	$(CC) $(CFLAGS) fillit_7_rec_fig.c
fillit_8_rec_pos_helper.o:
	$(CC) $(CFLAGS) fillit_8_rec_pos_helper.c
fillit_9_rec_pos.o:
	$(CC) $(CFLAGS) fillit_9_rec_pos.c

clean: libft_clean
	rm -f $(SRC)

fclean: clean libft_fclean
	rm -f $(NAME);

re: fclean all
