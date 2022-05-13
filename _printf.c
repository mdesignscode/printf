#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - prints an integer.
 * @n: int to be printed.
 *
 * Return: nothing.
 */
void print_number(int n)
{
	unsigned int x;

	x = n;
	if (n < 0)
	{
		_putchar(45);
		x = -n;
	}
	if (x / 10)
		print_number(x / 10);
	_putchar((x % 10) + 48);
}

/**
 * _printf - produces output according to a format.
 * @format: a character string.
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list characters;
	char *string;
	int index, ctr, printed;

	index = ctr = printed = 0;

	va_start(characters, format);

	for (; format[index]; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == 'c')
			{
				_putchar(va_arg(characters, int));
				printed++;
			}

			if (format[index + 1] == 's')
			{
				string = va_arg(characters, char *);
				for (; string[ctr]; ctr++)
				{
					_putchar(string[ctr]);
					printed++;
				}
			}

			if (format[index + 1] == '%')
			{
				_putchar('%');
				printed++;
			}

			if (format[index + 1] == 'i' || format[index + 1] == 'd')
			{
				print_number((va_arg(characters, int)));
				printed++;
			}

			index += 2;
		}
		_putchar(format[index]);
		printed++;
	}
	va_end(characters);
	return (printed);
}
