#include <iostream>
#include "Phonebook.h"
using namespace std;
int main()
{

    Phonebook * entry = new Phonebook();
    entry->loadFromfile(); 
    string number;
   
    number = entry->findNumber("Kashvi Ranjan");
    cout << "Number 1: " << number << endl;
    

    number = entry->findNumber("Ravi Ranjan");
    cout << "Number 2: " << number << endl;
    
    number = entry->findNumber("Yash Ranjan");
    cout << "Number 3: " << number << endl;
    delete entry;
}
