#include "contacts.h"

contacts::contacts(int contacts_size)
{
    m_size = contacts_size;
    m_contacts = new contact[m_size];
    m_contacts_sorted_ind = new int[m_size];


    m_count = 0;
}

contacts::~contacts()
{
    delete [] m_contacts;
}

void insert_sort(int arr[],int n,contact *m_contacts)
{
    for (int i=1;i<n;i++)
        {
        int key=arr[i];
        int j=i-1;
        while (j>=0&&m_contacts[arr[j]].getContactFname() > (m_contacts[key]).getContactFname())
        {
                arr[j+1]=arr[j];
                j--;

            }
            arr[j+1]=key;
        }
}


void contacts::addNewContact() {
    contact *new_contact = new contact();
    new_contact->setContactId(m_count+1);

    new_contact->readInput();
    m_contacts_sorted_ind[m_count]=m_count;
    m_contacts[m_count++] = * new_contact;
}

bool contacts::detContact(int contact_id) {


    bool deleted=false;
    if(m_count==0){
        return deleted;
    }

    for(int i=0;i<m_count;++i){
        if(m_contacts[i].getContactId()==contact_id){
            //delete contact
            char y=0;
            m_contacts[i].print();
            cout<<"if you want to confirm press [y]\n";
            cin>>y;
            if(!(y=='y'||y=='Y'))
                return false;
                for(int j=i;j<m_count;++j){
                    m_contacts[j+1].setContactId(j+1);
                    m_contacts[j]=m_contacts[j+1];
                }
        deleted=true;
        break;
        }
    }
    for(int i=0;i<m_count;++i){
        if(m_contacts_sorted_ind[i]==contact_id-1){
            //delete indices
             //   m_contacts_sorted_ind[i]= m_contacts_sorted_ind[m_count-1];
            //    m_contacts_sorted_ind[i]=i+1;
            for(int j=i;j<m_count;++j){
                    m_contacts_sorted_ind[j]=m_contacts_sorted_ind[j+1];
                }
        deleted=true;
        break;
            }
    }
    m_count--;
    return deleted;



}


void contacts::editContact(int contact_id) {
    if(m_count==0){
        cout<<"NO CONTACT EXIST\n";
        return ;
    }
    bool edited=false;
    for(int i=0;i<m_count;++i){
        if(m_contacts[i].getContactId()==contact_id){

            char y=0;
            m_contacts[i].print();
            cout<<"if you want to confirm press [y]\n";
            cin>>y;


            if(!(y=='y'||y=='Y'))
            {cout<<"CANCLED\n";
            return ;
            }
            m_contacts[i].partialedit();

            edited = true;
            break;
        }
    }

    if(edited){
        cout<<"CONTACT EDITED SUCESSFULLY\n";
    }else{
        cout<<"NO CONTACT EXIST\n";
    }

}
void contacts::print(){
    insert_sort(m_contacts_sorted_ind,m_count ,m_contacts);
    char choice='n';
    while( choice!='Q' && choice!='q' ){
        system("clear");

        if(m_count==0){
            cout<< "NO CONTACT FOUND\n";
            return;
        }

        if(choice=='n'||choice=='N')
            for(int i=0;i<m_count;++i){

                m_contacts[i].print();
            }
        else
            for(int i=0;i<m_count;++i){

                m_contacts[m_contacts_sorted_ind[i]].print();
            }

        cout<<"\n"<<((choice=='n'||choice=='N')? "show them sorted [S]" : "show them unsorted [N]"  )<<"\t\t go back to main menu [Q]\n";
        cin>>choice;
        }


}
void contacts::FindAll(string key){
    int Find_counter=0;
    for(int i=0;i<m_count;++i){
        if(m_contacts[i].findAny(key)){
            m_contacts[i].print();
            Find_counter++;
        }
    }
    if(Find_counter==0){
        cout<<"NO CONTACT FOUNDED\n";
    }else{
        cout<< Find_counter << " FOUNDED\n";
    }
}
