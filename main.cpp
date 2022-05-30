#include <iostream>
#include <string>
#include <unistd.h>
#include "Character.hpp"
using namespace std;

void PrintChapter1(){
  cout << "\nStage 1: The Beginning." << endl;


    cout << "Leaving your hometown in pursuit of the Princess, you trek across the long roads across the mountains with your horse." << endl;
    sleep(1.5);
    cout << "While passing by an abandoned settlement, you are attacked by a wild monkey." << endl;
    sleep(3);

    bool isVictory = true;
    if(isVictory){
      cout <<  "You defeat the monkey." << endl;
    }
    else{
      cout << "You are defeated by the monkey." << endl;
    }

    sleep(10);
    system("clear");
}

void PrintChapter2(){
  cout << "\nStage 2" << endl;


    cout << "With your first victory in hand, you continue down the long mountain roads." << endl;
    sleep(1.5);
    cout << "At the end of the path is a small brush of trees. You hear sounds of grunts and metal clanging, and run into the brush to investigate." << endl;
    sleep(1.5);
    cout << "In a small clearing, you find a knight, struggling to fight off a duo of goblins." << endl;
    sleep(1.5);
    cout << "You step in to help the knight." << endl;
    sleep(3);

    bool isVictory = true;
    if(isVictory){
      cout <<  "You defeat the goblin." << endl;
    }
    else{
      cout << "You are defeated by the goblin." << endl;

    }


    sleep(10);
    system("clear");
}

void PrintChapter3(){
  cout << "\nStage 3" << endl;
    string answer;

    cout << "The knight greets you in thanks, telling you that he had been separated from his patrol group." << endl;
    sleep(1.5);
    cout << "He explains the increase in monster activity has demanded more frequent and thorough patrols through the area. " << endl;
    sleep(1.5);
    cout << "He gives his thanks again, and you go on your own ways..\n" << endl;
    sleep(1.5);
    cout << "Past the trees, you find a small town with a traveling merchant." << endl;

    sleep(1.5);
    cout << "You thank the merchant, and continue on your way." << endl;
    sleep(1.5);
    cout << "At the edge of the town, you hear a small commotion in an alleyway. Do you want to investigate?" << endl;
    cout << "Press 1 to investigate." << endl;
    cout << "Press 2 to continue on your way." << endl;
    sleep(1.5);
    cin >> answer;
    if(answer == "1"){
      cout << "In the alleyway, you find two scavengers fighting each other over a small chest. Upon seeing you, however, both flee." << endl;
      sleep(1.5);
      cout << "Perhaps they thought you were a knight." << endl;
      sleep(1.5);
      cout << "Picking up the chest, you find that it has a small lock. Do you want to lockpick?" << endl;
      sleep(1.5);
      cout << "Press 1 to lockpick." << endl;
      sleep(1);
      cout << "Press 2 to continue on your way." << endl;
      sleep(1);
      cin >> answer;


      cout << "Setting down the chest, you make your way out of the alley and past the town." << endl;
    }
    else{
      cout << "You ignore the sounds of the commotion, and make your way past the town." << endl;
    }
    sleep(1.5);
    cout << "Walking through the roads, you are suddenly approached by a group of bandits." << endl;
    sleep(1.5);

    bool isVictory = true;
    if(isVictory){
      cout <<  "You defeat the bandits." << endl;
    }
    else{
      cout << "You are defeated by the bandits." << endl;

    }

    sleep(10);
    system("clear");
}

void PrintChapter4(){
  cout << "\nStage 4" << endl;


    cout << "You resume on your journey after defeating the bandits. " << endl;
    sleep(1.5);
    cout << "At the end of the long road, you find the edge of the dark forest, filled with the shrieks of wild demons and monsters" << endl;
    sleep(1.5);
    cout << "The shrieks become louder as you traverse through the woods. In a small clearing, you find two demons waiting." << endl;
    sleep(3);

  

    bool isVictory = true;
    if(isVictory){
      cout <<  "You defeat the first demon." << endl;
    }
    else{
      cout << "You are defeated by the first demon." << endl;

    }

    if(isVictory){
      cout <<  "You defeat the second demon." << endl;
    }
    else{
      cout << "You are defeated by the second demon." << endl;

    }

    sleep(10);
    system("clear");
}

void PrintChapter5(){
    cout << "\nStage 5" << endl;


    cout << "At the edge of the forest stands overbearing sight of a dark castle. " << endl;
    sleep(1.5);
    cout << "The same castle that the princess is being held in." << endl;
    sleep(1.5);
    cout << "Making your way up the castle stairs, you find the entrance guarded by a demon knight" << endl;
    sleep(1.5);
    cout << "Upon seeing you, the demon knight shouts, and charges at you" << endl;
    sleep(3);

  

    bool isVictory = true;
    if(isVictory){
      cout << "You defeat the demon knight." << endl;
    }
    else{
      cout << "You are defeated by the demon knight." << endl;

    }

    sleep(10);
    system("clear");
}

