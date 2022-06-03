#include <iostream>
#include <string>
#include <unistd.h>
#include "Character.hpp"
#include "gamefunc.h"
#include "Inventory.hpp"
using namespace std;

int main(){
    Inventory* actionItem = new ActionItem();
    Inventory* healItem = new HealItem();
    Inventory* smokeBomb = new SmokeBomb();
    Inventory* strengthPotion = new StrengthPotion();
    Inventory* healthPotion = new HealthPotion();

    
    string name = "";
    string answer;
    int goldStorage = 0;

    Character* enemy1;
    enemy1 = new Enemy("Monkey", "Beast", 1, 10, 3, 2, 2, 5);
  
    Character* enemy2;
    enemy2 = new Enemy("Goblin", "Beast", 1, 11, 3, 2, 2, 5);
    (*enemy2).setlevel(2);
    
    Character* enemy3;
    enemy3 = new Enemy("Bandit", "Human", 1, 12, 3, 2, 2, 5);
  (*enemy3).setlevel(3);
  
    Character* enemy4;
    enemy4 = new Enemy("Red Demon", "Demon", 1, 12, 3, 2, 2, 5);
  (*enemy4).setlevel(4);
  
    Character* enemy5;
    enemy5 = new Enemy("Blue Demon", "Demon", 1, 13, 4, 2, 2, 5);
  (*enemy5).setlevel(5);
  
    Character* enemy6;
    enemy6 = new Enemy("Demon Knight", "Demon", 1, 13, 2, 5, 2, 5);
  (*enemy6).setlevel(6);
  
    Character* enemy7;
    enemy7 = new Enemy("Demon Lord", "Demon", 1, 15, 3, 2, 2, 5);
  (*enemy7).setlevel(7);

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
    system("cls");
    cout << "I see. So your name is " << name << "?" << endl;
    cout << "Press 1 for Yes and 2 for No." << endl;
    cin >> answer;
    system("cls");

    while(answer != "1" && answer != "2"){
        cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
        answer = "";
        cin >> answer;
        system("cls");
    }


    while(answer == "2"){
        cout << "I see. Once again, what is your name?" << endl;
        name = "";
        cin >> name;
        system("cls");
        cout << "I see. So your name is " << name << "?" << endl;       //rechecks name
        cout << "Press 1 for Yes and 2 for No." << endl;                //redoes confirmation line
        answer = "";
        cin >> answer;
        system("cls");
        while(answer != "1" && answer != "2"){   //re-asks if invalid answer is given
            cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
            answer = "";
            cin >> answer;
          system("cls");
        }
    }
    

    sleep(1);
    cout << endl;
    system("cls");
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
    system("cls");
    Character* playerClass;
  
    while(answer != "1" && answer != "2" && answer != "3"){   
        cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
        cout << "Options:" << endl;
        cout << "1: I am a chivalrous knight. I am balanced and an all-rounder. (Press 1 to be assigned Knight class)" << endl;
        sleep(1);
        cout << endl;
        cout << "2: I am a wise mage. I prefer mana and magic attacks. (Press 2 to be assigned the Mage class)" << endl;
        sleep(1);
        cout << endl;
        cout << "3: I am a swift rogue. I boast high speed and attack. (Press 3 to be assigned the Rogue class)" << endl;
        cout << endl;
        sleep(1);
        cout << "PLEASE NOTE: Once you make your decision, there is no going back or changing your mind." << endl;
        answer = "";
        cin >> answer;
        system("cls");
    }
    if (answer == "1") {
        cout << "I see. So you are a knight!" << endl;
        playerClass = new Knight(name, "Knight", 10, 6, 10, 10, 4);
    }

    else if (answer == "2") {
        cout << "I see. So you are a mage!" << endl;
        playerClass = new Mage(name, "Mage", 7, 8, 3, 4, 6);
    }

    else if (answer == "3") {
        cout << "I see. So you are a rogue!" << endl;
        playerClass = new Rogue(name, "Rogue", 6, 8, 4, 3, 8);
    }
  
    sleep(1);
    cout << endl;
    cout << name << " the " << playerClass->get_type() << "!" << endl;
    cout << "I entrust you with saving the princess. Please return her safely!" << endl;
    sleep(5);

  

    system("cls");
    PrintChapter1(actionItem, healItem, playerClass, enemy1);
    cout << "You have leveled up! Your health has been reseted, and you have gained an increase to your stats." << endl;
    cout << "Press any key to continue." << endl;
    goldStorage += 50;
    cin >> answer;
    system("cls");
    playerClass->setlevel(2);
    PrintChapter2(actionItem, healItem, playerClass, enemy2);
    printShop1(goldStorage, actionItem, healItem, smokeBomb, strengthPotion, healthPotion);
    cout << "You have leveled up! Your health has been reseted, and you have gained an increase to your stats." << endl;
    cout << "Press any key to continue." << endl;
  goldStorage += 25;
    cin >> answer;
    system("cls");
    playerClass->setlevel(3);
    PrintChapter3(actionItem, healItem, healthPotion, playerClass, enemy3);
    cout << "You have leveled up! Your health has been reseted, and you have gained an increase to your stats." << endl;
    if(playerClass->get_type() == "Mage"){
      cout << "Your Void Blast has been blessed by the moonlight, strengthened by your conviction." << endl;
    }
    if(playerClass->get_type() == "Rogue"){
      cout << "Your skills have improved with training and practice." << endl;
    }
    cout << "Press any key to continue." << endl;
  goldStorage += 25;
    cin >> answer;
    system("cls");
    playerClass->setlevel(5);
    PrintChapter4(actionItem, healItem, playerClass, enemy4, enemy5);
    cout << "You have leveled up! Your health has been reseted, and you have gained an increase to your stats." << endl;
    cout << "Press any key to continue." << endl;
  goldStorage += 50;
    playerClass->setlevel(6);
    PrintChapter5(actionItem, healItem, playerClass, enemy6);
    cout << "You have leveled up! Your health has been reseted, and you have gained an increase to your stats." << endl;
    cout << "Press any key to continue." << endl;
  goldStorage += 25;
    playerClass->setlevel(7);
    printShop2(goldStorage, actionItem, healItem, smokeBomb, strengthPotion, healthPotion);
    PrintChapter6(actionItem, healItem, smokeBomb, playerClass, enemy7);
    playerClass->setlevel(8);
    delete playerClass;
    delete enemy1;
    delete enemy2;
    delete enemy3;
    delete enemy4;
    delete enemy5;
    delete enemy6;
    delete enemy7;
    delete actionItem;
    delete healItem;
    delete smokeBomb;
    delete strengthPotion;
    delete healthPotion;
}


