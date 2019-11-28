#include "shell.h"
/**
 * *_get_env - This is a auxiliary function
 *
 *
 * Description: Function found by the PATH of the environ variable
 * section header: Section description
 * Return: Returns the counter value to the main function
 */
char  *_get_env(void)
{
        char *path = "PATH=";
        unsigned int i, j;
        char **env;
        int p;
        for(p = 0; environ[p] != NULL ; p++);
        env = malloc(sizeof(char *) * (p + 1));
        for(p = 0; environ[p] != NULL; p++)
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

char *verify_path(char *cmd)
{
        char *test, *token, *_path;
        int cnt;
        struct stat st;
        test= _get_env();
        _path = malloc(sizeof(char) * _strlen(test));
        token = strtok(test,":");
        for (cnt = 0; token; cnt++)
        {
                _strcpy(_path,token);
                _strcat(_path, "/");
                _strcat(_path, cmd);
                if (stat(_path, &st) == 0)
                {
                        break;
                }
                token = strtok(NULL, ":");
        }
        return (_path);
}

int execute(char **argv, char *path)
{
        struct stat st;
        if(stat(path,&st) == 0)
        {
                if(execve(path, argv, NULL) == -1)
                {
                        perror("Error de ejecución");
                }
        }
        else
        {
                printf("No such file");
        }
        return(0);
}
