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
	int returnv;
	char **c_env;
	char *t_all_cmd;
	char *c_all_cmd;
	char **c_cmd;
} svar_t;

//VERIFY USER COMMAND
void parse_user_commands(svar_t *svar);
int verify_exit_command(svar_t *svar, char *command);
int verify_env_command(svar_t *svar, char *command);
int verify_cd_command(svar_t *svar, char *command);
int verify_setenv_command(svar_t *svar, char *command);
int verify_unsetenv_command(svar_t *svar, char *command);
int verify_binary_command(svar_t *svar, char *command);
int exec_out_prm(char *c_path, char *buff, svar_t *svar);

//MAKE COMMAND WITH ;
char *semicolon_formating(char *command);
char **make_table_command(char *command);
char *make_clean_cmd(char *buff);

//EXEC OTHER PATH COMMAND
int exec_outside(svar_t *svar, char *command);
int exec_outside_wpath(svar_t *svar, char *command);

//CD HANDLING
int cd_less(svar_t *svar, char *command, char *pathname);
int cd_jalapeno(svar_t *svar, char *command, char *pathname);
int cd_pathname(svar_t *svar, char *command, char *pathname);

//ENV CREATING PWD OLDPWD FOR CD
void switch_env_cd_less(svar_t *svar);
void make_new_pwd(svar_t *svar, char *new_pwd);

//FREE EVERYTHING
void free_svar_while(svar_t *svar);
int free_svar_exit(svar_t *svar);

//PROMPT
void print_custom_prompt(svar_t *svar);

//PARSING USER COMMAND
void get_user_command(svar_t *svar);
int verify_command(char *command, char *verify);
char *get_args(char *buffer);
char *get_args_nbr(char *buffer, int number);
char *get_command_without_args(char *cmd);

//ENV HANDLING
int search_env(char *name, svar_t *svar);
char *get_env(char *line);
int verify_exist_pwd(svar_t *svar);
char **get_path(svar_t *svar);
void print_env(svar_t *svar);

//SIGNALS
void verify_signals(void);
