#include "shell.h"
/**
 * get_command - pos get commands.
 * @s: string.
 * @arg_vec: pointer string.
 * @env: environment variables.
 * @ct: execution cter.
 * @fl: file
 * @out: out
 * Return: out
 */
int get_command(char *s, char **arg_vec, char *fl, char **env, int ct, int out)
{
	int (*validar)(char *, char **, char *, char **, int, int);

	validar = b_tns(arg_vec[0]);
	if (validar)
		out = validar(s, arg_vec, fl, env, ct, out);
	else
		out = search_command(arg_vec, fl, env, ct);
	return (out);
}
/**
 * arguments - separate the user's string into arguments.
 * @s: pointer string.
 * @environ: environment variables.
 * @ct: execution cter.
 * @file: file
 * @out: out
 * Return: out
 */
int arguments(char *s, char *file, char **environ, int ct, int out)
{
	char **argv = NULL, *token = NULL;
	int index = 0;

	argv = malloc(64 * sizeof(char *));
	if (!argv)

	{
		perror("Error on allocation");
		exit(0);
	}
	token = strtok(s, SEP_ESPAC);
	while (token)
	{
		argv[index] = token;
		index++;
		token = strtok(NULL, SEP_ESPAC);
	}
	argv[index] = NULL;
	out = get_command(s, argv, file, environ, ct, out);
	free(argv);
	return (out);
}
