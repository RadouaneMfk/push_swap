/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:26:24 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/02 13:58:41 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack)
{
	swap(stack);
}

void	sb(t_stack **stack)
{
	swap(stack);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
}
