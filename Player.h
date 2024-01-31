#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "GameCharacter.h"
#include "Item.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item;

class Player : public GameCharacter {
  public:
    Player();
    Player(string, int, int, int, int);
    void addItem(Item *);
    void increaseStates(int, int, int, int);
    void changeRoom(Room *);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object *) override;

    /* Set & Get function*/
    void setMoney(int);
    void setCurrentRoom(Room *);
    void setPreviousRoom(Room *);
    void setInventory(vector<Item *>);
    void put_stuff_in(Item *);
    int getMoney() const;
    Room *getCurrentRoom() const;
    Room *getPreviousRoom() const;
    vector<Item *> getInventory() const;

  private:
    int money;
    Room *currentRoom;
    Room *previousRoom;
    vector<Item *> inventory;
};

#endif // PLAYER_H_INCLUDED
