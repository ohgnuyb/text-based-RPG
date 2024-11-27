#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

void load_game_data() {
	FILE* fp = fopen("save_data.txt", "r"); // ���� ����
	playerInfo.itemIndex = 0;
	if (fp == NULL) {



		return;
	}

	// �÷��̾� ���� �ҷ�����
	fscanf(fp, "%[^,], %d, %d, %d\n", playerInfo.playerName, &playerInfo.level, &playerInfo.levelPro, &playerInfo.money);

	fscanf(fp, "%d, %d, %d, %d, %s, %s, %[^ ]\n",
		&playerInfo.playerScharacterInfo.hp, &playerInfo.playerScharacterInfo.defense,
		&playerInfo.playerScharacterInfo.attack, &playerInfo.playerScharacterInfo.mana,
		playerInfo.playerScharacterInfo.name, playerInfo.playerScharacterInfo.skill,
		playerInfo.playerScharacterInfo.charState);

	// �κ��丮 ���� �ҷ�����
	while (fscanf(fp, "%[^,], %d, %d, %d, %d, %d, %d, %d, %[^ ]\n",
		playerInfo.inventory[playerInfo.itemIndex].item, &playerInfo.inventory[playerInfo.itemIndex].quantity, &playerInfo.inventory[playerInfo.itemIndex].type,
		&playerInfo.inventory[playerInfo.itemIndex].isEquipped, &playerInfo.inventory[playerInfo.itemIndex].addAttack, &playerInfo.inventory[playerInfo.itemIndex].addDefense,
		&playerInfo.inventory[playerInfo.itemIndex].addHp, &playerInfo.inventory[playerInfo.itemIndex].addMana, playerInfo.inventory[playerInfo.itemIndex].state) != EOF) {

		playerInfo.itemIndex++;
	}

	

	fclose(fp); // ���� �ݱ�
}

//�÷��̾� �̸� ���� ����ġ ��
// 
//hp ���� ���ݷ� ���� ĳ���� �̸� ��ų ĳ���� ����
// 
//������1 �̸� ������1 ���� ������1 ���� ������1 �������� ������1 �߰� ���ݷ� ������1 
//�߰� ���� ������1 �߰� ü�� ������1 �߰� ���� ������1 ����
// 
//������2 �̸� ������2 ���� ������2 ���� ������2 �������� ������2 �߰� ���ݷ� ������2 
//�߰� ���� ������2 �߰� ü�� ������2 �߰� ���� ������2 ����

void save_game_data() {
	FILE* fp = fopen("save_data.txt", "w"); // ���� ����
	if (fp == NULL) {
		printf("error!\n");
		return;
	}

	// �÷��̾� ���� ����
	fprintf(fp, "%s, %d, %d, %d\n", playerInfo.playerName, playerInfo.level, playerInfo.levelPro, playerInfo.money);

	fprintf(fp, "%d, %d, %d, %d, %s, %s, %s\n",
		playerInfo.playerScharacterInfo.hp, playerInfo.playerScharacterInfo.defense,
		playerInfo.playerScharacterInfo.attack, playerInfo.playerScharacterInfo.mana,
		playerInfo.playerScharacterInfo.name, playerInfo.playerScharacterInfo.skill,
		playerInfo.playerScharacterInfo.charState);
	// �κ��丮 ���� ����
	for (int i = 0; i < playerInfo.itemIndex; i++) {
		fprintf(fp, "%s, %d, %d, %d, %d, %d, %d, %d, %s\n",
			playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[i].type,
			playerInfo.inventory[i].isEquipped, playerInfo.inventory[i].addAttack, playerInfo.inventory[i].addDefense,
			playerInfo.inventory[i].addHp, playerInfo.inventory[i].addMana, playerInfo.inventory[i].state);
	}

	

	fclose(fp); // ���� �ݱ�
}

void printSlowly(const char* text, int delay) { //print ���ڿ� �ϳ��ϳ� õõ��
	for (int i = 0; text[i] != '\0'; i++) {
		putchar(text[i]);
		Sleep(delay);
	}

}
char* StringvalueOf(int num) {
	char* str = malloc(sizeof(char) * 11);
	if (str == NULL) {
		return NULL;
	}
	sprintf(str, "%d", num);
	return str;
}

void printBar() {
	printf("------------------------------------------------------------------------------------------------------------------------\n");
}

void clear() {
	system("cls");
}