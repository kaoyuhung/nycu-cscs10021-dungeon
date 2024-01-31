#include "Item.h"

Item ::Item() : Object("unknown", "Item"), health(0), attack(0), defense(0), price(0), maxhealth(0) {}

Item ::Item(string name, int a, int b, int c) : Object(name, "Item"), health(a), attack(b), defense(c), price(0), maxhealth(0) {}
Item ::Item(string name, int a, int b, int c, int d) : Object(name, "Item"), health(a), attack(b), defense(c), price(d), maxhealth(0) {}
Item ::Item(string name, int e, int a, int b, int c, int d) : Object(name, "Item"), health(a), attack(b), defense(c), price(d), maxhealth(e) {}
bool Item ::triggerEvent(Object *a) {
    Player *player = dynamic_cast<Player *>(a);
    if (this->getPrice()) {
        player->setMoney(player->getMoney() - this->getPrice());
        player->increaseStates(this->getHealth(), this->getAttack(), this->getDefense(), this->getMaxhealth());
        if (player->getCurrentHealth() > player->getMaxHealth()) {
            player->setCurrentHealth(player->getMaxHealth());
        }
        return 1;
    } else {
        char choose;
        cout << "Oh ! There is a " << this->getName() << ".\n\n";
        if (getName() == "Potion") {
            cout << "It can help you increase 20 health.\n\n";
        }
        while (1) {
            cout << "A. Pick it up\nB. Do not pick it up\n";
            cout << "Input : ";
            cin >> choose;
            cout << '\n';
            if (choose == 'a' || choose == 'A') {
                player->increaseStates(this->getHealth(), this->getAttack(), this->getDefense(), this->getMaxhealth());
                if (getName() != "Potion") {
                    player->put_stuff_in(this);
                }
                player->getCurrentRoom()->popObject(this);
                if (player->getCurrentHealth() > player->getMaxHealth()) {
                    player->setCurrentHealth(player->getMaxHealth());
                }
                break;
            } else if (choose == 'b' || choose == 'B') {
                return 0;
            }
        }
        return 1;
    }
}

int Item ::getHealth() const {
    return health;
}

int Item ::getAttack() const {
    return attack;
}

int Item ::getDefense() const {
    return defense;
}

int Item ::getMaxhealth() const {
    return maxhealth;
}
int Item ::getPrice() const {
    return price;
}
void Item ::setHealth(int a) {
    health = a;
}

void Item ::setAttack(int a) {
    attack = a;
}

void Item ::setDefense(int a) {
    defense = a;
}

void Item ::setPrice(int a) {
    price = a;
}
