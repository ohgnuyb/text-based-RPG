#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <io.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>
#include <stdbool.h>
#include <fcntl.h>
#include "color.h"
#include "korean.c"
#include "english.c"
#include "rpg_struct.h"
#include "stringFunc.h"

typedef void (*drawWarrior_ptr)();
typedef void (*drawMage_ptr)();
typedef void (*drawRogue_ptr)();
typedef void (*drawChar_ptr)();
typedef void (*displayInventory_ptr)();
typedef void (*printstatus_ptr)();
typedef int (*useSkill_ptr)(int monsterIndex, int* skillIndex, int* con);
typedef bool (*battle_ptr)(int monsterIndex);
typedef void (*shop_ptr)();
typedef void (*printLevel_ptr)();
typedef void (*levelUp_ptr)();
typedef int (*selectPro_ptr)();
typedef void (*loadLevelPro_ptr)(int x, char* reason);
typedef void (*addMoney_ptr)(int x);
typedef void (*deleteItem_ptr)(char* target_itemName, int index);


drawWarrior_ptr drawWarrior;
drawMage_ptr drawMage;
drawRogue_ptr drawRogue;
drawChar_ptr drawChar;
displayInventory_ptr displayInventory;
printstatus_ptr printstatus;
useSkill_ptr useSkill;
battle_ptr battle;
shop_ptr shop;
printLevel_ptr printLevel;
levelUp_ptr levelUp;
loadLevelPro_ptr loadLevelPro;
selectPro_ptr selectPro;
addMoney_ptr addMoney;
deleteItem_ptr deleteItem;

int choice;
int charSel;
char title[50];;
int padding;
int st_ex;

void printMonster1() { //몬스터 첫번째
	setColor(VIOLET);
	printf("              .-\"\"\"\"\"-.\n");
	printf("            .'          '.\n");
	printf("           /   O      O   \\\n");
	printf("          :           `    :\n");
	printf("          |                |\n");
	printf("          :    .------.    :\n");
	printf("           \\  '        '  /\n");
	printf("            '.          .'\n");
	printf("              '-......-'\n");
	printf("               /        \\\n");
	printf("              |          |\n");
	printf("              |  .------.| \n");
	printf("              |  |      ||  \n");
	printf("              |  |      ||  \n");
	printf("              |  |      ||  \n");
	printf("              |  |      ||  \n");
	printf("              |  |      ||  \n");
	printf("             /    |    |  \\ \n");
	printf("            |     |    |   |\n");
	printf("            |_____|____|___|\n");
	printf("           (_____(_____)____)\n\n");
	setColor(WHITE);
}





