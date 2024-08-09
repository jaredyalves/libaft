#include "libaft.h"

#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	size_t	written;
	va_list	args;

	va_start(args, format);
	written = ft_vdprintf(STDOUT_FILENO, format, args);
	va_end(args);
	return (written);
}
