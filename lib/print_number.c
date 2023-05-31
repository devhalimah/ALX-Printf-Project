/**
 * print_number - function to write number to output
 * @num: the number to be outputted
 * @print_negative_sign: indicates if a negative sign should be outputted
 *
 */
void print_number(int num, int print_negative_sign)
{
	if (num < 0)
	{
		if (print_negative_sign)
		{
			_putchar('-');
		}
		num = num * -1;
	}

	if (num >= 10)
	{
		print_number((num - (num % 10)) / 10, 0);
	}

	_putchar('0' + (num % 10));
}
