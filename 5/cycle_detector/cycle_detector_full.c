/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_detector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:24:51 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/12 17:30:11 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

#include <stdio.h>

void	ft_lstdel(t_list **tmp)
{
	if ((*tmp)->next)
		ft_lstdel(&(*tmp)->next);
	free(*tmp);
	*tmp = NULL;
}

int		addr_cmp(t_list *cmp, const t_list *list)
{
	t_list	*data;

	while (cmp)
	{
		data = *((t_list**)&cmp->data);
		if (data == list)
			return (1);
		cmp = cmp->next;
	}
	return (0);
}

void	write_addr(t_list **data, const t_list *addr)
{
	*data = (t_list*)addr;
}

int		cycle_detector(const t_list *list)
{
	t_list	*tmp;
	t_list	*start;
	int		res;

	if (!list)
		return (0);
	tmp = (t_list*)malloc(sizeof(t_list));
	start = tmp;
	write_addr((t_list**)&tmp->data, list);
	while ((list = list->next))
	{
		tmp->next = NULL;
		if ((res = addr_cmp(start, list)))
			break ;
		tmp->next = (t_list*)malloc(sizeof(t_list));
		tmp = tmp->next;
		write_addr((t_list**)&tmp->data, list);
	}
	ft_lstdel(&start);
	return (res);
}

int		main(int ac, char **av)
{
	t_list	*lst;
	t_list	*start;
	int		i;
	t_list	*connect;

	if (ac != 3)
		return (0);
	lst = (t_list*)malloc(sizeof(t_list));
	start = lst;
	i = -1;
	while (++i < atoi(av[1]))
	{
		i == atoi(av[2]) - 1 ? connect = lst : 0;
		lst->next = (t_list*)malloc(sizeof(t_list));
		lst = lst->next;
	}
	lst->next = connect;
	printf("return = %d", cycle_detector(start));
	system("leaks -q cycle_detector");
	return (0);
}
