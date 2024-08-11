#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[12];
	int				i;
	unsigned int	num;

	i = 11;
	buffer[i--] = '\0';
	if (n < 0)
	{
		write(fd, "-", 1);
		num = (unsigned int)-n;
	}
	else
		num = (unsigned int)n;
	if (num == 0)
		buffer[i--] = '0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	write(fd, &buffer[i + 1], 11 - i);
}
