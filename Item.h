#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include "Object.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player;

class Item : public Object {
  public:
    Item();
    Item(string, int, int, int);
    Item(string, int, int, int, int);
    Item(string, int, int, int, int, int);
    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object *) override;
    /* Set & Get function*/
    int getHealth() const;
    int getMaxhealth() const;
    int getAttack() const;
    int getDefense() const;
    int getPrice() const;
    void setPrice(int);
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);

  private:
    int health, attack, defense, price, maxhealth;
};

#endif // ITEM_H_INCLUDED
