#include "PhoneBook.hpp"
#include <iostream>

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
	std::cout << "You can choose these 3 options:" << std::endl;
	std::cout << "1. ADD" << std::endl;
	std::cout << "2. SEARCH" << std::endl;
	std::cout << "3. EXIT" << std::endl;
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

void	PhoneBook::search(void) {
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
		if (this->_contacts[index-1].is_empty())
			std::cout << "Sorry, it appears that this contact is still empty" << std::endl;
		else
			this->_contacts[index-1].show_contact();
	}
	return;
}
