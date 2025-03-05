/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:27:58 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/03 14:12:56 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_stack **stack)
{
	int	first;
	int	second;

	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first > second)
		sa(stack);
}

void	sort_three(t_stack	**stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	if (first > third && third > second)
		ra(stack);
	else if (second > first && first > third)
		rra(stack);
	else if (second < first && first < third)
		sa(stack);
	else if (third < second && first < second)
	{
		rra(stack);
		sa(stack);
	}
}

void	find_min(t_stack **head, t_stack **min, int *i, int *k)
{
	*i = 0;
	*k = 0;
	while (*head)
	{
		(*i)++;
		if ((*head)->value < (*min)->value)
		{
			*min = *head;
			*k = *i;
		}
		*head = (*head)->next;
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	t_stack	*head;
	int		i;
	int		k;

	min = *stack_a;
	head = *stack_a;
	find_min(&head, &min, &i, &k);
	while ((*stack_a)->value != min->value)
	{
		if (k <= 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	t_stack	*head;
	int		i;
	int		k;

	min = *stack_a;
	head = *stack_a;
	find_min(&head, &min, &i, &k);
	while ((*stack_a)->value != min->value)
	{
		if (k <= 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
