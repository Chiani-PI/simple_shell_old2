#include "shell.h"

/**
 * bfree - Func frees_pointr and NULLs_ addy
 * @ptr: Pointer to be freed’s addy
 *
 * Return: 1 when freed, else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
