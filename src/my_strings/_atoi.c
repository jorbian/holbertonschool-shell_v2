#include "my_strings.h"

/**
 * _atoi - converts a string to an integer
 * @s: input string
 *
 * Return: the converted integer
 */
int _atoi(char *s)
{
	int i, l, n, sign;

	n = 0;
	sign = 1;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	l = i;
	for (i = 0; i < l; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if ((n * -10) - (s[i] - 48) == -2147483648)
			{
				n = (n * -10) - (s[i] - 48);
				return (n);
			}
			n = n * 10 + (s[i] - '0');
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		else
		{
			return (-1);
		}
	}
	return (n * sign);
}