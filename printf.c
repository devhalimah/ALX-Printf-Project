#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
#include "lib/p_d.c"
#include "lib/p_c.c"
#include "lib/p_s.c"
#include "lib/p_u.c"
#include "lib/digit_length.c"
#include "lib/is_pad_key.c"
#include "lib/is_format_key.c"
#include "lib/_putchar.c"

/**
 * _printf - print function
 * @format: arg
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
	va_list vl;
	int l = 0;
	int i = 0;
	int size = 0;
	int is_formatted = 0;

	if (format == NULL)
		return (0);

	va_start(vl, format);
	while (*(format + i) != '\0')
	{
		if (*(format + i) == '%' && !is_formatted)
		{
			is_formatted = 1;
			size = 0;
			i++;
			continue;
		}

		if (is_formatted)
		{
			size++;
			if (is_pad_key(*(format + i)))
				continue;
			else if (is_format_key(format + i))
				l += _print_format(vl, format, i, &size, &is_formatted);
			else
				l += _print_prev(format + i - size, &size, &is_formatted);
		}
		else
		{
			l += _putchar(*(format + i));
		}
		i++;
	}
	va_end(vl);

	return (l);
}

/**
 * _print_format - function to print format
 * @vl: va list
 * @format: text to be formatted
 * @index: current index
 * @size: substring size
 * @is_formatted: is_formatted parameter
 *
 * Return: a value indicating if format should be reset
 */
int _print_format(va_list vl, const char *format, int index, int *size,
	int *is_formatted)
{
	int l = 0;

	switch (*(format + index))
	{
		case 'c':
			l += p_c(vl, format + index - *size + 1, *size - 1);
			break;
		case 's':
			l += p_s(vl, format + index - *size + 1, *size - 1);
			break;
		case 'd':
		case 'i':
			l += p_d(vl, format + index - *size + 1, *size - 1);
			break;
		case 'u':
			l += p_u(vl, format + index - *size + 1, *size - 1);
			break;
		case 'p':
			break;
		case 'o':
		case 'x':
		case 'X':
			break;
		case '%':
			l += _putchar(*(format + index));
			break;
		default:
			break;
	}

	if (is_format_key(format + index))
	{
		_reset(is_formatted, size);
	}

	return (l);
}

/**
 * _print_prev - print characters before current position within size
 * @format: the substring to print
 * @size: the length of the substring
 * @is_formatted: is_formatted parameter
 *
 * Return: length
 */
int _print_prev(const char *format, int *size, int *is_formatted)
{
	int l = 0;
	int i = 0;

	while (i <= *size)
	{
		l += _putchar(*(format + i));
		i++;
	}

	_reset(is_formatted, size);

	return (l);
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
