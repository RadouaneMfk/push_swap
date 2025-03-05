/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:46:46 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/02 13:59:47 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	last = *stack;
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void	ra(t_stack	**a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}
