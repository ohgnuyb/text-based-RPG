#pragma once

#define MAX_INVENTORY_SIZE 10
#define DEFENSE_RATE 0.2


struct character {
    char name[20];
    char skill[50];
    char charState[100];
    int hp;
    int attack;
    int defense;
    int mana;
};

struct inventoryItem {
    char item[20];
    int  quantity;
    int type; //1: ���, 2: ����
    int isEquipped;
    int addAttack;
    int addDefense;
    int addHp;
    int addMana;
};
struct character characterInfo[3] = {
   {"", "", "", 120, 10, 10, 0}, //������ ���� ��� ���� �� ���� ��ų �� �� ��� ����
   {"", "", "", 90, 20, 0, 10}, //��ų ���� ���� -10
   {"", "", "", 60, 30, 0, 0}, //������ ���� ��� ���� �� ���� ��ų �� �� ��� ����
};

struct {
    char name[20];
    char skill[20];
    int hp;
    int attack;
    int defense;
} monster[100];

struct {
    char playerName[20];
    struct character playerScharacterInfo;
    struct inventoryItem inventory[MAX_INVENTORY_SIZE];
} playerInfo;
