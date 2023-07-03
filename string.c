#include "shell.h"

/**
 * _strlen - Func will return str_length
 * @s: Strng for length_check
 *
 * Return: int for string_length
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - Func does dictionary analogy of two_strngs.
 * @s1: String1
 * @s2: String2
 *
 * Return: nega_tive if s1 less_than s2,
 * posi_tive if s1 greater_than s2, zero0 if s1 is_equal_to s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Func evaluates if sewpin starts with haystack
 * @haystack: Strng to be search with
 * @needle: Substrng to be found
 *
 * Return: Addy of nxt_haystack_char or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Func concatjoins two_strngs
 * @dest: Desti_buffer
 * @src: Src_buffer
 *
 * Return: Pointer to desti_buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
