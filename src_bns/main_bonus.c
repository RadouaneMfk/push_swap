/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 09:33:35 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/02 15:19:26 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_already_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	is_operator(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(move, "sa\n", 3) && move[3] == '\0')
		sa(a);
	else if (!ft_strncmp(move, "sb\n", 3) && move[3] == '\0')
		sb(b);
	else if (!ft_strncmp(move, "ss\n", 3) && move[3] == '\0')
		ss(a, b);
	else if (!ft_strncmp(move, "pa\n", 3) && move[3] == '\0')
		pa(a, b);
	else if (!ft_strncmp(move, "pb\n", 3) && move[3] == '\0')
		pb(a, b);
	else if (!ft_strncmp(move, "ra\n", 3) && move[3] == '\0')
		ra(a);
	else if (!ft_strncmp(move, "rb\n", 3) && move[3] == '\0')
		rb(b);
	else if (!ft_strncmp(move, "rr\n", 3) && move[3] == '\0')
		rr(a, b);
	else if (!ft_strncmp(move, "rra\n", 4) && move[4] == '\0')
		rra(a);
	else if (!ft_strncmp(move, "rrb\n", 4) && move[4] == '\0')
		rrb(b);
	else if (!ft_strncmp(move, "rrr\n", 4) && move[4] == '\0')
		rrr(a, b);
	else
		return (1);
	return (0);
}

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
}

void	read_move(char **move, t_stack **a, t_stack **b)
{
	while (1)
	{
		*move = get_next_line(0);
		if (!*move)
			break ;
		if (is_operator(*move, a, b) == 1)
		{
			free(*move);
			free_stacks(a);
			free_stacks(b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(*move);
	}
}

int	main(int ac, char *av[])
{
	char	*move;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit(0);
	parse_input(ac, av, &a);
	read_move(&move, &a, &b);
	if (is_already_sorted(&a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stacks(&a);
	free_stacks(&b);
	return (0);
}
