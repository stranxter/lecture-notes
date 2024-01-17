#include <iostream>
#include <fstream>

struct PhoneContact
{
    //уникални имена
    char name[100];

    size_t nPhones;
    char **phoneNumbers;
};

PhoneContact readContact(std::istream &bookfile)
{
    PhoneContact contact;
    bookfile.getline(contact.name,100);

    bookfile >> contact.nPhones;
    contact.phoneNumbers = new char*[contact.nPhones];
    for(int i = 0; i < contact.nPhones; ++i)
    {   
        contact.phoneNumbers[i] = new char[30];
        bookfile >> contact.phoneNumbers[i];
    }
    bookfile.get();

    return contact;
}

void printContact(PhoneContact contact, std::ostream &out)
{
    out << std::endl;
    out << contact.name << std::endl;
    out << contact.nPhones;
    for(int i = 0; i < contact.nPhones; ++i)
    {
              out << " " << contact.phoneNumbers[i];
    }

}

void printAdressBook()
{
    std::ifstream bookfile ("phonebbok.phbkn");

    while(!bookfile.eof())
    {

        PhoneContact c = readContact(bookfile);
        printContact(c, std::cout);

    }

}

void addNewContact()
{
    std::cout << "Please enter a new contact below:\n";
    
    PhoneContact contact;
    contact = readContact(std::cin);
    
    std::ofstream bookfile ("phonebbok.phbkn", std::ios::app);

    printContact(contact,bookfile);

}


void addPhoneNumberToContact ()
{

}

void findContact ()
{

}

void editContact ()
{

}

void printMenu()
{
    std::cout << "Select on option:\n"
              << "1. Print all\n"
              << "2. Add new contact\n"
              << "3. Add phone nr to contact\n"
              << "4. Find contact\n"
              << "5. Edit contact\n"
              << "10. Exit\n"
              << "Enter you choice:";

}

int main()
{
    printMenu();
    int i;
    std::cin >> i; std::cin.get();
    while (i != 10)
    {
        switch(i)
        {
            case 1: printAdressBook(); 
            break;
            case 2: addNewContact();
            break;
            case 3: addPhoneNumberToContact();
            break;
            case 4: findContact();
            break;
            case 5: editContact();
            break;
        }
        printMenu();
        std::cin >> i; std::cin.get();
    }
    
    
}