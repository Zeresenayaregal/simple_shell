#include "project.h"

/**
 * promptve - function get command li mode
 * @arg_vector: Pointer to strings
 * @eCou: Count times receiving a command.
 * @e_v: e_v var.
 * Return: s_e value.
 **/
int promptve(char *arg_vector[], int eCou, char **e_v)
{
	int promptve = 1, statProc, i, rfr_line = 0;
	size_t len = 0;
	char *li, *tuk = NULL, *ags[32];

	isatty(STDIN_FILENO) == 0 ? promptve = 0 : promptve;
	while (1)
	{
		promptve == 1 ? write(STDIN_FILENO, "$ ", 2) : promptve;
		rfr_line = getline(&li, &len, stdin);
		if (rfr_line == EOF)
		{
			free(li), write(STDIN_FILENO, "\n", 1);
			return (statProc);
		}
		else if (op_sncmp(li, "exit\n", 4) == 0)
		{
			free(li);
			return (statProc);
		}
		else
		{
			if (op_sncmp(li, "e_v\n", 3) == 0)
				own_env(e_v);
			else
			{
				tuk = strtok(li, " \t\n\r");
				ags[0] = arg_vector[0];
				for (i = 0; tuk != NULL && i < 31; i++)
				{
					ags[i + 1] = tuk;
					tuk = strtok(NULL, " \t\n\r");
				}
				ags[i + 1] = NULL;
				if (ags[1])
					statProc = op_proc(ags, eCou, e_v);
			}
		}
		eCou++;
	}
	return (statProc);
}

/**
 * main - shell proyect
 * @arg_count: count arguments
 * @arg_vector: store arguments
 * @e_v: env_vars
 * Return: cond exiting ...;
 **/

int main(int arg_count, char *arg_vector[], char **e_v)
{
	int s_e = 0;
	(void)arg_count;

	s_e = promptve(arg_vector, 1, e_v);
	return (s_e);
}
