#include "print_unsigned_number.c"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * p_u - function to print unsigned digit
 * @vl: va list
 * @text: the substring containg format
 * @size: the size of the substring
 */
void p_u(va_list vl, const char *text, int size)
{
	char *p;
	unsigned int num = va_arg(vl, unsigned int);
	int num_size = digit_length(num, 0);

	if (*(text + size) == 'u')
	{
		p = malloc(num_size * sizeof(char));
		if (p == NULL)
		{
			exit(EXIT_FAILURE);
		}
		print_unsigned_number(num);
		free(p);
	}
	else
	{
		exit(EXIT_FAILURE);
	}
}
