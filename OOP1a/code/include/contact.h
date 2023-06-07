#include <ctime>
#include <string>
#include <iostream>
#include <algorithm>

#include "phone.h"
#include "email.h"
#include "address.h"

using namespace std;
#ifndef CONTACT_H
#define CONTACT_H


class contact
{
private:
        int m_id;
        string m_fname;
        string m_lname;
        int m_age;
        int m_gender;

        time_t m_added;
        tm * ltm;

        char * ldt;
        phone * m_phones;
        address * m_address;
        email * m_emails;

        int m_phone_size;
        int m_address_size;
        int m_email_size;

        int m_phone_count;
        int m_address_count;
        int m_email_count;
public:
        contact();
        virtual ~contact();

        void print();
        void readInput();
        void partialedit();
        void setContactId(int);
        void setFirstName(string);
        void setLastName(string);
        void setAge(int);
        void setGender(int);

        int getContactId();
        string getContactFname();
        bool findAny(string);

};

#endif // CONTACT_H
