#include <iostream>
#include <string.h>
#include <yaml-cpp/yaml.h>
#include "alpha2int.h"

int getRoomIndex(YAML::Node &rooms, std::string roomID);
void describeRoom(YAML::Node &rooms, std::string roomID, bool full);
void prompt();

int main(int argc, char** argv) {

    YAML::Node rooms = YAML::LoadFile("rooms.yml");
    struct character {
        std::string currentRoom;
        std::string previousRoom;
    };

    character Player;
    Player.currentRoom = "cave_entrance";

    bool exitGame = 0;
    while ( exitGame != 1 ) {
        describeRoom(rooms, Player.currentRoom, true);
        prompt();
    }
    return 0;
}

int getRoomIndex(YAML::Node &rooms, std::string roomID) {
    for ( int i = 0; rooms[i]; i++ ) {
        if ( rooms[i]["id"].as<std::string>() == roomID ) {
            return i;
        }
    }
    return -1;
}

void describeRoom(YAML::Node &rooms, std::string roomID, bool full) {
    switch (full) {
        case true:
            std::cout << rooms[getRoomIndex(rooms, roomID)]["long_desc"].as<std::string>();
            break;
        default:
            std::cout << rooms[getRoomIndex(rooms, roomID)]["short_desc"].as<std::string>();
            break;
    }
    
    return;
}

void prompt() {
    std::string inputString;
    std::cout << "> ";
    std::cin >> inputString;
    
}