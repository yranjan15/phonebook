/*
Yash Ranjan phonebook application
*/

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <vector>
#include <string>
#include <unordered_map>
#define LEN 10

class PhoneNode
{
    public:
	PhoneNode();
	bool isNumber;
	PhoneNode * parent;
	PhoneNode * children[LEN];	
};

class Phonebook
{
    public:
    	//Create a phone book that uses a Trie backend
    	Phonebook();
    
    	//insert a phone number into the trie
    	bool insert(std::string p_number, std::string contact_name);
    
    	//find a phone number in the trie
    	bool find(std::string contact_name);
	
	std::string findNumber(std::string contact_name);

	void deleteContact(std::string contact_name);

	void writeTofile();

	void loadFromfile();
    	~Phonebook();

    private:
	PhoneNode * root;
	std::unordered_map<std::string, PhoneNode *> contacts;
	void deleteAll(PhoneNode * n);
};


#endif
