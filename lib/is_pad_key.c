/**
 * is_pad_key - determines if key is used for padding a format
 * @c: the key
 *
 * Return: 1 if true
 */
int is_pad_key(char c)
{
	if (
		c == '.' ||
		c == '\\' ||
		c == '+' ||
		c == '-' ||
		c == ' ' ||
		(c >= 48 && c < 48 + 10)
	   )
	{
		return (1);
	}

	return (0);
}
