/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:46:11 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/01 09:44:10 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	reverse_rot(t_stack	**stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
}

void	rra(t_stack	**a)
{
	reverse_rot(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack	**b)
{
	reverse_rot(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	**a, t_stack **b)
{
	reverse_rot(a);
	reverse_rot(b);
	write(1, "rrr\n", 4);
}
