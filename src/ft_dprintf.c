#include "libaft.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	int		written;
	va_list	ap;

	va_start(ap, format);
	written = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (written);
}
