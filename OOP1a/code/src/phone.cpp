#include "phone.h"

phone::phone(){
}

phone::phone(string phone_number, string phone_type,string phone_description){
    setPhone(phone_number);
    setType(phone_type);
    setDescription(phone_description);
}

void phone::setPhone(string phone_number){
    m_phone = phone_number;
}
void phone::setType(string phone_type){
    m_type= phone_type;
}
void phone::setDescription(string phone_description){
    m_description = phone_description;
}

bool phone::isMatched(string key){
    return  (m_phone.compare(key)==0);
}

void phone::print(){
    cout << "Phone:\t " << m_phone << "\t\t Type: " << m_type <<"\t\t Description " << m_description << endl;
}
