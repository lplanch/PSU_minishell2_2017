/*
** EPITECH PROJECT, 2018
** other_cd_handling.c
** File description:
** other file to stock all other functions of cd
*/

#include "my.h"
#include "minishell2.h"

int cd_pathname(svar_t *svar, char *command, char *pathname)
{
	struct stat fstat;
	char cwd[1024];

	if (stat(pathname, &fstat) < 0) {
		my_putstrror(pathname);
		my_putstrror(": No such file or directory.\n");
		svar->returnv = 1;
	        return (0);
	}
	if (!S_ISDIR(fstat.st_mode)) {
		my_putstrror(pathname);
		my_putstrror(": Not a directory.\n");
		svar->returnv = 1;
		return (0);
	}
	chdir(pathname);
	if ((getcwd(cwd, sizeof(cwd))) == NULL)
		return (0);
	make_new_pwd(svar, cwd);
	return (1);
}

int cd_less(svar_t *svar, char *command, char *pathname)
{
	int OLDPWD = search_env("OLDPWD", svar);

	if (my_strcmp(pathname, "-") != 0)
		return (0);
	if (OLDPWD == -1) {
		my_putstrror(": No such file or directory.\n");
		svar->returnv = 1;
	} else {
		switch_env_cd_less(svar);
	}
	return (1);
}

int cd_jalapeno(svar_t *svar, char *command, char *pathname)
{
	int HOME;
	int USER;
	char *temp_home;

	if (pathname != NULL && my_strcmp(pathname, "~") != 0)
		return (0);
	if ((HOME = search_env("HOME", svar)) != -1) {
		make_new_pwd(svar, get_env(svar->c_env[HOME]));
	} else if ((USER = search_env("USER", svar)) != -1) {
		temp_home = my_strcat("/home/", get_env(svar->c_env[USER]));
		make_new_pwd(svar, temp_home);
		free(temp_home);
	} else {
		my_putstrror("User directory not found (no home and user).\n");
		svar->returnv = 1;
	}
	return (1);
}
