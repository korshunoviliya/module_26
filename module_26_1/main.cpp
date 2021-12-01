#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

class Track {
private:
    std::string title;
    std::time_t recordingDuration;
    std::tm *dateCreation;

public:
    Track setPlayList(std::string str, std::time_t value) {
        Track temp;
        temp.title = str;
        temp.recordingDuration = value;
        std::time_t t = std::time(nullptr);
        std::tm *local = std::localtime(&t);
        temp.dateCreation = local;
        return temp;
    }
    void showInfo(Track &track) {
        std::cout  << track.title << "\n"
                   << std::asctime(track.dateCreation)
                   << track.recordingDuration << "\n\n";
    }
    std::string getTitle(){
        return title;
    }
    void addTrack(std::vector<Track> &track){
        std::cout << "Enter the title new track:";
        std::string str;
        std::cin >> str;
        std::cout << "Enter recording duration:";
        int value;
        std::cin >> value;
        Track temp = setPlayList(str, value);
        track.push_back(temp);
    }
};

class Player{
private:
    bool isPlay{false};

public:
    void play(std::vector<Track> &track) {
        if (!isPlay) {
            std::string titleTrack;
            std::cout << "Enter the title of the track: ";
            std::cin >> titleTrack;
            for (int i = 0; i < track.size(); ++i) {
                if (titleTrack == track[i].getTitle()) {
                    track[i].showInfo(track[i]);
                    isPlay = true;
                }
            }
        }
    }
    void pause(){
        if(isPlay){
            std::cout << "Pause\n";
            isPlay = false;
        }
    }
    void next(std::vector<Track> &track){
        int randomTrack = std::rand() % track.size();
        track[randomTrack].showInfo(track[randomTrack]);
        isPlay = true;
    }
    void stop(){
        if(isPlay) std::cout << "Stop!\n";
        isPlay = false;
    }
};

int main() {
    std::vector<Track> track;

    track.push_back(track[0].setPlayList("a", 10));
    track.push_back(track[1].setPlayList("b", 15));
    track.push_back(track[2].setPlayList("c", 20));
    track.push_back(track[3].setPlayList("d", 25));
    track.push_back(track[4].setPlayList("e", 30));

    Player player;

    std::string command;
    do{
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "play") player.play(track);
        else if (command == "add") track[track.size()].addTrack(track);
        else if (command == "pause") player.pause();
        else if (command == "next") player.next(track);
        else if (command == "stop") player.stop();
        else if (command == "exit") return 0;
        else std::cout << "Command is error! Try again!!!\n";
    }while(true);
}
