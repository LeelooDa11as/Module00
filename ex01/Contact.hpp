#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
    public:
        Contact(void);
        ~Contact(void);

        //setters
        void    set_first_name(void);
        void    set_last_name(void);
        void    set_nickname(void);
        void    set_phone_number(void);
        void    set_darkest_secret(void);
        
        //show all information of one contact
        void    show_contact(void) const;
        //shows the whole list of saved contacts
        void    show_contact_list(void);
        //additional functions
        bool    is_empty(void) const;

        void format_column(std::string text);


    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
};

#endif