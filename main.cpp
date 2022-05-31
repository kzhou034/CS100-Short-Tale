#include <iostream>
#include <string>
#include <unistd.h>
#include "Character.hpp"
using namespace std;

void knightSkills(Character* player, Character* enemy){
  bool isshieldraised = player->getStatus();
  string answer;
  system("clear");
  cout << "Available Skills: " << endl;
  cout << "1) Basic Attack" << endl;
  if(!isshieldraised){
    cout << "2) Raise Shield" << endl;
    cout << "        Increase defense by 50% but reduces attack damage" << endl;
  }
  else{
    cout << "2) Lower Shield" << endl;
  }
  if(player->getCD() == 0){
    cout << "3) Holy Smite" << endl;
    cout << "        Smites the enemy in a holy light." << endl;
  }
  else{
    cout << "3) Holy Smite " << "(Cooldown of " << player->getCD()  << " turn/s."<<endl;
    cout << "        Smites the enemy in a holy light." << endl;
  }
  cin >> answer;
  while(answer != "1" && answer != "2" && answer != "3"){   
      cout << "\nThat doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("clear");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      if(!isshieldraised){
        cout << "2) Raise Shield" << endl;
        cout << "        Increase defense by 50% but reduces attack damage" << endl;
      }
      else{
        cout << "2) Lower Shield" << endl;
      }
      if(player->getCD() == 0){
        cout << "3) Holy Smite" << endl;
        cout << "        Smites the enemy in a holy light." << endl;
      }
      else{
        cout << "3) Holy Smite " << "(Cooldown of " << player->getCD()  << " turn/s)"<<endl;
        cout << "        Smites the enemy in a holy light." << endl;
      }
      answer = "";
      cin >> answer;
      system("clear");
  }
    system("clear");
    if(answer == "3"){
      if(player->getCD() == 0){
        player->holysmite(enemy);
        cout << "You conjure upon a holy magic to smite the " << enemy->get_name() << "." << endl;
        player->setCD();
        player->setCD();
        player->setCD();
      }
      else{

        while(answer != "1" && answer != "2"){   
          cout << "You are unable to cast holy smite. Please choose another skill.\n" << endl;
          sleep(2);
          cout << "Available Skills: " << endl;
          cout << "1) Basic Attack" << endl;
          if(!isshieldraised){
            cout << "2) Raise Shield" << endl;
            cout << "        Increase defense by 50% but reduces attack damage" << endl;
          }
          else{
            cout << "2) Lower Shield" << endl;
          }
          answer = "";
          cin >> answer;
          system("clear");
        }
      }
    }
    if(answer == "1"){
      cout << "You attack the " << enemy->get_name() << "." << endl;
      player->atk(enemy);
      cout << endl;
      sleep(2);
    }
    if(answer == "2"){
      if(!isshieldraised){
        player->raiseshield();
        isshieldraised = true;
        cout << "You raise your shield against the " << enemy->get_name() << "." << endl;
      }
      else{
        player->lowershield();
        isshieldraised = false;
        cout << "You lower your shield against the " << enemy->get_name() << "." << endl;
      }
    }
}

bool inCombat(Character* player, Character* enemy){
  int turnNum = 1;
  bool isVictory = true;
  string answer;
  while(isVictory){
    cout << "[Turn " << turnNum << "]\n" << endl;
    enemy->print();
    cout << "\nYou currently have " << player->get_health() << " health.\n" << endl;
    cout << "Options:" << endl;
    cout << "Press 1 to attack." << endl;
    cout << "Press 2 to use skills." << endl;
    cout << "Press 3 to use items." << endl;
    cout << "Press 4 to see your stats." << endl;
    cout << "Press 5 to run away." << endl;
    cin >> answer;
    while(answer != "1" && answer != "2" && answer != "3" && answer != "4" && answer != "5"){   
        cout << "\nThat doesn't seem to be a valid answer. Please try again.\n" << endl;
        sleep(2);
        system("clear");
        cout << "Name: " << enemy->get_name() << "\nType: " << enemy->get_type() << "\nHealth: " << enemy->get_health() << endl << endl << endl;
        cout << "You currently have " << player->get_health() << " health." << endl;
        cout << "Options:" << endl;
        cout << "Press 1 to attack." << endl;
        cout << "Press 2 to use skills." << endl;
        cout << "Press 3 to use items." << endl;
        cout << "Press 4 to see your stats." << endl;
        cout << "Press 5 to run away." << endl;
        answer = "";
        cin >> answer;
    }
    if (answer == "1") {
        cout << "\nYou attack the " << enemy->get_name() << "." << endl;
        player->atk(enemy);
        cout << endl;
        sleep(2);
        if(enemy->get_health() <= 0){
          return true;
        }
        else{
          enemy->action(player);
          cout << "Press any key to continue." << endl;
          cin >> answer;
          system("clear");
        }
    }
    else if (answer == "2") {
      if(player->get_type() == "Knight"){
        knightSkills(player, enemy);
      }
      cout << endl;
        sleep(2);
        if(enemy->get_health() <= 0){
          return true;
      }
      else{
        enemy->action(player);
        cout << "Press any key to continue." << endl;
        cin >> answer;
        system("clear");
      }
    }
      
    else if (answer == "3") {
        cout << "You open inventory" << endl;
      
        system("clear");
    }
    else if (answer == "4") {
        system("clear");
        cout << "Name: " << player->get_name() << endl;
        cout << "Class: " << player->get_type() << endl;
        cout << "Level: " << player->get_level() << endl;
        cout << "Attack: " << player->get_attack() << endl;
        cout << "Defense: " << player->get_defense() << endl;
        cout << "Resistance: "<< player->get_resistance() << endl;
        cout << "Speed: " << player->get_speed() << endl;
        cout << "\nPress any key to return. " << endl;
        cin >> answer;
        turnNum--;
        player->setCD();
        system("clear");
    }

    else if (answer == "5") {
        cout << "You try to run away." << endl;
        system("clear");
        return false;
    }
    turnNum++;
    if(player->getCD() != 0){
      player->redCD();
    }
  }
  return true;
}

void PrintChapter1(Character* player, Character* enemy){
  Character* userPlay = player;
  Character* userEnemy = enemy;
  
  cout << "Stage 1: The Beginning." << endl;
    string answer = "";

    cout << "Leaving your hometown in pursuit of the Princess, you trek across the long roads across the mountains with your horse." << endl;

    cout << "While passing by an abandoned settlement, you are attacked by a wild monkey." << endl;

    cout << "Press any key to continue." << endl;
    cin >> answer;
    
    system("clear");
    bool isVictory = inCombat(userPlay, userEnemy);
    if(isVictory){
      cout <<  "You defeat the monkey." << endl;
    }
    else{
      cout << "You are defeated by the monkey." << endl;
    }

    sleep(10);
    system("clear");
}


int main(){
    string name = "Joseph";
    string answer;

    Character* enemy1;
    enemy1 = new Enemy("Monkey", "Beast", 1, 10, 3, 2, 2, 5);
    enemy1->setlevel(10);
    Character* playerClass;

    playerClass = new Knight(name, "Knight", 10, 6, 8, 6, 4);
    playerClass->setlevel(10);
    PrintChapter1(playerClass, enemy1);
    // PrintChapter2();
    // PrintChapter3();
    // PrintChapter4();
    // PrintChapter5();
    // PrintChapter6();
    
    delete playerClass;
    delete enemy1;
}
