#include "shell.h"

/**
 *_get_env - This is a auxiliary function
 *
 * Description: Function found by the PATH of the environ variable
 * Return: The  string whith the path
 */

char  *_get_env(void)
{
	char *path = "PATH=";
	unsigned int i, j;
	char **env;
	int p;

	for (p = 0; environ[p] != NULL ; p++)
		;

	env = malloc(sizeof(char *) * (p + 1));

	for (p = 0; environ[p] != NULL; p++)
	{
		env[p] = _strdup(environ[p]);
	}

	env[p] = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if (j == 5)
			break;
	}
	return (env[i]);
}


/**
 *verify_path - Find the righ bin to the execve(Execute)
 *
 * @cmd: First part of get_line sended by the main
 * Description: Use the the return of get_env
 * Return: The righ bin to first parameter of execve(Execute)
 */

char *verify_path(char *cmd)
{
	char *test, *token, *_path;
	struct stat st;

	test = _get_env();
	_path = malloc(sizeof(char) * _strlen(test));
	token = strtok(test, ":");
	if (access(cmd, F_OK) == 0)
	{
		_strcat(_path, cmd);
	}
	else
	{
		for (; token; token = strtok(NULL, ":"))
		{
			_strcpy(_path, token);
			_strcat(_path, "/");
			_strcat(_path, cmd);
			if (stat(_path, &st) == 0)
			{
				break;
			}
		}
	}
	return (_path);
}


/**
 *execute - Execute the final path
 *
 * @argv: Contains the array with arguments of get_line
 * @path: First part with the right bin sended by verify_path to main
 *
 * Description: Execute the path
 * Return: Always 0
 */

int execute(char **argv, char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
	{
		if (execve(path, argv, NULL) == -1)
		{
			perror("Error de ejecución");
		}
	}
	else
	{
		printf("No such file");
	}
	return (0);
}
