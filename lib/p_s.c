#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * p_s - function to print string
 * @vl: va list
 * @text: the substring containing format
 * @size: the size of the substring
 *
 * Return: length
 */
int p_s(va_list vl, const char *text, int size)
{
	int l = 0;
	int i = 0;
	char *content = va_arg(vl, char*);

	if (size != 0 || *(text + size) != 's')
	{
		exit(EXIT_FAILURE);
	}

	if (content == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('i');
		_putchar('l');
		_putchar(')');
		_putchar(0);
	}

	while (*(content + i) != '\0')
	{
		l += _putchar(*(content + i));
		i++;
	}

	return (l);
}
