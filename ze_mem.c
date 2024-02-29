#include "shell.h"

/**
 * ze_ralloc - reallocates memory block
 * @pr: pointer to the previous memory
 * @osz: the old size
 * @nsz: the new size
 *
 * Return: a pointer to the newly allocated memory
 */
void *ze_ralloc(void *pr, unsigned int osz, unsigned int nsz)
{
	void *result;

	if (nsz == osz)
		return (pr);
	if (nsz == 0 && pr)
	{
		free(pr);
		return (NULL);
	}
	result = malloc(nsz);
	if (result == NULL)
		return (NULL);
	if (pr == NULL)
	{
		fill_ds(result, '\0', nsz);
		free(pr);
	}
	else
	{
		ze_mmcopy(result, pr, osz);
		free(pr);
	}
	return (result);
}
/**
 * ze_mmst - fills a memory with constant byte
 * @s: pointer to memory area
 * @numb: fs numb bytes
 * @bte: constant byte
 *
 * Return: A pointer to a character
 */
char *ze_mmst(char *s, char bte, unsigned int numb)
{
	unsigned int i;

	for (i = 0; i < numb; i++)
	{
		s[i] = bte;
	}
	return (s);
}
/**
 * ze_free - frees dt
 * @dt: the dt structure
 *
 * Return: (Success) positive number
 */
int ze_free(sh_t *dt)
{
	free(dt->line);
	dt->line = NULL;
	free(dt->ags);
	dt->ags = NULL;
	free(dt->com);
	dt->com = NULL;
	free(dt->errmg);
	dt->errmg = NULL;
	return (0);
}
/**
 * ze_mmcopy - cpies
 * @dst: Destination
 * @src: src
 * @numb: Amount of memory byte
 *
 * Return: A pointer to dst
 */
char *ze_mmcopy(char *dst, char *src, unsigned int numb)
{
	unsigned int i;

	for (i = 0; i < numb; i++)
	{
		dst[i] = src[i];
	}
	return (dst);
}
