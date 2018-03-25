#include "Phonebook.h"
#include <iostream>
#include <stack>
#include <iostream>
#include <fstream>

using namespace std;
PhoneNode::PhoneNode()
{
    parent = nullptr;
    isNumber = false;
    
    for(int i = 0; i < LEN; i++)
    {
	children[i] = nullptr;
    }
}

Phonebook::Phonebook()
{	
    root = nullptr;
}

bool Phonebook::insert(std::string p_number, std::string contact_name)
{
    int len = p_number.size();
    
    if(contacts.find(contact_name) != contacts.end())
    {
	return false;
    }

    if(root == nullptr)
    {
	root = new PhoneNode();
    }    

    PhoneNode * lastParent = root;

    for(int i = 0; i < len; i++)
    {
	char curr = p_number.at(i);

	int index = curr - '0';
	
	if(i != len - 1)
	{
	    if(lastParent->children[index] == nullptr)
	    {
	    	lastParent->children[index] = new PhoneNode();
	    	lastParent->children[index]->parent = lastParent;
	    }
	}

	else
	{
	    if(lastParent->children[index] == nullptr)
	    {
	    	lastParent->children[index] = new PhoneNode();
	    	lastParent->children[index]->parent = lastParent;
	    }
	    
	    lastParent->children[index]->isNumber = true;

	    //contacts.insert({contact_name, lastParent->children[index]});
	    contacts[contact_name] = lastParent->children[index];
	}

	lastParent = lastParent->children[index];
    } 

    return true;
}

bool Phonebook::find(std::string contact_name)
{
    if(contacts.find(contact_name) != contacts.end())
    {
	PhoneNode * curr = contacts.find(contact_name)->second;
	
	if(curr->isNumber)
	{
	    return true;
	}	
    }   

    return false; 
}

std::string Phonebook::findNumber(std::string contact_name)
{
    std::stack<int> digits;
    if(find(contact_name))
    {
	PhoneNode * curr = contacts.find(contact_name)->second;
	PhoneNode * curr_parent = curr->parent;

	while(curr != root)
	{
	    int num = 0;
	    for(int i = 0; i < LEN; i++)
	    {
		if(curr_parent->children[i] == curr)
		{
		    digits.push(i);
		    break;
		}
            } 

	    curr = curr_parent;
	    curr_parent = curr_parent->parent;
	}

	string output = "";
	
	while(!digits.empty())
	{
	    int digit = digits.top();
	    digits.pop();
	    output = output + to_string(digit);
	}
	
	return output;
    }

    else
    {
	return  "The specified contact name " + 
	contact_name + " is not in the phonebook";
    }
}

void Phonebook::deleteContact(std::string contact_name)
{
    if(find(contact_name))
    {
	contacts.erase(contact_name);
    }

    else
    {
	cout << "The specified contact " << contact_name 
	<< " does not exist in the phonebook." << endl;
    }
}
void Phonebook::deleteAll(PhoneNode * n)
{
    if(n == nullptr)
    {
	return;
    }

    else
    {
	for(int i = 0; i < LEN; i++)
	{
	    if(n->children[i] != nullptr)
	    {
		deleteAll(n->children[i]);
            }
	}

	delete n;
    }

}

Phonebook::~Phonebook()
{
    deleteAll(root);
}

void Phonebook::writeTofile()
{
    ofstream writeFile;
    writeFile.open("Contacts.txt");
    	
    vector<string> contact_names;    
    for(unordered_map<string, PhoneNode *>::iterator it = contacts.begin(); it != contacts.end(); ++it)
    {
	string name = it->first;
	//string number = findNumber(name); was causing issues, was trying to access contact
	//map while iterating throug the contact map
	contact_names.push_back(name);
    }       

   for(int i = 0; i < contact_names.size(); i++)
   {
	string name = contact_names.at(i);
	string number = findNumber(name);
	string result = name + "," + number + "\n";
	writeFile << result;
   }
     
}
