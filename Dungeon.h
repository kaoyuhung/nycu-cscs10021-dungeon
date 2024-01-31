#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include "Monster.h"
#include "NPC.h"
#include "Object.h"
#include "Player.h"
#include "Record.h"
#include "Room.h"
#include <exception>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Dungeon {
  public:
    Dungeon();
    ~Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction(vector<Object *>);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();

  private:
    Player player;
    vector<Room *> rooms;
};

#endif // DUNGEON_H_INCLUDED
