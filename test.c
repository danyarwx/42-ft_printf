#include <stdio.h>
#include <unistd.h>

void	ft_puthex(unsigned int n)
{
	char	base[] = "0123456789abcdef";
	char c;

	if (n > 16)
	{
		ft_puthex(n / 16);
	}
	c = base[n % 16];
	write(1, &c, 1);
}

int main()
{
	unsigned int n;

	n = 455;

	printf(" - The puthex output");
	ft_puthex(n);
	printf("\nThe printf output is : %x\n", n);

	return (0);
}
