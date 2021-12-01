#include <iostream>
#include <string>

class TelephoneNumber{
    std::string number;
public:
    bool validationNumber(){
        if(number.size() != 12 || (number[0] != '+') || (number[1] != '7')) return false;
        for (int i = 2; i < number.size(); ++i){
            if (!isdigit(number[i])) return false;
        }
        return true;
    }

};

class PhoneBook{
private:
    std::string name;
    std::string number;
public:
    bool validationNumber(){
        if(number.size() != 12 || (number[0] != '+') || (number[1] != '7')) return false;
        for (int i = 2; i < number.size(); ++i){
            if (!isdigit(number[i])) return false;
        }
        return true;
    }
};
class Telephone{

};

int main() {

    return 0;
}
