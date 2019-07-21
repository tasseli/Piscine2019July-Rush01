/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnenonen <mnenonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:51:16 by mnenonen          #+#    #+#             */
/*   Updated: 2019/07/21 22:48:42 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strncpy(char *str, int n);
char	*str_minus_c(char *cell, char c);
char	*right_answer(char *cell, char c);
char	*ctostr(char c);

char	*extract_token(char *str)
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (*(str + i))
	{
		++i;
		++length;
	}
	if (length == 9)
	{
		return (str);
	}
	else if (length == 11)
	{
		return (ft_strncpy(str + 1, 9));
	}
	return ("ERROR\n");
}

char	****update_on_input(char ****container, char *input_line, int line_y)
{
	int		debug;
	char	*cell;
	int		i;

	debug = 0;
	i = 0;
	while (i < 9)
	{
		if (debug)
		{
			ft_putstr("IL: ");
			ft_putstr(input_line);
			ft_putchar('\n');
		}
		if (input_line[i] >= 49 && input_line[i] <= 57)
		{
			cell = ctostr(input_line[i]);
			free((*container)[line_y][i]);
			(*container)[line_y][i] = cell;
		}
		++i;
	}
	return (container);
}

char	****read_input(char ****container, char **argv, int argc)
{
	int i;

	i = 0;
	if (argc == 9)
		while (i < 9)
		{
			container = update_on_input(container, extract_token(argv[i]), i);
			++i;
		}
	else
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	return (container);
}
