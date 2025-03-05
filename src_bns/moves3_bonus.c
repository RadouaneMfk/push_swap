/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:46:11 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/02 13:59:53 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
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
}

void	rrb(t_stack	**b)
{
	reverse_rot(b);
}

void	rrr(t_stack	**a, t_stack **b)
{
	reverse_rot(a);
	reverse_rot(b);
}
