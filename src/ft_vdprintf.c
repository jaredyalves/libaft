#include <stdarg.h>
#include <unistd.h>

static size_t	write_string(int fd, const char *s)
{
	size_t	written;

	written = 0;
	if (s == NULL)
		s = "(null)";
	while (*s)
		written += write(fd, s++, 1);
	return (written);
}

static size_t	write_number(int fd, ssize_t n, const int b, const char *bs)
{
	size_t	i;
	size_t	written;
	char	buffer[65];

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

static size_t	write_memory(int fd, size_t m)
{
	size_t	written;

	written = 0;
	if (m == 0)
		written += write_string(fd, "(nil)");
	else
	{
		written += write_string(fd, "0x");
		written += write_number(fd, m, 16, "0123456789abcdef");
	}
	return (written);
}

static size_t	write_format(int fd, const int f, va_list args)
{
	char	c;

	if (f == 'c')
	{
		c = va_arg(args, int);
		return (write(fd, &c, 1));
	}
	if (f == 's')
		return (write_string(fd, va_arg(args, const char *)));
	if (f == 'd' || f == 'i')
		return (write_number(fd, va_arg(args, int), 10, "0123456789"));
	if (f == 'u')
		return (write_number(fd, va_arg(args, size_t), 10, "0123456789"));
	if (f == 'x')
		return (write_number(fd, va_arg(args, size_t), 16, "0123456789abcdef"));
	if (f == 'X')
		return (write_number(fd, va_arg(args, size_t), 16, "0123456789ABCDEF"));
	if (f == 'p')
		return (write_memory(fd, (size_t)va_arg(args, void *)));
	if (f == '%')
		return (write(fd, "%", 1));
	return (0);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	const char	*p;
	size_t		written;

	p = format;
	written = 0;
	while (*p)
	{
		if (*p == '%' && *(p + 1))
			written += write_format(fd, *(++p), args);
		else
			written += write(fd, p, 1);
		p++;
	}
	return (written);
}
