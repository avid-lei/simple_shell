#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "header.h"
#include <signal.h>

/**
 * init - function line counter
 * Return: always 0
 */
void init(void) __attribute__ ((constructor));

void init(void)
{

}

/**
 * main - main shell function
 * @argc: int
 * @argv: char
 * Return: always 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char **buffer;
	char *get = NULL, *first, *checker, *gcopy, *com = NULL, *token;
	size_t y = 0;
	int status = 0;
	int exit_status = 0;
	int x = 0, z, args = 0, i = 1, arg1;
	pid_t child2;
	list *path = getpath();
	list *env = genv();
	int linecount = 0;

	signal(SIGINT, sigHandler);


	while (x != -1)
	{
		linecount++;
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "divalicious$ ", 13);

		y = 0;
		get = NULL;
		com = NULL;

		x = getline(&get, &y, stdin);
		if (x == -1)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free(get);
			break;
		}
		get[x - 1] = '\0';
		arg1 = _strn(get);
		if (arg1 == -1 || arg1 == 0)
			continue;
		com = _strtok(get, "#");
		gcopy = _strdup(com);
		args = _strn(com);
		buffer = malloc(sizeof(char *) * (args + 1));
		if (!buffer)
		{
			free(get);
			break;
		}
		first = _strtok(com, " ");

		if (is_a(first) == 1) /*check if its a path name*/
		{

			if (_strcmp(first, "exit") == 0)
			{
				if (args > 2)
				{
					_errors(argv, first);
				}
				if (args == 1)
				{
					free(get);
					free(buffer);
					free(gcopy);
					free_list(&path);
					free_list(&env);
					exit(exit_status);
				}

				else
				{
					token = _strtok(NULL, " ");

					if (isnum(token) == -1)
					{
						_errors(argv, first);
					}
					else
					{

						exit_status = _atoi(token);

					if (exit_status == -1)
					{
						_errors(argv, first);
						exit_status = 2;
						continue;
					}
						free(get);
						free(buffer);
						free(gcopy);
						free_list(&path);
						free_list(&env);

						exit(exit_status);
					}
				}


				continue;

			}

			else if (built_in(gcopy, env) == 0)/*check built in*/
			{
				free(buffer);
				free(get);
				free(gcopy);
				continue;
			}
			checker = _which(first, path);

			if (checker != NULL) /*check if its a path*/
				buffer[0] = checker;
			else
			{
				exit_status = 127;
				_errors(argv, first);
				free(buffer);
				free(get);
				free(gcopy);
				continue;
			}
		}
		else /*/bin/ls */
		{
			buffer[0] = _strdup(first);
		}
		for (i = 1; i < args ; i++)
			buffer[i] = _strtok(NULL, " ");

		buffer[i] = NULL;

		child2 = fork();

		if (child2 > 0)
		{
			free(buffer[0]);
			free(buffer);
			free(get);
			free(gcopy);
			wait(&status);

			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);


		}
		if (child2 == 0)
		{
			z = execve(buffer[0], buffer, NULL);
			if (z == -1)
			{
				exit_status = 1;
				perror("Execution Error");
				break;
			}
		}
	}
if (path)
	free_list(&path);
if (env)
	free_list(&env);
	return (0);
}
