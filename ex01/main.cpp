#include "PhoneBook.hpp"

#define YELLOW "\033[33m"
#define RESET  "\033[0m"
#define GREEN "\033[38;2;156;175;136m"


int	main(int ac, char *av[])
{
	if (ac != 1)
		return (1);
	(void)av;

	PhoneBook	PhoneBook;
	std::string	command;
	bool		run = true;
	std::cout << YELLOW << "Welcome to Awesome Phonebook :D" << RESET << std::endl;
	PhoneBook.show_instructions();
	while (run && std::getline(std::cin, command))
	{
		
		if(command.compare("ADD") == 0)
			PhoneBook.add_contact();
		else if(command.compare("SEARCH") == 0)
			PhoneBook.search();
		else if(command.compare("EXIT") == 0)
		{
			std::cout << GREEN <<"Thank you for using this PhoneBook" << GREEN <<std::endl;
			run = false;
		}
		else if (std::cin.eof()) // NEW: Check if EOF is detected
    	{
        	std::cout << "\nEOF detected. Exiting PhoneBook...\n";
        	exit(1);
    	}
		command.clear();
		if (run)
			PhoneBook.show_instructions();
		
	}
	return (0);
}