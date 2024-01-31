#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"
#include <iostream>
#include <string>
using namespace std;

class GameCharacter : public Object {
  public:
    GameCharacter();
    GameCharacter(string, int, int, int);
    bool checkIsDead();
    int takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth() const;
    int getCurrentHealth() const;
    int getAttack() const;
    int getDefense()const;

  private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
};
#endif // GAMECHARACTER_H_INCLUDED
