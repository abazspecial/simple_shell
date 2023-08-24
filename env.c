#include "shell.h"

/**
 * _env - diSPLy the current env
 * Return: Always 0
 * @info: this contains potential arguments. Which is to maintain
 *          constant function prototype in programming.
 */
int _env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _envget - gets the number of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env variable name etc
 *
 * Return: the value
 */
char *_envget(info_t *info, const char *name)
{
	char *p;
list_t *node = info->env;
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
 * _setmyenv - checkout a new and good environment variable,
 *             or magnify an existing one
 *  Return: Always 0
 * @info: this contains potential arguments. Which is to maintain
 *          constant function prototype in programming.
  */
int _setmyenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Wrong number of arguments\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - use to remove some environment variable
 * Return: Always 0
 * @info: this contains potential arguments. Which is to maintain
 *          constant function prototype in programming.
 */
int _unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * porp_env_list - populates environment linked list
 * Return: Always 0
 * @info: this contains potential arguments. Which is to maintain
 *          constant function prototype in programming.
 * end
 */
int porp_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}


