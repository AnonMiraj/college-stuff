#include "email.h"

email::email(){
}

email::email(string email,string email_type,string email_desc)
{
    setEmail(email);
    setType(email_type);
    setDescription(email_desc);
}


void email::setEmail(string email){
    this->m_email = email;
}

void email::setType(string email_type){
    this->m_type = email_type;
}
void email::setDescription(string email_desc){
    this->m_description = email_desc;
}

void email::print() {
    cout << "Email:\t " << m_email << "\t\t Type: " << m_type <<"\t\t Description "<< m_description << endl;
}

bool email::isMatched(string key){
    return (m_email.compare(key)==0);
}
