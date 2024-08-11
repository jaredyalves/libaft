#include "libaft.h"

#include <unistd.h>

void	ft_putendl(char *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
