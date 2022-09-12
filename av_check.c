#include "philo.h"

int	ft_atoi(char *str)
{
	long long	ref;
	int			i;

	i = 0;
	ref = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (FALSE);
		str++;
	}
	while (str[i])
	{
		if (ref > INT_MAX || ref < INT_MIN || !(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		ref = ref * 10 + (str[i] - '0');
		i++;
	}
	if (i == 0)
		return (FALSE);
	return (ref);
}

int	av_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) == FALSE)
		{
			printf("%s", av[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}