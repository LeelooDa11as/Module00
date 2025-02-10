#include "PhoneBook.hpp"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

PhoneBook::PhoneBook(void){
	//std::cout << "PhoneBook constructor" << std::endl;
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	//std::cout << "PhoneBook destructor" << std::endl;
	return;
}

void	PhoneBook::show_instructions(void) {
	std::cout << RED << "You can choose these 3 options:" << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << RESET << std::endl;
	return;
}

void	PhoneBook::add_contact(void) {
	this->_contacts[this->_index].set_first_name();
	this->_contacts[this->_index].set_last_name();
	this->_contacts[this->_index].set_nickname();
	this->_contacts[this->_index].set_phone_number();
	this->_contacts[this->_index].set_darkest_secret();
	if (this->_index < 7)
		this->_index++;
	else 
		this->_index = 0;
	return;
}

void PhoneBook::search(void) {
    int index;

    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < 8; i++) {
        if (this->_contacts[i].is_empty())
            break;
        std::cout << "|" << std::setw(10) << std::right << i + 1;
        this->_contacts[i].show_contact_list();
    }
    std::cout << "|-------------------------------------------|" << std::endl;

    // Main loop for accepting valid input
    while (true) {
        std::cout << "Choose a contact by index (1-8) or 0 to return to PhoneBook: ";
		std::cout << std::endl;
        std::cin >> index;
		if (std::cin.eof()) { 
            std::cin.clear(); // Limpia el error de EOF
            std::cin.ignore(10000, '\n');  // Discard invalid input (clear the input buffer)
            std::cout << "\nEOF detected. Please provide a valid input." << std::endl;
        }

        // Check for invalid input (non-numeric values)
        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(10000, '\n');  // Discard invalid input (clear the input buffer)
            std::cout << "Invalid input! Please enter a number between 0 and 8." << std::endl;
            //std::cout << std::endl;  // Blank line after the error message
            continue;  // Ask for input again
        }

        // Clear any extra characters in the input buffer
        std::cin.ignore(10000, '\n');

        // Validate if the index is within range
        if (index < 0 || index > 8) {
            std::cout << "Out of range! Please enter a number between 0 and 8." << std::endl;
            //std::cout << std::endl;  // Blank line after the error message
            continue;  // Ask for input again
        }

        break;  // If input is valid, exit the loop
    }

    // Show contact or error message if empty
    if (index != 0) {
        if (this->_contacts[index - 1].is_empty())
            std::cout << "Sorry, it appears that this contact is still empty" << std::endl;
		else
            this->_contacts[index - 1].show_contact();
    }
}


/*void	PhoneBook::search(void) {
	// std::string input;
	int	index;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (this->_contacts[i].is_empty())
			break;
		std::cout << "|" << std::setw(10) << std::right << i+1;
		this->_contacts[i].show_contact_list();
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "Choose a contact by index (1-8) or 0 to return to PhoneBook" << std::endl;
	//std::getline(std::cin, input);
	//index = std::atoi(input.c_str());  // Convert the string to an integer

	std::cin >> index;
	std::cin.ignore();
	while (index < 0 || index > 9)
	{
		std::cout << "Choose a contact by index (1-8) or 0 to return to PhoneBook" << std::endl;
		std::cin >> index;
	}
	if (index != 0)
	{
		if (index > 8)
			std::cout << "Sorry, you are trying to go out of range" << std::endl;
		else if (this->_contacts[index-1].is_empty())
			std::cout << "Sorry, it appears that this contact is still empty" << std::endl;
		else
			this->_contacts[index-1].show_contact();
	}
	return;
} */
