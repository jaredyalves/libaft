#include "libaft.h"

int	ft_isspace(int c)
{
	return (ft_isblank(c) || c == '\f' || c == '\n' || c == '\r' || c == '\v');
}
