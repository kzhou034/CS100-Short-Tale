#include <iostream>
#include <string>
#include <limits>
#include "Character.hpp"

using namespace std;

int main() {
    int playerChoice = 0;
    string username = "";
    Character* playerRole;        
    
    while (playerChoice < 1 || playerChoice > 3) {
        cout << "choose option:" << endl;
        cout << "1: knight" << endl;
        cout << "2: mage" << endl;
        cout << "3: rogue" << endl << endl;

        cout << "enter a number and press enter to choose a role" << endl << endl;

        cin >> playerChoice;

        if (playerChoice < 1 || playerChoice > 3) {
            cout << "please enter a number between 1 and 3" << endl << endl;
            cin.clear();
            cin.ignore();
        }
    }

    if (playerChoice == 1) {
        cout << "what is your name?" << endl;
        cin >> username;
        playerRole = new Knight(username, "Knight", 15, 10, 10, 9, 8);
    }
    else if (playerChoice == 2) {
        cout << "what is your name?" << endl;
        cin >> username;
        playerRole = new Mage(username, "Mage", 15, 10, 10, 9, 8);
    }
    else if (playerChoice == 3) {
        cout << "what is your name?" << endl;
        cin >> username;
        playerRole = new Rogue(username, "Rogue", 15, 10, 10, 9, 8);
    }

    cout << endl << "stats: " << endl;
    cout << "name: " << playerRole->get_name() << endl;
    cout << "level: " << playerRole->get_level() << endl;
    cout << "class: " << playerRole->get_type() << endl;
    cout << "health: " << playerRole->get_health() << endl;
    cout << "attack: " << playerRole->get_attack() << endl;
    cout << "defense: " << playerRole->get_defense() << endl;
    cout << "resistance: " << playerRole->get_resistance() << endl;
    cout << "speed: " << playerRole->get_speed() << endl;

    // change in stats
    playerRole->add_level(1);
    playerRole->add_attack(3);
    playerRole->add_defense(2);
    playerRole->add_speed(-1);

    cout << endl << "stats modified. " << endl << endl << "updated stats: " << endl;
    cout << "name: " << playerRole->get_name() << endl;
    cout << "level: " << playerRole->get_level() << endl;
    cout << "class: " << playerRole->get_type() << endl;
    cout << "health: " << playerRole->get_health() << endl;
    cout << "attack: " << playerRole->get_attack() << endl;
    cout << "defense: " << playerRole->get_defense() << endl;
    cout << "resistance: " << playerRole->get_resistance() << endl;
    cout << "speed: " << playerRole->get_speed() << endl;

    cout << endl << "you attempted to pick a lock." << endl;
    cout << "." << endl;
    cout << "." << endl;
    cout << "." << endl;
    if (playerRole->pickLock()) {
        cout << "you were able to pick the lock. you quietly push the door open to the next room." << endl << endl;
    }
    else {
        cout << "you can't pick locks." << endl;
    }

    return 0;
}
