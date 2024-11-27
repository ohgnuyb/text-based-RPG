#pragma once

#define MAX_INVENTORY_SIZE 10
#define DEFENSE_RATE 0.2

struct INVENTORY_SHOP {
    char item[20];
    int  quantity;
    int type; //1: 무기, 2: 물약, 3: 일반 4: 장비
    int isEquipped;
    int addAttack;
    int addDefense;
    int addHp;
    int addMana;
    char state[300];
    int price;
};

struct inventoryItem {
    char item[20];
    int  quantity;
    int type; //1: 무기, 2: 물약, 3: 일반 4: 장비
    int isEquipped;
    int addAttack;
    int addDefense;
    int addHp;
    int addMana;
    char state[300];
};

struct character {
    char name[20];
    char skill[50];
    char charState[100];
    int hp;
    int attack;
    int defense;
    int mana;
};


struct inventoryItem_shop {
    char item[20];
    int  quantity;
    int type; 
    int isEquipped;
    int addAttack;
    int addDefense;
    int addHp;
    int addMana;
    char state[300];
    int price;
};

struct character characterInfo[3] = {
   {"", "", "", 100, 5, 7, 0}, //마나가 없는 대신 전투 한 번에 스킬 한 번 사용 가능
   {"", "", "", 70, 15, -3, 0}, //스킬 사용시 마나 -10
   {"", "", "", 40, 25, -3, 0}, //마나가 없는 대신 전투 한 번에 스킬 한 번 사용 가능
};

struct {
    char name[20];
    int hp;
    int attack;
    int defense;
} monster[100];

struct {
    char playerName[20];
    int money;
    int level;
    int levelPro;
    struct character playerScharacterInfo;
    struct inventoryItem inventory[MAX_INVENTORY_SIZE];
    int itemIndex;
    int potionUsed;
    char type;
    int potionAdd;
} playerInfo;
