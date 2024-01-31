#include "Record.h"

Record ::Record() {}

void Record ::savePlayer(Player *player, ofstream &out) {
    out.open("record.txt", ios::trunc);
    out << player->getName() << ' ' << player->getMaxHealth() << ' ' << player->getCurrentHealth() << ' ' << player->getAttack() << ' ' << player->getDefense() << ' ' << player->getMoney() << ' ' << player->getCurrentRoom()->getIndex();
    out << '\n';
    vector<Item *> stuff = player->getInventory();
    for (int i = 0; i < (int)stuff.size(); i++) {
        if (stuff[i]->getPrice() != 0) {
            out << stuff[i]->getName() << '\n';
        }
    }
    out << "..." << '\n';
    out.close();
}

void Record ::saveRooms(vector<Room *> &rooms, ofstream &out) {
    out.open("record.txt", ios::app);
    unsigned long num = rooms[0]->getObjects().size();
    if (num == 2) {
        out << 0;
    } else if (num == 1) {
        string name = rooms[0]->getObjects()[0]->getName();
        if (name == "Wooden shield") {
            out << 1;
        } else {
            out << 2;
        }
    } else {
        out << 3;
    }
    out << ' ';
    int check = rooms[2]->getObjects().size();
    if (check) {
        out << 0;
    } else {
        out << 1;
    }
    out.close();
}

void Record ::saveToFile(Player *player, vector<Room *> &rooms) {
    ofstream out;
    savePlayer(player, out);
    saveRooms(rooms, out);
}

void Record ::loadFromFile(Player *player, vector<Room *> &rooms, ifstream &in) {
    in.open("record.txt");
    string name;
    int maxhealth, currenthealth, attack, defense, money, roomindex;
    in >> name >> maxhealth >> currenthealth >> attack >> defense >> money >> roomindex;
    player->setName(name);
    player->setMaxHealth(maxhealth);
    player->setCurrentHealth(currenthealth);
    player->setAttack(attack);
    player->setDefense(defense);
    player->setMoney(money);
    player->setCurrentRoom(rooms[roomindex]);
    string weapon;
    while (getline(in, weapon)) {
        if (weapon == "...") {
            break;
        }
        NPC *npc = dynamic_cast<NPC *>(rooms[3]->getObjects()[0]);
        vector<Item *> commodity = npc->getCommodity();
        for (int i = 0; i < (int)commodity.size(); i++) {
            if (weapon == commodity[i]->getName()) {
                player->addItem(commodity[i]);
            }
        }
    }
    int check, check2;
    in >> check >> check2;
    if (check == 1) {
        Item *item = dynamic_cast<Item *>(rooms[0]->getObjects()[0]);
        player->addItem(item);
        rooms[0]->popObject(rooms[0]->getObjects()[0]);
    } else if (check == 2) {
        Item *item = dynamic_cast<Item *>(rooms[0]->getObjects()[1]);
        player->addItem(item);
        rooms[0]->popObject(rooms[0]->getObjects()[1]);
    } else if (check == 3) {
        Item *item1 = dynamic_cast<Item *>(rooms[0]->getObjects()[0]);
        Item *item2 = dynamic_cast<Item *>(rooms[0]->getObjects()[1]);
        player->addItem(item1);
        player->addItem(item2);
        rooms[0]->popObject(rooms[0]->getObjects()[1]);
        rooms[0]->popObject(rooms[0]->getObjects()[0]);
    }
    if (check2) {
        rooms[2]->popObject(rooms[2]->getObjects()[0]);
    }
    cout << "\nLoad successfully\n"
         << endl;
    player->triggerEvent(player);
}
