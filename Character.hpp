#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class Character {
    public: 
		Character() {};
        ~Character() {};

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

        virtual void setCD() = 0;
        virtual void redCD() = 0;
        virtual void setlevel(int) = 0; 
		    virtual void heal() = 0;
		    virtual void atk(Character* target) = 0;
		    virtual void hurt(Character* target) = 0;
		    virtual void print() = 0;
		    virtual void action(Character*) = 0;
        virtual void raiseshield() = 0;
        virtual void lowershield() = 0;
        virtual void holysmite(Character* target) = 0;
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
            int mod = rand() % l;

            level = l;

            max_health *= pow(l, 1.5);
            max_health += mod;
            health = max_health;

            attack *= pow(l, 1.2);
            attack += mod;

            defense *= pow(l, 1.7);
            defense -= mod;

            resistance *= pow(l, 1.5);
            resistance -= mod;

            speed *= pow(l, 1.3);
            speed += mod;
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
        bool pickLock() {return false;};
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

        void setlevel(int) {};
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
          skillcd = 3;
        };
        void redCD(){
          skillcd--;
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

        void setlevel(int) {};
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
            if (level == 2 && type == "Rogue" && max_lockpicks > 0) {
                lockPick = true;
                max_lockpicks--;
                return true;
            }
            return false;
        }; 
        void raiseshield() {};
        void lowershield() {};
        void holysmite(Character* target) {};
bool getStatus() {return false;}; 
int getCD(){
          return skillcd;
        };
        void setCD(){
          skillcd = 3;
        };
        void redCD(){
          skillcd--;
        };
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

            mhealth *= pow(l, 1.5);
            mhealth += mod;
            health = mhealth;

            attack *= pow(l, 1.6);
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
            double mult = 0.05 * level;
            if(get_level() > 7){
              mult *= 0.2;
            }
            amt = mult * mhealth;
            amt++;

            if (amt + health >= mhealth) {
                health = mhealth;
            }
            else {
                health += amt;
            }
            cout << "The " << get_name() << " healed for " << amt << "." << endl;
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
                dmg -= target->get_resistance();
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
                if (act < 66) {
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
      int getCD(){
        };
        void setCD(){
        };
        void redCD(){
        };
};

#endif //__CHARACTER_HPP__
