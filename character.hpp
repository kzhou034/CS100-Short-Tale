fndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

class Character {
	protected:
		string name;
		string type;
		int level;
		int health;
		int defense;
		int resistance;
		int speed;

	public: 
		Character() {};
        	~Character() {};

		virtual void set_name(string) = 0;
        	virtual void set_type(string) = 0;
        	virtual void set_level(int) = 0;
        	virtual void set_health(int) = 0;
        	virtual void set_attack(int) = 0;
        	virtual void set_defense(int) = 0;
        	virtual void set_resistance(int) = 0;
        	virtual void set_speed(int) = 0;

        	virtual void add_level(int) = 0;
        	virtual void add_health(int) = 0;
        	virtual void add_attack(int) = 0;
        	virtual void add_defense(int) = 0;
        	virtual void add_resistance(int) = 0;
        	virtual void add_speed(int) = 0;

        	virtual string get_name() = 0;
        	virtual string get_type() = 0;
        	virtual int get_level() = 0;
        	virtual int get_health() = 0;
        	virtual int get_attack() = 0;
        	virtual int get_defense() = 0;
        	virtual int get_resistance() = 0;
        	virtual int get_speed() = 0;

		virtual bool pickLock() = 0;

		virtual void add(Character* ) = 0;
        	virtual void remove(Character* ) = 0;
};

#endif
