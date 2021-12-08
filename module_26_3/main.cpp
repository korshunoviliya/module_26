#include <iostream>
#include <string>

class Window;

class Screen {
    const int maxWidth = 80;
    const int maxHeight = 50;
public:
    void display(Window &window);

    int getMaxWidth(){
        return maxWidth;
    }
    int getMaxHeight(){
        return maxHeight;
    }
};
class Window{
    int coordinateX{0};
    int coordinateY{0};
    int width{10};
    int height{10};

    bool checkInput() const{
        Screen tempScreen;
        if (coordinateX < 0 || (coordinateX + width) > tempScreen.getMaxWidth() ||
            coordinateY < 0 || (coordinateY + height) > tempScreen.getMaxHeight() ||
            width < 0 || height < 0) {
            std::cout << "Input is incorrect!\n";
            return false;
        }else return true;
    }

public:

    int getCoordinateX() {
        return coordinateX;
    }

    int getCoordinateY() {
        return coordinateY;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

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
                     " Y:" << coordinateY << std::endl;
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
                  " Height:" << height << std::endl;
    }
};

void Screen::display(Window &window){
    std::cout << std::endl;
    for (int i = 0; i < maxHeight; ++i){
        for (int j = 0; j < maxWidth; ++j){
            if (j >= window.getCoordinateX() && j < (window.getCoordinateX() +
                window.getWidth()) && i >= window.getCoordinateY() &&
                i < (window.getCoordinateY() + window.getHeight())) std::cout << "*";
            else std::cout << "0";
        }
        std::cout << std::endl;
    }
}

int main() {
    Window *window = new Window;
    Screen *screen = new Screen;
    std::string command;
    do{
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "move") window->move();
        else if (command == "resize") window->resize();
        else if (command == "display") screen->display(*window);
        else if (command == "close") {
            std::cout << "The window closed\n";
            delete window;
            delete screen;
            return 0;
        }
        else std::cout << "Command is error! Try again!!!\n";
    }while(true);
}
