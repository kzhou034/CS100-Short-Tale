#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <ctime>

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
      virtual ~Character() {};

		virtual void set_name(string) = 0;
        virtual void set_type(string) = 0;
        virtual void set_level(int) = 0;
        virtual void set_health(int) = 0;
        virtual void set_max_health(int) = 0;
        virtual void set_attack(int) = 0;
        virtual void set_defense(int) = 0;
        virtual void set_resistance(int) = 0;
        virtual void set_speed(int) = 0;

        virtual void add_level(int) = 0;
        virtual void add_health(int) = 0;
        virtual void add_max_health(int) = 0;
        virtual void add_attack(int) = 0;
        virtual void add_defense(int) = 0;
        virtual void add_resistance(int) = 0;
        virtual void add_speed(int) = 0;

        virtual string get_name() = 0;
        virtual string get_type() = 0;
        virtual int get_level() = 0;
        virtual int get_health() = 0;
        virtual int get_max_health() = 0;
        virtual int get_attack() = 0;
        virtual int get_defense() = 0;
        virtual int get_resistance() = 0;
        virtual int get_speed() = 0;
        virtual bool getStatus() = 0; 
        virtual int getCD() = 0;
        virtual int getCD2() = 0;

        virtual void setCD() = 0;
        virtual void redCD() = 0;
        virtual void setCD2() = 0;
        virtual void redCD2() = 0;
        virtual void setlevel(int) = 0; 
		    virtual void heal() = 0;
		    virtual void atk(Character* target) = 0;
		    virtual void hurt(Character* target) = 0;
		    virtual void print() = 0;
		    virtual void action(Character*) = 0;
        virtual void raiseshield() = 0;
        virtual void lowershield() = 0;
        virtual void holysmite(Character* target) = 0;
        virtual void sneakattack(Character* target) = 0;
        virtual void shadowshift(Character* target) = 0;
        virtual void mindtrick(Character* target) = 0;
        virtual void voidBlast(Character* target) = 0;
        virtual void thunderCloud(Character* target) = 0;
        virtual void waningMoon(Character* target) = 0;
		    virtual bool pickLock() = 0;
      
};

class Knight : public Character {
    private:
        string name;
        string type;

        int max_health;
        int max_lockpicks = 0;

        int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;
        int skillcd = 0;
        bool shieldraised = false;
        bool lockPick = false;

    public:
        Knight() {
            name = "unknown";
            type = "unknown";
            
            max_health = -1;
            max_lockpicks = -1;

            level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;
        };
        ~Knight() {};


