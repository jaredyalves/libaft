#include "libaft.h"

#include <unistd.h>

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}
