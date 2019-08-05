#include "header.h"
/**
 * built_in - takes the string and args and check it through the env.
 * @get: string that is being passed
 * @env: args that are being passed.
 * Return: 0 if Success else -1
 **/
int built_in(char *get, list *env)
{

	int args, x;
	char *token;

	builtin b[] = {

		{"cd", _cd},
		{"exit", _ex},
		{"env", _e},
		{"setenv", _set},
		{"unsetenv", _unset},

	};

	args = _strn(get);

	token = _strtok(get, " ");

	for (x = 0; x < 5; x++)
	{
		if (_strcmp(b[x].command, token) == 0)
		{

			if (args == 1)
			{
				b[x].func("", args, env);
			}
			else
			{
				token = _strtok(NULL, "\n");
				b[x].func(token, args, env);
			}
			return (0);
		}
	}

	return (-1);
}
/**
 * _cd - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 **/

void _cd(char *s, int args, list *env __attribute__((unused)))
{

	int x;


	if (args > 2)
	{
		write(STDERR_FILENO, "Error: Too many arguments\n", 26);
		return;
	}
	if (args == 1)
	{
		chdir("..");
		return;
	}

	if (_strcmp(s, "-") == 0)
		chdir("..");
	else
	{
		x = chdir(s);
		if (x == -1)
			perror("Error: ");
	}

}
/**
 * _set - set the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 **/
void _set(char *s, int args, list *env)
{
	char *var;
	char *val;
	char *str;
	int len = _strlen(s) + 1;
	list *temp = env;

	if (args != 3)
	{
		write(STDERR_FILENO, "Command usage: setenv VARIABLE VALUE\n", 37);
		return;
	}
	var = _strtok(s, " ");

	val  = _strtok(NULL, " ");

	str = malloc(len * sizeof(char));
	_strcpy(str, var);
	_strcat(str, "=");
	_strcat(str, val);


	while (env)
	{
		if (_strncmp(env->s, var, _strlen(var)) == 0)
		{
			env->s = _strdup(str);
			free(str);
			return;
		}
		env = env->next;

	}

		env = add_node_end(&temp, str);

}
/**
 * _unset - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: unset the env.
 **/

void _unset(char *s, int args, list *env)
{
	char *var;
	int x;
	list *temp = env;

	if (args != 2)
	{
		write(STDERR_FILENO, "Command usage: unsetenv VARIABLE\n", 33);
		return;
	}

	var = _strtok(s, " ");

	for (x = 0; env; x++)
	{
		if (_strncmp(env->s, var, _strlen(var)) == 0)
		{
			delete_node(&temp, x);
			break;
		}
		env = env->next;
	}
}
/**
 * _ex - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 **/

void _ex(char *s, int args, list *env __attribute__((unused)))
{

	static int exitval;

	exitval = 0;

	if (args == 1)
	{
		exit(exitval);
	}

	else
	{
		if (isnum(s) == -1)
		{
			write(STDERR_FILENO, "Exit: Illegal number\n", 21);
			return;
		}
		else
		{
			exitval = _atoi(s);
			exit(exitval);
		}
	}
}
