##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

NAME		=	mysh

CC		=	cc

CFLAGS		+=	-g -I include/

LDFLAGS		+=	-L lib/my/ -lmy

FILES		=	src/main_minishell2.c			\
			src/prompt_handling.c			\
			src/command_formating.c			\
			src/free_minishell2.c			\
			src/signals_handling.c			\
			src/cd_handling.c			\
			src/cd_verify_handling.c		\
			src/switch_env_handling.c		\
			src/env_handling.c			\
			src/setenv_handling.c			\
			src/unsetenv_handling.c			\
			src/env_verify.c			\
			src/exit_handling.c			\
			src/binary_handling.c			\
			src/exec_outside.c			\
			src/verify_user_command.c		\
			src/command_handling.c			\
			src/arguments_handling.c		\

SRCS		=	$(FILES)

OBJ		=	$(SRCS:.c=.o) $(MAIN:.c=.o)

all:			$(NAME)


.PHONY: fclean clean all re

RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BG_COLOR	=	\033[46m

$(NAME):	$(OBJ)
	@echo -e '${BG_COLOR}Flags: $(LDFLAGS) $(CFLAGS)${NC}'
	@echo -e '${RED}Create${NC}: ${GREY}./$(NAME)${NC}'
	@make -C lib/my/
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CFLAGS)

%.o:		%.c
	@echo -e '${GREEN} [ OK ]${NC} Building minishell2...$<'
	@$(CC) -o $@ -c $< $(LDFLAGS) $(CFLAGS)


clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_T)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@echo -e '${RED}Clean${NC} : OK'
	@make clean -C lib/my/

fclean:		clean
	@rm -rf $(NAME)
	@echo -e '${RED}Fclean${NC}: ./$(NAME) removed'
	@make fclean -C lib/my/

re:		fclean all
