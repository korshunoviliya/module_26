#include <iostream>
#include <string>
#include <vector>

#define ERROR -1

class Contact{
private:
    std::string name;
    std::string number;

public:
    static bool validationNumber(std::string &str){
        if((str.size() != 12) || (str[0] != '+') || (str[1] != '7')) return false;
        for (int i = 2; i < str.size(); ++i){
            if (!isdigit(str[i])) return false;
        }
        return true;
    }

    std::string getNumber(){
        return number;
    }

    std::string getName(){
        return name;
    }

    void setNumber(std::string &str){
        number = str;
    }

    void setName(std::string &str){
        name = str;
    }
};

class Telephone {
private:
    std::vector<Contact> contact;

    int contactRequest() {
        std::string tempInput;
        std::cout << "Enter the name or number contact: ";
        std::cin >> tempInput;
        if (Contact::validationNumber(tempInput)) {
            for (int i = 0; i < contact.size(); ++i) {
                if (tempInput == contact[i].getNumber()) {
                    return i;
                }
            }
        } else {
            for (int i = 0; i < contact.size(); ++i) {
                if (tempInput == contact[i].getName()) {
                    return i;
                }
            }
        }
        std::cout << "Contact with the same name or number was not found\n";
        return ERROR;
    }

public:
    void add() {
        Contact temp;
        std::string tempNumber;
        std::string tempName;
        do {
            std::cout << "Enter contact name:";
            std::cin >> tempName;
            temp.setName(tempName);
            std::cout << "Enter the " << tempName << "'s phone number:";
            std::cin >> tempNumber;
            temp.setNumber(tempNumber);

            if (Contact::validationNumber(tempNumber)) {
                contact.push_back(temp);
                return;
            } else std::cout << "The phone number was entered incorrectly! Try again!\n";
        } while (true);
    }

    void call(){
        int tempCall = contactRequest();
        if (tempCall != ERROR){
            std::cout << "*****CALL!!!*****\n";
            std::cout << contact[tempCall].getNumber() << std::endl;
        }
    }

    void sms(){
        int tempSms = contactRequest();
        std::string message;
        if (tempSms != ERROR){
            std::cout << "Enter SMS message: ";
            std::getline(std::cin,message);
            std::cin.ignore(32767, '\n');
            std::cout << "SMS message has been sent to the number "
                      << contact[tempSms].getNumber() << std::endl;
        }
    }
};

int main() {
    Telephone telephone;
    std::string command;
    while (true){
        std::cout << "Enter the command add, call, sms or exit: ";
        std::cin >> command;
        if (command == "add") telephone.add();
        else if (command == "call") telephone.call();
        else if (command == "sms") telephone.sms();
        else if (command == "exit") return 0;
        else std::cout << "Input is not correct! Try again!!!\n";
    }
}
