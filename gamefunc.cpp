#include <iostream>
#include <string>
#include <unistd.h>
#include "Character.hpp"
#include "gamefunc.h"
using namespace std;

void knightSkills(Character* player, Character* enemy){
  bool isshieldraised = player->getStatus();
  string answer;
  system("cls");
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
    cout << "3) Holy Smite " << "(Cooldown of " << player->getCD()  << " turn/s)."<<endl;
    cout << "        Smites the enemy in a holy light." << endl;
  }
  cin >> answer;
  while(answer != "1" && answer != "2" && answer != "3"){   
      cout << "\nThat doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
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
      system("cls");
  }
    system("cls");
    if(answer == "3"){
      if(player->getCD() == 0){
        
        cout << "You conjure upon a holy magic to smite the " << enemy->get_name() << "." << endl;
        player->holysmite(enemy);
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
          system("cls");
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

void rogueSkills(Character* player, Character* enemy){
  bool isShrouded = player->getStatus();
  string answer;
  system("cls");
  cout << "Available Skills: " << endl;
  cout << "1) Basic Attack" << endl;
  if(player->getCD() == 0){
    cout << "2) Sneak Attack" << endl;
    cout << "        Deals an attack that ignores 50% of the enemy's armor." << endl;
  }
  else{
    cout << "2) Sneak Attack " << "(Cooldown of " << player->getCD()  << " turn/s)."<<endl;
    cout << "        Deals an attack that ignores 50% of the enemy's armor." << endl;
  }
  if(player->get_level() >= 5){
    if(player->getCD2() == 0){
      cout << "3) Smoke Cloud " << endl;
      cout << "        Gain permanent attack damage, and reduce enemy defense permanently." << endl;
    }
    else{
      cout << "3) Smoke Cloud " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Gain permanent attack damage, and reduce enemy defense permanently." << endl;
    }
  }
  else{
    if(player->getCD2() == 0){
      cout << "3) Confuse " << endl;
      cout << "        Permanently reduce enemy defense." << endl;
    }
    else{
      cout << "3) Confuse " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Permanently reduce enemy defense." << endl;
    }
  }
  cin >> answer;
  while(answer != "1" && answer != "2" && answer != "3"){   
      cout << "\nThat doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      if(player->getCD() == 0){
        cout << "2) Sneak Attack" << endl;
        cout << "        Deals an attack that ignores 50% of the enemy's armor." << endl;
      }
      else{
        cout << "2) Sneak Attack " << "(Cooldown of " << player->getCD()  << " turn/s)."<<endl;
        cout << "        Deals an attack that ignores 50% of the enemy's armor." << endl;
      }
      if(player->get_level() >= 5){
        if(player->getCD2() == 0){
          cout << "3) Smoke Cloud " << endl;
          cout << "        Gain permanent attack damage, and reduce enemy defense permanently." << endl;
        }
      else{
        cout << "3) Smoke Cloud " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
        cout << "        Gain permanent attack damage, and reduce enemy defense permanently." << endl;
      }
    }
    else{
      if(player->getCD2() == 0){
        cout << "3) Confuse " << endl;
        cout << "        Permanently reduce enemy defense." << endl;
      }
      else{
        cout << "3) Confuse " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
        cout << "        Permanently reduce enemy defense." << endl;
      }
    }
      answer = "";
      cin >> answer;
      system("cls");
  }
    system("cls");

  if(player->getCD() != 0 && player->getCD2() == 0){
    while(answer != "1" && answer != "3"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      if(player->get_level() >= 5){
        cout << "3) Smoke Cloud " << endl;
        cout << "        Gain permanent attack damage, and reduce enemy defense permanently." << endl;
      }
      else{
        cout << "3) Confuse " << endl;
        cout << "        Permanently reduce enemy defense." << endl;
      }
      answer = "";
      cin >> answer;
      system("cls");
    }
  }

  if(player->getCD() != 0 && player->getCD2() != 0){
    while(answer != "1"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      
      answer = "";
      cin >> answer;
      system("cls");
    }
  }
  if(player->getCD() == 0 && player->getCD2() != 0){
    while(answer != "1" && answer != "2"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      cout << "2) Sneak Attack" << endl;
      cout << "        Deals an attack that ignores 50% of the enemy's armor." << endl;
      answer = "";
      cin >> answer;
      system("cls");
    }
  }

  if(answer == "1"){
    cout << "You attack the " << enemy->get_name() << "." << endl;
    player->atk(enemy);
    cout << endl;
    sleep(2);
  }
  if(answer == "2"){
    player->sneakattack(enemy);
    player->setCD();
    player->setCD();
    sleep(2);
  }
  if(answer == "3"){
    if(player->get_level() >= 5){
      player->shadowshift(enemy);
      player->setCD2();
      player->setCD2();
      player->setCD2();
    }
    else{
      player->mindtrick(enemy);
      player->setCD2();
      player->setCD2();
      player->setCD2();
    }
  }
}

void mageSkills(Character* player, Character* enemy){
  string answer;
  system("cls");
  cout << "Available Skills: " << endl;
  cout << "1) Basic Attack" << endl;
  if(player->getCD() == 0){
    cout << "2) Thunder Cloud" << endl;
    cout << "        Cast a spell of thunder." << endl;
  }
  else{
    cout << "2) Thunder Cloud " << "(Cooldown of " << player->getCD()  << " turn/s)."<<endl;
    cout << "        Cast a spell of thunder." << endl;
  }
  if(player->get_level() >= 5){
    if(player->getCD2() == 0){
      cout << "3) Waning Moon " << endl;
      cout << "        Cast a spell of the moonlight, and heal for 20% of max health." << endl;
    }
    else{
      cout << "3) Waning Moon " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Cast a spell of the moonlight, and heal for 20% of max health." << endl;
    }
  }
  else{
    if(player->getCD2() == 0){
      cout << "3) Void Blast " << endl;
      cout << "        Cast a spell of the void." << endl;
    }
    else{
      cout << "3) Void Blast " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Cast a spell of void." << endl;
    }
  }
  cin >> answer;
  while(answer != "1" && answer != "2" && answer != "3"){   
      cout << "\nThat doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      if(player->getCD() == 0){
      cout << "2) Thunder Cloud" << endl;
      cout << "        Cast a spell of thunder." << endl;
    }
  else{
    cout << "2) Thunder Cloud " << "(Cooldown of " << player->getCD()  << " turn/s)."<<endl;
    cout << "        Cast a spell of thunder." << endl;
  }
  if(player->get_level() >= 5){
    if(player->getCD2() == 0){
      cout << "3) Waning Moon " << endl;
      cout << "        Cast a spell of the moonlight, and heal for 20% of max health." << endl;
    }
    else{
      cout << "3) Waning Moon " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Cast a spell of the moonlight, and heal for 20% of max health." << endl;
    }
  }
  else{
    if(player->getCD2() == 0){
      cout << "3) Void Blast " << endl;
      cout << "        Cast a spell of the void." << endl;
    }
    else{
      cout << "3) Void Blast " << "(Cooldown of " << player->getCD2()  << " turn/s)."<<endl;
      cout << "        Cast a spell of void." << endl;
    }
  }
      answer = "";
      cin >> answer;
      system("cls");
  }
    system("cls");

  if(player->getCD() != 0 && player->getCD2() == 0){
    while(answer != "1" && answer != "3"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      if(player->get_level() >= 5){
        cout << "3) Waning Moon " << endl;
        cout << "        Cast a spell of the moonlight, and heal for 20% of max health." << endl;
      }
      else{
        cout << "3) Void Blast " << endl;
        cout << "        Cast a spell of the void." << endl;
      }
      answer = "";
      cin >> answer;
      system("cls");
    }
  }

  if(player->getCD() != 0 && player->getCD2() != 0){
    while(answer != "1"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      
      answer = "";
      cin >> answer;
      system("cls");
    }
  }
  if(player->getCD() == 0 && player->getCD2() != 0){
    while(answer != "1" && answer != "2"){   
      cout << "That doesn't seem to be a valid answer. Please try again.\n" << endl;
      sleep(2);
      system("cls");
      cout << "Available Skills: " << endl;
      cout << "1) Basic Attack" << endl;
      cout << "2) Thunder Cloud" << endl;
      cout << "        Cast a spell of thunder." << endl;
      answer = "";
      cin >> answer;
      system("cls");
    }
  }

  if(answer == "1"){
    cout << "You attack the " << enemy->get_name() << "." << endl;
    player->atk(enemy);
    cout << endl;
    sleep(2);
  }
  if(answer == "2"){
    player->thunderCloud(enemy);
    player->setCD();
    player->setCD();
    sleep(2);
  }
  if(answer == "3"){
    if(player->get_level() >= 5){
      player->waningMoon(enemy);
      player->setCD2();
      player->setCD2();
      player->setCD2();
    }
    else{
      player->voidBlast(enemy);
      player->setCD2();
      player->setCD2();
      player->setCD2();
    }
  }
}

