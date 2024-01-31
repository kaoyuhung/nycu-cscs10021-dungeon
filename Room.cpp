#include "Room.h"

Room ::Room() : Room(0, 0, "None", vector<Object *>()) {}

Room ::Room(bool a, int getindex, string c) : isExit(a), index(getindex), name(c) {}

Room ::Room(bool a, int getindex, string c, vector<Object *> object) : isExit(a), index(getindex), name(c), objects(object) {}


bool Room ::popObject(Object *a) {
    for (int i = 0; i < (int)objects.size(); i++) {
        if (objects[i] == a) {
            objects.erase(objects.begin() + i);
            return true;
        }
    }
    return false;
}

void Room ::setUpRoom(Room *a) {
    upRoom = a;
}

void Room ::setDownRoom(Room *a) {
    downRoom = a;
}

void Room ::setLeftRoom(Room *a) {
    leftRoom = a;
}

void Room ::setRightRoom(Room *a) {
    rightRoom = a;
}

void Room ::setIsExit(bool a) {
    isExit = a;
}

void Room ::setIndex(int a) {
    index = a;
}

void Room ::setObjects(vector<Object *> a) {
    objects = a;
}

bool Room ::getIsExit() {
    return isExit;
}

int Room ::getIndex() {
    return index;
}

string Room ::getName() {
    return name;
}
void Room ::putObject_in(Object *a) {
    objects.push_back(a);
    return;
}

vector<Object *> Room ::getObjects() {
    return objects;
}

Room *Room ::getUpRoom() {
    return upRoom;
}

Room *Room ::getDownRoom() {
    return downRoom;
}

Room *Room ::getLeftRoom() {
    return leftRoom;
}

Room *Room ::getRightRoom() {
    return rightRoom;
}
