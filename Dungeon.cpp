#include "Dungeon.h"

Dungeon ::Dungeon() : player(), rooms() {
    this->player.setTag("Player");
}

Dungeon ::~Dungeon() {
    for (int i = 0; i < (int)this->rooms.size(); i++) {
        for (int j = 0; j < (int)this->rooms[i]->getObjects().size(); j++) {
            delete this->rooms[i]->getObjects()[j];
        }
        delete this->rooms[i];
    }
}

void Dungeon ::runDungeon() {
    this->startGame();
    this->chooseAction(this->player.getCurrentRoom()->getObjects());
    while (1) {
        char op2;
        cout << "What do you want to do ?\nA.Move\nB.Check your status\nC.Save to file\nD.Leave game\nInput: ";
        cin >> op2;
        cout << '\n';
        if (op2 == 'a' || op2 == 'A') {
            handleMovement();
            cout << "You are in " << this->player.getCurrentRoom()->getName() << " now !\n\n";
            chooseAction(this->player.getCurrentRoom()->getObjects());
            if (!checkGameLogic()) {
                cout << "Please try again.\n";
                break;
            }
            if (this->rooms[4]->getIsExit() == true &&
                this->player.getCurrentRoom()->getIndex() == 4) {
                cout << "You win the game !!\n\n";
                return;
            }
        } else if (op2 == 'b' || op2 == 'B') {
            this->player.triggerEvent(&this->player);
        } else if (op2 == 'c' || op2 == 'C') {
            Record record;
            record.saveToFile(&this->player, this->rooms);
            cout << "The data have been saved.\n\n";
        } else if (op2 == 'd' || op2 == 'D') {
            break;
        }
    }
    cout << "Game over !" << endl;
    return;
}

void Dungeon ::startGame() {
    char op;
    cout << "Input 'A' to start a new game or 'B' to load privious data: ";
    cin >> op;
    cout << '\n';
    if (op == 'a' || op == 'A') {
        this->createPlayer();
        this->createMap();
        this->player.setCurrentRoom(this->rooms[0]);
        cout << "Game start !\n\n";
        cout << "You are in " << this->player.getCurrentRoom()->getName() << " now \n"
             << endl;
        return;
    }
    if (op == 'b' || op == 'B') {
        this->createMap();
        Record record;
        ifstream in;
        record.loadFromFile(&this->player, this->rooms, in);
        cout << "You are in the " << this->player.getCurrentRoom()->getName() << " now !\n"
             << endl;
        return;
    }
}

void Dungeon ::createPlayer() {
    string name;
    cout << "Please input enter name: ";
    cin >> name;
    cout << '\n';
    this->player.setName(name);
    this->player.setMaxHealth(100);
    this->player.setCurrentHealth(100);
    this->player.setAttack(50);
    this->player.setDefense(30);
    this->player.setMoney(0);
}