void useInventory(Inventory* actionItem, Inventory* healItem, Character* player){
    string answer = "";
    cout << "What items would you like to use?" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "1. Action Items" << endl;
    cout << "2. Heal Items" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Please enter 1 or 2, or 3 to exit." << endl;

    answer = "";
    cin >> answer;
    system("cls");
    while(answer != "1" && answer != "2" && answer != "3"){
        cout << "That doesn't seem to be a valid answer. Please press 1 or 2, or 3 to exit.\n" << endl;
        cout << "What items would you like to use?" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "1. Action Items" << endl;
    cout << "2. Heal Items" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Please enter 1 or 2, or 3 to exit." << endl;
        answer = "";
        cin >> answer;
      system("cls");
    }

    if (answer == "1"){
        if(actionItem->isEmpty()){
          cout << "Action Items are empty. Please try another option, or press 3 to exit." << endl;
          useInventory(actionItem, healItem, player);
          return;
        }
        else{
          actionItem->printItem();
      
        cout << "Please press 1 to use the left item, 2 to use the right item, and 3 to exit." << endl; 
        answer = "";
        cin >> answer;

        while(answer != "1" && answer != "2" && answer != "3"){
           cout << "That doesn't seem to be a valid answer. Please press 1, 2, or 3." << endl;
           answer = "";
           cin >> answer;
        }

        if (answer == "1"){
            actionItem->use(actionItem->getLeftChild(), player);                                       //under the assumption that the Character* is named as playerClass in main
          sleep(3);
        }
        else if (answer == "2"){
            actionItem->use(actionItem->getRightChild(), player);                                      //under the assumption that the Character* is named as playerClass in main
          sleep(3);
        }
        else if (answer == "3"){
            return;
        }
        }

    }

    if (answer == "2"){
        if(healItem->isEmpty()){
          cout << "Healing Items are empty. Please try another option, or press 3 to exit." << endl;
          useInventory(actionItem, healItem, player);
          return;
        }
        else{
          healItem->printItem();
      
        cout << "Please press 1 to use the left item, 2 to use the right item, and 3 to exit." << endl; 
        answer = "";
        cin >> answer;

        while(answer != "1" && answer != "2" && answer != "3"){
           cout << "That doesn't seem to be a valid answer. Please press 1, 2, or 3." << endl;
           answer = "";
           cin >> answer;
        }

        if (answer == "1"){
            healItem->use(healItem->getLeftChild(), player);                                       //under the assumption that the Character* is named as playerClass in main
          healItem->remove(healItem->getLeftChild());
          sleep(3);
        }
        else if (answer == "2"){
            healItem->use(healItem->getRightChild(), player);                                      //under the assumption that the Character* is named as playerClass in main
          healItem->remove(healItem->getRightChild());
          sleep(3);
        }
        else if (answer == "3"){
            return;
        }
        }
}
  }

