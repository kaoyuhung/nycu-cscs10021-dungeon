#include "NPC.h"

NPC ::NPC() : GameCharacter("unknown", 10000, 10000, 10000) {
    setTag("NPC");
}

NPC ::NPC(string name, string getscript, vector<Item *> a) : GameCharacter(name, 10000, 10000, 10000) {
    setCommodity(a);
    setTag("NPC");
    setScript(getscript);
}

void NPC ::listCommodity() const {
    cout << getName() << " : "
         << "I have...\n";
    for (auto i = 0; i < (int)commodity.size(); i++) {
        cout << commodity[i]->getName() << '\n';
    }
    return;
}

void NPC ::setScript(string Script) {
    script = Script;
    return;
}

void NPC ::setCommodity(vector<Item *> a) {
    commodity = a;
    return;
}

string NPC ::getScript() {
    return script;
}

vector<Item *> NPC ::getCommodity() {
    return commodity;
}

void NPC ::putItem_in(Item *a) {
    commodity.push_back(a);
    return;
}

bool NPC ::triggerEvent(Object *a) {
    Player *player = dynamic_cast<Player *>(a);
    char choose;
    while (1) {
        cout << getName() << " : " << getScript() << "\n";
        cout << "You now have $" << player->getMoney() << "\n";
        cout << "Input : ";
        cin >> choose;
        if (choose == 'a' || choose == 'A') {
            Item *item = commodity[0];
            if (player->getMoney() >= item->getPrice()) {
                player->increaseStates(item->getHealth(), item->getAttack(), item->getDefense(), item->getMaxhealth());
                player->setMoney(player->getMoney() - item->getPrice());
                cout << getName() << " : OK ! You can check your status later.\n\n";
            } else {
                cout << getName() << " : Sorry You don't have enough money.\n";
            }
        } else if (choose == 'b' || choose == 'B') {
            Item *item = commodity[1];
            if (player->getMoney() >= item->getPrice()) {
                player->increaseStates(item->getHealth(), item->getAttack(), item->getDefense(), item->getMaxhealth());
                player->setMoney(player->getMoney() - item->getPrice());
                player->put_stuff_in(item);
                cout << getName() << " : OK ! You can check your status later.\n\n";
            } else {
                cout << getName() << " : Sorry You don't have enough money.\n";
            }
        } else if (choose == 'c' || choose == 'C') {
            Item *item = commodity[2];
            if (player->getMoney() >= item->getPrice()) {
                player->increaseStates(item->getHealth(), item->getAttack(), item->getDefense(), item->getMaxhealth());
                player->setMoney(player->getMoney() - item->getPrice());
                player->put_stuff_in(item);
                cout << getName() << " : OK ! You can check your status later.\n\n";
            } else {
                cout << getName() << " : Sorry You don't have enough money.\n";
            }
        } else if (choose == 'd' || choose == 'D') {
            Item *item = commodity[3];
            if (player->getMoney() >= item->getPrice()) {
                player->increaseStates(item->getHealth(), item->getAttack(), item->getDefense(), item->getMaxhealth());
                player->setMoney(player->getMoney() - item->getPrice());
                player->put_stuff_in(item);
                cout << getName() << " : OK ! You can check your status later.\n\n";

            } else {
                cout << getName() << " : Sorry You don't have enough money.\n";
            }
        } else if (choose == 'e' || choose == 'E') {
            break;
        }
    }
    return 1;
}
