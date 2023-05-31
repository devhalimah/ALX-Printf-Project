#include "print_number.c"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * p_d - function to print digit
 * @vl: va list
 * @text: the substring containg format
 * @size: the size of the substring
 *
 * Return: length
 */
int p_d(va_list vl, const char *text, int size)
{
	int l = 0;
	char *p;
	int num = va_arg(vl, int);
	int num_size = digit_length(num, 0);

	if (*(text + size) == 'd' || *(text + size) == 'i')
	{
		p = malloc((num < 0 ? num_size + 1 : num_size) * sizeof(char));
		if (p == NULL)
		{
			exit(EXIT_FAILURE);
		}
		l += print_number(num, 1);
		free(p);
	}
	else
	{
		exit(EXIT_FAILURE);
	}

	return (l);
}