void Dungeon ::createMap() {
    Item *wooden_sword = new Item("Wooden sword", 0, 15, 0);
    Item *wooden_shield = new Item("Wooden shield", 15, 15, 0, 15, 0);
    Item *potion = new Item("Potion", 20, 0, 0, 10);
    Item *iron_sword = new Item("Iron Sword", 0, 30, 0, 20);
    Item *iron_shield = new Item("Iron shield", 30, 30, 0, 30, 20);
    Item *diamond_sword = new Item("Diamond sword", 0, 100, 0, 120);
    Item *potion2 = new Item("Potion", 20, 0, 0, 0);

    vector<Object *> objects_in_the_beginning_room;
    objects_in_the_beginning_room.push_back(wooden_sword);
    objects_in_the_beginning_room.push_back(wooden_shield);
    Room *the_beginning_room = new Room(false, 0, "the beginning room", objects_in_the_beginning_room);

    vector<Object *> objects_in_the_second_room;
    Monster *cute_dragon = new Monster("Cute Dragon", 100, 20, 20, 40);
    objects_in_the_second_room.push_back(cute_dragon);
    Room *the_second_room = new Room(false, 1, "the second room", objects_in_the_second_room);

    Room *the_third_room = new Room(false, 2, "the third room");
    the_third_room->putObject_in(potion2);

    vector<Object *> objects_in_the_store;
    vector<Item *> npc_sell;
    npc_sell.push_back(potion);
    npc_sell.push_back(iron_sword);
    npc_sell.push_back(iron_shield);
    npc_sell.push_back(diamond_sword);
    NPC *shop_assistant = new NPC("Shop assistant", "What do you want ?\n ----------\nA.Potion $10\nB.Iron sword $20\nC.Iron shield $20\nD.Diamond sword $120\nE.Leave\n", npc_sell);
    objects_in_the_store.push_back(shop_assistant);
    Room *store = new Room(false, 3, "store", objects_in_the_store);

    vector<Object *> objects_in_the_fourth_room;
    Monster *evil_dragon = new Monster("Evil Dragon", 200, 80, 80, 0);
    objects_in_the_fourth_room.push_back(evil_dragon);
    Room *the_fourth_room = new Room(false, 4, "the fourth room", objects_in_the_fourth_room);

    the_beginning_room->setUpRoom(the_second_room);
    the_second_room->setDownRoom(the_beginning_room);
    the_second_room->setUpRoom(the_third_room);
    the_third_room->setDownRoom(the_second_room);
    the_third_room->setRightRoom(store);
    store->setLeftRoom(the_third_room);
    the_third_room->setUpRoom(the_fourth_room);
    the_fourth_room->setDownRoom(the_third_room);

    this->rooms.push_back(the_beginning_room);
    this->rooms.push_back(the_second_room);
    this->rooms.push_back(the_third_room);
    this->rooms.push_back(store);
    this->rooms.push_back(the_fourth_room);
}

void Dungeon ::handleMovement() {
    char op;
    int go[4] = {0};
    cout << "Where do you want to go ?\n";
    if (this->player.getCurrentRoom()->getUpRoom() != NULL) {
        go[0] = 1;
        cout << "A. Go up !\n";
    }
    if (this->player.getCurrentRoom()->getDownRoom() != NULL) {
        go[1] = 1;
        cout << "B. Go down !\n";
    }
    if (this->player.getCurrentRoom()->getRightRoom() != NULL) {
        go[2] = 1;
        cout << "C. Go Right !\n";
    }
    if (this->player.getCurrentRoom()->getLeftRoom() != NULL) {
        go[3] = 1;
        cout << "D. Go Left !\n";
    }
    while (1) {
        cout << "Input: ";
        cin >> op;
        cout << '\n';
        if ((op == 'A' || op == 'a') && go[0]) {
            this->player.setPreviousRoom(this->player.getCurrentRoom());
            this->player.setCurrentRoom(this->player.getCurrentRoom()->getUpRoom());
            break;
        } else if ((op == 'B' || op == 'b') && go[1]) {
            this->player.setPreviousRoom(this->player.getCurrentRoom());
            this->player.setCurrentRoom(this->player.getCurrentRoom()->getDownRoom());
            break;
        } else if ((op == 'C' || op == 'c') && go[2]) {
            this->player.setPreviousRoom(this->player.getCurrentRoom());
            this->player.setCurrentRoom(this->player.getCurrentRoom()->getRightRoom());
            break;
        } else if ((op == 'D' || op == 'd') && go[3]) {
            this->player.setPreviousRoom(this->player.getCurrentRoom());
            this->player.setCurrentRoom(this->player.getCurrentRoom()->getLeftRoom());
            break;
        }
    }
}

bool Dungeon ::checkGameLogic() {
    if (this->player.checkIsDead()) {
        return 0;
    }
    return 1;
}

void Dungeon ::chooseAction(vector<Object *> a) {
    for (auto i = 0; i < (int)a.size(); i++) {
        a[i]->triggerEvent(&this->player);
    }
}
