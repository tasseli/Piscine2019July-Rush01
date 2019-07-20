#include <stdlib.h> 

void ft_putstr(char *str);
void ft_putchar(char c);
char ****init_game(void);
char ****test_init(char ****);
void print_game(char ****game);

int main(int argc, char **argv)
{
	int i;
	char ***sudoku_chart;
	char ****container;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		++i;
	}
//	container = init_game();
//	print_game(container);
	container = malloc(sizeof(char ***));
	sudoku_chart = *test_init(container);
	ft_putchar(sudoku_chart[0][0][0]);
//	sudoku_chart = *container;
	return (0);
}
