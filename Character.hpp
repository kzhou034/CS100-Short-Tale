#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

//component
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
        	virtual ~Character() {};

		// setters/getters/stat changes
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

		// new skills/attacks?
		virtual bool pickLock() = 0;

		// add/remove
		virtual void add(Character* ) = 0;
        	virtual void remove(Character* ) = 0;
};

//leaf

class Knight : public Character {
    private:
        string name;
        string type;

        int max_level;
        int max_health;
        int max_lockpicks = 0;
	// int max_attack;
	// int max_defense;
	// int max_resistance;
	// int max_speed
	
	int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;

        bool lockPick = false;

   public:
	Knight() {
            name = "unknown";
            type = "unknown";
            
            max_level = -1;
            max_health = -1;
	    // max_attack = -1;
	    // max_defense = -1;
	    // max_resistance = -1;
	    // max_speed = -1;
	    
	    level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;

        };
        ~Knight() {};

	//format: Knight(Name, TypeName, health, attack, defense, resistance, speed)
	Knight(const string &_name, const string &_type, int _health, int _attack, int _defense , int _resistance , int _speed) {
            name = _name;  
            type = _type;
	    
	    //when we do damage calculations: after battle, set the stats back to these
	    max_level = 5;
            max_health = _health;
	    // max_attack = _attack;
	    // max_defense = _defense;
	    // max_resistance = _resistance;
	    // max_speed = _speed;
	    
	    level = 1;
            health = _health;
            attack = _attack;
            defense = _defense;
            resistance = _resistance;
            speed = _speed;
        };

	void set_name(string a) {name = a;};
        void set_type(string a) {type = a;};
        void set_level(int x) {level = x;};
        void set_health(int x) {health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

	//Knight can't do this
	bool pickLock() {
            if (level == 2 && type == "rogue" && max_lockpicks > 0) {
                lockPick = true;
                max_lockpicks--;
                return true;
            }
            return false;
        };

	//Knight can't do these
	void add(Character* ) {};
        void remove(Character* ) {};

};

//leaf
class Mage : public Character {
    private:
        string name;
        string type;

        int max_level;
        int max_health;
        int max_lockpicks = 0;
	// int max_attack;
	// int max_defense;
	// int max_resistance;
	// int max_speed;
	
	int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;

        bool lockPick = false;

    public:
        Mage() {
            name = "unknown";
            type = "unknown";
            
            max_level = -1;
            max_health = -1;
	    // max_attack = -1;
	    // max_defense = -1;
	    // max_resistance = -1;
	    // max_speed = -1;
	    
	    level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;

        };
        ~Mage() {};

	//format: Knight(Name, TypeName, health, attack, defense, resistance, speed)
	Mage(const string & _name, const string & _type, int _health, int _attack, int _defense , int _resistance , int _speed){
            name = _name;
            type = _type;

	    //when we do damage calculations: after battle, set the stats back to these
	    max_level = 5;
            max_health = _health;
            // max_attack = _attack;
            // max_defense = _defense;
            // max_resistance = _resistance;
            // max_speed = _speed;

	    level = 1;
            health = _health;
            attack = _attack;
            defense = _defense;
            resistance = _resistance;
            speed = _speed;
        };

        void set_name(string a) {name = a;};
        void set_type(string a) {type = a;};
        void set_level(int x) {level = x;};
        void set_health(int x) {health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

	//Mage can't do this
	bool pickLock() {
            if (level == 2 && type == "rogue" && max_lockpicks > 0) {
                lockPick = true;
                max_lockpicks--;
                return true;
            }
            return false;
        };

	//Mage can't do these
	void add(Character* ) {};
        void remove(Character* ) {};

};      

//leaf
class Rogue : public Character {
    private:
        string name;
        string type;

        int max_level;
        int max_health;
        int max_lockpicks = 2;
	// int max_attack;
	// int max_defense;
	// int max_resistance;
	// int max_speed;
	
	int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;

        bool lockPick = true;

    public:
        Rogue() {
            name = "unknown";
            type = "unknown";
            
            max_level = -1;
            max_health = -1;
	    // max_attack = -1;
	    // max_defense = -1;
	    // max_resistance = -1;
	    // max_speed = -1;
	    
	    level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;

        };
        ~Rogue() {};

        //format: Rogue(Name, TypeName, health, attack, defense, resistance, speed)
        Rogue(const string & _name, const string & _type, int _health, int _attack, int _defense , int _resistance , int _speed){
            name = _name;
            type = _type;

            //when we do damage calculations: after battle, set the stats back to these
            max_level = 5;
            max_health = _health;
            // max_attack = _attack;
            // max_defense = _defense;
            // max_resistance = _resistance;
            // max_speed = _speed;
            
	    level = 1;
            health = _health;
            attack = _attack;
            defense = _defense;
            resistance = _resistance;
            speed = _speed;
        };

        void set_name(string a) {name = a;};
        void set_type(string a) {type = a;};
        void set_level(int x) {level = x;};
        void set_health(int x) {health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

        bool pickLock() {
            if (level == 2 && type == "rogue" && max_lockpicks > 0) {
                lockPick = true;
                max_lockpicks--;
                return true;
            }
            return false;
        }; 

	//Rogue can't do these
	void add(Character* ) {};
	void remove(Character* ) {};
};

#endif //__CHARACTER_HPP__


