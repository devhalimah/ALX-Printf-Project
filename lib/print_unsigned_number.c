/**
 * print_unsigned_number - function to write number to output
 * @num: the number to be outputted
 */
void print_unsigned_number(unsigned int num)
{
	if (num >= 10)
	{
		print_number((num - (num % 10)) / 10, 0);
	}

	_putchar('0' + (num % 10));
}
