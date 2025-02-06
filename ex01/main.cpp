#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;
	bool		run = true;
	PhoneBook.show_instructions();
	while (run && std::getline(std::cin, command))
	{
		if(command.compare("ADD") == 0)
			PhoneBook.add_contact();
		else if(command.compare("SEARCH") == 0)
			PhoneBook.search();
		else if(command.compare("EXIT") == 0)
		{
			std::cout << "Thank you for using this PhoneBook" << std::endl;
			run = false;
		}
		command.clear();
		if (run)
			PhoneBook.show_instructions();
	}
	return (0);
}