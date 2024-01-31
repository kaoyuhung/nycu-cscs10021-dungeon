#include "Player.h"

Player ::Player() : GameCharacter("unknown", 100, 80, 60) {
    setTag("Player");
}

Player ::Player(string name, int a, int b, int c, int d) : GameCharacter(name, a, b, c) {
    setTag("Player");
    setMoney(d);
}

void Player ::addItem(Item *a) {
    inventory.push_back(a);
    return;
}

void Player ::increaseStates(int a, int b, int c, int d) {
    setMaxHealth(getMaxHealth() + d);
    setCurrentHealth(getCurrentHealth() + a);
    if (getCurrentHealth() > getMaxHealth()) {
        setCurrentHealth(getMaxHealth());
    }
    setAttack(getAttack() + b);
    setDefense(getDefense() + c);
    return;
}

void Player ::changeRoom(Room *to_move) {
    setPreviousRoom(getCurrentRoom());
    setCurrentRoom(to_move);
    return;
}

void Player ::setMoney(int a) {
    money = a;
}
bool Player ::triggerEvent(Object *a) {
    cout << "Name : " << getName() << '\n';
    cout << "Health : " << getCurrentHealth() << "/" << getMaxHealth() << "\n";
    cout << "Attck : " << getAttack() << '\n';
    cout << "Defense : " << getDefense() << '\n';
    cout << "Money : " << getMoney() << "\n";
    cout << "You now have ";
    for (int i = 0; i < (int)inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i]->getName() << ' ';
    }
    cout << "\n\n";
    return 1;
}

int Player ::getMoney() const {
    return money;
}
void Player ::setCurrentRoom(Room *a) {
    currentRoom = a;
}

void Player ::setPreviousRoom(Room *a) {
    previousRoom = a;
}

void Player ::put_stuff_in(Item *a) {
    inventory.push_back(a);
}
vector<Item *> Player ::getInventory() const {
    return inventory;
}

Room *Player ::getCurrentRoom() const {
    return currentRoom;
}

Room *Player ::getPreviousRoom() const {
    return previousRoom;
}
