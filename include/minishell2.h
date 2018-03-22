/*
** EPITECH PROJECT, 2018
** minishell2.h
** File description:
** library file for minishell2
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <stdio.h>

typedef struct shell_var
{
	int done;
	char **c_env;
	char *t_cmd;
	char *c_cmd;
	char *n_cmd;
} svar_t;

//VERIFY USER COMMAND
void verify_user_command(svar_t *svar);
int verify_exit_command(svar_t *svar);
int verify_env_command(svar_t *svar);
int verify_binary_command(svar_t *svar);
int exec_out_prm(char *c_path, char *buff, svar_t *svar);

//EXEC OTHER PATH COMMAND
int exec_outside_without_path(svar_t *svar);
int exec_outside(svar_t *svar);


//FREE EVERYTHING
void free_svar_while(svar_t *svar);
void free_svar_exit(svar_t *svar);

//PROMPT
void print_custom_prompt(svar_t *svar);

//PARSING USER COMMAND
void get_user_command(svar_t *svar);
int verify_command(char *command, char *verify);

//ENV HANDLING
int search_env(char *name, svar_t *svar);
char *get_env(char *line);

//SIGNALS
void verify_signals(void);
