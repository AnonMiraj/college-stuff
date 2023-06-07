#include <string>
#include <iostream>
using namespace std;

#ifndef EMAIL_H
#define EMAIL_H

class email
{
private:
        string m_email;
        string m_type;
        string m_description;
public:
        email();
        email(string,string,string);

        void setEmail(string);
        void setType(string);
        void setDescription(string);

        bool isMatched(string);

        void print();
};

#endif // EMAIL_H
