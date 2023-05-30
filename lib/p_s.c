#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * p_s - function to print string
 * @vl: va list
 * @text: the substring containing format
 * @size: the size of the substring
 */
void p_s(va_list vl, const char *text, int size)
{
	int i = 0;
	char *content = va_arg(vl, char*);

	if (size != 0 || *(text + size) != 's')
	{
		exit(EXIT_FAILURE);
	}

	while (*(content + i) != '\0')
	{
		_putchar(*(content + i));
		i++;
	}
}
