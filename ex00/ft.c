/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatikka <tmatikka@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 14:21:52 by tmatikka          #+#    #+#             */
/*   Updated: 2019/07/21 21:09:30 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		++str;
	}
}

char	*ft_strcpy(char *str)
{
	char	*cpy;
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (*(str + i))
	{
		++length;
		++i;
	}
	cpy = malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i < length)
	{
		cpy[i] = str[i];
		++i;
	}
	cpy[length] = '\0';
	return (cpy);
}

char	*ft_strncpy(char *str, int n)
{
	int		length;
	int		i;
	char	*cpy;

	cpy = malloc(10 * sizeof(char));
	cpy[9] = '\0';
	length = 0;
	i = 0;
	while (*(str + i))
	{
		++i;
		++length;
	}
	i = 0;
	while (i < length && i < n)
	{
		cpy[i] = str[i];
		++i;
	}
	return (cpy);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
