# C - Simple Shell

This Simple Shell is able to display the following prompt #cisfun$, where it expects the user to type a command and execute it after the user presses enter, showing the result of the command execution on the screen. After showing on the screen the result of the previous execution shows the same prompt again, waiting for the user to type a command again. This Simple Shell does not yet process advanced features such as: semicolons, pipes or redirections. It receives arguments such as: ls -l or cat main.c

## How to run the Simple Shell


### 1. Step - compilation

The first thing we must do is to execute the program, so that it shows us the command line.

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell_test$ gcc -Wall -Werror -Wextra -pedantic *.c -o simple
```


### 2. Step - execute

And now what we have to do is run the program, so that it shows us the command line.

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell_test$ ./simple
```


### 3. Step - linea de comandos

Here we will have the command line available, for the user to enter the commands you want to execute

```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./simple
#cisfun$
```

## How to use the Simple Shell

In the command line we can only enter one word to execute at a time.

```
#cisfun$
```
As in the following examples:

```
#cisfun$ ls
README.md  main.c  path.c  shell.h  simple
```
or

```
#cisfun$ pwd
/home/vagrant/simple_shell
```

or

```
#cisfun$ pwd
#cisfun$ cat shell.c
#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void sig_handler(int num);
int execute(char **argv, char *path);
char  *_get_env(void);
char *verify_path(char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

#endif
```

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language 

## Authors

* **Manuel Mosquera [mmanumos]** [https://github.com/mmanumos](https://github.com/mmanumos)
* **Julián Sandoval [derhks]** [https://github.com/Derhks](https://github.com/Derhks)

## Acknowledgments

I take this opportunity to thank each of the pages and video tutorials that helped us along the way to find a way to build our little program. In a special way I thank each colleague who dedicated part of his precious time helping us to resolve doubts and solve difficulties that we encountered throughout this process, thank you because it has been a challenge of great proportions.
```