void PrintChapter6(){
    cout << "\nStage 6" << endl;
    string answer;

    cout << "Upon defeating the demon knight, you enter the now defenseless castle gate." << endl;
    sleep(1.5);
    cout << "You carefully traverse the long hallway before you, and find a small chest a top a wooden stand. Do you want to lockpick?" << endl;
    sleep(1.5);
      cout << "Press 1 to lockpick." << endl;
      sleep(1);
      cout << "Press 2 to continue on your way." << endl;
      sleep(1);
      cin >> answer;


    cout << "Setting down the chest, you continue on your path down the hallway." << endl;
    sleep(1.5);
    cout << "At the end of the hallway, you find stairs, covered in red carpet." << endl;
    sleep(1.5);
    cout << "Perhaps this is the way to the princess." << endl;
    sleep(1.5);
    cout << "Atop the stairs sits the Demon Lord in his throne, with the kidnapped princess by his side." << endl;
    sleep(1.5);
    cout << "In a trance to save the princess, you raise your sword and challenge the Demon Lord." << endl;
    sleep(3);

  

    bool isVictory = true;
    if(isVictory){
      cout << "You defeat the demon lord." << endl;
    }
    else{
      cout << "You are defeated by the demon lord." << endl;

    }


    sleep(1.5);
    cout << "With the demon lord now defeated, and the princess saved, you return the princess to the kingdom." << endl;
    sleep(1.5);
    cout << "You recieve the highest honor from the King, and is granted fief and prosperity for the rest of your days" << endl;
    sleep(1.5);
    cout << "The End." << endl;
    sleep(10);
}





int main(){
    string name = "";
    string answer;

    Character* enemy1;
    enemy1 = new Enemy("Monkey", "Beast", 1, 10, 3, 2, 2, 5);
  
    Character* enemy2;
    enemy2 = new Enemy("Goblin", "Beast", 1, 10, 3, 2, 2, 5);
    (*enemy2).set_level(2);
    
    
    Character* enemy3;
    enemy1 = new Enemy("Bandit", "Human", 1, 10, 3, 2, 2, 5);
  (*enemy3).set_level(3);
  
    Character* enemy4;
    enemy1 = new Enemy("Red Demon", "Demon", 1, 10, 3, 2, 2, 5);
  (*enemy4).set_level(4);
  
    Character* enemy5;
    enemy1 = new Enemy("Blue Demon", "Demon", 1, 10, 3, 2, 2, 5);
  (*enemy5).set_level(5);
  
    Character* enemy6;
    enemy1 = new Enemy("Demon Knight", "Demon", 1, 10, 3, 2, 2, 5);
  (*enemy6).set_level(6);
  
    Character* enemy7;
    enemy1 = new Enemy("Demon Lord", "Demon", 1, 10, 3, 2, 2, 5);
  (*enemy7).set_level(7);

    cout << "Welcome to Short Tale! The princess has been kidnapped, and there was nothing we could do to stop it!" << endl;
    sleep(1.5);
    cout << "She has been taken by hordes of monsters, across many lands." << endl;
    sleep(1.5);
    cout << "You are the only hero strong enough to save her!" << endl;
    cout << endl;
    sleep(3);
    cout << "Before you embark on your mission, what is your name?" << endl;
    cin >> name;
    cout << endl;
    cout << "I see. So your name is " << name << "?" << endl;
    cout << "Press 1 for Yes and 2 for No." << endl;
    cin >> answer;


    while(answer != "1" && answer != "2"){
        cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
        answer = "";
        cin >> answer;
    }


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


    sleep(1);
    cout << endl;
    cout << "I see, so you're " << name << "!" << endl;
    sleep(2);
    cout << "Well, " << name << ", I don't seem to remember what your class was. Can you please remind me?" << endl;
    sleep(3);
    cout << "If I recall, you were a..." << endl;
    sleep(4);
    cout << endl;
    cout << "I'm sorry, what class were you again?" << endl;
    sleep(1.5);


    cout << "Options:" << endl;
    cout << "1: I am a chivalrous knight. I am balanced and an all-rounder. (Press 1 to be assigned Knight class)" << endl;
    sleep(3);
    cout << endl;
    cout << "2: I am a wise mage. I prefer mana and magic attacks. (Press 2 to be assigned the Mage class)" << endl;
    sleep(3);
    cout << endl;
    cout << "3: I am a swift rogue. I boast high speed and attack. (Press 3 to be assigned the Rogue class)" << endl;
    cout << endl;
    sleep(3);
    cout << "PLEASE NOTE: Once you make your decision, there is no going back or changing your mind." << endl;


    answer = "";
    cin >> answer;

    Character* playerClass;


    if (answer == "1") {
        cout << "I see. So you are a knight!" << endl;
        playerClass = new Knight(name, "Knight", 10, 6, 8, 6, 4);
    }

    else if (answer == "2") {
        cout << "I see. So you are a mage!" << endl;
        playerClass = new Mage(name, "Mage", 7, 8, 3, 4, 6);
    }

    else if (answer == "3") {
        cout << "I see. So you are a rogue!" << endl;
        playerClass = new Rogue(name, "Rogue", 6, 8, 3, 2, 8);
    }
    else{
        while(answer != "1" && answer != "2" && answer != "3"){   
            cout << "That doesn't seem to be a valid answer. Please try again." << endl;
            answer = "";
            cin >> answer;
        }
    }
    sleep(1);
    cout << endl;
    cout << name << " the " << playerClass->get_type() << "!" << endl;
    cout << "I entrust you with saving the princess. Please return her safely!" << endl;
    sleep(2);

    system("clear");
    PrintChapter1();
    PrintChapter2();
    PrintChapter3();
    PrintChapter4();
    PrintChapter5();
    PrintChapter6();
    delete playerClass;
    delete enemy1;
    delete enemy2;
    delete enemy3;
    delete enemy4;
    delete enemy5;
    delete enemy6;
    delete enemy7;
}
