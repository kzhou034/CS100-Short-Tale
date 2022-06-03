#include "gtest/gtest.h"
#include "Character.hpp"

using namespace std;

TEST(MageTest, Getter){
    	Character* mage;
    	mage = new Mage("Player", "Mage", 10, 6, 8, 6, 4);

    	EXPECT_EQ(mage->get_name(), "Player");
    	EXPECT_EQ(mage->get_type(), "Mage");
    	EXPECT_EQ(mage->get_level(), 1);
    	EXPECT_EQ(mage->get_health(), 10);
    	EXPECT_EQ(mage->get_max_health(), 10);
    	EXPECT_EQ(mage->get_attack(), 6);
    	EXPECT_EQ(mage->get_defense(), 8);
    	EXPECT_EQ(mage->get_resistance(), 6);
    	EXPECT_EQ(mage->get_speed(), 4);

    	EXPECT_EQ(mage->getCD(), 0);
    	EXPECT_EQ(mage->getCD2(), 0);
    	EXPECT_EQ(mage->getStatus(), false);       

	delete mage;

}

TEST(MageTest, DefaultConstructorAndSetter) {
        Character* mage;
        mage = new Mage();

        EXPECT_EQ(mage->get_name(), "unknown");
        EXPECT_EQ(mage->get_type(), "unknown");
        EXPECT_EQ(mage->get_level(), -1);
        EXPECT_EQ(mage->get_health(), -1);
        EXPECT_EQ(mage->get_max_health(), -1);
        EXPECT_EQ(mage->get_attack(), -1);
        EXPECT_EQ(mage->get_defense(), -1);
        EXPECT_EQ(mage->get_resistance(), -1);
        EXPECT_EQ(mage->get_speed(), -1);

        EXPECT_EQ(mage->getCD(), 0);
        EXPECT_EQ(mage->getStatus(), false);

        mage->set_name("Error");
        mage->set_type("Mage");
        mage->set_level(1);
        mage->set_health(2);
        mage->set_max_health(2);
        mage->set_attack(3);
        mage->set_defense(4);
        mage->set_resistance(5);
        mage->set_speed(6);

        EXPECT_EQ(mage->get_name(), "Error");
        EXPECT_EQ(mage->get_type(), "Mage");
        EXPECT_EQ(mage->get_level(), 1);
        EXPECT_EQ(mage->get_health(), 2);
        EXPECT_EQ(mage->get_max_health(), 2);
        EXPECT_EQ(mage->get_attack(), 3);
        EXPECT_EQ(mage->get_defense(), 4);
        EXPECT_EQ(mage->get_resistance(), 5);
        EXPECT_EQ(mage->get_speed(), 6);

        EXPECT_EQ(mage->getCD(), 0);
        EXPECT_EQ(mage->getCD2(), 0);
        EXPECT_EQ(mage->getStatus(), false);

        delete mage;
}

TEST(MageTest, AdderAndSetter) {
        Character* mage;
        mage = new Mage();

        mage->set_name("Error");
        mage->set_type("Mage");
        mage->set_level(1);
        mage->set_health(2);
        mage->set_max_health(2);
        mage->set_attack(3);
        mage->set_defense(4);
        mage->set_resistance(5);
        mage->set_speed(6);

        EXPECT_EQ(mage->get_name(), "Error");
        EXPECT_EQ(mage->get_type(), "Mage");
        EXPECT_EQ(mage->get_level(), 1);
        EXPECT_EQ(mage->get_health(), 2);
        EXPECT_EQ(mage->get_max_health(), 2);
        EXPECT_EQ(mage->get_attack(), 3);
        EXPECT_EQ(mage->get_defense(), 4);
        EXPECT_EQ(mage->get_resistance(), 5);
        EXPECT_EQ(mage->get_speed(), 6);

        EXPECT_EQ(mage->getCD(), 0);
        EXPECT_EQ(mage->getCD2(), 0);
        EXPECT_EQ(mage->getStatus(), false);

        mage->add_level(1);
        mage->add_health(1);
        mage->add_max_health(1);
        mage->add_attack(1);
        mage->add_defense(1);
        mage->add_resistance(1);
        mage->add_speed(1);

        EXPECT_EQ(mage->get_name(), "Error");
        EXPECT_EQ(mage->get_type(), "Mage");
        EXPECT_EQ(mage->get_level(), 2);
        EXPECT_EQ(mage->get_health(), 3);
        EXPECT_EQ(mage->get_max_health(), 3);
        EXPECT_EQ(mage->get_attack(), 4);
        EXPECT_EQ(mage->get_defense(), 5);
        EXPECT_EQ(mage->get_resistance(), 6);
        EXPECT_EQ(mage->get_speed(), 7);

        EXPECT_EQ(mage->getCD(), 0);
        EXPECT_EQ(mage->getCD2(), 0);
        EXPECT_EQ(mage->getStatus(), false);

        delete mage;
}
