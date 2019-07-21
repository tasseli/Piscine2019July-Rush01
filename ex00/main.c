/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatikka <tmatikka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:50:36 by tmatikka          #+#    #+#             */
/*   Updated: 2019/07/21 22:49:34 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	****use_your_brain(char ****container);
char	****read_input(char ****container, char **argv, int argc);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	****init_game(char ****container);
void	print_game(char ****game);

int		main(int argc, char **argv)
{
	int		i;
	char	****container;

	container = NULL;
	container = init_game(container);
	container = read_input(container, &argv[1], argc - 1);
	if (container == NULL)
		return (-1);
	i = 0;
	while (i < 42 * 100)
	{
		container = use_your_brain(container);
		++i;
	}
	print_game(container);
	return (0);
}
