#include "gtest/gtest.h"
#include "Character.hpp"

using namespace std;

TEST(KnightTest, Getter){
    Character* knight;
    knight = new Knight("Player", "Knight", 10, 6, 8, 6, 4);

    EXPECT_EQ(knight->get_name(), "Player");
    EXPECT_EQ(knight->get_type(), "Knight");
    EXPECT_EQ(knight->get_level(), 1);
    EXPECT_EQ(knight->get_health(), 10);
    EXPECT_EQ(knight->get_max_health(), 10);
    EXPECT_EQ(knight->get_attack(), 6);
    EXPECT_EQ(knight->get_defense(), 8);
    EXPECT_EQ(knight->get_resistance(), 6);
    EXPECT_EQ(knight->get_speed(), 4);

    EXPECT_EQ(knight->getCD(), 0);
    EXPECT_EQ(knight->getStatus(), false);

    delete knight;
}

TEST(KnightTest, DefaultConstructorAndSetter) {
	Character* knight;
	knight = new Knight();
	
	EXPECT_EQ(knight->get_name(), "unknown");
	EXPECT_EQ(knight->get_type(), "unknown");
	EXPECT_EQ(knight->get_level(), -1);
	EXPECT_EQ(knight->get_health(), -1);
	EXPECT_EQ(knight->get_max_health(), -1);
	EXPECT_EQ(knight->get_attack(), -1);
 	EXPECT_EQ(knight->get_defense(), -1);
    	EXPECT_EQ(knight->get_resistance(), -1);
    	EXPECT_EQ(knight->get_speed(), -1);

   	EXPECT_EQ(knight->getCD(), 0);
    	EXPECT_EQ(knight->getStatus(), false);
	
	knight->set_name("Error");
	knight->set_type("Knight");
	knight->set_level(1);
	knight->set_health(2);
	knight->set_max_health(2);
	knight->set_attack(3);
	knight->set_defense(4);
	knight->set_resistance(5);
	knight->set_speed(6);

	EXPECT_EQ(knight->get_name(), "Error");
        EXPECT_EQ(knight->get_type(), "Knight");
        EXPECT_EQ(knight->get_level(), 1);
        EXPECT_EQ(knight->get_health(), 2);
        EXPECT_EQ(knight->get_max_health(), 2);
        EXPECT_EQ(knight->get_attack(), 3);
        EXPECT_EQ(knight->get_defense(), 4);
        EXPECT_EQ(knight->get_resistance(), 5);
        EXPECT_EQ(knight->get_speed(), 6);

        EXPECT_EQ(knight->getCD(), 0);
        EXPECT_EQ(knight->getStatus(), false);

	delete knight;
} 

TEST(KnightTest, DefaultConstructorAndAdder) {
        Character* knight;
        knight = new Knight();

        knight->set_name("Error");
        knight->set_type("Knight");
        knight->set_level(1);
        knight->set_health(2);
        knight->set_max_health(2);
        knight->set_attack(3);
        knight->set_defense(4);
        knight->set_resistance(5);
        knight->set_speed(6);

        EXPECT_EQ(knight->get_name(), "Error");
        EXPECT_EQ(knight->get_type(), "Knight");
        EXPECT_EQ(knight->get_level(), 1);
        EXPECT_EQ(knight->get_health(), 2);
        EXPECT_EQ(knight->get_max_health(), 2);
        EXPECT_EQ(knight->get_attack(), 3);
        EXPECT_EQ(knight->get_defense(), 4);
        EXPECT_EQ(knight->get_resistance(), 5);
        EXPECT_EQ(knight->get_speed(), 6);

        EXPECT_EQ(knight->getCD(), 0);
        EXPECT_EQ(knight->getStatus(), false);

        knight->add_level(1);
        knight->add_health(1);
        knight->add_max_health(1);
        knight->add_attack(1);
        knight->add_defense(1);
        knight->add_resistance(1);
        knight->add_speed(1);

        EXPECT_EQ(knight->get_name(), "Error");
        EXPECT_EQ(knight->get_type(), "Knight");
        EXPECT_EQ(knight->get_level(), 2);
        EXPECT_EQ(knight->get_health(), 3);
        EXPECT_EQ(knight->get_max_health(), 3);
        EXPECT_EQ(knight->get_attack(), 4);
        EXPECT_EQ(knight->get_defense(), 5);
        EXPECT_EQ(knight->get_resistance(), 6);
        EXPECT_EQ(knight->get_speed(), 7);

        EXPECT_EQ(knight->getCD(), 0);
        EXPECT_EQ(knight->getStatus(), false);

        delete knight;
}
