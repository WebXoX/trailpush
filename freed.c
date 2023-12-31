/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperinch <jperinch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:31:58 by jperinch          #+#    #+#             */
/*   Updated: 2023/06/15 15:30:26 by jperinch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freed(char **a)
{
	int	j;

	j = 0;
	while (a[j] != (void *)0)
	{
		free(a[j]);
		j++;
	}
	free(a);
}
