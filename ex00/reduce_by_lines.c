/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_by_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnenonen <mnenonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:16:37 by mnenonen          #+#    #+#             */
/*   Updated: 2019/07/21 22:21:18 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	****return_reduction_by_x(char *certains, char ****container, int y)
{
	int		x;
	int		i;

	x = 0;
	while (x < 9)
	{
		i = 0;
		while (i < ft_strlen(certains))
		{
			if (ft_strlen((*container)[y][x]) > 1)
			{
				(*container)[y][x] = str_minus_c((*container)[y][x],
						certains[i]);
			}
			++i;
		}
		++x;
	}
	return (container);
}

char	****reduce_by_certain_on_x(char ****container, int y)
{
	int		x;
	char	*certains;

	certains = malloc(10);
	certains = "";
	x = 0;
	while (x < 9)
	{
		if (ft_strlen((*container)[y][x]) == 1)
		{
			certains = straddc_nocheck(certains, (*container)[y][x][0]);
		}
		++x;
	}
	return (return_reduction_by_x(certains, container, y));
}

char	****return_reduction_by_y(char *certains, char ****container, int x)
{
	int		y;
	int		i;

	y = 0;
	while (y < 9)
	{
		i = 0;
		while (i < ft_strlen(certains))
		{
			if (ft_strlen((*container)[y][x]) > 1)
			{
				(*container)[y][x] = str_minus_c((*container)[y][x],
						certains[i]);
			}
			++i;
		}
		++y;
	}
	return (container);
}

char	****reduce_by_certain_on_y(char ****container, int x)
{
	int		y;
	char	*certains;

	certains = malloc(10);
	certains = "";
	y = 0;
	while (y < 9)
	{
		if (ft_strlen((*container)[y][x]) == 1)
		{
			certains = straddc_nocheck(certains, (*container)[y][x][0]);
		}
		++y;
	}
	return (return_reduction_by_y(certains, container, x));
}
