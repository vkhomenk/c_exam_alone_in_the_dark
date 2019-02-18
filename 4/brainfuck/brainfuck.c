/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:33:01 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/18 18:28:04 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	move_index(char **tmp)
{
	int		direction;
	int		count;
	char	*str;
	int		i;

	str = *tmp;
	i = 0;
	direction = str[i] == '[' ? 1 : -1;
	count = 1;
	while (i += direction)
	{
		if (str[i] == '[')
			count += direction;
		else if (str[i] == ']')
			count -= direction;
		if (!count)
		{
			*tmp += i;
			return ;
		}
	}
}

int		main(int ac, char **av)
{
	char	*ptr;

	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ptr = (char*)malloc(2048);
	while (*av[1])
	{
		if (*av[1] == '+')
			++*ptr;
		else if (*av[1] == '-')
			--*ptr;
		else if (*av[1] == '>')
			ptr++;
		else if (*av[1] == '<')
			ptr--;
		else if (*av[1] == '.')
			write(1, ptr, 1);
		else if ((*av[1] == '[' && !*ptr) || (*av[1] == ']' && *ptr))
			move_index(&av[1]);
		++av[1];
	}
	return (0);
}
