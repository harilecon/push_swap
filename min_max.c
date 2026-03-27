#include <stdio.h>
#include <string.h>

int min_max(char *str)
{
	int	i;
	int	signe;
	int	len;

	signe = 1;
	i = 0;
	if (str[0] == '-')
	{
		signe = -1;
		i++;
	}
	if (str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	len = strlen(str + i);
	if (len < 10)
		return(1);

	printf("len = %d\n\n", strlen(str+ i));
	if (len == 10)
	{
		if (signe == 1)
			if (strncmp(str + i, "2147483647", 11) <= 0)
				return (1);
		if (signe == -1)
			if (strncmp(str + i, "2147483648", 11) <= 0)
				return (1);
	}
	return (0);
}

int main(int grc, char **argv)
{
	printf("%d", min_max(argv[1]));
	return 0;
}
