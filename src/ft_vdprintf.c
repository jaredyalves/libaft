#include <stdarg.h>
#include <unistd.h>

static int write_character(int fd, int c)
{
	return (write(fd, &c, 1));
}

static int write_string(int fd, char *s)
{
	int written;

	written = 0;
	if (s == NULL)
		s = "(null)";
	while (*s)
		written += write_character(fd, *s++);
	return (written);
}

static int write_number(int fd, ssize_t n, const int b, const char *bs)
{
	int	 i;
	int	 written;
	char buffer[65];

	i = 0;
	written = 0;
	if (n < 0)
	{
		n = -n;
		written += write(fd, "-", 1);
	}
	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = bs[n % b];
			n /= b;
		}
	}
	while (i > 0)
		written += write(fd, &(buffer[--i]), 1);
	return (written);
}

static int write_address(int fd, void *a)
{
	int written;

	written = 0;
	if (a == NULL)
		return (write_string(fd, "(nil)"));
	written += write_string(fd, "0x");
	written += write_number(fd, (size_t)a, 16, "0123456789abcdef");
	return (written);
}

// ---

static int write_type(int fd, int type, va_list ap)
{
	if (type == 'c')
		return (write_character(fd, va_arg(ap, int)));
	if (type == 's')
		return (write_string(fd, va_arg(ap, char *)));
	if (type == 'd' || type == 'i')
		return (write_number(fd, va_arg(ap, int), 10, "0123456789"));
	if (type == 'u')
		return (write_number(fd, va_arg(ap, size_t), 10, "0123456789"));
	if (type == 'x')
		return (write_number(fd, va_arg(ap, size_t), 16, "0123456789abcdef"));
	if (type == 'X')
		return (write_number(fd, va_arg(ap, size_t), 16, "0123456789ABCDEF"));
	if (type == 'p')
		return (write_address(fd, va_arg(ap, void *)));
	if (type == '%')
		return (write_character(fd, '%'));
	return (0);
}

int ft_vdprintf(int fd, const char *format, va_list ap)
{
	int written;

	written = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			written += write_type(fd, *(++format), ap);
		else
			written += write_character(fd, *format);
		format++;
	}
	return (written);
}
