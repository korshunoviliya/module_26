#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Track {
private:
    std::string title;
    std::time_t recordingDuration;
    std::tm *dateCreation;

public:
    Track setPlayList(std::string const &str, std::time_t const &value) {
        Track temp;
        temp.title = str;
        temp.recordingDuration = value;
        std::time_t t = std::time(nullptr);
        std::tm *local = std::localtime(&t);
        temp.dateCreation = local;
        return temp;
    }

    std::string getTitle(){
        return title;
    }
    std::time_t getRecordingDuration(){
        return recordingDuration;
    }
    tm* getDateCreation(){
        return dateCreation;
    }

};

class Player{
private:
    bool isPlay{false};
    bool isPause{false};

    void showInfo(Track &track) {
        std::cout  << "Track name: " << track.getTitle() << std::endl
                   << "Date of creation: " << std::asctime(track.getDateCreation())
                   << "Play time: " << track.getRecordingDuration() << "\n";
    }

public:
    void play(std::vector<Track> &track) {
        if(track.empty()) return;
        if (isPause) {
            std::cout << "Pause OFF\n";
            std::cout << "Track playback resumed\n";
            isPause = false;
            return;
        }
        if (!isPlay) {
            std::string titleTrack;
            std::cout << "Enter the title of the track: ";
            std::cin >> titleTrack;
            for (int i = 0; i < track.size(); ++i) {
                if (titleTrack == track[i].getTitle()) {
                    showInfo(track[i]);
                    isPlay = true;
                    return;
                }
            }
            std::cout << "Couldn't find a track with this name\n";
        }
    }

    void addTrack(std::vector<Track> &track){
        std::cout << "Enter the title new track:";
        std::string str;
        std::cin >> str;
        std::cout << "Enter recording duration:";
        int value;
        std::cin >> value;
        Track temp = temp.setPlayList(str, value);
        track.push_back(temp);
    }

    void pause(std::vector<Track> &track){
        if (isPause) play(track);
        if(isPlay){
            std::cout << "Pause ON\n";
            isPlay = false;
            isPause = true;
        }
    }

    void next(std::vector<Track> &track){
        int randomTrack = std::rand() % track.size();
        showInfo(track[randomTrack]);
        isPlay = true;
    }

    void stop(){
        if(isPlay) std::cout << "Playback is stopped\n";
        isPlay = false;
    }
};

int main() {
    std::vector<Track> track;
    Track temp;
    track.push_back(temp.setPlayList("a", 10));
    track.push_back(temp.setPlayList("b", 15));
    track.push_back(temp.setPlayList("c", 20));
    track.push_back(temp.setPlayList("d", 25));
    track.push_back(temp.setPlayList("e", 30));

    Player player;

    std::string command;
    do{
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "play") player.play(track);
        else if (command == "add") player.addTrack(track);
        else if (command == "pause") player.pause(track);
        else if (command == "next") player.next(track);
        else if (command == "stop") player.stop();
        else if (command == "exit") return 0;
        else std::cout << "Command is error! Try again!!!\n";
    }while(true);
}

