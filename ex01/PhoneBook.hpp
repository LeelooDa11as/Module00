#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

	//methods for 3 options
	void	show_instructions(void);
	void	add_contact(void);
	void	search(void);
	

private:
	Contact _contacts[8];
	int		_index;
};

#endif