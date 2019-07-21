/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnenonen <mnenonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:01:41 by mnenonen          #+#    #+#             */
/*   Updated: 2019/07/21 21:31:10 by mnenonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

char	*straddc_nocheck(char *str, char c)
{
	char	*answer;
	int		i;
	int		strlen;

	strlen = ft_strlen(str);
	answer = malloc(10);
	answer[0] = c;
	i = 0;
	while (i < 9 && i < strlen)
	{
		answer[i + 1] = str[i];
		i++;
	}
	return (answer);
}

char	*ctostr(char c)
{
	char	*answer;

	answer = malloc(2);
	answer[0] = c;
	answer[1] = '\0';
	return (answer);
}

char	*str_minus_c(char *str, char c)
{
	char	*dest;
	int		a;
	int		len;
	int		c_came;

	c_came = 0;
	len = 0;
	dest = malloc(10 * sizeof(char));
	a = 0;
	while (*(str + a) != 0)
	{
		len++;
		a++;
	}
	a = 0;
	while (a < len)
	{
		if (*(str + a) != c)
			dest[a - c_came] = str[a];
		else
			c_came += 1;
		a++;
	}
	dest[a] = '\0';
	return (dest);
}
