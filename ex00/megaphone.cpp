#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (i < argc)
	{
		x = -1;
		while (argv[i][++x] != '\0')
			std::cout << (char) std::toupper(argv[i][x]);	
		if (i+1 < argc)
			std::cout << " ";
		i++;
	}
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" ;
	std::cout << std::endl;
	return (0);
}