##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	my_compute_power_rec.c	\
		my_showmem.c	\
		my_str_isupper.c	\
		my_compute_square_root.c	\
		my_showstr.c	\
		my_strlen.c	\
		my_find_prime_sup.c	\
		my_sort_int_array.c	\
		my_strlowcase.c	\
		my_getnbr.c	\
		my_strcapitalize.c	\
		my_strncat.c	\
		my_strcat.c	\
		my_strncmp.c	\
		my_isneg.c	\
		my_strcmp.c	\
		my_strncpy.c	\
		my_is_prime.c	\
		my_strcpy.c	\
		my_strstr.c	\
		my_putchar.c	\
		my_str_isalpha.c	\
		my_strupcase.c	\
		my_put_nbr.c	\
		my_str_islower.c	\
		my_swap.c	\
		my_putstr.c	\
		my_str_isnum.c	\
		my_revstr.c	\
		my_str_isprintable.c	\
		my_show_word_array.c	\
		my_strdup.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_delim.c	\
		str_swap.c	\
		my_memset.c	\
		my_itoa.c	\
		longest.c	\
		my_put_error.c	\
		fs_open_file.c	\
		load_file_in_mem.c	\
		my_printf/after_backslash.c	\
		my_printf/d_to_normal_base.c	\
		my_printf/my_put_nbr_base.c	\
		my_printf/wrapper_1.c	\
		my_printf/wrapper_2.c	\
		my_printf/my_printf.c	\
		my_tab_length.c	\
		free_double_tab.c	\
		copy_tab.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
