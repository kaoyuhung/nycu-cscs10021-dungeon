#include "Object.h"

Object ::Object() : name("unknown"), tag("object") {}

Object ::Object(string Name, string Tag) : name(Name), tag(Tag) {}

void Object ::setName(string getname) {
    this->name = getname;
};

void Object ::setTag(string gettag) {
    this->tag = gettag;
}

string Object ::getName() const {
    return this->name;
}

string Object ::getTag() const {
    return this->tag;
}
