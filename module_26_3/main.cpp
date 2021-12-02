#include <iostream>
#include <string>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

class Window{
    int coordinateX{0};
    int coordinateY{0};
    int width{10};
    int height{10};

    bool checkInput() const{
        if (coordinateX < 0 || (coordinateX + width) > MAX_WIDTH ||
            coordinateY < 0 || (coordinateY + height) > MAX_HEIGHT ||
            width < 0 || height < 0) {
            std::cout << "Input is incorrect!\n";
            return false;
        }else return true;
    }

public:
    void move() {
        int tempX = coordinateX;
        int tempY = coordinateY;
        std::cout << "Enter new window coordinates\n";
        std::cout << "X:";
        std::cin >> coordinateX;
        std::cout << "Y:";
        std::cin >> coordinateY;
        if (!checkInput()){
            coordinateX = tempX;
            coordinateY = tempY;
        }
        std::cout << "Window coordinates.\n" <<
                     "X:" << coordinateX <<
                     "Y:" << coordinateY << std::endl;
    }
    void resize(){
        int tempWidth = width;
        int tempHeight = height;
        std::cout << "Enter new window size\n";
        std::cout << "Width:";
        std::cin >> width;
        std::cout << "Height:";
        std::cin >> height;
        if (!checkInput()){
            width = tempWidth;
            height = tempHeight;
        }
        std::cout << "Window size.\n" <<
                  "Width:" << width <<
                  "Height:" << height << std::endl;
    }
    void display() const{
        std::cout << std::endl;
        for (int i = 0; i < MAX_HEIGHT; ++i){
            for (int j = 0; j < MAX_WIDTH; ++j){
                if (j >= coordinateX && j < (coordinateX + width)
                    && i >= coordinateY && i < (coordinateY + height)) std::cout << "*";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    Window window;
    std::string command;
    do{
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "move") window.move();
        else if (command == "resize") window.resize();
        else if (command == "display") window.display();
        else if (command == "close") return 0;
        else std::cout << "Command is error! Try again!!!\n";
    }while(true);
}