bool inCombat(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy){
  int turnNum = 1;
  bool openedstats = false;
  bool isVictory = true;
  string answer;
  while(isVictory){
    if(player->get_health() <= 0){
      player->set_health(player->get_max_health());
      return false;
    }
    cout << "[Turn " << turnNum << "]\n" << endl;
    enemy->print();
    cout << endl;
    if(openedstats){
      openedstats = false;
    }
    else{
      if(enemy->get_speed() > player->get_speed()){
        enemy->action(player);
      }
    }
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
        system("cls");
        cout << "[Turn " << turnNum << "]\n" << endl;
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
          if(enemy->get_speed() <= player->get_speed()){
            enemy->action(player);
          }
          cout << "Press any key to continue." << endl;
          cin >> answer;
          system("cls");
        }
    }
    else if (answer == "2") {
      if(player->get_type() == "Knight"){
        knightSkills(player, enemy);
      }
      if(player->get_type() == "Rogue"){
        rogueSkills(player, enemy);
      }
      if(player->get_type() == "Mage"){
        mageSkills(player, enemy);
      }
      cout << endl;
      sleep(2);
      
      if(enemy->get_health() <= 0){
          return true;
      }
      else{
          if(enemy->get_speed() <= player->get_speed()){
            enemy->action(player);
          }
          cout << "Press any key to continue." << endl;
          cin >> answer;
          system("cls");
        }
    }
      
    else if (answer == "3") {
        system("cls");
        cout << "You open inventory.\n" << endl;
        useInventory(actionItems, healItems, player);
        turnNum--;
        player->setCD();
        openedstats = true;
        system("cls");
    }
    else if (answer == "4") {
        system("cls");
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
        openedstats = true;
        system("cls");
    }

    else if (answer == "5") {
        cout << "You try to run away." << endl;
        if(player->get_speed() >= enemy->get_speed()){
          system("cls");
          return false;
        }
        else{
          cout << "You failed to run away." << endl;
          system("cls");
        }
    }
    turnNum++;
    if(player->getCD() != 0){
      player->redCD();
    }
    if(player->getCD2() != 0){
      player->redCD2();
    }
  }
  return true;
}


