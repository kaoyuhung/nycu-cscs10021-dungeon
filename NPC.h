#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "GameCharacter.h"
#include "Item.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NPC : public GameCharacter {
  public:
    NPC();
    NPC(string, string, vector<Item *>);
    void listCommodity() const; /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object *) override;

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item *>);
    void putItem_in(Item *);
    string getScript();
    vector<Item *> getCommodity();

  private:
    string script;
    vector<Item *> commodity;
};

#endif // NPC_H_INCLUDED
