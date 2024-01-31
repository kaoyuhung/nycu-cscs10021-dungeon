#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "Object.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {
  public:
    Room();
    Room(bool, int, string);
    Room(bool, int, string, vector<Object *>);
    bool popObject(Object *); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setUpRoom(Room *);
    void setDownRoom(Room *);
    void setLeftRoom(Room *);
    void setRightRoom(Room *);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object *>);
    string getName();
    void putObject_in(Object *);
    bool getIsExit();
    int getIndex();
    vector<Object *> getObjects();
    Room *getUpRoom();
    Room *getDownRoom();
    Room *getLeftRoom();
    Room *getRightRoom();

  private:
    Room *upRoom = NULL;
    Room *downRoom = NULL;
    Room *leftRoom = NULL;
    Room *rightRoom = NULL;
    bool isExit;
    int index;
    string name;
    vector<Object *> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
};

#endif // ROOM_H_INCLUDED