void PrintChapter1(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy){
  cout << "Stage 1: The Beginning." << endl;
    string answer = "";

    cout << "Leaving your hometown in pursuit of the Princess, you trek across the long roads across the mountains with your horse." << endl;
    sleep(1.5);
    cout << "While passing by an abandoned settlement, you are attacked by a wild monkey." << endl;
    sleep(1.5);
    cout << "Press any key to continue." << endl;
    cin >> answer;
    system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout <<  "You defeat the monkey." << endl;
    }
    else{
      cout << "You are defeated by the monkey." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      system("cls");
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      PrintChapter1(actionItems, healItems, player, enemy);
    }
    
    sleep(10);
    system("cls");
}

void PrintChapter2(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy){
  cout << "Stage 2" << endl;
  string answer = "";

    cout << "With your first victory in hand, you continue down the long mountain roads." << endl;
    sleep(3);
    cout << "At the end of the path is a small brush of trees. You hear sounds of grunts and metal clanging, and run into the brush to investigate." << endl;
    sleep(3);
    cout << "In a small clearing, you find a knight, struggling to fight off a duo of goblins." << endl;
    sleep(3);
    cout << "You step in to help the knight." << endl;
    sleep(3);
    cout << "Press any key to continue." << endl;
    cin >> answer;
    system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout <<  "You defeat the goblin." << endl;
    }
    else{
      cout << "You are defeated by the goblin." << endl;
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      system("cls");
      PrintChapter2(actionItems, healItems, player, enemy);
    }

    sleep(10);
    system("cls");
}

