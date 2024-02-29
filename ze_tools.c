#include "shell.h"
/**
 * ze_goev - gets the pth
 * @pnme: a pointer to the struct of dt
 *
 * Return: (Success) a positive number
 */
char *ze_goev(char *pnme)
{
	char **env_sor, *env_ptr, *nme_ptr;

	env_sor = environ;
	while (*env_sor)
	{
		env_ptr = *env_sor;
		nme_ptr = pnme;
		while (*env_ptr == *nme_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			nme_ptr++;
		}
		if ((*env_ptr == '=') && (*nme_ptr == '\0'))
			return (env_ptr + 1);
		env_sor++;
	}
	return (NULL);
}
/**
 * sig_hand - handle the process interrept signal
 * @sgni: the signal identifier
 *
 * Return: void
 */
void sig_hand(int sgni)
{
	if (sgni == SIGINT)
	{
		PRINT("\n");
		PRINT("$ ");
	}
}
/**
 * fill_ds - fill an array with elements
 * @apa: the given array
 * @elem: the given element
 * @sze: the length of the array
 *
 * Return: pointer to filled array
 */
void *fill_ds(void *apa, int elem, unsigned int sze)
{
	char *ptr = apa;
	unsigned int idd;

	for (idd = 0; idd < sze; idd++)
	{
		*ptr = elem;
		ptr++;
	}
	return (apa);
}

/**
 * ds_v - reverse array
 * @lis: the given array
 * @sze: the array length
 *
 * Return: void
 */
void ds_v(char *lis, int sze)
{
	int i;
	char tempo;

	i = 0;
	while (i < (sze / 2))
	{
		tempo = lis[i];
		lis[i] = lis[(sze - 1) - i];
		lis[(sze - 1) - i] = tempo;
		i++;
	}
}
/**
 * idx_c - indexed command
 * @dt: a pointer to the dt structure
 *
 * Return: void
 */
void idx_c(sh_t *dt)
{
	dt->idd += 1;
}
