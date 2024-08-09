#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte_value;
	unsigned long	long_value;

	ptr = (unsigned char *)s;
	byte_value = (unsigned char)c;
	long_value = byte_value;
	long_value |= long_value << 8;
	long_value |= long_value << 16;
	long_value |= long_value << 32;
	while (n >= 8)
	{
		*((unsigned long *)ptr) = long_value;
		ptr += 8;
		n -= 8;
	}
	while (n-- > 0)
		*ptr++ = byte_value;
	return (s);
}