void PrintChapter3(Inventory* actionItems, Inventory* healItems, Inventory* healthPotion, Character* player, Character* enemy){
  cout << "Stage 3" << endl;
    string answer = "";
    cout << "At the edge of the town, you hear a small commotion in an alleyway. Do you want to investigate?" << endl;
    cout << "Press 1 to investigate." << endl;
    cout << "Press 2 to continue on your way." << endl;
    cin >> answer;
    if(answer == "1"){
      cout << "In the alleyway, you find two scavengers fighting each other over a small chest. Upon seeing you, however, both flee." << endl;
      sleep(3);
      cout << "Perhaps they thought you were the knight of the town." << endl;
      sleep(3);
      cout << "Picking up the chest, you find that it has a small lock. Do you want to lockpick?" << endl;
      sleep(1.5);
      cout << "Press 1 to lockpick." << endl;
      sleep(1);
      cout << "Press 2 to continue on your way." << endl;
      sleep(1);
      cin >> answer;
      if(answer == "1"){
        if(player->get_type() != "Rogue"){
          cout << "\nYou do not possess the skill to lockpick."<< endl;
          cout << "Hint: Only Rogues can lockpick!"<< endl;
        }
        else{
          if(player->pickLock()){
            cout << "\nYou successfully pick the lock."<< endl;
            healItems->setChild(healthPotion);
            cout << endl;
          }
          else if(!player->pickLock()){
            cout << "\nYou failed to pick the lock." << endl;
            cout << "Hint: You can only lock pick twice!" << endl;
          }
        }
      }

      cout << "Setting down the chest, you make your way out of the alley and past the town." << endl;
    }
    else{
      cout << "You ignore the sounds of the commotion, and make your way past the town." << endl;
    }
    sleep(3);
    cout << "Walking through the roads, you are suddenly approached by a group of bandits." << endl;
    sleep(3);
    cout << "Press any key to continue." << endl;
    cin >> answer;
system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout <<  "You defeat the bandits." << endl;
    }
    else{
      cout << "You are defeated by the bandits." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      system("cls");
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      PrintChapter3(actionItems, healItems, healthPotion, player, enemy);
    }

    sleep(10);
    system("cls");
}

void PrintChapter4(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy, Character* enemy2){
  cout << "Stage 4" << endl;
  string answer = "";

    cout << "You resume on your journey after defeating the bandits. " << endl;
    sleep(3);
    cout << "At the end of the long road, you find the edge of the dark forest, filled with the shrieks of wild demons and monsters" << endl;
    sleep(3);
    cout << "The shrieks become louder as you traverse through the woods. In a small clearing, you find two demons waiting." << endl;
    sleep(3);
    cout << "Press any key to continue." << endl;
    cin >> answer;
    system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout <<  "You defeat the first demon." << endl;
      cout << "Press any key to continue." << endl;
      cin >> answer;
    }
    else{
      cout << "You are defeated by the first demon." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      system("cls");
      PrintChapter4(actionItems, healItems, player, enemy, enemy2);
    }

    isVictory = inCombat(actionItems, healItems, player, enemy2);
    if(isVictory){
      cout <<  "You defeat the second demon." << endl;
    }
    else{
      cout << "You are defeated by the second demon." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      player->set_health(player->get_max_health());
      enemy2->set_health(enemy2->get_max_health());
      system("cls");
      PrintChapter4(actionItems, healItems, player, enemy, enemy2);
    }

    sleep(10);
    system("cls");
}

void PrintChapter5(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy){
    cout << "Stage 5" << endl;
    string answer = "";

    cout << "At the edge of the forest stands overbearing sight of a dark castle. " << endl;
    sleep(3);
    cout << "The same castle that the princess is being held in." << endl;
    sleep(3);
    cout << "Making your way up the castle stairs, you find the entrance guarded by a demon knight." << endl;
    sleep(3);
    cout << "Upon seeing you, the demon knight shouts, and charges at you." << endl;
    sleep(3);
    cout << "Press any key to continue." << endl;
    cin >> answer;
  
system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout << "You defeat the demon knight." << endl;
    }
    else{
      cout << "You are defeated by the demon knight." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      system("cls");
      PrintChapter5(actionItems, healItems, player, enemy);
    }

    sleep(10);
    system("cls");
}

