#include "gtest/gtest.h"
#include "Character.hpp"

using namespace std;

TEST(RogueTest, Getter){
    	Character* rogue;
    	rogue = new Rogue("Player", "Rogue", 10, 6, 8, 6, 4);

    	EXPECT_EQ(rogue->get_name(), "Player");
    	EXPECT_EQ(rogue->get_type(), "Rogue");
    	EXPECT_EQ(rogue->get_level(), 1);
    	EXPECT_EQ(rogue->get_health(), 10);
    	EXPECT_EQ(rogue->get_max_health(), 10);
    	EXPECT_EQ(rogue->get_attack(), 6);
    	EXPECT_EQ(rogue->get_defense(), 8);
    	EXPECT_EQ(rogue->get_resistance(), 6);
    	EXPECT_EQ(rogue->get_speed(), 4);

    	EXPECT_EQ(rogue->getCD(), 0);
    	EXPECT_EQ(rogue->getCD2(), 0);
    	EXPECT_EQ(rogue->getStatus(), false);       

	delete rogue;

}

TEST(RogueTest, DefaultConstructorAndSetter) {
        Character* rogue;
        rogue = new Rogue();

        EXPECT_EQ(rogue->get_name(), "unknown");
        EXPECT_EQ(rogue->get_type(), "unknown");
        EXPECT_EQ(rogue->get_level(), -1);
        EXPECT_EQ(rogue->get_health(), -1);
        EXPECT_EQ(rogue->get_max_health(), -1);
        EXPECT_EQ(rogue->get_attack(), -1);
        EXPECT_EQ(rogue->get_defense(), -1);
        EXPECT_EQ(rogue->get_resistance(), -1);
        EXPECT_EQ(rogue->get_speed(), -1);

        EXPECT_EQ(rogue->getCD(), 0);
        EXPECT_EQ(rogue->getCD2(), 0);
        EXPECT_EQ(rogue->getStatus(), false);

        rogue->set_name("Error");
        rogue->set_type("Rogue");
        rogue->set_level(1);
        rogue->set_health(2);
        rogue->set_max_health(2);
        rogue->set_attack(3);
        rogue->set_defense(4);
        rogue->set_resistance(5);
        rogue->set_speed(6);

        EXPECT_EQ(rogue->get_name(), "Error");
        EXPECT_EQ(rogue->get_type(), "Rogue");
        EXPECT_EQ(rogue->get_level(), 1);
        EXPECT_EQ(rogue->get_health(), 2);
        EXPECT_EQ(rogue->get_max_health(), 2);
        EXPECT_EQ(rogue->get_attack(), 3);
        EXPECT_EQ(rogue->get_defense(), 4);
        EXPECT_EQ(rogue->get_resistance(), 5);
        EXPECT_EQ(rogue->get_speed(), 6);

        EXPECT_EQ(rogue->getCD(), 0);
        EXPECT_EQ(rogue->getCD2(), 0);
        EXPECT_EQ(rogue->getStatus(), false);

        delete rogue;
}

TEST(RogueTest, AdderAndSetter) {
        Character* rogue;
        rogue = new Rogue();

        rogue->set_name("Error");
        rogue->set_type("Rogue");
        rogue->set_level(1);
        rogue->set_health(2);
        rogue->set_max_health(2);
        rogue->set_attack(3);
        rogue->set_defense(4);
        rogue->set_resistance(5);
        rogue->set_speed(6);

        EXPECT_EQ(rogue->get_name(), "Error");
        EXPECT_EQ(rogue->get_type(), "Rogue");
        EXPECT_EQ(rogue->get_level(), 1);
        EXPECT_EQ(rogue->get_health(), 2);
        EXPECT_EQ(rogue->get_max_health(), 2);
        EXPECT_EQ(rogue->get_attack(), 3);
        EXPECT_EQ(rogue->get_defense(), 4);
        EXPECT_EQ(rogue->get_resistance(), 5);
        EXPECT_EQ(rogue->get_speed(), 6);

        EXPECT_EQ(rogue->getCD(), 0);
        EXPECT_EQ(rogue->getCD2(), 0);
        EXPECT_EQ(rogue->getStatus(), false);

        rogue->add_level(1);
        rogue->add_health(1);
        rogue->add_max_health(1);
        rogue->add_attack(1);
        rogue->add_defense(1);
        rogue->add_resistance(1);
        rogue->add_speed(1);

        EXPECT_EQ(rogue->get_name(), "Error");
        EXPECT_EQ(rogue->get_type(), "Rogue");
        EXPECT_EQ(rogue->get_level(), 2);
        EXPECT_EQ(rogue->get_health(), 3);
        EXPECT_EQ(rogue->get_max_health(), 3);
        EXPECT_EQ(rogue->get_attack(), 4);
        EXPECT_EQ(rogue->get_defense(), 5);
        EXPECT_EQ(rogue->get_resistance(), 6);
        EXPECT_EQ(rogue->get_speed(), 7);

        EXPECT_EQ(rogue->getCD(), 0);
        EXPECT_EQ(rogue->getCD2(), 0);
        EXPECT_EQ(rogue->getStatus(), false);

        delete rogue;
}
