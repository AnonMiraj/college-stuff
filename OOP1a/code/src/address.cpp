#include "address.h"

address::address(){

}
address::address(string add,string add_type,string add_desc)
{
    setAddress(add);
    setType(add_type);
    setDescription(add_desc);
}

void address::setAddress(string add){
    this->m_address = add;
}

void address::setType(string add_type){
    this->m_type = add_type;
}
void address::setDescription(string add_desc){
    this->m_description = add_desc;
}

void address::print(){
    cout << "Address:\t "<< m_address << "\t\t Type: " << m_type <<"\t\t Description "<< m_description << endl;
}

bool address::isMatched(string key) {
    return  (m_address.compare(key)==0);
}