void PrintChapter6(Inventory* actionItems, Inventory* healItems, Inventory* smokeBomb, Character* player, Character* enemy){
    cout << "Stage 6" << endl;
    string answer = "";

    cout << "With the demon knight defeated, you enter the now defenseless castle gate." << endl;
    sleep(3);
    cout << "You carefully traverse the long hallway before you, and find a small chest a top a wooden stand. Do you want to lockpick?" << endl;
    sleep(3);
      cout << "Press 1 to lockpick." << endl;
      sleep(1);
      cout << "Press 2 to continue on your way." << endl;
      sleep(1);
      cin >> answer;
      if(answer == "1"){
        if(player->get_type() != "Rogue"){
          cout << "\nYou do not possess the skill to lockpick."<< endl;
          cout << "Hint: Only Rogues can lockpick!\n"<< endl;
        }
        else{
          if(player->pickLock()){
            cout << "\nYou successfully pick the lock."<< endl;
            actionItems->setChild(smokeBomb);
            cout << endl;
          }
          else{
            cout << "\nYou failed to pick the lock." << endl;
            cout << "Hint: You can only lock pick twice!\n" << endl;
          }
        }
      }

    cout << "\nSetting down the chest, you continue on your path down the hallway." << endl;
    sleep(3);
    cout << "At the end of the hallway, you find stairs, covered in red carpet." << endl;
    sleep(3);
    cout << "Perhaps this is the way to the princess." << endl;
    sleep(3);
    cout << "Atop the stairs sits the Demon Lord in his throne, with the kidnapped princess by his side." << endl;
    sleep(3);
    cout << "In a trance to save the princess, you raise your sword and challenge the Demon Lord." << endl;
    sleep(3);
    cout << "Press any key to continue." << endl;
    cin >> answer;
  
system("cls");
    bool isVictory = inCombat(actionItems, healItems, player, enemy);
    if(isVictory){
      cout << "You defeat the demon lord." << endl;
    }
    else{
      cout << "You are defeated by the demon lord." << endl;
      cout << "Restart the chapter?" << endl;
      cin >> answer;
      system("cls");
      player->set_health(player->get_max_health());
      enemy->set_health(enemy->get_max_health());
      PrintChapter6(actionItems, healItems, smokeBomb, player, enemy);
    }


    sleep(3);
    cout << "With the demon lord now defeated, and the princess saved, you return the princess to the kingdom." << endl;
    sleep(3);
    cout << "You recieve the highest honor from the King, and is granted fief and prosperity for the rest of your days" << endl;
    sleep(3);
    cout << "The End." << endl;
    sleep(10);
}

