#include "Monster.h"

Monster ::Monster() : GameCharacter() {}

Monster ::Monster(string name, int a, int b, int c, int d) : GameCharacter(name, a, b, c) {
    setfallen_money(d);
    setTag("Monster");
}

void Monster ::setfallen_money(int a) {
    fallen_money = a;
}

int Monster ::getfallen_money() const {
    return fallen_money;
}

bool Monster ::triggerEvent(Object *player2) {
    Player *player = dynamic_cast<Player *>(player2);
    char choose;
    cout << "Oh ! It is the monster " << getName() << "!\n";
    while (1) {
        cout << "A. Fight\nB. Flee\nInput: ";
        cin >> choose;
        cout << '\n';
        if (choose == 'a' || choose == 'A') {
            while (player->getCurrentHealth() > 0) {
                cout << "A.Attack\nB.Flee\nInput :";
                cin >> choose;
                cout << "\n";
                if (choose == 'a' || choose == 'A') {
                    cout << "Your attack does " << (player->getAttack() / 10 * 6) - (getDefense() / 5) << " damage\n\n";
                    takeDamage((player->getAttack() / 10 * 6) - (getDefense() / 5));
                    if (getCurrentHealth() < 0) {
                        setCurrentHealth(0);
                    }
                    cout << getName() << " now have " << getCurrentHealth() << " health\n\n";
                    if (getCurrentHealth() == 0) {
                        cout << "Oh ! " << getName() << " is dead!\n\n";
                        player->getCurrentRoom()->setIsExit(true);
                        if (this->getfallen_money()) {
                            cout << "You win and get $ " << getfallen_money() << "!\n\n";
                        }
                        player->setMoney(player->getMoney() + this->getfallen_money());
                        setCurrentHealth(getMaxHealth());
                        return 1;
                    }
                    cout << getName() << " does " << (getAttack() / 10 * 5 - (player->getDefense() / 8)) << " damage\n\n";
                    player->takeDamage((getAttack() / 10 * 5 - (player->getDefense() / 8)));
                    if (player->getCurrentHealth() < 0) {
                        player->setCurrentHealth(0);
                    }
                    cout << "You now have " << player->getCurrentHealth() << " health\n\n";
                    if (player->getCurrentHealth() == 0) {
                        cout << "You lose!\n\n";
                        return 0;
                    }
                } else if (choose == 'b' || choose == 'B') {
                    setCurrentHealth(getMaxHealth());
                    player->setCurrentRoom(player->getPreviousRoom());
                    cout << "You are in " << player->getCurrentRoom()->getName() << " now !\n\n";
                    return 0;
                }
            }
        } else if (choose == 'b' || choose == 'B') {
            setCurrentHealth(getMaxHealth());
            player->setCurrentRoom(player->getPreviousRoom());
            cout << "You are in " << player->getCurrentRoom()->getName() << " now !\n\n";
            return 0;
        }
    }
}
