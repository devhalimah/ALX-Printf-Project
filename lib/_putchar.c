#include <unistd.h>

/**
 * _putchar - writes a character to output
 * @c: the character
 *
 * Return: int
 */
int _putchar(char c)
{
	/**
	 * return (write(1, &c, 1));
	 */

	return (putchar(c));
}
