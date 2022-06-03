#ifndef __UNIT_TEST_CPP__
#define __UNIT_TEST_CPP__
#include "gtest/gtest.h"

#include "Inventory.hpp"
#include "Character.hpp"

int main(int argc, char **argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

TEST(ActionItemTests, NameGetter){
        Inventory* temp = new ActionItem();
        EXPECT_EQ(temp->getItemName(), "Action Item");
        delete temp;
}

TEST(ActionItemTests, checkLeftSet){
        Inventory* temp = new ActionItem();
        Inventory* temp2 = new StrengthPotion();
        temp->setChildLeft(temp2);
        EXPECT_EQ(temp->getLeftChild(), temp2);
        delete temp;
	delete temp2;
}

TEST(ActionItemTests, checkRightSet){
        Inventory* temp = new ActionItem();
        Inventory* temp2 = new StrengthPotion();
        temp->setChildRight(temp2);
        EXPECT_EQ(temp->getRightChild(), temp2);
        delete temp;
	delete temp2;
}


TEST(HealItemTests, NameGetter){
        Inventory* temp = new HealItem();
        EXPECT_EQ(temp->getItemName(), "Heal Item");
        delete temp;
}

TEST(HealItemTests, checkLeftSet){
        Inventory* temp = new HealItem();
        Inventory* temp2 = new HealthPotion();
        temp->setChildLeft(temp2);
        EXPECT_EQ(temp->getLeftChild(), temp2);
        delete temp;
	delete temp2;
}

TEST(HealItemTests, checkRightSet){
        Inventory* temp = new HealItem();
        Inventory* temp2 = new HealthPotion();
        temp->setChildRight(temp2);
        EXPECT_EQ(temp->getRightChild(), temp2);
        delete temp;
	delete temp2;
}



TEST(SmokeBombTest, getSmokeBombName){
        Inventory* temp = new SmokeBomb();
        EXPECT_EQ(temp->getItemName(), "Smoke Bomb");
        delete temp;
}

TEST(HealthPotionTest, getHealthPotionName){
	Inventory* temp = new HealthPotion();
	EXPECT_EQ(temp->getItemName(), "Health Potion");
	delete temp;
}

TEST(StrengthPotionTest, getStrengthPotionName){
	Inventory* temp = new StrengthPotion();
	EXPECT_EQ(temp->getItemName(), "Strength Potion");
	delete temp;
}
#endif

