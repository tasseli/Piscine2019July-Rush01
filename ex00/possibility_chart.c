//typedef "123456789" clueless;

#include <stdlib.h>

void ft_putstr(char *str);
void ft_putchar(char c);

char *ft_strcpy(char *str)
{
	char *cpy;
	int length;
	int i;

	i = 0;
	length = 0;
	while (*(str+i))
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

//void test_teleportation(int *trial)
//{
//	trial = malloc(int*)

char ****test_init(char ****container)
{
	
	int x;
	int y;
//	char ****container;
	char ***chart;
	char **line;
	char *cell;
	
	chart = malloc(sizeof(char ***));
	line = malloc(sizeof(char **));
	cell = malloc(2*sizeof(char *));
	cell = ft_strcpy("a");
	line = &cell;
	chart = &line;
	container = &chart;
	return container;
}

char ****init_game(void)
{
	int x;
	int y;
	char ****container;
	char ***chart;
	char **line;
	char *cell;

	y = 0;
	chart = malloc(10 * sizeof(char **));
	while (y < 9)
	{
		x = 0;
		line = malloc(10 * sizeof(char *));
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

void print_game(char ****container)
{
	char ***chart;
	int x;
	int y;

	chart = *container;
	y = 0;
	while (y < 9)
	{
		x = 0;
		while (y < 9)
		{
			ft_putstr(chart[y][x]);
			ft_putchar(' ');
			++x;
		}
		++y;
		ft_putchar('\n');
	}
}
