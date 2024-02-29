#include "project.h"
/**
 * op_proc - child process and executes
 * @arg_vector: Ptr to an array of strings
 * @eCou: exes in each pos
 * @e_v: Env'tal vars.
 * Return: void
 **/
int op_proc(char *arg_vector[], int eCou, char **e_v)
{
	char *path, *f_f = NULL, erms[100];
	int cond, fdd, ltt, ext = 0;
	pid_t c_pid;
	struct stat stul;

	if (stat(arg_vector[1], &stul) == 0)
		fdd = 1, f_f = arg_vector[1];
	else
	{
		path = gev("PATH", e_v), f_f = ppf(path, arg_vector[1]);
		if (f_f != NULL)
			fdd = 1, ltt = 1;
		free(path);
	}
	if (fdd)
	{
		c_pid = fork();
		if (c_pid == 0)
		{
			if ((execve(f_f, (arg_vector + 1), e_v)) == -1)
			{
				sprintf(erms, "%s: %d: %s: not fdd\n", arg_vector[0], eCou, arg_vector[1]);
				write(2, erms, op_slen(erms));
				if (ltt == 1)
					free(f_f);
			}
		}
		  waitpid(c_pid, &cond, 0), (ltt == 1) ? free(f_f) : (void) ltt;
		if (WIFEXITED(cond))
		{
			ext = WEXITSTATUS(cond);
			return (ext);
		}
	} else
	{
		sprintf(erms, "%s: %d: %s: not fdd\n", arg_vector[0], eCou, arg_vector[1]);
		write(2, erms, op_slen(erms));
		return (128);
	}
	return (0);
}
