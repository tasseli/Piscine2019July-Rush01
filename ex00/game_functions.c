/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnenonen <mnenonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:14:25 by mnenonen          #+#    #+#             */
/*   Updated: 2019/07/21 21:21:58 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

char	****init_game(char ****container)
{
	int		x;
	int		y;
	char	***chart;
	char	**line;
	char	*cell;

	y = 0;
	chart = malloc(9 * sizeof(char **));
	while (y < 9)
	{
		x = 0;
		line = malloc(9 * sizeof(char *));
		chart[y] = line;
		while (x < 9)
		{
			cell = malloc(10 * sizeof(char));
			cell = ft_strcpy("123456789");
			chart[y][x] = cell;
			++x;
		}
		++y;
	}
	container = malloc(sizeof(char ***));
	*container = chart;
	return (container);
}

void	print_game(char ****container)
{
	char	***chart;
	int		x;
	int		y;

	chart = *container;
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			ft_putstr(chart[y][x]);
			if (x != 8)
				ft_putchar(' ');
			++x;
		}
		++y;
		ft_putchar('\n');
	}
}
