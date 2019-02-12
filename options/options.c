/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:34:39 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/12 17:19:44 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	options(int ac, char **av, char *bytes)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == 'h')
				res = 1;
			j = 0;
			while (av[i][++j])
			{
				if (av[i][j] < 'a' || av[i][j] > 'z')
					return (-1);
				bytes[128 - av[i][j]] = '1';
			}
		}
	}
	return (res);
}

int			main(int ac, char **av)
{
	int		res;
	char	bytes[32];
	int		i;

	i = -1;
	while (++i < 32)
		bytes[i] = '0';
	i = -1;
	if (ac == 1 || (res = options(ac, av, bytes)) == 1)
		write(1, "options: abcdefjhijklmnopqrstuvwxyz", 35);
	else if (res == -1)
		write(1, "Invalid Option", 14);
	else
		while (++i < 4)
		{
			i ? write(1, " ", 1) : 0;
			write(1, &bytes[i * 8], 8);
		}
	write(1, "\n", 1);
	return (0);
}
