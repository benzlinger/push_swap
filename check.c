/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:34:45 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/12 12:39:15 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_ps(const char *str)
{
	int		count;
	long	isnegative;
	long	result;

	count = 0;
	result = 0;
	isnegative = 1;
	if (str[count] == '-')
	{
		count++;
		isnegative = -1;
	}	
	else if (str[count] == '+')
		count++;
	while (str[count] != '\0' && ft_isdigit(str[count]))
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	if (!ft_isdigit(str[count]) && str[count])
		return (0);
	return (result * isnegative);
}

static void	err_msg(char c)
{
	if (c == '1')
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	else if (c == '2')
		exit (0);
}

static void	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				err_msg('1');
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_input(int argc, char **argv)
{
	int		count;
	int		size;
	long	num;

	count = 1;
	size = 0;
	num = 0;
	if (argc <= 1)
		err_msg('2');
	check_dup(argv);
	while (argv[count])
	{
		size = ft_strlen(argv[count]);
		num = ft_atoi_ps(argv[count]);
		if (ft_strncmp(argv[count], "0", size) && num == 0)
			err_msg('1');
		else if (num < INT_MIN || num > INT_MAX)
			err_msg('1');
		count++;
	}
}
