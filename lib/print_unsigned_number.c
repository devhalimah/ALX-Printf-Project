/**
 * print_unsigned_number - function to write number to output
 * @num: the number to be outputted
 *
 * Return: length
 */
int print_unsigned_number(unsigned int num)
{
	int l = 0;

	if (num >= 10)
	{
		l += print_number((num - (num % 10)) / 10, 0);
	}

	l += _putchar('0' + (num % 10));

	return (l);
}
