/**
 * is_format_key - determines if character is an escape character
 * @c: the key
 *
 * Return: 1 if true, 0 otherwise
 */
int is_format_key(const char *c)
{
	if (
		*c == '%' ||
		*c == 'a' ||
		*c == 'c' ||
		*c == 'd' ||
		*c == 'e' ||
		*c == 'f' ||
		*c == 'g' ||
		(*c == 'h' && c + 1 != NULL && *(c + 1) == 'd') ||
		*c == 'i' ||
		(*c == 'j' && c + 1 != NULL && *(c + 1) == 'd') ||
		(*c == 'l' && c + 1 != NULL && *(c + 1) == 'd') ||
		*c == 'n' ||
		*c == 'o' ||
		*c == 'p' ||
		(*c == 'q' && c + 1 != NULL && *(c + 1) == 'd') ||
		*c == 's' ||
		(*c == 't' && c + 1 != NULL && *(c + 1) == 'd') ||
		*c == 'u' ||
		*c == 'x' ||
		*c == 'X' ||
		(*c == 'v' && c + 1 != NULL && *(c + 1) == 'd')
	)
	{
		return (1);
	}

	return (0);
}
