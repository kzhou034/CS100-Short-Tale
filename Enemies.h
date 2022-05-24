nclude "character.hpp"

using namespace std;

class Enemy : public Character {
	private:
		string name;
		string type;
		int level;
		int health;
		int mhealth;
		int atk;
		int defense;
		int resistance;
		int speed;

	public:
		Enemy();
		Enemy(const string n, const string t, const int l, const int h, const int a, const int d, const int r, const int s);
		~Enemy();
		void set_name(string);
		void set_type(string);
		void set_level(int);
		void set_health(int);
		void set_max_health(int);
		void set_attack(int);
		void set_defense(int);
		void set_resistance(int);
		void set_speed(int);
		
		void add_level(int);
		void add_health(int);
		void add_max_health(int);
		void add_attack(int);
		void add_defense(int);
		void add_resistance(int);
		void add_speed(int);

		string get_name();
		string get_type();
		int get_level();
		int get_health();
		int get_max_health();
		int get_attack();
		int get_defense();
		int get_resistance();
		int get_speed();

		void setlevel(int); // make sure to only use default constructor unless you want crazy scaling
		void heal();
		void attack(Character*);
		void hurt(Character*);
		void print();
		void action(Character*);

		bool picklock();
		void add(Character*);
		void remove(Character*);
};
