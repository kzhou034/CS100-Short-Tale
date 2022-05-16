#include <iostream>
#include "Character.hpp"
#include <string>
#include <unistd.h>
using namespace std;

int main(){

    string name = "";
        int answer;

    //beginning of the game: should have intro, name selection, character selection

    cout << "Welcome to Short Tale! The princess has been kidnapped, and you are the only hero strong enough to save her!" << endl;
    //sleep(2);
    cout << endl;
    cout << "First of all, what is your name?" << endl;
    cin >> name;
    cout << "I see. So your name is " << name << "?" << endl;
    cout << "Press 1 for Yes and 2 for No." << endl;
    cin >> answer;

    //if invalid answer is given
    while(answer != 1 && answer !=2){
       cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
       answer = 0;
       cin >> answer;
    }

    //if "No"
    while(answer == 2){
       cout << "I see. Once again, what is your name?" << endl;
       answer = 0;
       cin >> answer;
       while(answer != 1 && answer !=2){   //re-asks if invalid answer is given
          cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
          answer = 0;
          cin >> answer;
       }
    }
//sleep(2);
cout << "I see, so you're " << name << "!" << endl;
//sleep(2);
cout << "Well, " << name << ", I don't seem to remember what your class was. Can you please remind me?" << endl;
//sleep(2);
cout << "If I recall, you were a...";
//***********************end of beginning of the game
}
