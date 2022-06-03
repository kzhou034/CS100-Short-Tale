#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__
#include <iostream>
#include <string>
#include "Enemy.cpp"
#include "Character.hpp"
using namespace std;

class Inventory {

    protected:

    string name;

    public:

        virtual void setChildLeft(Inventory* ptr) = 0;
        virtual void setChildRight(Inventory* ptr) = 0;
        virtual void remove(Inventory* ptr) = 0;
        virtual void use(Inventory* ptr, Character* playerClass) = 0;
        virtual void printItem() = 0;
        virtual string getItemName() = 0;

};

class ActionItem : public Inventory {

    private:

        Inventory* leftChild;
        Inventory* rightChild;
        bool firstAdd = true;

    public:

        ActionItem(){
            name = "Action Item"                                                                // shouldn't really be used, just initialized for consistency's sake
        }

        ~ActionItem(){                                                                          // shouldn't have to delete item pointers because they're deleted here
            delete leftChild;
            delete rightChild;
        }

        void setChild(Inventory* ptr){
            if (leftChild != 0 && rightChild != 0){
                cout << "Action Items tab is full." << endl;
            }
            else if (leftChild == 0){
                setChildLeft(ptr);
            }
            else if (rightChild == 0){
                setChildRight(ptr);
            }
        }

        void setChildLeft(Inventory* ptr){                                                      // add items to Action Items
            if (leftChild == 0 && firstAdd == true){
                cout << "You have opened up the Action Items tab in the Inventory!" << endl;
                leftChild = ptr;
                firstAdd = false;
            }
            else if (leftChild == 0 && firstAdd == false){
                leftChild = ptr;
                cout << leftChild->getItemName() << " has been added to the Inventory!" << endl; //outputs when something is added to left slot of Inventory
            }
            else{
                cout << "There is already an item in the left slot." << endl;                    //disallows setChildLeft (could be used to disallow player to buy from shop if inventory is full)
            }
        }

        void setChildRight(Inventory* ptr){                                                     //add items to Action Items
            if (rightChild == 0 && firstAdd == true){
                cout << "You have opened up the Action Items tab in the Inventory!" << endl;
                rightChild = ptr;
                firstAdd == false;
            }
            else if (rightChild == 0 && firstAdd == false){
                rightChild = ptr;
                cout << rightChild->getItemName() << " has been added to the Inventory!" << endl; //outputs when something is added to right slot of Inventory
            }
            else{
                cout << "There is already an item in the right slot." << endl;                  //disallows setChildLeft (could be used to disallow player to buy from shop if inventory is full)
            }
        }

        void remove(Inventory* ptr){                                                            //useful for shop selling (if implemented, otherwise useless function)
            if (leftChild == ptr){                                                              //if the left item matches ptr, the function will get rid of left item
                delete leftChild;
                leftChild = 0;
                cout << "The left item has been removed from Action Items."
            }
            else if (rightChild == ptr){                                                        //if the right item matches ptr, the function will get rid of right item (left is priority remove)
                delete rightChild;
                rightChild = 0;
                cout << "The right item has been removed from Action Items."
            }
            else{
                cout << "Sorry, the item cannot be removed!" << endl;                           //if ptr doesn't match anything the item probably isn't here. (shouldn't be seen by player since we use remove function)
            }
        }

        void use(Inventory* ptr, Character* playerClass){
            if (leftChild == ptr){                                                              //if the left item matches ptr, it'll use the left one
                leftChild->use(ptr);
            }
            else if (rightChild == ptr){                                                        //if the right item matches ptr, it'll use the right one (left is priority use)
                rightChild->use(ptr);
            }
            else{                                                                               //if ptr doesn't match anything then the item requested isn't here. (shouldn't be seen by player since we call use function)
                cout << "The requested item is not in Action Items."
            }
        }

