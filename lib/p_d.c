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
	int n = va_arg(vl, int);
	int nl = digit_length(n, 0);
	int i = 0;
	int sign = 0;
	int zero_pad = 0;
	int space_pad = 0;
	int reverse_pad = 0;
	int pad_size = 0;
	int decimal_pad_size = 0;
	int alloc_, x_pad_size, xd_pad_size;

	if (*(text + size) == 'd' || *(text + size) == 'i')
	{
		if (n < 0)
			sign = 1;

		process_start_index(text, &i, &reverse_pad, &sign, &zero_pad, &space_pad);
		calculate_pad_size(text, &i, size, &pad_size, &decimal_pad_size);

		pad_size = (pad_size == 0 && space_pad == 1) ? 1 + nl : pad_size;
		alloc_ = (sign ? 1 : 0) + (nl > decimal_pad_size ? nl : decimal_pad_size);
		p = malloc((pad_size > alloc_ ? pad_size : alloc_) * sizeof(char));

		if (p == NULL)
			exit(EXIT_FAILURE);

		x_pad_size = pad_size > alloc_ ? pad_size - alloc_ : 0;
		xd_pad_size = nl > decimal_pad_size ? 0 : decimal_pad_size - nl;
		l += print_padded_number(n, reverse_pad, sign, x_pad_size, xd_pad_size);
		free(p);
	}
	else
	{
		exit(EXIT_FAILURE);
	}

	return (l);
}

/**
 * print_padded_number - printf a padded numer
 * @reverse_padding: indicates if padding is reversed
 * @sign: indicates if sign is included
 * @extra_pad_size: size of the extra padding before decimal
 * @extra_decimal_pad_size: size of the extra padding after decimal
 * @num: the number to be printed
 *
 * Return: length
 */
int print_padded_number(int num, int reverse_padding, int sign,
	int extra_pad_size, int extra_decimal_pad_size)
{
	int l = 0;
	const char pad_value = '0';

	if (!reverse_padding)
	{
		l += print_pad(extra_pad_size, NULL);
		l += print_sign(sign, num);
		l += print_pad(extra_decimal_pad_size, &pad_value);
		l += print_number(num, 0);
	}
	else
	{
		l += print_sign(sign, num);
		l += print_pad(extra_decimal_pad_size, &pad_value);
		l += print_number(num, 0);
		l += print_pad(extra_pad_size, NULL);
	}

	return (l);
}
