#include "shell.h"

int main(void)
{
        int cnt = 0, status;
        size_t s_line = 0;
        ssize_t r_getline;
        char *c_line = NULL,*c_line2 = NULL, *token = NULL, **argv, *path;

	while(1)
        {
                write(STDOUT_FILENO, "#cisfun$ ", 10);
                if((r_getline = getline(&c_line, &s_line, stdin)) != -1)
                {
                        token = strtok(c_line, " \n\t");

                        argv = malloc(r_getline * sizeof(char *));
                        for (cnt = 0; token; cnt++)
                        {
                                argv[cnt] = token;
                                token = strtok(NULL, " \n\t");
                        }

			path = verify_path(argv[0]);

                        if (fork() == 0)
                        {
                                execute(argv, path);
                        }
                        else
                        {
                                wait(&status);
                        }
                }
                else if (getline(&c_line, &s_line, stdin) == -1)
                {
                        perror("\n");
                        exit(98);
                }
        }
        free(c_line);
        free(argv);
        return (0);
}
