#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * p_c - function to print character
 * @vl: va list
 * @text: the substring containing format
 * @size: the size of the substring
 *
 * Return: length
 */
int p_c(va_list vl, const char *text, int size)
{
	int l = 0;
	char content = va_arg(vl, int);

	if (size != 0 || *(text + size) != 'c')
	{
		exit(EXIT_FAILURE);
	}

	l += _putchar(content);
	return (l);
}
