#include "libaft.h"

static void	reverse(char *string, int length)
{
	char	temp;
	int		end;
	int		start;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		negative;

	string = (char *)ft_calloc(12, sizeof(char));
	if (string == NULL)
		return (NULL);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	i = 0;
	if (n == 0)
		string[i++] = '0';
	while (n > 0)
	{
		string[i++] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		string[i++] = '-';
	return (reverse(string, i), string);
}
