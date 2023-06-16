/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:20 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/16 11:14:34 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	algo1(t_list **a, t_list **b, int divide, int total)
{
	int	i;
	int	j;
	int	amt;
    int total2;

	i = total / divide - 2;
	
	  while(i != -1){
        j=0;
            amt =chunck(total,i,divide);
        total2 = ft_lstsize((*a));
            
        while ((*a))
            {
            if(j == total2)
                break;
            if(amt >= (*a)->amount){
                pab(&(*a),&(*b),2);
            }
            else{
                rab(&(*a),1);
            }
            j++;
            }  
            i--;
        }
}

void	algo2(t_list **a, t_list **b, int jk, int k)
{
	while ((*a))
		pab(&(*a), &(*b), 2);
	jk = ft_lstsize((*b)) - 1;
	while ((*b))
	{
		k = distance((*b), jk);
		if ((*b)->amount == jk)
		{
			pab(&(*b), &(*a), 1);
			jk--;
		}
		else
		{
			if (k == 1)
				rab(&(*b), 2);
			else
				rrab(&(*b), 2);
		}
	}
}

void	algorithm(t_list **a, t_list **b, int divide)
{
	init((*a));
	calc((*a));
	if (divide < 25)
		divide = divide / 2;
	else
		divide = 25;
	if (ft_lstsize((*a)) <= 10)
	{
		sort(&(*a), &(*b));
		return ;
	}
	algo1(&(*a), &(*b), divide, ft_lstsize((*a)));
	algo2(&(*a), &(*b), 0, 0);
}

void	push_caller(t_list **a, int *status, char *argc[], int argv)
{
	t_list	*tmp;
	int		move;
	int i;

	i = 1;

	while (i < argv)
	{

		if (ft_strchr(argc[i], ' '))
		{
			tmp = split(argc[i],status);
			if (tmp == NULL)
				break ;
			ft_lstadd_back(&(*a), tmp);
		}
		else
		{
			if (checker(argc[i]) == 1)
				return ;
			move = ft_atoi(argc[i],status,1);
			tmp = ft_lstnew(move);
			ft_lstadd_back(&(*a), tmp);
		}
		i++;
	}
}

int	main(int argv, char *argc[])
{
	t_list	*a;
	t_list	*b;
	int status;
	
	status = 0;
	if (argv > 1)
	{
		a = NULL;
		b = NULL;
		push_caller(&(a), &status, argc, argv);
		if (same((a), status) == 0 && validate((a)) == 0 && status !=1)
			algorithm(&(a), &(b), ft_lstsize((a)));
		ft_lstclear(&(a), free);

	}

}
