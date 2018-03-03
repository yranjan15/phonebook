#include <iostream>
#include "Phonebook.h"
using namespace std;
int main()
{

    Phonebook * entry = new Phonebook();

    bool result = entry->insert("9494197017", "Yash Ranjan");

    if(result)
    {
	cout<<"Insertion has occurred and returned true" << endl;
    }

    result = entry->insert("9494197025", "Ravi Ranjan");

    if(result)
    {
	cout<<"Insertion 2 has occurred and returned true" << endl;
    }

    string retrieval = entry->findNumber("Yash Ranjan");
    cout << "Retrieval Result 1: " << endl;
    cout << retrieval << endl;


    retrieval = entry->findNumber("Ravi Ranjan");
    cout << "Retrieval Result 2: " << endl;
    cout << retrieval << endl;

    retrieval = entry->findNumber("Anupama Asthana");
    cout << "Retrieval Result 3: " << endl;
    cout << retrieval << endl;
    delete entry;
}
