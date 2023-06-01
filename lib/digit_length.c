/**
 * digit_length - function to calculate the size of a digit.
 * eg. 233 is 3, 47 is 2, 0 is 1
 * @num: the digit
 * @include_sign: indicates if sign should be part of the equation
 *
 * Return: digit length
 */
int digit_length(int num, int include_sign)
{
	int count = 0;

	if (include_sign)
	{
		count += 1;
	}

	if (num < 0)
	{
		num = num * -1;
	}

	while (num >= 10)
	{
		num = (num - (num % 10)) / 10;
		count += 1;
	}

	return (count + 1);
}
