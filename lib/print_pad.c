/**
 * print_pad - function to pad output
 * @count: pad count
 * @c: pad content
 *
 */
int print_pad(int count, const char *c)
{
	int l = 0;
	int i = 0;

	while (i < count)
	{
		if (c == NULL)
		{
			l += _putchar(' ');
		}
		else
		{
			l += _putchar(*c);
		}
		i++;
	}

	return (l);
}
