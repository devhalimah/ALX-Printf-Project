/**
 * print_sign - function to print sign (-/+)
 * @include_sign: 1 if sign should be printed, 0 otherwise
 * @num: number to be printed
 *
 * Return: length
 */
int print_sign(int include_sign, int num)
{
	int l = 0;

	if (include_sign)
	{
		if (num < 0)
		{
			l += _putchar('-');
		}
		else
		{
			l += _putchar('+');
		}
	}

	return (l);
}
