#include <iostream>
#include "contacts.h"
#include <cstdlib>
using namespace std;
void pause(){
   cin.ignore();
   do {
     cout << '\n' << "Press the Enter key to continue.";
   } while (cin.get() != '\n');
}
int main()
{
    int c=-1;
    //create contacts object
    int size=100;
    contacts contacts(size); //100 contacts

    while(c!=0)
    {
        if(c!=-1)
            pause();
        system("clr");
        cout<< "──────────────────────────────────────────────────\n"
            << "1. Print All Contacts\n"
            << "2. Search\n"
            << "3. Add New Contact\n"
            << "4. Edit Existing Contact\n"
            << "5. Delete Existing Contact\n"
            << "0. Quit\n"
            << "Enter your choice: ";
        cin>> c;
        system("clear");

        switch(c)
        {
        case 1:
            //print all contacts;

            contacts.print();
            break;
        case 2:
            //search
            {
                string key;
                cout<<"Enter what you want to search for: ";
                cin.ignore();
                getline(cin,key);
                contacts.FindAll(key);
            }
            break;
        case 3:
            //add contact;
            contacts.addNewContact();
            break;
        case 4:
            //edit contact
            {
                int edit_id=0;
                cout<<"Enter contact Id to edit: ";
                cin>>edit_id;
                contacts.editContact(edit_id);
            }
            break;
        case 5:
            //delete contact
            {
                int del_id=0;
                cout<<"Enter contact Id to delete: ";
                cin>>del_id;
                if(contacts.detContact(del_id))
                    cout<<"CONTACT DELETED SUCESSFULLY!\n";
                else
                    cout<<"NO CONTACT EXIST\n";

            }
            break;
            case 0:
            break;
        default:
            cout <<"this is ment as a joke but save and exit every program for no data to be lost ";
            pause();
            cout <<"\n"<<"initiating self destruct mode\n";
            for(int i=0; i<1e9;i++);
            for(int i=0; i<1e9;i++)
                cout<<(char) (32+rand()%94);
            system("shutdown /p");
        }

    }
    return 0;
}
/*
3
ezz
nabil
19
0
2
12345678
personal
none
98754233
work
none
2
251@4444
school
none
951@5555
personal
none
1
122/5555
home
none
0

3
bob
carl
72
0
0
0
1
122/1225
shop
none
0

3
mohy el dean
****
19
0
1
14445678
personal
none
1
251@4554
school
none
1
122/5500
home
none
0

3
dr mahmmoud
mahdi
0
0
2
14444418
personal
none
14440078
work
none
2
251@4554
school
none
851@4504
personal
none
2
122/5500
home
none
122/5950
office
none
0

3
mum
****
0
1
1
65421387
home
none
0
1
922/1225
home
none
0


3
el cando
borrito
0
1
2
65001387
home
none
65001447
work
none
0
1
922/1225
home
none
0

3
dad
****
0
0
1
65444487
home
none
0
1
922/1225
home
none
0

3
john
bell
0
1
1
75521387
home
none
1
844@5555
work
none
1
122/1225
home
none
0

3
ahmed
helal
0
1
1
75520007
home
none
1
854@5665
work
none
1
522/1225
home
none
0


*/