        void printItem(){                                                                       //outputs what is in Action Items tab and asks for user input
            if (firstAdd == true){                                                              // if action items were never added
                cout << "The Action Items tab is empty!" << endl;
            }
            else if (leftChild == 0 && rightChild == 0){                                        // if action items were added but used up
                cout << "The Action Items tab is empty!" << endl;
            }
            else if (leftChild == 0){                                                           // if there is no current left item in Action Items
                cout << "The Action Items tab consists of:" << endl;
                cout << "Left slot: empty." << endl;
                cout << "Right slot: " << rightChild->getItemName() << endl;
            }
            else if (rightChild == 0){                                                          // if there is no current right item in Action Items
                cout << "The Action Items tab consists of:" << endl;
                cout << "Left slot: " << leftChild->getItemName() << endl;
                cout << "Right slot: empty." << endl;
            }
            else{                                                                               // will output both slots if everything is there
                cout << "The Action Items tab consists of:" << endl;
                cout << "Left slot: " << leftChild->getItemName() << endl;
                cout << "Right slot: " << rightChild->getItemName() << endl;
            }
            cout << "Please press 1 to use the left item, 2 to use the right item, and 3 to exit." << endl;         // user input
        }
        
        string getItemName(){                 //this should essentially be useless for Action Item class
            return name;
        }

        Inventory* getLeftChild(){
            return leftChild;
        }

        Inventory* getRightChild(){
            return rightChild;
        }

};

class HealItem : public Inventory {

    private:

        Inventory* leftChild;
        Inventory* rightChild;
        bool firstAdd = true;

    public:

        HealItem(){
            name = "Heal Item"                                                                // shouldn't really be used, just initialized for consistency's sake
        }

        ~HealItem(){                                                                          // shouldn't have to delete item pointers because they're deleted here
            delete leftChild;
            delete rightChild;
        }

        void setChild(Inventory* ptr){
            if (leftChild != 0 && rightChild != 0){
                cout << "Heal Items tab is full." << endl;
            }
            else if (leftChild == 0){
                setChildLeft(ptr);
            }
            else if (rightChild == 0){
                setChildRight(ptr);
            }
        }

        void setChildLeft(Inventory* ptr){                                                      // add items to Heal Items
            if (leftChild == 0 && firstAdd == true){
                cout << "You have opened up the Heal Items tab in the Inventory!" << endl;
                leftChild = ptr;
                firstAdd = false;
            }
            else if (leftChild == 0 && firstAdd == false){
                leftChild = ptr;
                cout << leftChild->getItemName() << " has been added to the Inventory!" << endl; //outputs when something is added to left slot of Inventory
            }
            else{
                cout << "There is already an item in the left slot." << endl;                    //disallows setChildLeft (could be used to disallow player to buy from shop if inventory is full)
            }
        }

        void setChildRight(Inventory* ptr){                                                     //add items to Heal Items
            if (rightChild == 0 && firstAdd == true){
                cout << "You have opened up the Heal Items tab in the Inventory!" << endl;
                rightChild = ptr;
                firstAdd == false;
            }
            else if (rightChild == 0 && firstAdd == false){
                rightChild = ptr;
                cout << rightChild->getItemName() << " has been added to the Inventory!" << endl; //outputs when something is added to right slot of Inventory
            }
            else{
                cout << "There is already an item in the right slot." << endl;                  //disallows setChildLeft (could be used to disallow player to buy from shop if inventory is full)
            }
        }

        void remove(Inventory* ptr){                                                            //useful for shop selling (if implemented, otherwise useless function)
            if (leftChild == ptr){                                                              //if the left item matches ptr, the function will get rid of left item
                delete leftChild;
                leftChild = 0;
                cout << "The left item has been removed from Heal Items."
            }
            else if (rightChild == ptr){                                                        //if the right item matches ptr, the function will get rid of right item (left is priority remove)
                delete rightChild;
                rightChild = 0;
                cout << "The right item has been removed from Heal Items."
            }
            else{
                cout << "Sorry, the item cannot be removed!" << endl;                           //if ptr doesn't match anything the item probably isn't here. (shouldn't be seen by player since we use remove function)
            }
        }

        void use(Inventory* ptr, Character* playerClass){
            if (leftChild == ptr){                                                              //if the left item matches ptr, it'll use the left one
                leftChild->use(ptr, playerClass);
            }
            else if (rightChild == ptr){                                                        //if the right item matches ptr, it'll use the right one (left is priority use)
                rightChild->use(ptr, playerClass);
            }
            else{                                                                               //if ptr doesn't match anything then the item requested isn't here. (shouldn't be seen by player since we call use function)
                cout << "The requested item is not in Heal Items."
            }
        }