void printShop1(int gold, Inventory* actionItem, Inventory* healItem, Inventory* smokeBomb, Inventory* strengthPotion, Inventory* healthPotion){
  string answer = "";
  cout << "The knight greets you in thanks, telling you that he had been separated from his patrol group." << endl;
    sleep(3);
    cout << "He explains the increase in monster activity has demanded more frequent and thorough patrols through the area. " << endl;
    sleep(3);
    cout << "He gives his thanks again, and you go on your own ways..\n" << endl;
    sleep(3);
    cout << "Past the trees, you find a small town with a traveling merchant." << endl;
    cout << "Press any key to speak to the merchant" << endl;
    cin >> answer;
    system("cls");
    answer = "1";
while(answer == "1"){
    cout << "Shop:              Current Gold: " << gold << " gold" << endl;
    cout << "1. Smoke Bomb-----------x1, 50 gold" << endl;
    cout << "2. Health Potion--------x1, 50 gold" << endl;
    cout << "3. To exit shop. " << endl;
    cout << "Please type the respective number in order to buy the item, or 3 to exit shop." << endl;

  answer = "";
  cin >> answer;

  while(answer != "1" && answer != "2" && answer != "3"){
      cout << "That doesn't seem to be a valid answer. Please press 1 or 2, or 3 to exit shop." << endl;
      answer = "";
      cin >> answer;
      system("cls");
  } 

  if (answer == "1"){
    if(gold >= 50){
     actionItem->setChild(smokeBomb);
     gold -=50;
      }
    else{
      cout << "\nYou do not possess enough gold to purchase this item." << endl;
    }
  }

  if (answer == "2"){
    if(gold >= 50){
     healItem->setChild(healthPotion);
     gold -=50;
      }
    else{
      cout << "\nYou do not possess enough gold to purchase this item." << endl;
    }
  }
  
  if (answer == "3"){
  }
  else{
  cout << endl;
  actionItem->printItem();
  cout << endl;
  healItem->printItem();
  cout << endl;
  cout << "Would you like to continue shopping? (Please press 1 for Yes or 2 for No.)" << endl;

  answer = "";
  cin >> answer;
  system("cls");
  while(answer != "1" && answer != "2"){
    cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
    answer = "";
    cin >> answer;
  }
  }  
  }
  cout << "You thank the merchant, and continue on your way." << endl;
  cout << "Press any key to continue." << endl;
  cin >> answer;
  sleep(3);
  system("cls");
}

void printShop2(int gold, Inventory* actionItem, Inventory* healItem, Inventory* smokeBomb, Inventory* strengthPotion, Inventory* healthPotion){
  string answer = "";
  cout << "You hear a faint whisper in the shadows, and move to investigate." << endl;
    sleep(3);
    cout << "A terrified trader seemed to have lost his way." << endl;
    sleep(3);
    cout << "You show him the way to safety, and in exchange he offers you wares for discount..\n" << endl;
    sleep(3);
    cout << "Press any key to look at his wares." << endl;
    cin >> answer;
    system("cls");
    answer = "1";
while(answer == "1"){
    cout << "Shop:              Current Gold: " << gold << " gold" << endl;
    cout << "1. Smoke Bomb-----------x1, 25 gold" << endl;
    cout << "2. Health Potion--------x1, 25 gold" << endl;
    cout << "3. Strength Potion------x1, 50 gold" << endl;
    cout << "4. To exit shop. " << endl;
    cout << "Please type the respective number in order to buy the item, or 4 to exit shop." << endl;

  answer = "";
  cin >> answer;

  while(answer != "1" && answer != "2" && answer != "3"){
      cout << "That doesn't seem to be a valid answer. Please press 1 or 2, or 3 to exit shop." << endl;
      answer = "";
      cin >> answer;
      system("cls");
  } 

  if (answer == "1"){
    if(gold >= 25){
     actionItem->setChild(smokeBomb);
     gold -=25;
      }
    else{
      cout << "\nYou do not possess enough gold to purchase this item." << endl;
    }
  }

  if (answer == "2"){
    if(gold >= 25){
      healItem->setChild(healthPotion);
     gold -=25;
      }
    else{
      cout << "\nYou do not possess enough gold to purchase this item." << endl;
    }
  }
  if (answer == "3"){
    if(gold >= 50){
     actionItem->setChild(strengthPotion);
     gold -=50;
      }
    else{
      cout << "\nYou do not possess enough gold to purchase this item." << endl;
    }
  }
  
  if (answer == "4"){
  }
  else{
  cout << endl;
  actionItem->printItem();
  cout << endl;
  healItem->printItem();
  cout << endl;
  cout << "Would you like to continue shopping? (Please press 1 for Yes or 2 for No.)" << endl;

  answer = "";
  cin >> answer;
  system("cls");
  while(answer != "1" && answer != "2"){
    cout << "That doesn't seem to be a valid answer. Please press 1 for Yes and 2 for No." << endl;
    answer = "";
    cin >> answer;
  }
  }  
  }
  cout << "You thank the merchant, and continue on your way." << endl;
  cout << "Press any key to continue." << endl;
  cin >> answer;
  sleep(3);
  system("cls");
}


