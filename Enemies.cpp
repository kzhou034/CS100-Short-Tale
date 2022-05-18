nclude "Enemies.h"
#include <cmath>

using namespace std;

Enemy::Enemy() {
	name = "???";
	type = "???";
	level = 1;
	health = 10;
	mhealth = 10;
	atk = 3;
	defense = 2;
	resistance = 2;
	speed = 5;
}

Enemy::Enemy(const string n, const string t, const int l, const int h, const int a, const int d, const int r, const int s) {
	name = n;
	type = t;
	level = l;
	health = h;
	mhealth = h;
	atk = a;
	defense = d;
	resistance = r;
	speed = s;
}

Enemy::~Enemy() {}

void Enemy::set_name(string n) {
	name = n;
}
void Enemy::set_type(string t) {
	type = t;
}
void Enemy::set_level(int l) {
	level = l;
}
void Enemy::set_health(int h) {
	health = h;
}
void Enemy::set_max_health(int m) {
	mhealth = m;
}
void Enemy::set_attack(int a) {
	atk = a;
}
void Enemy::set_defense(int d) {
	defense = d;
}
void Enemy::set_resistance(int r) {
	resistance = r;
}
void Enemy::set_speed(int s) {
	speed = s;
}

void Enemy::add_level(int l) {
	level += l;
}
void Enemy::add_health(int h) {
	health += h;
}
void Enemy::add_max_health(int m) {
	mhealth += m;
}
void Enemy::add_attack(int a) {
	atk += a;
}
void Enemy::add_defense(int d) {
	defense += d;
}
void Enemy::add_resistance(int r) {
	resistance += r;
}
void Enemy::add_speed(int s) {
	speed += s;
}

string Enemy::get_name() {
	return name;
}
string Enemy::get_type() {
	return type;
}
int Enemy::get_level() {
	return level;
}
int Enemy::get_health() {
	return health;
}
int Enemy::get_max_health() {
	return mhealth;
}
int Enemy::get_attack() {
	return atk;
}
int Enemy::get_defense() {
	return defense;
}
int Enemy::get_resistance() {
	return resistance;
}
int Enemy::get_speed() {
	return speed;
}

void Enemy::setlevel(int l) {
	int mod = rand() % l;

	level = l;

	mhealth *= pow(l, 1.5);
	mhealth += mod;
	health = mhealth;

	atk *= pow(l, 1.6);
	atk += mod;

	defense *= pow(l, 1.7);
	defense -= mod;

	resistance *= pow(l, 1.7);
	resistance -= mod;

	speed *= pow(l, 1.3);
	speed += mod;
}
void Enemy::heal() {
	double amt;
	double mult = 0.05 * level;
	amt = mult * mhealth;
	amt++;

	if (amt + health <= mhealth) {
		health = mhealth;
	}
	else {
		health += amt;
	}
}
void Enemy::attack(Character* target) {
	int dmg;
	if (get_type() == "magic") {
		dmg = get_attack() - target->get_resistance();
	}
	else {
		dmg = get_attack() - target->get_defense();
	}
	target->set_health(target->get_health() - dmg);
}

bool Enemy::picklock() {
	return false;
}
void Enemy::add(Character*) {}
void Enemy::remove(Character*) {}
