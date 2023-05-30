#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 *
 * Return: 0;
 */
int main(void)
{
	int len = 24;

	printf("\nLength:[%d, %i]", len, len);
	_printf("\nLength:[%d, %i]", len, len);

	printf("\nThis is a test");
	_printf("\nThis is a test");

	printf("\nMy name is %s", "printer");
	_printf("\nMy name is %s", "printer");

	printf("\nMy favourite character is \'%c\' and the other is '%c'", 'h', '%');
	_printf("\nMy favourtie character is \'%c\' and the other is '%c'", 'h', '%');

	printf("\nIf you wanna know my age, it is %d years old", 81);
	_printf("\nIf you wanna know my age, it is %d years old", 81);

	return (0);
}
