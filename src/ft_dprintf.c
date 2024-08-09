#include "libaft.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	size_t	written;
	va_list	args;

	va_start(args, format);
	written = ft_vdprintf(fd, format, args);
	va_end(args);
	return (written);
}
