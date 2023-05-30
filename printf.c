#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include "lib/p_d.c"
#include "lib/p_c.c"
#include "lib/p_s.c"

/**
 * _printf - print function
 * @format: arg
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int i = 0;
	int size = 0;
	int is_formatted = 0;
	int reset = 0;

	va_start(vl, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%')
		{
			is_formatted = 1;
			size = 0;
			i++;
			continue;
		}

		if (is_formatted)
		{
			size++;
			reset = _print_format(vl, format, i, &size);

			if (reset)
			{
				_reset(&is_formatted, &size);
			}
		}
		else
		{
			_putchar(*(format + i));
		}

		i++;
	}
	va_end(vl);

	return (i);
}

/**
 * _print_format - function to print format
 * @vl: va list
 * @format: text to be formatted
 * @index: current index
 * @size: substring size
 *
 * Return: a value indicating if format should be reset
 */
int _print_format(va_list vl, const char *format, int index, int *size)
{
	int reset = 1;

	switch (*(format + index))
	{
		case 'c':
			p_c(vl, format + index - *size + 1, *size - 1);
			break;
		case 's':
			p_s(vl, format + index - *size + 1, *size - 1);
			break;
		case 'd':
		case 'i':
			p_d(vl, format + index - *size + 1, *size - 1);
			break;
		default:
			reset = 0;
			break;
	}

	return (reset);
}

/**
 * _reset - reset reused variables
 * @is_formatted: arg to be reset
 * @size: arg to be reset
 */
void _reset(int *is_formatted, int *size)
{
	*is_formatted = 0;
	*size = 0;
}
