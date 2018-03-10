#include <iostream>
#include "Phonebook.h"
using namespace std;
int main()
{
    Phonebook * entry = new Phonebook();

    bool done = false;

    while(!done)
    {
	cout << "Select the phonebook operation to perform below: " << endl;

	cout << "i) Insert Contact r) Remove Contact f) find Contact " << endl;
	cout << "s) save phonebook q) quit" << endl;

	string input = "";
	getline(cin, input);

	cout << "Input: " << input << endl;

	if(input == "q")
	{
	    done = true;
	}

	else if(input == "i")
	{
	    string name;
	    string number;
	    
	    cout << "Enter new phonebook contact name. " << endl;

	    getline(cin, name);

	    cout << "Enter 10 digit phone number for new contact. " << endl;

	    getline(cin, number);
	    //cout << number << endl;
	    //cout << name << endl;	    
            if(number[10] != 0)
	    {	
		number[10] = 0;
		cout << "Invalid phone number. Please retry operation with " <<
			"valid fields. " << endl;
            }
	    if(number.size() != 10)
	    {
		cout << "Invalid phone number. Please retry operation with " <<
			"valid fields. " << endl;
            }
	}
    }

    delete entry;

}
