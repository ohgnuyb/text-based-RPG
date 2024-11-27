#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

void load_game_data() {
	FILE* fp = fopen("save_data.txt", "r"); // 파일 열기
	playerInfo.itemIndex = 0;
	if (fp == NULL) {



		return;
	}

	// 플레이어 정보 불러오기
	fscanf(fp, "%[^,], %d, %d, %d\n", playerInfo.playerName, &playerInfo.level, &playerInfo.levelPro, &playerInfo.money);

	fscanf(fp, "%d, %d, %d, %d, %s, %s, %[^ ]\n",
		&playerInfo.playerScharacterInfo.hp, &playerInfo.playerScharacterInfo.defense,
		&playerInfo.playerScharacterInfo.attack, &playerInfo.playerScharacterInfo.mana,
		playerInfo.playerScharacterInfo.name, playerInfo.playerScharacterInfo.skill,
		playerInfo.playerScharacterInfo.charState);

	// 인벤토리 정보 불러오기
	while (fscanf(fp, "%[^,], %d, %d, %d, %d, %d, %d, %d, %[^ ]\n",
		playerInfo.inventory[playerInfo.itemIndex].item, &playerInfo.inventory[playerInfo.itemIndex].quantity, &playerInfo.inventory[playerInfo.itemIndex].type,
		&playerInfo.inventory[playerInfo.itemIndex].isEquipped, &playerInfo.inventory[playerInfo.itemIndex].addAttack, &playerInfo.inventory[playerInfo.itemIndex].addDefense,
		&playerInfo.inventory[playerInfo.itemIndex].addHp, &playerInfo.inventory[playerInfo.itemIndex].addMana, playerInfo.inventory[playerInfo.itemIndex].state) != EOF) {

		playerInfo.itemIndex++;
	}

	

	fclose(fp); // 파일 닫기
}

//플레이어 이름 레벨 경험치 돈
// 
//hp 방어력 공격력 마나 캐릭터 이름 스킬 캐릭터 상태
// 
//아이템1 이름 아이템1 수량 아이템1 종류 아이템1 장착여부 아이템1 추가 공격력 아이템1 
//추가 방어력 아이템1 추가 체력 아이템1 추가 마나 아이템1 상태
// 
//아이템2 이름 아이템2 수량 아이템2 종류 아이템2 장착여부 아이템2 추가 공격력 아이템2 
//추가 방어력 아이템2 추가 체력 아이템2 추가 마나 아이템2 상태

void save_game_data() {
	FILE* fp = fopen("save_data.txt", "w"); // 파일 열기
	if (fp == NULL) {
		printf("error!\n");
		return;
	}

	// 플레이어 정보 저장
	fprintf(fp, "%s, %d, %d, %d\n", playerInfo.playerName, playerInfo.level, playerInfo.levelPro, playerInfo.money);

	fprintf(fp, "%d, %d, %d, %d, %s, %s, %s\n",
		playerInfo.playerScharacterInfo.hp, playerInfo.playerScharacterInfo.defense,
		playerInfo.playerScharacterInfo.attack, playerInfo.playerScharacterInfo.mana,
		playerInfo.playerScharacterInfo.name, playerInfo.playerScharacterInfo.skill,
		playerInfo.playerScharacterInfo.charState);
	// 인벤토리 정보 저장
	for (int i = 0; i < playerInfo.itemIndex; i++) {
		fprintf(fp, "%s, %d, %d, %d, %d, %d, %d, %d, %s\n",
			playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[i].type,
			playerInfo.inventory[i].isEquipped, playerInfo.inventory[i].addAttack, playerInfo.inventory[i].addDefense,
			playerInfo.inventory[i].addHp, playerInfo.inventory[i].addMana, playerInfo.inventory[i].state);
	}

	

	fclose(fp); // 파일 닫기
}

void printSlowly(const char* text, int delay) { //print 문자열 하나하나 천천히
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