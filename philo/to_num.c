
#include "philosophers.h"

int	is_valid_input(char *str)
{
	int i;

	i = 0;
	if (!str || !str[0])
        return (0);
	if (str[i] == '-')
		print_error("Numbers should be positive!"); //change to return 0
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// static int	overflowing(long long n, int sign, char c, int *over_check)
// {
// 	if (sign == 1)
// 	{
// 		if (n > INT_MAX / 10
// 			|| (n == INT_MAX / 10 && (c - '0') > INT_MAX % 10))
// 		{
// 			*over_check = 1;
// 			return (*over_check);
// 		}
// 	}
// 	if (sign == -1)
// 	{
// 		if (n > -(long)INT_MIN / 10
// 			|| (n == -(long)INT_MIN / 10 && (c - '0') > -(long)(INT_MIN % 10)))
// 		{
// 			*over_check = 1;
// 			return (*over_check);
// 		}
// 	}
// 	return (0);
// }

long	to_num(const char *str, int *over_check)
{
	int			i;
	// int			sign;
	long long	n;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		// if (overflowing(n, sign, str[i], over_check) == 1)
		// 	return (overflowing(n, sign, str[i], over_check));
		n = (n * 10) + str[i] - 48;
		if (n > INT_MAX)
		{
			*over_check = 1;
			return (0);
		}
		i++;
	}
	return (n);
}
