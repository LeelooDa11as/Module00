#include "Contact.hpp"

Contact::Contact(void) {
    //std::cout << "Contact constructor" << std::endl;
}

Contact::~Contact(void) {
    //std::cout << "Contact destructor" << std::endl;
}

void Contact::format_column(std::string text) {
    const int columnWidth = 10;
	std::string	copy;
    if (text.length() > columnWidth) {
        // Truncate the string and replace the last character with a dot
		copy = text.substr(0, columnWidth - 1) + '.';
    } else {
        copy = text;
    }
	std::cout << "|" << std::setw(10) << std::right << copy;
	return;
}

void    Contact::show_contact_list(void)  {
	format_column(this->_first_name);
	format_column(this->_last_name);
	format_column(this->_nickname);
	std::cout << '|' << std::endl ;
    return;
}

void    Contact::show_contact(void) const {
    std::cout << "First name: " <<this->_first_name << std::endl;
    std::cout << "Last name: " << this->_last_name << std::endl;
    std::cout << "Nickname: " << this->_nickname << std::endl;
    std::cout << "Phone number: " << this->_phone_number << std::endl;
    std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
    return;
}

void 	Contact::set_first_name(void) {
    std::string	info;

	std::cout << "Provide fist name:" << std::endl;
    std::getline(std::cin, info);
    while (info.empty())
    {
        std::cout << "Provide fist name:" << std::endl;
        std::getline(std::cin, info);
    }
    this->_first_name = info;
    return;
}

void 	Contact::set_last_name(void) {
    std::string	info;

	std::cout << "Provide last name:" << std::endl;
    std::getline(std::cin, info);
    while (info.empty())
    {
        std::cout << "Provide last name:" << std::endl;
        std::getline(std::cin, info);
    }
    this->_last_name = info;
    return;
}

void 	Contact::set_nickname(void) {
    std::string	info;

	std::cout << "Provide nickname:" << std::endl;
    std::getline(std::cin, info);
    while (info.empty())
    {
        std::cout << "Provide nickname:" << std::endl;
        std::getline(std::cin, info);
    }
    this->_nickname = info;
    return;
}


void 	Contact::set_phone_number(void) {
    std::string	info;

	std::cout << "Provide phone number:" << std::endl;
    std::getline(std::cin, info);
    while (info.empty())
    {
        std::cout << "Provide phone number:" << std::endl;
        std::getline(std::cin, info);
    }
    this->_phone_number = info;
    return;
}


void 	Contact::set_darkest_secret(void) {
    std::string	info;

	std::cout << "And your darkest secret:" << std::endl;
    std::getline(std::cin, info);
    while (info.empty())
    {
        std::cout << "And your darkest secret:" << std::endl;
        std::getline(std::cin, info);
    }
    this->_darkest_secret = info;
    return;
}

bool	Contact::is_empty(void) const {
	if (this->_first_name.empty()) 
		return (true);
	return (false);
}


