#include "contact.h"
#include <string>
using namespace std;

#ifndef CONTACTS_H
#define CONTACTS_H


class contacts
{
    private:
        int m_count;
        int m_size;
        contact * m_contacts;
        int  * m_contacts_sorted_ind;

    public:
        contacts(int);
        virtual ~contacts();

        void addNewContact();
        bool detContact(int);
        void editContact(int);
        void print();
        void FindAll(string);

};

void insert_sort(int *,int,contact*);

#endif // CONTACTS_H
