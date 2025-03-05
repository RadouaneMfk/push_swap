/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:15:23 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/01 11:49:59 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_atoi(char **result, int *j, int *k, long *numbers)
{
	while (result[*j][*k] && (result[*j][*k] >= '0' && result[*j][*k] <= '9'))
		(*k)++;
	if (result[*j][*k] != '\0')
	{
		ft_putstr_fd("Error\n", 2);
		free_s(result);
		free(numbers);
		exit(1);
	}
	if (ft_atoi(result[*j]) == (2147483648))
	{
		ft_putstr_fd("Error\n", 2);
		free_s(result);
		free(numbers);
		exit(1);
	}
}

void	split_res(char ***result, char **str, int *j)
{
	*j = 0;
	*result = ft_split(*str, ' ');
	if (!*result[*j])
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	storing_stack(int count, t_stack **stack_a, long *numbers)
{
	count--;
	while (count >= 0)
		add_to_stack(stack_a, numbers[count--]);
	free(numbers);
}

void	parse_input(int ac,	char **str, t_stack **stack_a)
{
	char	**result;
	long	*numbers;

	result = NULL;
	int (i), (j), (k), (count);
	malloc_arr(ac, str, result, &numbers);
	count = 0;
	i = 1;
	while (str[i])
	{
		split_res(&result, &str[i], &j);
		while (result[j])
		{
			k = 0;
			check_sign(result, &j, &k, numbers);
			while (result[j][k])
				check_atoi(result, &j, &k, numbers);
			numbers[count++] = ft_atoi(result[j]);
			j++;
		}
		i++;
		free_s(result);
	}
	check_duplicate(numbers, count);
	storing_stack(count, stack_a, numbers);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
