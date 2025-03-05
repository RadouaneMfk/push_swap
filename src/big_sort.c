/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:01:19 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/03 14:13:44 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_indices(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;
	int		i;

	head = *stack;
	while (head)
	{
		i = 0;
		tmp = *stack;
		while (tmp)
		{
			if (head->value > tmp->value)
				i++;
			tmp = tmp->next;
		}
		head->indice = i;
		head = head->next;
	}
}

int	max_indice(t_stack *stack)
{
	int	i;
	int	indice;

	i = 0;
	indice = stack_size(stack) - 1;
	while (stack)
	{
		if (stack->indice == indice)
			return (i);
		i++;
		stack = stack->next;
	}
	return (indice);
}

void	range_sort(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	size;

	min = 0;
	max = 0.048 * stack_size(*a) + 10;
	size = stack_size(*a);
	while (*a)
	{
		if ((*a)->indice > max)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->indice < min)
				rb(b);
			min++;
			max++;
		}
	}
}

void	back_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	i;

	set_indices(a);
	range_sort(a, b);
	i = max_indice(*b);
	while (*b)
	{
		size = stack_size(*b);
		if (i == 0)
			pa(a, b);
		else if (i <= (size / 2) && i != 0)
			rb(b);
		else if (i > (size / 2) && i != 0)
			rrb(b);
		i = max_indice(*b);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		back_to_a(a, b);
}
