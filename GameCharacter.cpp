#include "GameCharacter.h"

GameCharacter ::GameCharacter() : Object("unknown", "Gamecharacter"), maxHealth(0), currentHealth(0), attack(0), defense(0) {}

GameCharacter ::GameCharacter(string name, int a, int b, int c) : maxHealth(a), currentHealth(a), attack(b), defense(c) {
    this->setTag("GameCharacter");
    this->setName(name);
}

bool GameCharacter ::checkIsDead() {
    return (this->currentHealth == 0);
}

int GameCharacter ::takeDamage(int damage) {
    this->currentHealth -= damage;
    return this->currentHealth;
}

void GameCharacter ::setMaxHealth(int health) {
    this->maxHealth = health;
}

void GameCharacter ::setCurrentHealth(int health) {
    this->currentHealth = health;
}

void GameCharacter ::setAttack(int setattck) {
    this->attack = setattck;
}

void GameCharacter ::setDefense(int setdefense) {
    this->defense = setdefense;
}

int GameCharacter ::getMaxHealth() const {
    return this->maxHealth;
}

int GameCharacter ::getCurrentHealth() const {
    return this->currentHealth;
}

int GameCharacter ::getAttack() const {
    return this->attack;
}

int GameCharacter ::getDefense() const {
    return this->defense;
}
