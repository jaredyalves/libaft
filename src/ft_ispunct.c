#include "libaft.h"

int	ft_ispunct(int c)
{
	return (ft_isprint(c) && !ft_isalnum(c) && !ft_isblank(c));
}