        Knight(const string & _name, const string & _type, int _health, int _attack, int _defense , int _resistance , int _speed) {
            name = _name;
            type = _type;

            max_lockpicks = 0;
            max_health = _health;

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
        void set_max_health(int x) {max_health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_max_health(int x) {max_health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_max_health() {return max_health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

        void setlevel(int l) {
            level = l;

            max_health = 7 * pow(l, 1.5);
            health = max_health;

            attack = 8 * pow(l, 1.2);

            defense = 3 * pow(l, 1.7);

            resistance = 4 * pow(l, 1.5);

            speed = 6 * pow(l, 1.3);
        };
        void heal() {
            double amt;
            double mult = 0.05 * level;
            amt = mult * max_health;
            amt++;

            if (amt + health >= max_health) {
                health = max_health;
            }
            else {
                health += amt;
            }
        };

        void atk(Character* target) {
            int dmg = get_attack();
            double realdmg1 = 75;
            double realdmg2 = 0;
            if (get_type() == "Mage") {
                dmg -= target->get_resistance();
            }
            else {
                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            
            if (dmg < 0) {
                dmg = 0;
            }

            target->set_health(target->get_health() - dmg);

            cout << target->get_name() << " took " << dmg << " points of damage" << endl;
        };

        void hurt(Character* target) { 
            int dmg;
            if (target->get_type() == "Mage") {
                dmg = target->get_attack() - get_resistance();
            }
            else {
                dmg = target->get_attack() - get_defense();
            }

            if (dmg < 0)
                dmg = 0;
            
            set_health(get_health() - dmg);

            cout << get_name() << " took " << dmg << " points of damage" << endl;
        };

        void print() {
            cout << "Name: " << get_name() << endl;
            cout << "Level: " << get_level() << endl;
            cout << "Health: " << get_health() << "/" << get_max_health() << endl;
        };

        void action(Character* target) {};
        void raiseshield() {
            defense *= 1.5;
            attack *= 0.5;
            shieldraised = true;
        };
        void lowershield() {
            defense /= 1.5;
            attack /= 0.5;
            shieldraised = false;
        };
        void holysmite(Character* target) {
          int dmg = target->get_max_health() * 0.3;

          target->set_health(target->get_health() - dmg);

          cout << target->get_name() << " took " << dmg << " points of damage" << endl;
        };
        int getCD(){
          return skillcd;
        };
        void setCD(){
          skillcd++;
        };
        void redCD(){
          skillcd--;
        };
        bool getStatus() {
          if(shieldraised){
            return true;
          }
          else{
            return false;
          }
        }; 
        //Knight can't do this
        void setCD2(){};
        void redCD2(){};
        int getCD2(){return 0;};
        void sneakattack(Character* target){};
        void shadowshift(Character* target){};
        void mindtrick(Character* target){};
        bool pickLock() {return false;};
        void voidBlast(Character* target){};
        void thunderCloud(Character* target){};
        void waningMoon(Character* target){};
        
};

class Mage : public Character {
    private:
        string name;
        string type;

        int max_health;
        int max_lockpicks = 0;

        int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;

        int skillcd;
        int skillcd2;
        bool lockPick = false;

    public:
        Mage() {
            name = "unknown";
            type = "unknown";
            
            max_lockpicks = -1;
            max_health = -1;

            level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;

        };
        ~Mage() {};

        Mage(const string & _name, const string & _type, int _health, int _attack, int _defense , int _resistance , int _speed) : Character() {
            name = _name;
            type = _type;

            max_lockpicks = 0;
            max_health = _health;

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
        void set_max_health(int x) {max_health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_max_health(int x) {max_health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_max_health() {return max_health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

        void setlevel(int l) {
            level = l;

            max_health = 7 * pow(l, 1.5);
            health = max_health;

            attack = 8 * pow(l, 1.2);

            defense = 3 * pow(l, 1.7);

            resistance = 4 * pow(l, 1.5);

            speed = 6 * pow(l, 1.3);
        };
        void heal() {
            double amt;
            double mult = 0.05 * level;
            amt = mult * max_health;
            amt++;

            if (amt + health >= max_health) {
                health = max_health;
            }
            else {
                health += amt;
            }
        };

        void atk(Character* target) {
            int dmg = get_attack();
            double realdmg1 = 75;
            double realdmg2 = 0;
            if (get_type() == "Mage") {
                realdmg2 = (75 + target->get_resistance());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            else {
                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            
            if (dmg < 0) {
                dmg = 0;
            }

            target->set_health(target->get_health() - dmg);

            cout << target->get_name() << " took " << dmg << " points of damage" << endl;
        };

        void hurt(Character* target) { 
            int dmg;
            if (target->get_type() == "Mage") {
                dmg = target->get_attack() - get_resistance();
            }
            else {
                dmg = target->get_attack() - get_defense();
            }

            if (dmg < 0)
                dmg = 0;
            
            set_health(get_health() - dmg);

            cout << get_name() << " took " << dmg << " points of damage" << endl;
        };

        void print() {
            cout << "Name: " << get_name() << endl;
            cout << "Level: " << get_level() << endl;
            cout << "Health: " << get_health() << "/" << get_max_health() << endl;
        };

        void action(Character* target) {};
    
        //Mage can't do this
        bool pickLock() {return false;}; 
        void raiseshield() {};
        void lowershield() {};
        void holysmite(Character* target) {};
        bool getStatus() {return false;};
        int getCD(){
          return skillcd;
        };
        void setCD(){
          skillcd++;
        };
        void redCD(){
          skillcd--;
        };
        void setCD2() {
          skillcd2++;
        };
        void redCD2() {
          skillcd2--;
        };
        int getCD2(){
          return skillcd2;
        };
        void sneakattack(Character* target) {};
        void shadowshift(Character* target) {};
        void mindtrick(Character* target) {};
        void voidBlast(Character* target){
            int dmg = get_attack() * 1.2;
            double realdmg1 = 75;
            double realdmg2 = 0;

                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;

            target->set_health(target->get_health() - dmg);
            cout << "You cast a spell of the void against " << target->get_name() << "."<< endl;
            cout << target->get_name() << " took " << dmg << " points of damage." << endl;
        };
        void thunderCloud(Character* target){
          int dmg = get_attack() * 1.4;
            double realdmg1 = 75;
            double realdmg2 = 0;

                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            target->set_health(target->get_health() - dmg);
            cout << "You cast a spell of thunder against " << target->get_name() << "."<< endl;
            cout << target->get_name() << " took " << dmg << " points of damage." << endl;
        };
        void waningMoon(Character* target){
            int dmg = get_attack() * 1.2;

            int heal = 0.2 * get_max_health();


            double realdmg1 = 75;
            double realdmg2 = 0;
            if (get_type() == "Mage") {
                realdmg2 = (75 + target->get_resistance());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            else {
                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            target->set_health(target->get_health() - dmg);

            set_health(get_health() + heal);


          
            cout << "You cast a spell of moon's blessing.\n" << endl;
            cout << "You heal " << heal << " points of health." << endl; 
            cout << target->get_name() << " took " << dmg << " points of damage." << endl;
        };
};           

class Rogue : public Character {
    private:
        string name;
        string type;

        int max_level;
        int max_health;
        int max_lockpicks = 2;

        int level;
        int health;
        int attack;
        int defense;
        int resistance;
        int speed;
        int skillcd;
        int skillcd2;
        bool isShrouded = false;
        bool lockPick = true;

    public:
        Rogue() {
            name = "unknown";
            type = "unknown";
            
            max_level = -1;
            max_health = -1;

            level = -1;
            health = -1;
            attack = -1;
            defense = -1;
            resistance = -1;
            speed = -1;

        };
        ~Rogue() {};


        Rogue(const string & _name, const string & _type, int _health, int _attack, int _defense , int _resistance , int _speed) {

            name = _name;
            type = _type;

            max_health = _health;

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
        void set_max_health(int x) {max_health = x;};
        void set_attack(int x) {attack = x;};
        void set_defense(int x) {defense = x;};
        void set_resistance(int x) {resistance = x;};
        void set_speed(int x) {speed = x;};

        void add_level(int x) {level += x;};
        void add_health(int x) {health += x;};
        void add_max_health(int x) {max_health += x;};
        void add_attack(int x) {attack += x;};
        void add_defense(int x) {defense += x;};
        void add_resistance(int x) {resistance += x;};
        void add_speed(int x) {speed += x;};

        string get_name() {return name;};
        string get_type() {return type;};
        int get_level() {return level;};
        int get_health() {return health;};
        int get_max_health() {return max_health;};
        int get_attack() {return attack;};
        int get_defense() {return defense;};
        int get_resistance() {return resistance;};
        int get_speed() {return speed;};

        void setlevel(int l) {
            level = l;

            max_health = 6 * pow(l, 1.5);
            health = max_health;

            attack = 8 * pow(l, 1.2);

            defense = 3 * pow(l, 1.7);

            resistance = 2 * pow(l, 1.5);

            speed = 8 * pow(l, 1.3);
        };

        void heal() {
            double amt;
            double mult = 0.05 * level;
            amt = mult * max_health;
            amt++;

            if (amt + health >= max_health) {
                health = max_health;
            }
            else {
                health += amt;
            }
        };

        void atk(Character* target) {
            int dmg = get_attack();
            double realdmg1 = 75;
            double realdmg2 = 0;
            srand(time(0));

            if (get_type() == "Mage") {
                realdmg2 = (75 + target->get_resistance());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            else {
                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            
            if (dmg < 0) {
                dmg = 0;
            }
            
            int mod = rand();

            if (mod % 3 == 0) {
                dmg += 4;
            }

            target->set_health(target->get_health() - dmg);

            cout << target->get_name() << " took " << dmg << " points of damage" << endl;
        };

        void hurt(Character* target) { 
            int dmg;
            if (target->get_type() == "Mage") {
                dmg = target->get_attack() - get_resistance();
            }
            else {
                dmg = target->get_attack() - get_defense();
            }

            if (dmg < 0)
                dmg = 0;
            
            set_health(get_health() - dmg);

            cout << get_name() << " took " << dmg << " points of damage" << endl;
        };

        void print() {
            cout << "Name: " << get_name() << endl;
            cout << "Level: " << get_level() << endl;
            cout << "Health: " << get_health() << "/" << get_max_health() << endl;
        };

        void action(Character* target) {};

        bool pickLock() {

            if (max_lockpicks > 0) {

                lockPick = true;
                max_lockpicks--;
                return true;
            }
            return false;
        }; 
        void raiseshield() {
          isShrouded = true;
        };
        void lowershield() {
          isShrouded = false;
        };
        void holysmite(Character* target) {};
        bool getStatus() {
          if(isShrouded){
            return true;
          }
          else{
            return false;
          }
          }; 
        int getCD(){
          return skillcd;
        };
        int getCD2(){
          return skillcd2;
        };
        void setCD(){
          skillcd++;
        };
        void redCD(){
          skillcd--;
        };
        void setCD2() {
          skillcd2++;
        };
        void redCD2() {
          skillcd2--;
        };
        void sneakattack(Character* target) {
            int dmg = get_attack();
            double realdmg1 = 75;
            double realdmg2 = 0;
            srand(time(0));

            if (get_type() == "Mage") {
                realdmg2 = (75 + target->get_resistance());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            else {
                realdmg2 = (75 + (0.5*target->get_defense()));
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            
            if (dmg < 0) {
                dmg = 0;
            }
            
            int mod = rand();

            if (mod % 3 == 0) {
                dmg += 4;
            }

            target->set_health(target->get_health() - dmg);
            cout << "You backstab the " << target->get_name() << "."<< endl;
            cout << target->get_name() << " took " << dmg << " points of damage." << endl;
        };
        void shadowshift(Character* target) {
          cout << "You enshroud yourself in a cloud of smoke." << endl;
          attack *= 1.1;
          cout << "You gain bonus attack damage.\n" << endl;
          int defense = target->get_defense();
          defense *= .1;
          target->add_defense(defense);
          cout << "You reduce " << target->get_name() << "'s defense." << endl;
        };
        void mindtrick(Character* target) {
          cout << "You confuse the " << target->get_name() << ".\n" << endl;
          int defense = target->get_defense();
          defense *= .1;
          target->add_defense(defense);
          cout << "You reduce " << target->get_name() << "'s defense." << endl;
        };
        void voidBlast(Character* target){};
        void thunderCloud(Character* target){};
        void waningMoon(Character* target){};
};

class Enemy : public Character {
	private:
		string name;
		string type;
		int level;
		int health;
		int mhealth;
		int attack;
		int defense;
		int resistance;
		int speed;

        int max_lockpicks = 0;

        bool lockPick = false;
    public:
        Enemy() {
            name = "???";
            type = "???";
            level = 1;
            health = 10;
            mhealth = 10;
            attack = 3;
            defense = 2;
            resistance = 2;
            speed = 5;
        };
        
		Enemy(const string n, const string t, const int l, const int h, const int a, const int d, const int r, const int s) {
            name = n;
            type = t;
            level = l;
            health = h;
            mhealth = h;
            attack = a;
            defense = d;
            resistance = r;
            speed = s;
        };

		~Enemy() {};

		void set_name(string n) {
            name = n;
        }
		void set_type(string t) {
            type = t;
        };
		void set_level(int l) {
            level = l;
        };
		void set_health(int h) {
            health = h;
        };
		void set_max_health(int m) {
            mhealth = m;
        };
		void set_attack(int a) {
            attack = a;
        };
		void set_defense(int d) {
            defense = d;
        };
		void set_resistance(int r) {
            resistance = r;
        };
		void set_speed(int s) {
            speed = s;
        };
		
        void add_level(int l) {
            level += l;
        };
        void add_health(int h) {
            health += h;
        };
        void add_max_health(int m) {
            mhealth += m;
        };
        void add_attack(int a) {
            attack += a;
        };
        void add_defense(int d) {
            defense += d;
        };
        void add_resistance(int r) {
            resistance += r;
        };
        void add_speed(int s) {
            speed += s;
        };

        string get_name() {
            return name;
        };
        string get_type() {
            return type;
        };
        int get_level() {
            return level;
        };
        int get_health() {
            return health;
        };
        int get_max_health() {
            return mhealth;
        };
        int get_attack() {
            return attack;
        };
        int get_defense() {
            return defense;
        };
        int get_resistance() {
            return resistance;
        };
        int get_speed() {
            return speed;
        };

		void setlevel(int l) { 
            int mod = rand() % l;

            level = l;

            mhealth *= pow(l, 2);
            mhealth += mod;
            health = mhealth;

            attack *= pow(l, 1.2);

            attack += mod;

            defense *= pow(l, 1.7);
            defense -= mod;

            resistance *= pow(l, 1.7);
            resistance -= mod;

            speed *= pow(l, 1.3);
            speed += mod;
        };
        
        void heal() {
            double amt;

            double mult = level;
            if(get_level() > 4){
              mult *= 0.035;
            }
          else{
            mult *= 0.05;
          }

            amt = mult * mhealth;
            amt++;

            if (amt + health >= mhealth) {
                health = mhealth;
            }
            else {
                health += amt;
            }

            int val = amt;
            cout << "The " << get_name() << " healed for " << val << "." << endl;

        };

        void atk(Character* target) {
            int dmg = get_attack();
            double realdmg1 = 75;
            double realdmg2 = 0;
            int mod = rand() % (get_level() * 3);
            srand(time(0));
            int ch = rand() % 3;

            if (ch == 0) {
                dmg += mod;
            }
            else if (ch == 1) {
                dmg -= mod;
            }

            if (get_type() == "Mage") {
                realdmg2 = (75 + target->get_resistance());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            else {
                realdmg2 = (75 + target->get_defense());
                realdmg1 /= realdmg2;
                dmg *= realdmg1;
            }
            
            if (dmg <= 0)
                dmg = 1 + rand() % 1;

            target->set_health(target->get_health() - dmg);
            cout << get_name() << " attacks " << target->get_name() << "." << endl;
            cout << target->get_name() << " took " << dmg << " points of damage" << endl;
        };

        void hurt(Character* target) { 
            int dmg;
            if (target->get_type() == "Mage") {
                dmg = target->get_attack() - get_resistance();
            }
            else {
                dmg = target->get_attack() - get_defense();
            }

            if (dmg < 0)
                dmg = 0;
            
            set_health(get_health() - dmg);

            cout << get_name() << " took " << dmg << " points of damage" << endl;
        };

        void print() {
            cout << "Name: " << get_name() << endl;
            cout << "Level: " << get_level() << endl;
            cout << "Health: " << get_health() << "/" << get_max_health() << endl;
        };

        void action(Character* target) {
            srand(time(0));
            int act = rand() % 100;

            if (get_health() > (get_max_health() / 2)) {
                if (act < 80) {
                    atk(target);
                }
                else {
                    heal();
                }
            }
            else if (get_health() > (get_max_health() / 4)) {

                if (act < 70) {

                    atk(target);
                }
                else {
                    heal();
                }
            }
            else {
                if (act < 50) {
                    atk(target);
                }
                else {
                    heal();
                }
            }
        };

		bool pickLock() {return false;}; 
    void raiseshield() {};
    void lowershield() {};
    void holysmite(Character* target) {};
    bool getStatus() {return false;}; 
      int getCD(){return 0;
        };
        void setCD(){
        };
        void redCD(){
        };
      void setCD2() {};
        void redCD2() {};
        int getCD2(){return 0;};
        void sneakattack(Character* target) {};
        void shadowshift(Character* target) {};
        void mindtrick(Character* target) {};
        void voidBlast(Character* target){};
        void thunderCloud(Character* target){};
        void waningMoon(Character* target){};
};
#endif //__CHARACTER_HPP__

