#pragma once
#include "Character.hpp"
#include "Inventory.hpp"

void knightSkills(Character* player, Character* enemy);
void rogueSkills(Character* player, Character* enemy);
void mageSkills(Character* player, Character* enemy);

bool inCombat(Character* player, Character* enemy);

void PrintChapter1(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy);
void PrintChapter2(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy);
void PrintChapter3(Inventory* actionItems, Inventory* healItems, Inventory* healthPotion, Character* player, Character* enemy);
void PrintChapter4(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy, Character* enemy2);
void PrintChapter5(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy);
void PrintChapter6(Inventory* actionItems, Inventory* healItems, Inventory* smokeBomb, Character* player, Character* enemy);
void PrintChapter7(Inventory* actionItems, Inventory* healItems, Character* player, Character* enemy);
void useInventory(Inventory* actionItem, Inventory* healItem, Character* player);
void printShop1(int gold, Inventory* actionItem, Inventory* healItem, Inventory* smokeBomb, Inventory* strengthPotion, Inventory* healthPotion);
void printShop2(int gold, Inventory* actionItem, Inventory* healItem, Inventory* smokeBomb, Inventory* strengthPotion, Inventory* healthPotion);
