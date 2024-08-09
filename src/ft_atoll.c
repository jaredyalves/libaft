#include "libaft.h"

#include <limits.h>

long long	ft_atoll(const char *nptr)
{
	int			sign;
	int			digit;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (result > (LLONG_MAX - digit) / 10 && sign == 1)
			return (LLONG_MAX);
		else if (result > (LLONG_MAX - digit) / 10)
			return (LLONG_MIN);
		result = result * 10 + digit;
		nptr++;
	}
	return (result * sign);
}
