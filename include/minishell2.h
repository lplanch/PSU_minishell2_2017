/*
** EPITECH PROJECT, 2018
** minishell2.h
** File description:
** library file for minishell2
*/

typedef struct shell_var
{
	char **c_env;
	char *t_cmd;
	char *c_cmd;
	char *n_cmd;
} svar_t;

//FREE EVERYTHING
void free_svar_while(svar_t *svar);
void free_svar_exit(svar_t *svar);

//PROMPT
void print_custom_prompt(svar_t *svar);

//PARSING USER COMMAND
void get_user_command(svar_t *svar);

//ENV HANDLING
int search_env(char *name, svar_t *svar);
void print_env(char **envp);
char *get_env(char *line);

//SIGNALS
void verify_signals(void);
