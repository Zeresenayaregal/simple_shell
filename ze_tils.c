#include "shell.h"

/**
 * ze_arg - convert integer to array
 * @numb: the given number
 *
 * Return: a pointer to the null terminated string
 */
char *ze_arg(unsigned int numb)
{
	int sze = 0, i = 0;
	char *s;

	sze = sizint(numb);
	s = malloc(sze + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (numb / 10)
	{
		s[i] = (numb % 10) + '0';
		numb /= 10;
		i++;
	}
	s[i] = (numb % 10) + '0';
	ds_v(s, sze);
	s[i + 1] = '\0';
	return (s);
}
/**
 * ze_it - converts character to integer
 * @cze: the given character
 *
 * Return: An integer
 */
int ze_it(char *cze)
{
	unsigned int val = 0;
	int sign = 1;

	if (cze == NULL)
		return (0);
	while (*cze)
	{
		if (*cze == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*cze - '0');
		cze++;
	}
	return (sign * val);
}

/**
 * sizint - Determine the number of digit int integer
 * @numb: the given number
 *
 * Return: the length of the integer
 */
int sizint(int numb)
{
	int sze = 0;

	while (numb != 0)
	{
		sze++;
		numb /= 10;
	}
	return (sze);
}
/**
 * perr - prints error
 * @dt: the dt structure pointer
 *
 * Return: (Success) a positive number
 */
int perr(sh_t *dt)
{
	char *idx = ze_arg(dt->idd);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(dt->ags[0]);
	PRINT(": ");
	PRINT(dt->errmg);
	free(idx);
	return (0);
}

/**
 * wr_his - prints error
 * @dt: the dt structure pointer
 *
 * Return: (Success) a positive number
 */
int wr_his(sh_t *dt __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int sze;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[sze])
			sze++;
		w = write(fd, line_of_history, sze);
		if (w < 0)
			return (-1);
	}
	return (1);
}
