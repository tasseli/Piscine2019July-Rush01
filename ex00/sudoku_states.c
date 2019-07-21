/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_states.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnenonen <mnenonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:34:34 by mnenonen          #+#    #+#             */
/*   Updated: 2019/07/21 22:41:07 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	****reduce_by_certain_on_x(char ****container, int y);
char	****reduce_by_certain_on_y(char ****container, int x);
void	print_game(char ****container);
char	****init_game(char ****container);
void	putchar(char c);
void	putstr(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strcpy(char *str);
char	*str_minus_c(char *cell, char c);
char	*straddc_nocheck(char *str, char c);

char	****return_reduction_by_box(char *certains, char ****container,
		int x, int y)
{
	int i;

	i = 0;
	while (i < ft_strlen(certains))
	{
		if (ft_strlen((*container)[y][x]) > 1)
		{
			(*container)[y][x] = str_minus_c((*container)[y][x], certains[i]);
		}
		++i;
	}
	return (container);
}

char	****reduce_by_certain_in_box(char ****container, int x, int y)
{
	int		i;
	int		j;
	char	*certains;
	int		box_x;
	int		box_y;

	box_x = x / 3;
	box_y = y / 3;
	certains = malloc(10);
	certains = "";
	j = 0;
	while (j < 9)
	{
		i = 0;
		while (i < 9)
		{
			if ((j / 3 == box_y && i / 3 == box_x) &&
					ft_strlen((*container)[j][i]) == 1)
				certains = straddc_nocheck(certains, (*container)[j][i][0]);
			++i;
		}
		++j;
	}
	return (return_reduction_by_box(certains, container, x, y));
}

char	****return_using_your_brain(char ****container)
{
	int	y;
	int	x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			container = reduce_by_certain_in_box(container, x, y);
			++x;
		}
		++y;
	}
	return (container);
}

char	****use_your_brain(char ****container)
{
	int	y;
	int	x;

	y = 0;
	while (y < 9)
	{
		container = reduce_by_certain_on_x(container, y);
		++y;
	}
	x = 0;
	while (x < 9)
	{
		container = reduce_by_certain_on_y(container, x);
		++x;
	}
	return (return_using_your_brain(container));
}
