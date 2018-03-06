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

    result = entry->insert("9493315336", "Kashvi Ranjan");

    if(result)
    {
	cout<<"Insertion 3 has occurred and returned true" << endl;
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

    retrieval = entry->findNumber("Kashvi Ranjan");
    cout << "Retrival Result 4: " << endl;
    cout << retrieval << endl;


    //deleting one object that exists in the trie
    entry->deleteContact("Yash Ranjan");
    retrieval = entry->findNumber("Yash Ranjan");
    cout << "Retrieval Result 5: " << endl;
    cout << retrieval << endl;

    //check that none of the other numbers have been affected
    // by the deletion
    retrieval = entry->findNumber("Ravi Ranjan");
    cout << "Retrieval Result 6: " << endl;
    cout << retrieval << endl;

    retrieval = entry->findNumber("Anupama Asthana");
    cout << "Retrieval Result 7: " << endl;
    cout << retrieval << endl;

    retrieval = entry->findNumber("Kashvi Ranjan");
    cout << "Retrival Result 8: " << endl;
    cout << retrieval << endl;
    
    delete entry;
}
