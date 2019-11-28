#include "shell.h"

/**
 * *_strcpy - This is a function prototype
 * @dest: This variable recive the value of the function main
 * @src: This variable recive the value of the function main
 * Description: Function that copies the string pointed to by src
 * section header: Section description
 * Return: Returns the counter value to the main function
 */
char *_strcpy(char *dest, char *src)
{
	int cnt1 = 0;
	int cnt2;

	while (src[cnt1] != '\0')
	{
		cnt1++;
	}
	for (cnt2 = 0; cnt2 <= cnt1; cnt2++)
	{
		dest[cnt2] = src[cnt2];
	}
	return (dest);
}


/**
 * _strlen - This is a function prototype
 * @str: This variable recive the value of the function main
 * Description: Function that returns the length of a string
 * section header: Section description
 * Return: Returns the counter value to the main function
 */

int _strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return (cnt);
}


/**
 * *_strcat - This is a function prototype
 * @dest: This variable recive the value of the function main
 * @src: This variable recive the value of the function main
 * Description: Function that concatenates two strings
 * section header: Section description
 * Return: Returns the counter value to the main function
 */

char *_strcat(char *dest, char *src)
{
	int cnt1 = 0;
	int cnt2 = 0;

	while (dest[cnt1] != '\0')
	{
		cnt1++;
	}
	while (src[cnt2] != '\0')
	{
		dest[cnt1] = src[cnt2];
		cnt1++;
		cnt2++;
		dest[cnt1 + 1] = '\0';
	}
	return (dest);
}


/**
 * *_strdup - This is a function prototype
 * @str: This variable recive the value of the auxiliary function _get_env
 * Description: Function that duplicate the string str
 * section header: Section description
 * Return: A pointer to the new string str_copy
 */

char *_strdup(char *str)
{
	int cnt1 = 0;
	int cnt2 = 0;
	char *str_copy;

	if (str == NULL)
	{
		return ('\0');
	}

	while (str[cnt1] != '\0')
	{
		cnt1++;
	}
	str_copy = malloc((sizeof(char) * cnt1) + 1);
	if (str_copy == NULL)
	{
		return ('\0');
	}
	while (cnt2 < cnt1)
	{
		str_copy[cnt2] = str[cnt2];
		cnt2++;
	}
	return (str_copy);
}
