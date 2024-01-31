#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "GameCharacter.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monster : public GameCharacter {
  public:
    Monster();
    Monster(string, int, int, int, int);
    void setfallen_money(int);
    int getfallen_money() const;
    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object *) override;

  private:
    int fallen_money;
};

#endif // ENEMY_H_INCLUDED
