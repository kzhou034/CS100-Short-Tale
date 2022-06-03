#include "gtest/gtest.h"
#include "Character.hpp"

using namespace std;

TEST(EnemyTest, DefaultConstructorAndGetter){
    	Character* enemy;
    	enemy = new Enemy();

    	EXPECT_EQ(enemy->get_name(), "???");
    	EXPECT_EQ(enemy->get_type(), "???");
    	EXPECT_EQ(enemy->get_level(), 1);
    	EXPECT_EQ(enemy->get_health(), 10);
    	EXPECT_EQ(enemy->get_max_health(), 10);
    	EXPECT_EQ(enemy->get_attack(), 3);
    	EXPECT_EQ(enemy->get_defense(), 2);
    	EXPECT_EQ(enemy->get_resistance(), 2);
    	EXPECT_EQ(enemy->get_speed(), 5);

    	EXPECT_EQ(enemy->getCD(), 0);
    	EXPECT_EQ(enemy->getCD2(), 0);
    	EXPECT_EQ(enemy->getStatus(), false);       
}

TEST(EnemyTest, DefaultConstructorAndSetter){
    	Character* enemy;
    	enemy = new Enemy();

    	EXPECT_EQ(enemy->get_name(), "???");
    	EXPECT_EQ(enemy->get_type(), "???");
    	EXPECT_EQ(enemy->get_level(), 1);
    	EXPECT_EQ(enemy->get_health(), 10);
    	EXPECT_EQ(enemy->get_max_health(), 10);
    	EXPECT_EQ(enemy->get_attack(), 3);
    	EXPECT_EQ(enemy->get_defense(), 2);
    	EXPECT_EQ(enemy->get_resistance(), 2);
    	EXPECT_EQ(enemy->get_speed(), 5);

    	EXPECT_EQ(enemy->getCD(), 0);
    	EXPECT_EQ(enemy->getCD2(), 0);
    	EXPECT_EQ(enemy->getStatus(), false);
	
	    enemy->set_name("Error");
	    enemy->set_type("Mage");
	    enemy->set_level(1);
	    enemy->set_health(2);
	    enemy->set_max_health(2);
	    enemy->set_attack(3);
	    enemy->set_defense(4);
    	enemy->set_resistance(5);
    	enemy->set_speed(6);

    	EXPECT_EQ(enemy->get_name(), "Error");
    	EXPECT_EQ(enemy->get_type(), "Mage");
    	EXPECT_EQ(enemy->get_level(), 1);
    	EXPECT_EQ(enemy->get_health(), 2);
    	EXPECT_EQ(enemy->get_max_health(), 2);
    	EXPECT_EQ(enemy->get_attack(), 3);
    	EXPECT_EQ(enemy->get_defense(), 4);
    	EXPECT_EQ(enemy->get_resistance(), 5);
    	EXPECT_EQ(enemy->get_speed(), 6);

    	EXPECT_EQ(enemy->getCD(), 0);
    	EXPECT_EQ(enemy->getCD2(), 0);
    	EXPECT_EQ(enemy->getStatus(), false);       

	delete enemy;

}

TEST(EnemyTest, AdderAndSetter){
    	Character* enemy;
    	enemy = new Enemy();

    	EXPECT_EQ(enemy->get_name(), "???");
    	EXPECT_EQ(enemy->get_type(), "???");
    	EXPECT_EQ(enemy->get_level(), 1);
    	EXPECT_EQ(enemy->get_health(), 10);
    	EXPECT_EQ(enemy->get_max_health(), 10);
    	EXPECT_EQ(enemy->get_attack(), 3);
    	EXPECT_EQ(enemy->get_defense(), 2);
    	EXPECT_EQ(enemy->get_resistance(), 2);
    	EXPECT_EQ(enemy->get_speed(), 5);
	
    	EXPECT_EQ(enemy->getCD(), 0);
    	EXPECT_EQ(enemy->getCD2(), 0);
    	EXPECT_EQ(enemy->getStatus(), false);
	
    	enemy->set_name("Error");
    	enemy->set_type("Mage");
    	enemy->set_level(1);
    	enemy->set_health(2);
    	enemy->set_max_health(2);
    	enemy->set_attack(3);
    	enemy->set_defense(4);
    	enemy->set_resistance(5);
    	enemy->set_speed(6);

    	enemy->add_level(1);
    	enemy->add_health(1);
    	enemy->add_max_health(1);
    	enemy->add_attack(1);
    	enemy->add_defense(1);
    	enemy->add_resistance(1);
    	enemy->add_speed(1);

    	EXPECT_EQ(enemy->get_name(), "Error");
    	EXPECT_EQ(enemy->get_type(), "Mage");
    	EXPECT_EQ(enemy->get_level(), 2);
    	EXPECT_EQ(enemy->get_health(), 3);
    	EXPECT_EQ(enemy->get_max_health(), 3);
    	EXPECT_EQ(enemy->get_attack(), 4);
    	EXPECT_EQ(enemy->get_defense(), 5);
    	EXPECT_EQ(enemy->get_resistance(), 6);
    	EXPECT_EQ(enemy->get_speed(), 7);

    	EXPECT_EQ(enemy->getCD(), 0);
    	EXPECT_EQ(enemy->getCD2(), 0);
    	EXPECT_EQ(enemy->getStatus(), false);       
	
	delete enemy;
}
