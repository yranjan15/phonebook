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
	    else if(number.size() != 10)
	    {
		cout << "Invalid phone number. Please retry operation with " <<
			"valid fields. " << endl;
            }

	    else
            {
		bool result = entry->insert(number, name);
		if(!result)
		{
		    cout << "Insertion Failed. Contact already exists " <<
			    "in phonebook." << endl;
		}

		else
                {
		   cout << "Inserted " + name + " into phonebook." << endl;
                }
            }
	}

	else if(input == "f")
	{
	    string name;
	    
	    cout << "Enter name of contact to find." << endl;

	    getline(cin, name);
	    
	    cout << entry->findNumber(name) << endl;
	}
    }

    delete entry;

}
