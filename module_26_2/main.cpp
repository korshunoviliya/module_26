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

    int contactRequest(std::string &tempInput) {
        if (Contact::validationNumber(tempInput)) {
            for (int i = 0; i < contact.size(); ++i) {
                if (tempInput == contact[i].getNumber() ||
                    tempInput == contact[i].getName()) {
                    return i;
                }
            }
        }
        std::cout << "Contact with the same name or number was not found\n";
        return ERROR;

    }
public:

    void add(std::string &name, std::string &number)
    {
        Contact temp;
        temp.setName(name);
        temp.setNumber(number);
        if (Contact::validationNumber(number)) contact.push_back(temp);
        else std::cout << "The phone number was entered incorrectly! Try again!\n";
    }

    void call(std::string &tempInput)
    {
        int tempCall = contactRequest(tempInput);
        if (tempCall != ERROR){
            std::cout << "*****CALL!!!*****\n";
            std::cout << contact[tempCall].getNumber() << std::endl;
        }
    }

    void sms(std::string &tempInput){
        int tempSms = contactRequest(tempInput);
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
        if (command == "add"){
            std::cout << "Enter contact name:";
            std::string tempName;
            std::cin >> tempName;
            std::cout << "Enter the " << tempName << "'s phone number:";
            std::string tempNumber;
            std::cin >> tempNumber;
            telephone.add(tempName, tempNumber);
        }
        else if (command == "call") {
            std::string tempInput;
            std::cout << "Enter the name or number contact: ";
            std::cin >> tempInput;
            telephone.call(tempInput);
        }
        else if (command == "sms") {
            std::string tempInput;
            std::cout << "Enter the name or number contact: ";
            std::cin >> tempInput;
            telephone.sms(tempInput);
        }
        else if (command == "exit") return 0;
        else std::cout << "Input is not correct! Try again!!!\n";
    }
}
