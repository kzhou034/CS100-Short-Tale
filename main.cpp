#include <iostream>
#include "Character.hpp"
#include <string>
#include <unistd.h>
using namespace std;

int main(){

    string name = "";
    string answer;


    //beginning of the game: should have intro, name selection, character selection


    cout << "Welcome to Short Tale! The princess has been kidnapped, and there was nothing we could do to stop it!" << endl;
 //   sleep(1.5);
    cout << "She has been taken by hordes of monsters, across many lands." << endl;
 //   sleep(1.5);
    cout << "You are the only hero strong enough to save her!" << endl;
    cout << endl;
 //   sleep(3);
    cout << "Before you embark on your mission, what is your name?" << endl;
    cin >> name;
    cout << endl;
    cout << "I see. So your name is " << name << "?" << endl;
    cout << "Press 1 for Yes and 2 for No." << endl;
    cin >> answer;

    //if invalid answer is given
    while(answer != "1" && answer != "2"){
        cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
        answer = "";
        cin >> answer;
    }

    //if "No"
    while(answer == "2"){
        cout << "I see. Once again, what is your name?" << endl;
        name = "";
        cin >> name;
        cout << "I see. So your name is " << name << "?" << endl;       //rechecks name
        cout << "Press 1 for Yes and 2 for No." << endl;                //redoes confirmation line
        answer = "";
        cin >> answer;
        while(answer != "1" && answer != "2"){   //re-asks if invalid answer is given
            cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
            answer = "";
            cin >> answer;
        }
    }

    // connecting name creation to class selection
//    sleep(1);
    cout << endl;
    cout << "I see, so you're " << name << "!" << endl;
//    sleep(2);
    cout << "Well, " << name << ", I don't seem to remember what your class was. Can you please remind me?" << endl;
//    sleep(3);
    cout << "If I recall, you were a..." << endl;
//    sleep(4);
    cout << endl;
    cout << "I'm sorry, what class were you again?" << endl;
//    sleep(1.5);

    //class selection output
    cout << "Options:" << endl;
    cout << "1: I am a chivalrous knight. I am balanced and an all-rounder. (Press 1 to be assigned Knight class)" << endl;
//    sleep(3);
    cout << endl;
    cout << "2: I am a wise mage. I prefer mana and magic attacks. (Press 2 to be assigned the Mage class)" << endl;
//    sleep(3);
    cout << endl;
    cout << "3: I am a swift rogue. I boast high speed and attack. (Press 3 to be assigned the Rogue class)" << endl;
    cout << endl;
//    sleep(3);
    cout << "PLEASE NOTE: Once you make your decision, there is no going back or changing your mind." << endl;

    //class selection input
    answer = "";
    cin >> answer;

    Character* playerClass = new Knight(name, "Knight", 10, 6, 8, 6, 4);

    //knight class selection
    if (answer == "1") {
        cout << "I see. So you are a knight!" << endl;
    }
    //mage class selection
    else if (answer == "2") {
        cout << "I see. So you are a mage!" << endl;
	delete playerClass;
	playerClass = new Mage(name, "Mage", 7, 8, 3, 4, 6);
    }
    //rogue class selection
    else if (answer == "3") {
        cout << "I see. So you are a rogue!" << endl; 
	delete playerClass;
	playerClass = new Rogue(name, "Rogue", 6, 8, 3, 2, 8);
    }
    else{
        while(answer != "1" && answer != "2" && answer != "3"){   //re-asks if invalid answer is given
            cout << "That doesn't seem to be a valid answer. Please try again." << endl;
            answer = "";
            cin >> answer;
        }
    }
//    sleep(1);
    cout << endl;
    cout << "Kevin the " << playerClass->get_type() << "!" << endl;
    cout << "I entrust you with saving the princess. Please return her safely!" << endl;

//    sleep(2);

    cout << "Stage 1: The Beginning." << endl;
    
    //***********************end of beginning of the game
    delete playerClass;

    return 0;
}