        void printItem(){                                                                       //outputs what is in Heal Items tab and asks for user input
            if (firstAdd == true){                                                              // if Heal items were never added
                cout << "The Heal Items tab is empty!" << endl;
            }
            else if (leftChild == 0 && rightChild == 0){                                        // if Heal items were added but used up
                cout << "The Heal Items tab is empty!" << endl;
            }
            else if (leftChild == 0){                                                           // if there is no current left item in Heal Items
                cout << "The Heal Items tab consists of:" << endl;
                cout << "Left slot: empty." << endl;
                cout << "Right slot: " << rightChild->getItemName() << endl;
            }
            else if (rightChild == 0){                                                          // if there is no current right item in Heal Items
                cout << "The Heal Items tab consists of:" << endl;
                cout << "Left slot: " << leftChild->getItemName() << endl;
                cout << "Right slot: empty." << endl;
            }
            else{                                                                               // will output both slots if everything is there
                cout << "The Heal Items tab consists of:" << endl;
                cout << "Left slot: " << leftChild->getItemName() << endl;
                cout << "Right slot: " << rightChild->getItemName() << endl;
            }
            cout << "Please press 1 to use the left item, 2 to use the right item, and 3 to exit." << endl;         // user input
        }
        
        string getItemName(){                 //this should essentially be useless for Heal Item class
            return name;
        }

        Inventory* getLeftChild(){
            return leftChild;
        }

        Inventory* getRightChild(){
            return rightChild;
        }
}

class SmokeBomb : public Inventory {                                                            
    public:
        SmokeBomb(){
            name = "Smoke Bomb";
        }
        
        ~SmokeBomb(){

        }

        void setChildLeft(Inventory* ptr){                                                  //going to be an empty function because we aren't going to use it

        }
        void setChildRight(Inventory* ptr){                                                 //going to be an empty function because we aren't going to use it

        }
        void remove(Inventory* ptr){                                                        //going to be an empty function because we aren't going to use it

        }
        void use(Inventory* ptr, Character* playerClass){                                                           //right now, use for SmokeBomb is just a cout statement            
            cout << "You have raised your chances of escape!" << endl;
        }
        void printItem(){
            cout << "Smoke bomb: allows the user to run away more effectively." << endl;
        }
        string getItemName(){
            return name;
        } 
}

class StrengthPotion : public Inventory {                                                            
    public:
        StrengthPotion(){
            name = "Strength Potion";
        }
        
        ~StrengthPotion(){

        }

        void setChildLeft(Inventory* ptr){                                                  //going to be an empty function because we aren't going to use it
 
        }
        void setChildRight(Inventory* ptr){                                                 //going to be an empty function because we aren't going to use it

        }
        void remove(Inventory* ptr){                                                        //going to be an empty function because we aren't going to use it

        }
        void use(Inventory* ptr, Character* playerClass){                                                                       
            cout << "You have drunk a Strength Potion! " << endl;
            cout << "Your attack stat has been raised by 2 points." << endl;
            playerClass->set_attack(playerClass->get_attack() + 2);
        }
        void printItem(){
            cout << "Strength Potion: allows the user to raise their attack by 2 points for the rest of combat." << endl;
        }
        string getItemName(){
            return name;
        } 
}

class HealthPotion : public Inventory {                                                            
    public:
        HealthPotion(){
            name = "Health Potion";
        }
        
        ~HealthPotion(){

        }

        void setChildLeft(Inventory* ptr){                                                  //going to be an empty function because we aren't going to use it
 
        }
        void setChildRight(Inventory* ptr){                                                 //going to be an empty function because we aren't going to use it

        }
        void remove(Inventory* ptr){                                                        //going to be an empty function because we aren't going to use it

        }
        void use(Inventory* ptr, Character* playerClass){                                              
            cout << "You have drunk a Health Potion! " << endl;
            playerClass->heal();
        }
        void printItem(){
            cout << "Heal Potion: Allows the user to recover health." << endl;
        }
        string getItemName(){
            return name;
        } 
}


#endif
