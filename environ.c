#include "shell.h"

/**
 * _myenv - Func to print present env
 * @info: The struct containn possible args. For maintainn const func prototyp
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Func to get d vlue of an envirnmnt variabl
 * @info: The struct containn possible args. For maintainn const func prototyp
 * @name: The envirnmnt variabl’s name
 *
 * Return: Vlue of d envirnmnt variabl
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Func to init a fresh envirnmnt variabl or mod an existn var
 * @info: The struct containn possible args. For maintainn const func prototyp.
 *  Return: 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Func to remv an envirnmnt varbl
 * @info: The struct containn possible args. For maintainn const func prototyp
 * Return: 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Func will populate an envrnmnt linked_list
 * @info: The struct containn possible args. For maintainn const func prototyp
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
