#include "shell.h"

/**
 * _memset - Func fills memry with a const_byte
 * @s: Pointr to the mem_area
 * @b: Byte to_fill *s with
 * @n: Amnt of bytes_to be_filled
 * Return: (s) Pointer to s mem_area
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Func to free a strng_of_strngs
 * @pp: strng_of_strngs
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Func reallcts a mem_block
 * @ptr: Pointer to prev_ malloc'atd_block
 * @old_size: Byte sz of prev_block
 * @new_size: Byte sz of new_block
 *
 * Return: Pointer to da_ol'block_nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
