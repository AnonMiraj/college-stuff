#include <string>
#include <iostream>
using namespace std;

#ifndef PHONE_H
#define PHONE_H


class phone
{
    private:
        string m_phone;
        string m_type;
        string m_description;

    public:
        phone();
        phone(string,string,string);

        void setPhone(string);
        void setType(string);
        void setDescription(string);

        bool isMatched(string);

        void print();

};

#endif // PHONE_H
