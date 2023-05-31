/**
 * print_number - function to write number to output
 * @num: the number to be outputted
 * @print_negative_sign: indicates if a negative sign should be outputted
 *
 * Return: length
 */
int print_number(int num, int print_negative_sign)
{
	int l = 0;

	if (num < 0)
	{
		if (print_negative_sign)
		{
			l += _putchar('-');
		}
		num = num * -1;
	}

	if (num >= 10)
	{
		l += print_number((num - (num % 10)) / 10, 0);
	}

	l += _putchar('0' + (num % 10));

	return (l);
}
