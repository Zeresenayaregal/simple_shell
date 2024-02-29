#include "shell.h"
/**
 * ex - close the shell process.
 * @s: string.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @ct: execution cter.
 * @file: file
 * @out: out
 * Return: out
 */
int ex(char *s, char **argv, char *file, char **environ, int ct, int out)
{
	(void)environ;

	if (argv[1])
	{
		printerrorex(file, argv, ct, "Illegal number");
		return (127);
	}
	free(argv);
	free(s);
	exit(out);
}
/**
 * envir - print environment variables.
 * @s: string.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @ct: execution cter.
 * @file: file
 * @out: out
 * Return: 0
 */
int envir(char *s, char **argv, char *file, char **environ, int ct, int out)
{
	int i = 0;
	(void)s;

	if (argv[1] != NULL)
	{
		printerror(file, argv[0], ct, "No such file or directory");
		return (127);
	}
	while (environ[i])
	{
		_putchar(environ[i]);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (out);
}
