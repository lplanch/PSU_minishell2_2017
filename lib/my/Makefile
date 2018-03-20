##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME		=	libmy.a

CC		=	cc

FILES		=	my_putchar.c		\
			my_put_nbr.c		\
			my_put_nbrror.c		\
			my_put_llnbr.c		\
			my_putstr.c		\
			my_strlen.c		\
			my_nbrlen.c		\
			my_llnbrlen.c		\
			my_calloc.c		\
			my_revstr.c		\
			my_strcmp.c		\
			my_sort_params.c	\
			my_strdup.c		\
			my_tbldup.c		\
			my_strminimalize.c	\
			is_number.c		\
			str_to_int.c		\
			my_abs.c		\
			my_compute_power_rec.c	\
			replace_chr.c		\
			count_lines.c		\
			my_strcat.c		\
			free_tbl.c		\
			count_chr.c		\
			my_lstrlen.c		\
			create_table.c		\
			get_str_untill.c	\
			my_strchr.c		\
			my_putstrror.c		\
			my_tbl_append.c		\
			my_tbl_rm.c		\
			rm_str_untill.c		\
			is_letter.c		\
			my_putcharror.c		\
			get_next_line.c		\
			count_chr_tbl.c		\

SRCS		=	$(FILES)

OBJ		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

CFLAGS		=	-g -I ../../include/

all:			$(NAME)

.PHONY: fclean clean all re

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[45m

$(NAME):	$(OBJ)
	@echo -e '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}'
	@echo -e '${RED}Create${NC}: ${GREY}$(NAME)${NC}'
	@ar rc $(NAME) $(OBJ)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} LibBuild $<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@echo -e '${RED}LibClean${NC} : OK'

fclean:		clean
	@rm -rf $(NAME)
	@echo -e '${RED}LibFclean${NC}: $(NAME) removed'

re:		fclean all
