#include "Contact.hpp"

Contact::Contact() {
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->number = "";
	this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->number = number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name(void) const
{
	return (this->first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->last_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->nickname);
}

std::string Contact::get_number(void) const
{
	return (this->number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->darkest_secret);
}
