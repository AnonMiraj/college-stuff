#include <string>
#include <iostream>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H


class address
{
    public:
        address();
        address(string,string,string);

        void setAddress(string);
        void setType(string);
        void setDescription(string);

        bool isMatched(string);

        void print();
    protected:

    private:
        string m_address;
        string m_type;
        string m_description;
};

#endif // ADDRESS_H