int main(void) {
	FILE* checkNull = fopen("save_data.txt", "r");

	if (checkNull == NULL) {
		FILE* createFILE = fopen("save_data.txt", "w");

		fprintf(createFILE, "%d, %d\n", 0, 1);
		printf("다시 시작하세요. / Please restart.\n");

		fclose(createFILE);
		system("pause");
		return;
	}
	fseek(checkNull, 0, SEEK_END);
	long size = ftell(checkNull);
	if (size == 0) {
		checkNull = fopen("save_data.txt", "w");
;
		fprintf(checkNull, "%d, %d\n", 0, 1);
	}
	fclose(checkNull);

	system("title 문제해결기법 / 11조");

	checkNull = fopen("save_data.txt", "r"); // 파일 열기
	int temp;
	if (checkNull == NULL) {

		printf("Error\n");
		system("pause");
		return;
	}
	playerInfo.lang = 1;
	fscanf(checkNull, "%d, %d\n", &temp, &playerInfo.lang);
	fclose(checkNull);
	if (playerInfo.lang == 1) {

		choice = -1;
		charSel = -1;
		strcpy(title, "잊혀진 왕국의 비밀");
		padding = 46;

		st_ex = -1; //시작/종료 인덱스
		playerInfo.type = 'N';
		playerInfo.startIndex = 0;

		drawWarrior = drawWarrior_ko;
		drawMage = drawMage_ko;
		drawRogue = drawRogue_ko;
		drawChar = drawChar_ko;
		displayInventory = displayInventory_ko;
		printstatus = printstatus_ko;
		useSkill = useSkill_ko;
		battle = battle_ko;
		shop = shop_ko;
		printLevel = printLevel_ko;
		levelUp = levelUp_ko;
		loadLevelPro = loadLevelPro_ko;
		selectPro = selectPro_ko;
		addMoney = addMoney_ko;
		deleteItem = deleteItem_ko;

		strcpy(characterInfo[0].name, "전사");//한국어 캐릭터 구조체
		strcpy(characterInfo[0].skill, "파괴의 일격");
		strcpy(characterInfo[0].charState, "강인한 체력과 뛰어난 검술 실력을 가진 전사입니다.");
		strcpy(characterInfo[1].name, "마법사");//한국어 캐릭터 구조체
		strcpy(characterInfo[1].skill, "백만볼트");
		strcpy(characterInfo[1].charState, "강력한 마법을 사용하는 마법사입니다.");
		strcpy(characterInfo[2].name, "도적");//한국어 캐릭터 구조체
		strcpy(characterInfo[2].skill, "은신");
		strcpy(characterInfo[2].charState, "민첩한 움직임과 은밀한 행동에 능숙한 도적입니다.");

		strcpy(monster[0].name, "펜리르"); //첫 번째 몬스터
		monster[0].hp = 80;
		monster[0].attack = 20;
		monster[0].defense = 20;




	}
	else if (playerInfo.lang == 2) {

		choice = -1;
		charSel = -1;
		strcpy(title, "Secret of the Forgotten Kingdom");
		padding = 46;

		st_ex = -1;
		playerInfo.type = 'N';
		playerInfo.startIndex = 0;

		drawWarrior = drawWarrior_en;
		drawMage = drawMage_en;
		drawRogue = drawRogue_en;
		drawChar = drawChar_en;
		displayInventory = displayInventory_en;
		printstatus = printstatus_en;
		useSkill = useSkill_en;
		battle = battle_en;
		shop = shop_en;
		printLevel = printLevel_en;
		levelUp = levelUp_en;
		loadLevelPro = loadLevelPro_en;
		selectPro = selectPro_en;
		addMoney = addMoney_en;
		deleteItem = deleteItem_en;

		strcpy(characterInfo[0].name, "Warrior");
		strcpy(characterInfo[0].skill, "Destructive Strike");
		strcpy(characterInfo[0].charState, "A warrior with strong endurance and excellent swordsmanship.");
		strcpy(characterInfo[1].name, "Wizard");
		strcpy(characterInfo[1].skill, "Million Volt");
		strcpy(characterInfo[1].charState, "A wizard who uses powerful magic.");
		strcpy(characterInfo[2].name, "Rogue");
		strcpy(characterInfo[2].skill, "Stealth");
		strcpy(characterInfo[2].charState, "A rogue skilled in agile movements and stealthy actions.");

		strcpy(monster[0].name, "Fenrir");
		monster[0].hp = 80;
		monster[0].attack = 20;
		monster[0].defense = 20;



	}
	playerInfo.playerScharacterInfo.hp = 1;
	load_game_data();

	int startIndex = playerInfo.startIndex;

	if ((playerInfo.lang == 1 || playerInfo.lang == 2) && (startIndex == 0)) {
		goto line0;
	}
	else if (playerInfo.lang == 1 && startIndex == 1) {
		goto line1;
	}
	else if (playerInfo.lang == 1 && startIndex == 2) {
		goto line2;
	}
	else if (playerInfo.lang == 1 && startIndex == 3) {
		goto line3;
	}
	else if (playerInfo.lang == 1 && startIndex == 4) {
		goto line4;
	}
	else if (playerInfo.lang == 1 && startIndex == 5) {
		goto line5;

		//영어 버전
	}
	else if (playerInfo.lang == 2 && startIndex == 1) {
		goto line11;
	}
	else if (playerInfo.lang == 2 && startIndex == 2) {
		goto line12;
	}
	else if (playerInfo.lang == 2 && startIndex == 3) {
		goto line13;
	}
	else if (playerInfo.lang == 2 && startIndex == 4) {
		goto line14;
	}
	else if (playerInfo.lang == 2 && startIndex == 5) {
		goto line15;
	}


line0:
	printBar();

	printf("언어를 선택하세요. / Select a language.\n");
	printSlowly("1. 한국어 / Korean\n2. 영어 / English\n", 30);
	printf("Enter: ");

	while (playerInfo.playerScharacterInfo.hp > 0) {
		scanf("%d", &playerInfo.lang);
		printBar();
		if (playerInfo.lang == 1) {



			while (playerInfo.playerScharacterInfo.hp > 0) { //영어 부분 여기부터 복사
				srand(time(NULL));
				setColor(BLACK);


				for (int i = 0; i < padding; i++) {
					printf(" ");
				}
				setColor(RED);
				printf("\n");
				printf("      (\\____/)\n");
				printf("       (_oo_)\n");
				printf("        (oo)\n");
				printf("      /------\\/`\n");
				printf("     / |    ||\n");
				printf("    *  /\\---/\\\n");
				printf("       ~~   ~~\n");
				setColor(DARK_VOILET);
				for (int i = 0; i < padding - 15; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding + 3; i++) {
					printf(" ");
				}
				printSlowly(title, 250);
				printf("\n");
				for (int i = 0; i < padding - 15; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding + 1; i++) {
					printf(" ");
				}

				printf("\n\n");
				setColor(DARK_GREEN);
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                               .--\"\"--.\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              /        \\\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             |   *  *  |\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             \\  .--.  /\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              '.____.'\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                                ||||\n\n\n");

				setColor(WHITE);

			line1:
				printBar();
				printf("1. 시작\n2. 게임 종료\n");
				printBar();
				setColor(SKYBLUE);
				printSlowly("Tip: 게임 종료 시 내용은 저장됩니다.\n", 30);
				setColor(RED);
				printSlowly("Warning: 게임 종료 선택지로 종료해야 함.\n", 30);
				setColor(WHITE);
				printBar();
				while (playerInfo.playerScharacterInfo.hp > 0) {



					printf("Enter: ");
					scanf("%d", &st_ex);
					if (st_ex == 1) {
						playerInfo.level = 0;
						playerInfo.levelPro = 0;
						int charExit = 0;
						printBar();
						printf("이름을 입력하세요: \n");
						printf("Enter: ");
						scanf("%s", playerInfo.playerName);
						printBar();
						clear();
						printBar();
						for (int i = 0; i < padding; i++) {
							printf(" ");
						}
						setColor(RED);
						printf("\n");
						printf("      (\\____/)\n");
						printf("       (_oo_)\n");
						printf("        (oo)\n");
						printf("      /------\\/`\n");
						printf("     / |    ||\n");
						printf("    *  /\\---/\\\n");
						printf("       ~~   ~~\n");
						setColor(DARK_VOILET);
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 3; i++) {
							printf(" ");
						}
						printf(title);
						printf("\n");
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 1; i++) {
							printf(" ");
						}

						printf("\n\n");
						setColor(DARK_GREEN);
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                               .--\"\"--.\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              /        \\\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             |   *  *  |\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             \\  .--.  /\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              '.____.'\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                                ||||\n\n\n");
						setColor(WHITE);
						printBar();
						printSlowly("안녕하세요, ", 30);
						printSlowly(playerInfo.playerName, 200);
						printf("님!\n");
						printBar();
						loadLevelPro(100, "게임 시작");
						printBar();
						printLevel();
						printBar();
						addMoney(50);
						printBar();
						printSlowly("\'빈 종이\'와 \'하급 체력 포션\'이 지급되었습니다.\n", 100);
						printBar();
						loadLevelPro(30, "아이템 획득");
						printLevel();
						strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "빈 종이");
						strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "그냥 빈 종이입니다.");
						playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
						playerInfo.inventory[playerInfo.itemIndex].type = 3;
						playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
						playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
						playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
						playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
						playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
						playerInfo.itemIndex++;

						strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "하급 체력 포션");
						strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
						playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
						playerInfo.inventory[playerInfo.itemIndex].type = 2;
						playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
						playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
						playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
						playerInfo.inventory[playerInfo.itemIndex].addHp = 5;
						playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
						playerInfo.itemIndex++;


						line2:
						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip: 인벤토리와 상점은 선택창에 표시될 때 이용 가능합니다.\n", 30);
						setColor(WHITE);
						
						if (selectPro() == 4) {
							printBar();
							printSlowly("Game is closed!\n", 100);
							playerInfo.startIndex = 2;
							save_game_data();
							system("pause");
							return 0;
						}
						clear();
						printBar();
						setColor(RED);
						printSlowly("시작...\n", 300);

						setColor(WHITE);
						printSlowly("깊은 숲 속에 숨겨진 고대 왕국, '아르카디아'. 한때 번영했던 이 왕국은 어둠의 마법사 \n'말레피센트'의 저주로 인해 멸망하고, 사람들의 기억 속에서 잊혀졌습니다. \n당신은 우연히 아르카디아의 존재를 알게 된 모험가입니다. \n잊혀진 왕국의 비밀을 밝혀내고 말레피센트의 저주를 풀어 아르카디아를 부활시킬 수 있을까요?\n", 30);

	
						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip. 전사와 도적은 전투당 한 번의 스킬을 사용할 수 있고 마법사는 스킬 한 번당 마나 10을 소모합니다.\n", 100);
						while (playerInfo.playerScharacterInfo.hp > 0) {
							setColor(WHITE);
							printBar();
							printSlowly("캐릭터 선택: \n", 200);

							for (int i = 0; i < 3; i++) {
								setColor(i == 0 ? SKYBLUE : i == 1 ? YELLOW : RED);
								printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
								printSlowly(characterInfo[i].name, 200);
								printf(": ");
								setColor(WHITE);
								printSlowly(characterInfo[i].charState, 30);
								printf("\n");
							}

							printBar();
							printSlowly("4. 인벤토리\n5. 상점\n6. 게임 종료\n", 30);
							printBar();
							printf("Enter: ");
							scanf("%d", &charSel);
							int use = -1;

							if (charSel == 1) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("를 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);


								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
									printBar();
									loadLevelPro(100, "캐릭터 선택");
									printBar();
									printLevel();
									printBar();
									printSlowly("전사를 위한 \'목검\'이 지급되었습니다.\n", 30);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "목검");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 1;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 5;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
									
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("취소되었습니다.\n", 100);
									while (getchar() != '\n');
								}
								else {
									printBar();
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
								}


							}
							else if (charSel == 2) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("를 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;

									printBar();
									loadLevelPro(100, "캐릭터 선택");
									printBar();
									printLevel();
									printBar();
									printSlowly("마법사를 위한 \'마법사의 목걸이\'가 지급되었습니다.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "마법사의 목걸이");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 10;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("취소되었습니다.\n", 100);

									while (getchar() != '\n');
								}
								else {
									printBar();
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
								}

							}
							else if (charSel == 3) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("을 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;

									printBar();
									loadLevelPro(100, "캐릭터 선택");
									printBar();
									printLevel();
									printBar();
									printSlowly("도적을 위한 \'도적의 망토\'가 지급되었습니다.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "도적의 망토");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 10;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("취소되었습니다.\n", 100);

									while (getchar() != '\n');
								}
								else {
									printBar();
									while (getchar() != '\n');
								}
							}
							else if (charSel == 4) {
								displayInventory();
								while (getchar() != '\n');
							}
							else if (charSel == 5) {
								printBar();
								shop();
								while (getchar() != '\n');
							}
							else if (charSel == 6) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 2;
								save_game_data();
								system("pause");
								return 0;

							}
							else {
								printBar();
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}

						}
					line3:

						setColor(WHITE);

						if (selectPro() == 4) {
							printBar();
							printSlowly("Game is closed!\n", 100);
							playerInfo.startIndex = 3;
							save_game_data();
							system("pause");
							return 0;
						}
						clear();
						printBar();
					line4:
						setColor(RED);
						printSlowly("아르카디아로 향하는 길...\n", 200);
						setColor(WHITE);
						printSlowly("울창한 숲 속에서 길을 잃은 당신은 오래된 석판을 발견합니다.\n석판에는 아르카디아로 향하는 길에 대한 희미한 글귀가 새겨져 있습니다.\n", 20);
						printSlowly("\"저주받은 숲을 지나, 잊혀진 신전을 찾아라. \n신전의 수호자를 물리치고, 아르카디아의 문을 열어라.\"\n\n", 20);



						while (playerInfo.playerScharacterInfo.hp > 0) {
							printBar();
							setColor(RED);
							printf("선택: \n");
							setColor(WHITE);
							printSlowly("1. 저주받은 숲으로 향한다.\n", 100);
							printSlowly("2. 석판을 무시하고 다른 길을 찾는다.\n", 100);
							printBar();
							printSlowly("3. 인벤토리\n", 100);
							printSlowly("4. 상점\n", 100);
							printSlowly("5. 게임 종료\n", 100);
							printBar();
							printf("Enter: ");
							scanf("%d", &choice);
							if (choice == 1) { //1번 스토리
								printBar();
								setColor(YELLOW);
								printSlowly("숲의 보물\n", 50);
								setColor(WHITE);
								printSlowly("당신은 석판의 가르침에 따라 깊은 숲 속으로 들어섰다.\n저주받은 숲은 음산한 기운으로 가득하다...\n나무들은 기괴하게 뒤틀려 있고, 숲 속에는 알 수 없는 생명체들의 울음소리가 울려 퍼진다.\n", 20);
								printSlowly("깊은 숲을 헤치고 나아가던 중, 갑자기 시야에 오래된 유적지가 나타났다. 이곳은 분명 인간의 손길이 닿지 않은 듯한 모습이다.\n", 20);
								printSlowly("유적 한가운데 작은 제단이 놓여 있고, 그 위에는 뭔지모를 상자가 놓여있다.\n", 20);
								printBar();
								setColor(YELLOW);
								printSlowly("60% : 갑옷, 40 % : 포션\n", 100);
								setColor(WHITE);
								printBar();
								int use = -1;

								// 아이템 획득 확률 계산
								int itemChance = rand() % 100; // 0에서 99 사이의 랜덤 숫자
								if (itemChance < 60) { // 60% 확률로 갑옷 획득
									printSlowly("상자를 열어보니 갑옷이 들어있다.\n낡아 보이지만 아직 견고해 보인다.\n", 30);
									printBar();
									addMoney(50);
									printBar();
									loadLevelPro(50, "아이템 획득");
									printLevel();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "낡은 갑옷");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 5;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}

								}
								else { // 40% 확률로 공격력 증가 포션 획득
									printSlowly("상자를 열어보니 빛나는 포션이 들어있다.\n", 70);
									printBar();
									addMoney(50);
									printBar();
									loadLevelPro(50, "아이템 획득");
									printLevel();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "빛나는 포션");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 2;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 10;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}


								}

								printBar();
								printSlowly("아이템을 획득한 당신은 숲 속에서 빠져나가려 하지만, 여전히 음산한 기운이 주위를 감싸고 있다...\n", 20);
								printSlowly("숲 속에서 무언가가 움직이는 소리가 들린다. 당신은 발걸음을 재촉해 이곳을 빠져나가기로 한다.\n", 20);




							}
							else if (choice == 2) { //2번 스토리
								printBar();
								setColor(VIOLET);
								printSlowly("숲의 수호자\n", 50);
								setColor(WHITE);
								//몬스터 마주침
								printSlowly("석판의 가르침을 의심하며 다른 길을 선택한 당신은 숲을 헤매던 도중 거대한 몬스터, '펜리르'와 마주칩니다. \n펜리르는 숲의 수호자로, 아르카디아로 향하는 길을 막고 있습니다.\n", 20);
								setColor(YELLOW);
								printSlowly("전투 후 승리하세요.\n\n", 20);
								setColor(WHITE);
								printMonster1();
								printSlowly("이름: ", 50);
								printSlowly(monster[0].name, 50);
								printf("\n");
								setColor(RED);
								printSlowly(" - HP: ", 50);
								printSlowly(StringvalueOf(monster[0].hp), 50);
								setColor(WHITE);
								printf("\n");
								setColor(DARK_RED);
								printSlowly(" - 공격력: ", 50);
								printSlowly(StringvalueOf(monster[0].attack), 50);
								setColor(WHITE);
								printf("\n");
								setColor(SKYBLUE);
								printSlowly(" - 방어력: ", 50);
								printSlowly(StringvalueOf(monster[0].defense), 50);
								setColor(WHITE);
								printf("\n\n");

								drawChar();
								printSlowly(playerInfo.playerName, 200);
								printSlowly("님: ", 200);
								printSlowly(playerInfo.playerScharacterInfo.name, 200);
								printf("!\n");

								setColor(GREEN);
								printSlowly(" - Lv. ", 100);
								printSlowly(StringvalueOf(playerInfo.level), 100);
								printf("\n");

								setColor(RED);
								printSlowly(" - HP: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
								printf("\n");

								setColor(WHITE);
								printSlowly(" - 스킬: ", 100);
								printSlowly(playerInfo.playerScharacterInfo.skill, 100);
								printf("\n");
								setColor(DARK_RED);
								printSlowly(" - 공격력: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
								setColor(WHITE);
								printf("\n");
								setColor(SKYBLUE);
								printSlowly(" - 방어력: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
								setColor(WHITE);
								printf("\n");
								if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
									setColor(BLUE);
									printSlowly(" - 마나: ", 100);
									printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
									printf("\n");
									setColor(WHITE);
								}

								//원래 체력, 공격력, 방어력, 마나 기록
								int tempH = playerInfo.playerScharacterInfo.hp;
								int tempA = playerInfo.playerScharacterInfo.attack;
								int tempD = playerInfo.playerScharacterInfo.defense;
								int tempM = playerInfo.playerScharacterInfo.mana;

								if (battle(0) == true) { //0 = 몬스터 인덱스
									playerInfo.playerScharacterInfo.hp = tempH;
									playerInfo.playerScharacterInfo.attack = tempA;
									playerInfo.playerScharacterInfo.defense = tempD;
									playerInfo.playerScharacterInfo.mana = tempM;
									//전투에서 변경된 능력치 복구
									loadLevelPro(100, "전투 승리");
									printLevel();
									//승리일 경우 스토리 지속
									printBar();
									addMoney(60);
									printBar();
									printSlowly("펜리르를 물리친 당신은 드디어 숲을 빠져나가 아르카디아로 향하는 길을 여게 됩니다.\n", 30);


								}
								else {
									if (playerInfo.playerScharacterInfo.hp < 1) {
										printSlowly("플레이어가 사망했습니다.\n처음부터 다시 시작하세요.\n", 100);
										printSlowly("Game is closed!", 100);
										FILE* fp = fopen("save_data.txt", "r+");
										if (fp == NULL) {
											perror("파일 열기 실패");

										}
										int fd = fileno(fp);
										int result = _chsize(fd, 0);
										if (result != 0) {
											perror("파일 내용 비우기 실패\n");
											fclose(fp);

										}

										fclose(fp);
										system("pause");
										return 0;
									}
								}

								break;

							}
							else if (choice == 3) {
								displayInventory();
								while (getchar() != '\n');
							}

							else if (choice == 4) {
								printBar();
								shop();
								while (getchar() != '\n');
							}
							else if (choice == 5) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 4;
								save_game_data();
								system("pause");
								return 0;
							}
							else {
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}

						}

						//스토리 통합:
						printBar();
						printSlowly("숲을 빠져나온 당신은 새로운 세계, 아르카디아의 아름다움과 마주합니다.\n", 30);
						printSlowly("황금빛 들판과 맑은 하늘이 펼쳐지고, 희미한 전설로만 들었던 도시의 모습이 눈앞에 나타납니다.\n", 30);
						printSlowly("고난과 역경을 극복한 끝에, 이제 당신은 마침내 이곳에 도달했습니다.\n", 30);

					line5:
						printBar();
						setColor(SKYBLUE);

						printSlowly("아르카디아의 진정한 평화가 이제 시작되었습니다...\n", 30);
						setColor(WHITE);

						int option = 0;
						while (1) {
							printBar();
							printSlowly("1. 인벤토리\n2. 상점\n3. 게임 종료\n4. 처음부터 시작\n", 50);
							printf("Enter: ");
							scanf("%d", &option);
							if (option == 1) {
								displayInventory_ko();
								while (getchar() != '\n');
							}
							else if (option == 2) {
								shop_ko();
								while (getchar() != '\n');
							}
							else if (option == 3) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 5;
								save_game_data();
								system("pause");
								return 0;
							}
							else if (option == 4) {
								clear();
								setColor(SKYBLUE);
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("  _______ _            ______           _ \n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf(" |__   __| |          |  ____|         | |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | |__   ___  | |__   _ __   __| |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | '_ \\ / _ \\ |  __| | '_ \\ / _` |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | | | |  __/ | |____| | | | (_| |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    |_|  |_| |_|\\___| |______|_| |_|\\__,_|\n");
								setColor(WHITE);

								FILE* fp = fopen("save_data.txt", "r+");
								if (fp == NULL) {
									perror("파일 열기 실패");

								}
								int fd = fileno(fp);
								int result = _chsize(fd, 0);
								if (result != 0) {
									perror("파일 내용 비우기 실패");
									fclose(fp);

								}

								fclose(fp);
								printBar();
								int restart = 0;
								printSlowly("다시 시작하시겠습니까?\n", 50);
								printSlowly("1. 예\n2. 취소\n", 50);
								printf("Enter: ");
								while (1) {
									scanf("%d", &restart);
									if (restart == 1) {
										printSlowly("Game is closed!\n", 50);
										system("pause");
										return 0;

									}
									else {
										printBar();
										printSlowly("취소되었습니다.\n", 50);
										break;
									}
								}

							}
							else {
								printBar();
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}
						}


						system("pause");
						return 0;


						break;
					}
					else if (st_ex == 2) {
						printBar();
						printSlowly("Game is closed!\n", 100);
						playerInfo.startIndex = 1;
						save_game_data();
						system("pause");

						return 0;
					}
					else {
						printBar();
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						printBar();
						while (getchar() != '\n');
					}

				}

			}

			if (playerInfo.playerScharacterInfo.hp < 1) {
				printSlowly("플레이어가 사망했습니다.\n 처음부터 다시 시작하세요.\n", 100);
				printSlowly("Game is closed!", 100);
				FILE* fp = fopen("save_data.txt", "r+");
				if (fp == NULL) {
					perror("파일 열기 실패");

				}
				int fd = fileno(fp);
				int result = _chsize(fd, 0);
				if (result != 0) {
					perror("파일 내용 비우기 실패\n");
					fclose(fp);

				}

				fclose(fp);
				system("pause");
				return 0;//게임 종료/언어 선택 루프 종료
			}





			system("pause");
			return 0; //게임 종료/한국어 부분

			//영어 부분 여기까지 복사
		}
		else if (playerInfo.lang == 2) {
			choice = -1;
			charSel = -1;
			strcpy(title, "Secret of the Forgotten Kingdom");
			padding = 46;

			st_ex = -1;
			playerInfo.type = 'N';
			playerInfo.startIndex = 0;

			drawWarrior = drawWarrior_en;
			drawMage = drawMage_en;
			drawRogue = drawRogue_en;
			drawChar = drawChar_en;
			displayInventory = displayInventory_en;
			printstatus = printstatus_en;
			useSkill = useSkill_en;
			battle = battle_en;
			shop = shop_en;
			printLevel = printLevel_en;
			levelUp = levelUp_en;
			loadLevelPro = loadLevelPro_en;
			selectPro = selectPro_en;
			addMoney = addMoney_en;
			deleteItem = deleteItem_en;

			strcpy(characterInfo[0].name, "Warrior");
			strcpy(characterInfo[0].skill, "Destructive Strike");
			strcpy(characterInfo[0].charState, "A warrior with strong endurance and excellent swordsmanship.");
			strcpy(characterInfo[1].name, "Wizard");
			strcpy(characterInfo[1].skill, "Million Volt");
			strcpy(characterInfo[1].charState, "A wizard who uses powerful magic.");
			strcpy(characterInfo[2].name, "Rogue");
			strcpy(characterInfo[2].skill, "Stealth");
			strcpy(characterInfo[2].charState, "A rogue skilled in agile movements and stealthy actions.");

			strcpy(monster[0].name, "Fenrir");
			monster[0].hp = 80;
			monster[0].attack = 20;
			monster[0].defense = 20;


			//여기에 복붙

			while (playerInfo.playerScharacterInfo.hp > 0) {
				srand(time(NULL));
				setColor(BLACK);



				//두 번째 몬스터

				for (int i = 0; i < padding; i++) {
					printf(" ");
				}
				setColor(RED);
				printf("\n");
				printf("      (\\____/)\n");
				printf("       (_oo_)\n");
				printf("        (oo)\n");
				printf("      /------\\/`\n");
				printf("     / |    ||\n");
				printf("    *  /\\---/\\\n");
				printf("       ~~   ~~\n");
				setColor(DARK_VOILET);
				for (int i = 0; i < padding - 15; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding - 3; i++) {
					printf(" ");
				}
				printSlowly(title, 250);
				printf("\n");
				for (int i = 0; i < padding; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding + 1; i++) {
					printf(" ");
				}

				printf("\n\n");
				setColor(DARK_GREEN);
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                               .--\"\"--.\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              /        \\\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             |   *  *  |\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             \\  .--.  /\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              '.____.'\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                                ||||\n\n\n");

				setColor(WHITE);

			line11:
				printBar();
				printf("1. Start\n2. Game Over\n");
				printBar();
				setColor(SKYBLUE);
				printSlowly("Tip: The content will be saved at the end of the game.\n", 30);
				setColor(RED);
				printSlowly("Warning: Should be terminated with Game Over option.\n", 30);
				setColor(WHITE);
				printBar();
				while (playerInfo.playerScharacterInfo.hp > 0) {



					printf("Enter: ");
					scanf("%d", &st_ex);
					if (st_ex == 1) {
						playerInfo.level = 0;
						playerInfo.levelPro = 0;
						int charExit = 0;
						printBar();
						printf("Please enter your name: \n");
						printf("Enter: ");
						scanf("%s", playerInfo.playerName);
						printBar();
						clear();
						printBar();
						for (int i = 0; i < padding; i++) {
							printf(" ");
						}
						setColor(RED);
						printf("\n");
						printf("      (\\____/)\n");
						printf("       (_oo_)\n");
						printf("        (oo)\n");
						printf("      /------\\/`\n");
						printf("     / |    ||\n");
						printf("    *  /\\---/\\\n");
						printf("       ~~   ~~\n");
						setColor(DARK_VOILET);
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 3; i++) {
							printf(" ");
						}
						printf(title);
						printf("\n");
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 1; i++) {
							printf(" ");
						}

						printf("\n\n");
						setColor(DARK_GREEN);
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                               .--\"\"--.\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              /        \\\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             |   *  *  |\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             \\  .--.  /\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              '.____.'\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                                ||||\n\n\n");
						setColor(WHITE);
						printBar();
						printSlowly("Hello, ", 30);
						printSlowly(playerInfo.playerName, 200);
						printf("\'s choice!\n");
						printBar();
						loadLevelPro(100, "Game on");
						printBar();
						printLevel();
						printBar();
						addMoney(50);
						printBar();
						printSlowly("\'Empty Paper\' and \'a low-level Health Potion\' were given.\n", 100);
						printBar();
						loadLevelPro(30, "Acquire item");
						printLevel();
						strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "Empty Paper");
						strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "It's just Empty paper.");
						playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
						playerInfo.inventory[playerInfo.itemIndex].type = 3;
						playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
						playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
						playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
						playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
						playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
						playerInfo.itemIndex++;

						strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "a low-level Health Potion");
						strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
						playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
						playerInfo.inventory[playerInfo.itemIndex].type = 2;
						playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
						playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
						playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
						playerInfo.inventory[playerInfo.itemIndex].addHp = 5;
						playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
						playerInfo.itemIndex++;



						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip: Inventory and stores are available when displayed in the selection window.\n", 30);
						setColor(WHITE);
					line12:
						if (selectPro() == 4) {
							printBar();
							printSlowly("Game is closed!\n", 100);
							playerInfo.startIndex = 2;
							save_game_data();
							system("pause");
							return 0;
						}
						clear();
						printBar();
						setColor(RED);
						printSlowly("Start...\n", 300);

						setColor(WHITE);
						printSlowly("Arcadia, an ancient kingdom hidden in a deep forest. This once prosperous kingdom is a dark wizard \nDestroyed by the curse of Maleficent, forgotten in people's memory. \nYou are an adventurer who happens to know Arcadia's existence. \nCan we uncover the secrets of the forgotten kingdom and unlock the curse of Maleficent to resurrect Arcadia?\n", 30);

			
						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip. Warriors and Rogue can use one skill per battle and the wizard consumes Mana 10 per skill.\n", 100);
						while (playerInfo.playerScharacterInfo.hp > 0) {
							setColor(WHITE);
							printBar();
							printSlowly("Select a character: \n", 200);

							for (int i = 0; i < 3; i++) {
								setColor(i == 0 ? SKYBLUE : i == 1 ? YELLOW : RED);
								printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
								printSlowly(characterInfo[i].name, 200);
								printf(": ");
								setColor(WHITE);
								printSlowly(characterInfo[i].charState, 30);
								printf("\n");
							}

							printBar();
							printSlowly("4. Inventory\n5. Shop\n6. Game Over\n", 30);
							printBar();
							printf("Enter: ");
							scanf("%d", &charSel);
							int use = -1;

							if (charSel == 1) {
								printBar();
								printSlowly("Really ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("Would you like to select?\n", 50);
								printSlowly("1. select\n2. cancel\n", 50);


								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
									printBar();
									loadLevelPro(100, "Select a character");
									printBar();
									printLevel();
									printBar();
									printSlowly("\'Wooden Sword\' has been given for warriors.\n", 30);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "Wooden Sword");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 1;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 5;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. Inventory\n2. cancel\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("It has been canceled .\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("Invalid choice, please re-select.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("It has been canceled.\n", 100);
									while (getchar() != '\n');
								}
								else {
									printBar();
									printSlowly("Invalid choice, please re-select.\n", 100);
									while (getchar() != '\n');
								}


							}
							else if (charSel == 2) {
								printBar();
								printSlowly("Really ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("Do you want to select ?\n", 50);
								printSlowly("1. Select\n2. Cancel\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;

									printBar();
									loadLevelPro(100, "Select a character");
									printBar();
									printLevel();
									printBar();
									printSlowly("\'Wizard's Necklace\' has been given for the wizard.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "The Wizard's Necklace");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 10;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. Inventory\n2. Cancel\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("It has been canceled.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("Invalid choice, please re-select.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("It has been canceled.\n", 100);

									while (getchar() != '\n');
								}
								else {
									printBar();
									printSlowly("Invalid choice, please re-select.\n", 100);
									while (getchar() != '\n');
								}

							}
							else if (charSel == 3) {
								printBar();
								printSlowly("Really ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("Would you like to select?\n", 50);
								printSlowly("1.Select\n2. Cancel\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;

									printBar();
									loadLevelPro(100, "Select a character");
									printBar();
									printLevel();
									printBar();
									printSlowly("\'The Cloak of the Rouge' was given for the Rouge.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "The Cloak of the Rouge");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 10;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. Inventory\n2. Cancel\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("It has been canceled.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("Invalid choice, please re-select.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("It has been canceled .\n", 100);

									while (getchar() != '\n');
								}
								else {
									printBar();
									while (getchar() != '\n');
								}
							}
							else if (charSel == 4) {
								displayInventory();
								while (getchar() != '\n');
							}
							else if (charSel == 5) {
								printBar();
								shop();
								while (getchar() != '\n');
							}
							else if (charSel == 6) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 2;
								save_game_data();
								system("pause");
								return 0;

							}
							else {
								printBar();
								printSlowly("Invalid choice, please re-select.\n", 100);
								while (getchar() != '\n');
							}

						}
					line13:

						setColor(WHITE);

						if (selectPro() == 4) {
							printBar();
							printSlowly("Game is closed!\n", 100);
							playerInfo.startIndex = 3;
							save_game_data();
							system("pause");
							return 0;
						}
						clear();
						printBar();
					line14:
						setColor(RED);
						printSlowly("the road to Arcadia...\n", 200);
						setColor(WHITE);
						printSlowly("Lost in the dense forest, you find an old lithograph.\n[Voiceover] There's a faint inscription on the stone tablet about the way to Arcadia.\n", 20);
						printSlowly("\"Through the cursed forest, find a forgotten temple. \nDefeat the guardian of the temple, open the door of Arcadia.\"\n\n", 20);



						while (playerInfo.playerScharacterInfo.hp > 0) {
							printBar();
							setColor(RED);
							printf("선택: \n");
							setColor(WHITE);
							printSlowly("1. Heading into the Cursed Forest.\n", 100);
							printSlowly("2. Ignoring the lithographs and finding a different path.\n", 100);
							printBar();
							printSlowly("3. Inventory\n", 100);
							printSlowly("4. Inventory\n", 100);
							printSlowly("5. Game Over\n", 100);
							printBar();
							printf("Enter: ");
							scanf("%d", &choice);
							if (choice == 1) { //1번 스토리
								printBar();
								setColor(YELLOW);
								printSlowly("the treasure of the forest\n", 50);
								setColor(WHITE);
								printSlowly("You have entered the deep forest following the instructions of the lithograph.\nCursed forests are full of dreary energy...\nThe trees are grotesquely twisted, and there are calls of unknown creatures in the forest.\n", 20);
								printSlowly("While moving through the deep forest, an old historical site suddenly appeared in view. This place certainly seems to have been untouched by humans.\n", 20);
								printSlowly("A small altar is placed in the middle of the ruins, and a box is placed on top of it that you don't know what it is.\n", 20);
								printBar();
								setColor(YELLOW);
								printSlowly("60% : Armor, 40 % : Potion\n", 100);
								setColor(WHITE);
								printBar();
								int use = -1;

								// 아이템 획득 확률 계산
								int itemChance = rand() % 100; // 0에서 99 사이의 랜덤 숫자
								if (itemChance < 60) { // 60% 확률로 갑옷 획득
									printSlowly("I opened the box and found the armor.\nIt looks old, but it still looks solid.\n", 30);
									printBar();
									addMoney(50);
									printBar();
									loadLevelPro(50, "Acquire item");
									printLevel();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "old armor");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 4;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 0;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 5;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printBar();
									printSlowly("1. Inventory\n2. Cancel\n", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("It has been canceled .\n", 100);
											break;
										}
										else {
											printBar();
											printSlowly("Invalid choice, please re-select.\n", 100);
											while (getchar() != '\n');
										}

									}

								}
								else { // 40% 확률로 공격력 증가 포션 획득
									printSlowly("I opened the box and found a glowing potion.\n", 70);
									printBar();
									addMoney(50);
									printBar();
									loadLevelPro(50, "Acquire item");
									printLevel();
									strcpy(playerInfo.inventory[playerInfo.itemIndex].item, "shining potion");
									playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
									playerInfo.inventory[playerInfo.itemIndex].type = 2;
									playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
									playerInfo.inventory[playerInfo.itemIndex].addAttack = 10;
									playerInfo.inventory[playerInfo.itemIndex].addDefense = 0;
									playerInfo.inventory[playerInfo.itemIndex].addHp = 0;
									playerInfo.inventory[playerInfo.itemIndex].addMana = 0;
									strcpy(playerInfo.inventory[playerInfo.itemIndex].state, "UNDEFINED");
									playerInfo.itemIndex++;
									printBar();
									printSlowly("1. Inventory\n2. Cancel", 100);
									while (playerInfo.playerScharacterInfo.hp > 0) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly(".\n", 100);
											break;
										}
										else {
											printBar();
											printSlowly("Invalid choice, please re-select.\n", 100);
											while (getchar() != '\n');
										}

									}


								}

								printBar();
								printSlowly("Having acquired the item, you try to escape from the woods, but there is still a dreary energy surrounding you...\n", 20);
								printSlowly("I can hear something moving in the forest. You decide to rush your steps out of here.\n", 20);




							}
							else if (choice == 2) { //2번 스토리
								printBar();
								setColor(VIOLET);
								printSlowly("Guardian of the Forest\n", 50);
								setColor(WHITE);
								//몬스터 마주침
								printSlowly("Doubting the teachings of the lithographs, you choose a different path, and while wandering through the woods, you encounter a giant monster, 'Penrir.' \nPenrir is the guardian of the forest, blocking the way to Arcadia.\n", 20);
								setColor(YELLOW);
								printSlowly("전투 후 승리하세요 .\n\n", 20);
								setColor(WHITE);
								printMonster1();
								printSlowly("Name: ", 50);
								printSlowly(monster[0].name, 50);
								printf("\n");
								setColor(RED);
								printSlowly(" - HP: ", 50);
								printSlowly(StringvalueOf(monster[0].hp), 50);
								setColor(WHITE);
								printf("\n");
								setColor(DARK_RED);
								printSlowly(" - ATK: ", 50);
								printSlowly(StringvalueOf(monster[0].attack), 50);
								setColor(WHITE);
								printf("\n");
								setColor(SKYBLUE);
								printSlowly(" - DEF: ", 50);
								printSlowly(StringvalueOf(monster[0].defense), 50);
								setColor(WHITE);
								printf("\n\n");

								drawChar();
								printSlowly(playerInfo.playerName, 200);
								printSlowly("’s choice: ", 200);
								printSlowly(playerInfo.playerScharacterInfo.name, 200);
								printf("!\n");

								setColor(GREEN);
								printSlowly(" - Lv. ", 100);
								printSlowly(StringvalueOf(playerInfo.level), 100);
								printf("\n");

								setColor(RED);
								printSlowly(" - HP: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
								printf("\n");

								setColor(WHITE);
								printSlowly(" - Skill: ", 100);
								printSlowly(playerInfo.playerScharacterInfo.skill, 100);
								printf("\n");
								setColor(DARK_RED);
								printSlowly(" - ATK: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
								setColor(WHITE);
								printf("\n");
								setColor(SKYBLUE);
								printSlowly(" - DEF: ", 100);
								printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
								setColor(WHITE);
								printf("\n");
								if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
									setColor(BLUE);
									printSlowly(" - Mana: ", 100);
									printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
									printf("\n");
									setColor(WHITE);
								}

								//원래 체력, 공격력, 방어력, 마나 기록
								int tempH = playerInfo.playerScharacterInfo.hp;
								int tempA = playerInfo.playerScharacterInfo.attack;
								int tempD = playerInfo.playerScharacterInfo.defense;
								int tempM = playerInfo.playerScharacterInfo.mana;

								if (battle(0) == true) { //0 = 몬스터 인덱스
									playerInfo.playerScharacterInfo.hp = tempH;
									playerInfo.playerScharacterInfo.attack = tempA;
									playerInfo.playerScharacterInfo.defense = tempD;
									playerInfo.playerScharacterInfo.mana = tempM;
									//전투에서 변경된 능력치 복구
									loadLevelPro(100, "a battle victory");
									printLevel();
									//승리일 경우 스토리 지속
									printBar();
									addMoney(60);
									printBar();
									printSlowly("After defeating Penrir, you finally make your way out of the woods to Arcadia.\n", 30);


								}
								else {
									if (playerInfo.playerScharacterInfo.hp < 1) {

										printSlowly("Player died.\nPlease start again from the beginning..\n", 100);
										printSlowly("Game is closed!", 100);
										FILE* fp = fopen("save_data.txt", "r+");
										if (fp == NULL) {
											perror("Failed to open file");

										}
										int fd = fileno(fp);
										int result = _chsize(fd, 0);
										if (result != 0) {
											perror("Failed to empty file content\n");
											fclose(fp);

										}

										fclose(fp);
										system("pause");
										return 0;
									}
								}

								break;

							}
							else if (choice == 3) {
								displayInventory();
								while (getchar() != '\n');
							}

							else if (choice == 4) {
								printBar();
								shop();
								while (getchar() != '\n');
							}
							else if (choice == 5) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 4;
								save_game_data();
								system("pause");
								return 0;
							}
							else {
								printSlowly("Invalid choice, please re-select.\n", 100);
								while (getchar() != '\n');
							}

						}

						//스토리 통합:
						printBar();
						printSlowly("Out of the woods, you face a new world, the beauty of Arcadia.\n", 30);
						printSlowly("A golden field and clear sky unfold, and a city that you've only heard of as a faint legend appears in front of your eyes.\n", 30);
						printSlowly("After overcoming hardship and adversity, now you finally get here.\n", 30);

					line15:
						printBar();
						setColor(SKYBLUE);

						printSlowly("Real peace in Arcadia has begun...\n", 30);
						setColor(WHITE);

						int option = 0;
						while (1) {
							printBar();
							printSlowly("1. Inventory\n2. Shop\n3. Game Over\n4. Start from the beginning\n", 50);
							printf("Enter: ");
							scanf("%d", &option);
							if (option == 1) {
								displayInventory_ko();
								while (getchar() != '\n');
							}
							else if (option == 2) {
								shop_ko();
								while (getchar() != '\n');
							}
							else if (option == 3) {
								printBar();
								printSlowly("Game is closed!\n", 100);
								playerInfo.startIndex = 5;
								save_game_data();
								system("pause");
								return 0;
							}
							else if (option == 4) {
								clear();
								setColor(SKYBLUE);
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("  _______ _            ______           _ \n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf(" |__   __| |          |  ____|         | |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | |__   ___  | |__   _ __   __| |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | '_ \\ / _ \\ |  __| | '_ \\ / _` |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    | |  | | | |  __/ | |____| | | | (_| |\n");
								for (int i = 0; i < padding - 10; i++) {
									printf(" ");
								}
								printf("    |_|  |_| |_|\\___| |______|_| |_|\\__,_|\n");
								setColor(WHITE);

								FILE* fp = fopen("save_data.txt", "r+");
								if (fp == NULL) {
									perror("Failed to open file");

								}
								int fd = fileno(fp);
								int result = _chsize(fd, 0);
								if (result != 0) {
									perror("Failed to empty file content");
									fclose(fp);

								}

								fclose(fp);
								printBar();
								int restart = 0;
								printSlowly("Do you want to restart?\n", 50);
								printSlowly("1. Yes\n2. Cancel\n", 50);
								printf("Enter: ");
								while (1) {
									scanf("%d", &restart);
									if (restart == 1) {
										printSlowly("Game is closed!\n", 50);
										system("pause");
										return 0;
									}
									else {
										printBar();
										printSlowly(".\n", 50);
										break;
									}
								}

							}
							else {
								printBar();
								printSlowly("Invalid choice, please re-select.\n", 100);
								while (getchar() != '\n');
							}
						}

						system("pause");

						return 0;


						break;
					}
					else if (st_ex == 2) {
						printBar();
						printSlowly("Game is closed!\n", 100);
						playerInfo.startIndex = 1;
						save_game_data();
						system("pause");
						return 0;
					}
					else {
						printBar();
						printSlowly("Invalid choice, please re-select.\n", 100);
						printBar();
						while (getchar() != '\n');
					}

				}

			}

			if (playerInfo.playerScharacterInfo.hp < 1) {

				printSlowly("Player died.\nPlease start again from the beginning.\n", 100);
				printSlowly("Game is closed!", 100);
				FILE* fp = fopen("save_data.txt", "r+");
				if (fp == NULL) {
					perror("   Failed to open file");

				}
				int fd = fileno(fp);
				int result = _chsize(fd, 0);
				if (result != 0) {
					perror("Failed to empty file content\n");
					fclose(fp);

				}

				fclose(fp);
				system("pause");
				return 0;//게임 종료/언어 선택 루프 종료
			}




			system("pause");

			return 0; //게임 종료/한국어 부분




		}

		else {
			printSlowly("잘못된 선택입니다. 다시 선택해주세요. / It\'s a wrong choice. Please select again.\n", 100);
			printf("Enter: ");
			while (getchar() != '\n');
		}


	}

}