/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouafik <rmouafik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:50:18 by rmouafik          #+#    #+#             */
/*   Updated: 2025/03/05 12:11:25 by rmouafik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = *stack;
	*stack = new;
}

void	check_sign(char **result, int *j, int *k, long *numbers)
{
	if ((result[*j][*k] == '+' || result[*j][*k] == '-'))
		(*k)++;
	if (!(result[*j][*k] >= '0' && result[*j][*k] <= '9'))
	{
		ft_putstr_fd("Error\n", 2);
		free_s(result);
		free(numbers);
		exit(1);
	}
}

void	free_s(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
}

void	check_duplicate(long *arr, int count)
{
	int		i;
	int		j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(arr);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	malloc_arr(int ac, char **str, char **result, long **numbers)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 1;
	while (i < ac)
	{
		result = ft_split(str[i], ' ');
		j = 0;
		while (result[j])
		{
			j++;
			count++;
		}
		free_s(result);
		i++;
	}
	*numbers = malloc((count + 1) * sizeof(long));
	if (!*numbers)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
