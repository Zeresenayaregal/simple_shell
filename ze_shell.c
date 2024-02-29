#include "shell.h"

/**
 * main - the main function
 * Return: (1) 0 always
 */
int main(void)
{
	sh_t dt;
	int pl;

	ze_mmst((void *)&dt, 0, sizeof(dt));
	signal(SIGINT, sig_hand);
	while (1)
	{
		idx_c(&dt);
		if (re_ne(&dt) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (sp_ne(&dt) < 0)
		{
			ze_free(&dt);
			continue;
		}
		pl = pa_ne(&dt);
		if (pl == 0)
		{
			ze_free(&dt);
			continue;
		}
		if (pl < 0)
		{
			perr(&dt);
			continue;
		}
		if (p_md(&dt) < 0)
		{
			perr(&dt);
			break;
		}
		ze_free(&dt);
	}
	ze_free(&dt);
	exit(EXIT_SUCCESS);
}

/**
 * re_ne - read a line from the standard input
 * @dt: a pointer to the struct of dt
 * Return: (1) a positive number
 */
int re_ne(sh_t *dt)
{
	char *csr_ptr, *end_ptr, cze;
	size_t size = 256, readze_, length, nsz;

	dt->line = malloc(size * sizeof(char));
	if (dt->line == NULL)
		return (FAIL);
	if (isatty(STDIN_FILENO))
		PRINT("$ ");
	for (csr_ptr = dt->line, end_ptr = dt->line + size;;)
	{
		readze_ = read(STDIN_FILENO, &cze, 1);
		if (readze_ == 0)
			return (FAIL);
		*csr_ptr++ = cze;
		if (cze == '\n')
		{
			*csr_ptr = '\0';
			return (1);
		}
		if (csr_ptr + 2 >= end_ptr)
		{
			nsz = size * 2;
			length = csr_ptr - dt->line;
			dt->line = ze_ralloc(dt->line, size * sizeof(char),
						nsz * sizeof(char));
			if (dt->line == NULL)
				return (FAIL);
			size = nsz;
			end_ptr = dt->line + size;
			csr_ptr = dt->line + length;
		}
	}
}
#define DELIMITER " \n\t\r\a\v"
/**
 * sp_ne - splits line to tokens
 * @dt: a pointer to the struct of dt
 *
 * Return: (1) a positive number
 */
int sp_ne(sh_t *dt)
{
	char *token;
	size_t size = 64, nsz, i = 0;

	if (ze_comp(dt->line, "\n") == 0)
		return (FAIL);
	dt->ags = malloc(size * sizeof(char *));
	if (dt->ags == NULL)
		return (FAIL);
	token = strtok(dt->line, DELIMITER);
	if (token == NULL)
		return (FAIL);
	while (token)
	{
		dt->ags[i++] =  token;
		if (i + 2 >= size)
		{
			nsz = size * 2;
			dt->ags = ze_ralloc(dt->ags, size * sizeof(char *),
					nsz * sizeof(char *));
			if (dt->ags == NULL)
				return (FAIL);
			size = nsz;
		}
		token = strtok(NULL, DELIMITER);
	}
	dt->ags[i] = NULL;
	return (0);
}
#undef DELIMITER
#define DELIMITER ":"
/**
 * pa_ne - parses arguments to valid command
 * @dt: a pointer to the struct of dt
 *
 * Return: (1) a positive number
 */
int pa_ne(sh_t *dt)
{
	if (pazFm_c(dt) > 0)
		return (1);
	if (isbtin(dt) > 0)
	{
		if (hd_btin(dt) < 0)
			return (FAIL);
		return (0);
	}
	isfm(dt);
	return (1);
}
#undef DELIMITER
/**
 * p_md - process command and execute process
 * @dt: a pointer to the struct of dt
 *
 * Return: (1) a positive number
 */
int p_md(sh_t *dt)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(dt->com, dt->ags, environ) < 0)
		dt->errmg = ze_rep("not found\n");
			return (FAIL);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (0);
}
