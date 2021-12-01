#include <iostream>
#include <string>
#include <vector>

#define ERROR -1

class PhoneBook{
private:
    std::string name;
    std::string number;

    static bool validationNumber(std::string &str){
        if((str.size() != 12) || (str[0] != '+') || (str[1] != '7')) return false;
        for (int i = 2; i < str.size(); ++i){
            if (!isdigit(str[i])) return false;
        }
        return true;
    }

    friend class Telephone;
};

class Telephone {
private:
    PhoneBook temp;
    std::vector<PhoneBook> phoneBook;

    int contactRequest() {
        std::string tempInput;
        std::cout << "Enter the name or number contact: ";
        std::cin >> tempInput;
        if (PhoneBook::validationNumber(tempInput)) {
            for (int i = 0; i < phoneBook.size(); ++i) {
                if (tempInput == phoneBook[i].number) {
                    return i;
                }
            }
        } else {
            for (int i = 0; i < phoneBook.size(); ++i) {
                if (tempInput == phoneBook[i].name) {
                    return i;
                }
            }
        }
        std::cout << "Contact with the same name or number was not found\n";
        return ERROR;
    }

public:
    void add() {
        do {
            std::cout << "Enter contact name:";
            std::cin >> temp.name;
            std::cout << "Enter the " << temp.name << "'s phone number:";
            std::cin >> temp.number;
            if (PhoneBook::validationNumber(temp.number)) {
                phoneBook.push_back(temp);
                return;
            } else std::cout << "The phone number was entered incorrectly! Try again!\n";
        } while (true);
    }

    void call(){
        int tempCall = contactRequest();
        if (tempCall != ERROR){
            std::cout << "*****CALL!!!*****\n";
            std::cout << phoneBook[tempCall].number << std::endl;
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
                << phoneBook[tempSms].number << std::endl;
        }
    }
};

int main() {
    PhoneBook phonebook;
    Telephone telephone;

    std::string command;
    while (true){
        std::cout << "Enter the command add, call, sms or exit: ";
        std::cin >> command;
        if (command == "add") telephone.add();
        else if (command == "call") telephone.call();
        else if (command == "sms") telephone.sms();
        else if (command == "exit") return 0;
    }
}
