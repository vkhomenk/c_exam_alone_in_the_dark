/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:38:49 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/18 19:56:13 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int	i;

	if (nb == 1)
	{
		printf("1");
		return ;
	}
	i = 1;
	while (++i <= nb)
	{
		if (!(nb % i))
		{
			printf("%d", i);
			if (nb != i)
				printf("*");
			nb /= i;
			i--;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
