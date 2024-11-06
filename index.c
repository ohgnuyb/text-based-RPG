#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX_INVENTORY_SIZE 10
#define DEFENSE_RATE 0.2

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void setColor(unsigned short text) { //cmd창 글자색 설정
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

struct character {
	char name[20];
	char skill[20];
	char charState[100];
	int hp;
	int attack;
	int defense;
	int mana;
};

struct inventoryItem {
	char item[20];
	int  quantity;
	int type; //1: 장비, 2: 물약
	int isEquipped;
	int addAttack;
	int addDefense;
	int addHp;
	int addMana;
};

struct character characterInfo[3] = {
	{"전사", "파괴의 일격", "강인한 체력과 뛰어난 검술 실력을 가진 전사입니다.", 120, 10, 10, 0}, //마나가 없는 대신 전투 한 번에 스킬 한 번 사용 가능
	{"마법사", "백만볼트", "강력한 마법을 사용하는 마법사입니다.", 90, 20, 0, 10}, //스킬 사용시 마나 -10
	{"도적", "은신", "민첩한 움직임과 은밀한 행동에 능숙한 도적입니다.", 60, 30, 0, 0} //마나가 없는 대신 전투 한 번에 스킬 한 번 사용 가능
}; //스킬 데미지는 캐릭터의 현재 공격력 * 2

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


void drawWarrior() {
	printf("==|==>>\n");
	printf("\\  O\n");
	printf("  \\|\\\n");
	printf("  / \\\n");
	printf(" /   \\\n");

	printf("\n");
}

void drawMage() {
	printf("==== *\n");
	printf("\\  O\n");
	printf("  \\|\\\n");
	printf("  / \\\n");
	printf(" /   \\\n");
	printf("\n");
}

void drawRogue() {
	printf("   O\n");
	printf("  /|-- * * *\n");
	printf("  / \\\n");
	printf(" /   \\\n");
	printf("\n");
}

void drawChar() {
	if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0) {
		drawWarrior();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
		drawMage();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
		drawRogue();
	}
	else {
		//추가 캐릭터
	}
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

void displayInventory() {
	int selected = 0;

	while (1) { // while 루프를 사용하여 반복
		selected = 0; // selected 값 초기화
		printf("------------------------------------------------------------------------------------------\n");
		setColor(YELLOW);
		printf("===== 인벤토리 =====\n");
		setColor(WHITE);
		for (int i = 0; i < 10; i++) {
			if (playerInfo.inventory[i].quantity > 0) {
				if (playerInfo.inventory[i].isEquipped == 1) {
					printf("%d. %s: %d개 / 장착 중\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
				}
				else {
					if (playerInfo.inventory[i].type == 2) {
						printf("%d. %s: %d개 / 미사용\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else {
						printf("%d. %s: %d개 / 미장착 중\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					}
					
				selected++;
			}
		}

		if (selected == 0) {
			printSlowly("인벤토리가 비어 있습니다.\n", 30);
			break; // 인벤토리가 비어있으면 while 루프 종료
		}

		int selectedIndex = 0;
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("몇 번째 아이템을 선택하시겠습니까?\n0. 나가기\n", 30);

		while (1) {
			printf("Enter: ");
			scanf("%d", &selectedIndex);

			if (selectedIndex <= selected && selectedIndex != 0) {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("선택한 아이템: ", 30);
				printSlowly(playerInfo.inventory[selectedIndex - 1].item, 30);
				printf("\n");
				printf("------------------------------------------------------------------------------------------\n");
				printf("1. 장착/사용\n2. 장착 해제(장비)\n3. 취소\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						if (playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("이미 장착 중입니다.\n", 30);
							break;
						}
						else if(playerInfo.inventory[selectedIndex - 1].isEquipped == 0){
							if (playerInfo.inventory[selectedIndex - 1].type == 2) {
								if (playerInfo.inventory[selectedIndex - 1].addMana > 0 && strcmp(playerInfo.playerScharacterInfo.name, "마법사") != 0) {
									printSlowly("마나 증가 포션은 마법사만 사용할 수 있습니다.\n", 100);
								}
								else {
									playerInfo.inventory[selectedIndex - 1].quantity--;
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("포션을 사용했습니다. / 지속시간 5분\n", 30);
								}
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("체력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("방어력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("공격력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
										setColor(BLUE);
										printSlowly("마나: +", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addMana), 100);
										printf("\n");
										setColor(WHITE);
									}

								}
								else {
									//다른 능력일 경우
								}
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;

								// 타임 설정 해야됨.

							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
								playerInfo.inventory[selectedIndex - 1].isEquipped = 1;
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("장비를 착용했습니다.\n", 30);
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("체력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("방어력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("공격력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
										setColor(BLUE);
										printSlowly("마나: +", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addMana), 100);
										printf("\n");
										setColor(WHITE);
									}

								}
							}
						}
						
						break;

					}
					else if (temp == 2) {
						if (playerInfo.inventory[selectedIndex - 1].type == 2) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("포션은 장착 해제가 불가합니다.\n", 30);

						}
						else if(playerInfo.inventory[selectedIndex - 1].type == 1){
							if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("이미 장착하지 않고 있습니다.\n", 30);
								break;
							}
							else {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("장비를 착용 해제했습니다.\n", 30);
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("체력: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("방어력: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("공격력: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
										setColor(BLUE);
										printSlowly("마나: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addMana), 100);
										printf("\n");
										setColor(WHITE);
									}

								}
								playerInfo.inventory[selectedIndex - 1].isEquipped = 0;
								playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp -= playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana -= playerInfo.inventory[selectedIndex - 1].addMana;
								break;
							}
						}
					}
					else if (temp == 3) {
						printf("------------------------------------------------------------------------------------------\n");
						printf("취소되었습니다.\n");
						break;
					}
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
						while (getchar() != '\n');
					}
				}

				break; // 아이템 장착/사용 후 루프 종료
			}
			else if (selectedIndex == 0) {
				printf("------------------------------------------------------------------------------------------\n");
				drawChar();
				printSlowly(playerInfo.playerName, 200);
				printSlowly("님: ", 200);
				printSlowly(playerInfo.playerScharacterInfo.name, 200);
				printf("!\n");

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
				return; // 인벤토리 종료 후 함수 종료
			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
				while (getchar() != '\n');
			}
		}
	}
}



void printMonster1() {
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
}

void printstatus() {
	drawChar();
	printSlowly(playerInfo.playerName, 200);
	printSlowly("님의 선택: ", 200);
	printSlowly(playerInfo.playerScharacterInfo.name, 200);
	printf("!\n");

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
}


void useSkill(int monsterIndex, int* skillIndex, int* con) { //스킬 데미지는 캐릭터의 현재 공격력 * 2
	//마법사는 마나 -=10 / 도적은 공격이 아니라 방어력 100으로 은신 구현
	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "마법사") != 0) {
	printf("------------------------------------------------------------------------------------------\n");
	printSlowly("스킬 사용: ", 100);
	if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0) {
		setColor(GREEN);
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
		setColor(RED);
	}
	else {
		//추가 캐릭터
	}
	int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
	printSlowly(playerInfo.playerScharacterInfo.skill, 100);
	setColor(WHITE);
	printSlowly("!\n", 100);
	printSlowly(monster[monsterIndex].name, 50);
	printSlowly("에게 스킬을 사용했습니다. \n데미지: ", 50);
	setColor(RED);
	printSlowly(StringvalueOf(damage), 100);
	printf("\n");
	setColor(WHITE);
	printSlowly(monster[monsterIndex].name, 50);
	printf(":");
	setColor(RED);
	printSlowly(" HP ", 100);
	monster[monsterIndex].hp -= damage;
	printSlowly(StringvalueOf(monster[monsterIndex].hp), 50);
	setColor(WHITE);
	*skillIndex = 1;

	printf("\n");
	printf("------------------------------------------------------------------------------------------\n");
	printSlowly("사용 가능 횟수: 0\n", 30);


	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
		int skillMage = playerInfo.playerScharacterInfo.mana / 10;
		if (skillMage > 0) {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("스킬 사용: ", 100);
			setColor(BLUE);
			int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
			printSlowly(playerInfo.playerScharacterInfo.skill, 100);
			setColor(WHITE);
			printSlowly("!\n", 100);
			printSlowly(monster[monsterIndex].name, 50);
			printSlowly("에게 스킬을 사용했습니다. 마나: ", 50);
			setColor(BLUE);
			printSlowly("-10", 50);
			setColor(WHITE);
			printSlowly("\n데미지: ", 50);
			setColor(RED);
			printSlowly(StringvalueOf(damage), 100);
			printf("\n");
			setColor(WHITE);
			printSlowly(monster[monsterIndex].name, 50);
			printf(":");
			setColor(RED);
			printSlowly(" HP ", 100);
			monster[monsterIndex].hp -= damage;
			printSlowly(StringvalueOf(monster[monsterIndex].hp), 50);
			
			printf("\n");
			playerInfo.playerScharacterInfo.mana -= 10;
			setColor(WHITE);
		}
		else {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("마나가 부족합니다. / \n", 100);
			setColor(BLUE);
			printSlowly("필요 마나: 10 \n", 100);
			setColor(WHITE);
			
		}
	}
	else {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("이미 스킬을 사용하였습니다.\n", 100);
		printf("------------------------------------------------------------------------------------------\n");
		*con = -1;
	}

}
int battle(int monsterIndex) {
	int turn = 0;
	int defenseTurn = 0; //0. 방어 안 함, 1. 방어 상태
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {
		
		printf("------------------------------------------------------------------------------------------\n");
		setColor(YELLOW);
		printf("===== 전투 시작 =====\n");
		setColor(WHITE);

		while (1) {
			int playerChoice;
			turn = 0;
			if (turn > 0) {
			printf("------------------------------------------------------------------------------------------\n");
			setColor(YELLOW);
			printf("다음 턴\n");
			}
			setColor(WHITE);
			con = 0;
			printSlowly("1. 공격\n2. 방어\n3. 스킬\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);
		
		if (playerChoice == 1) {
			// 플레이어 공격
			int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
			monster[monsterIndex].hp -= damage;
			printf("------------------------------------------------------------------------------------------\n");
			setColor(YELLOW);
			printSlowly(monster[monsterIndex].name, 100);
			setColor(WHITE);
			printSlowly("에게 공격하였습니다.\n데미지: ", 100);
			setColor(RED);
			printSlowly(StringvalueOf(damage), 100);
			printf("\n");
			setColor(WHITE);
			printSlowly(monster[monsterIndex].name, 50);
			printf(":");
			setColor(RED);
			printSlowly(" HP ", 50);
			if (monster[monsterIndex].hp > 0) {
			printSlowly(StringvalueOf(monster[monsterIndex].hp), 50);
			printf("\n");
			setColor(WHITE);
			}
			else {
			printSlowly("0", 50);
			printf("\n");
			setColor(WHITE);
			break;
			}
			setColor(WHITE);
		}
		else if (playerChoice == 2) {
			// 플레이어 방어
			defenseTurn = 1;
			printf("------------------------------------------------------------------------------------------\n");
			printf("플레이어가 방어 자세를 취했습니다.\n");
			playerInfo.playerScharacterInfo.defense += 20;
		}
		else if (playerChoice == 3) {
			
			useSkill(monsterIndex, &skillIndex, &con);
			

		}
		else {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
			while (getchar() != '\n');
		}
		// 몬스터 턴
			int monsterDamage = monster[monsterIndex].attack - playerInfo.playerScharacterInfo.defense * DEFENSE_RATE;
			playerInfo.playerScharacterInfo.hp -= monsterDamage;
			if (monster[monsterIndex].hp > 0 ) {
				if (con == -1) {
					continue;
				}
			setColor(WHITE);
			printf("------------------------------------------------------------------------------------------\n");
			setColor(YELLOW);
			printSlowly(monster[monsterIndex].name, 100);
			setColor(WHITE);
			printSlowly("가 ", 100);
			printSlowly(playerInfo.playerName, 100);
			printSlowly("님에게 공격하였습니다.\n데미지: ", 100);
			setColor(RED);
			printSlowly(StringvalueOf(monsterDamage), 100);
			printf("\n");
			setColor(WHITE);
			printSlowly(playerInfo.playerName, 50);
			printf(":");
			setColor(RED);
			printSlowly(" HP ", 50);
			if (playerInfo.playerScharacterInfo.hp > 0) {
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 50);
			}
			else {
				printSlowly("0", 50);
				break;
			}
			printf("\n");
			setColor(WHITE);
			printf("------------------------------------------------------------------------------------------\n");

			}
			else {
				break;
			}
		}
		if (defenseTurn == 1) {
			playerInfo.playerScharacterInfo.defense -= 20;
		}
		defenseTurn = 0;
		turn++;
		
	}

	if (playerInfo.playerScharacterInfo.hp > 0 || monster[monsterIndex].hp <= 0) {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(SKYBLUE);
		printSlowly("승리!\n", 40);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return 1;
	}
	else {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(DARK_GRAY);
		setColor(YELLOW);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(WHITE);
		printSlowly("에게 패배...\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return 0;
	}
}


void main() {
	playerInfo.playerScharacterInfo.hp = 1;
	while(playerInfo.playerScharacterInfo.hp > 0){
	srand(time(NULL));
	setColor(WHITE);
	int choice = -1;
	int st_ex = -1;
	int charSel = -1;
	char title[50] = "잊혀진 왕국의 비밀";
	int totalWidth = 47;
	int strWidth = strlen(title);
	int padding = (totalWidth - strWidth) / 2;
	int itemIndex = 0;

	strcpy(monster[0].name, "펜리르"); //첫 번째 몬스터
	strcpy(monster[0].skill, "내려찍기");
	monster[0].hp = 80;
	monster[0].attack = 20;
	monster[0].defense = 20;

	//두 번째 몬스터

	setColor(RED);
	printf("     ,      ,\n");
	printf("      (\\____/)\n");
	printf("       (_oo_)\n");
	printf("        (oo)\n");
	printf("      /------\\/`\n");
	printf("     / |    ||\n");
	printf("    *  /\\---/\\\n");
	printf("       ~~   ~~\n");

	setColor(DARK_VOILET);
	printf("%*s\n\n", padding + strWidth, title);
	setColor(DARK_GREEN);

	printf("                               .--\"\"--.\n");
	printf("                              /        \\\n");
	printf("                             |   *  *  |\n");
	printf("                             \\  .--.  /\n");
	printf("                              '.____.'\n");
	printf("                                ||||\n");
	setColor(WHITE);

		printf("1. 시작\n2. 종료\n");
		while (1) {



			printf("Enter: ");
			scanf("%d", &st_ex);
			if (st_ex == 1) {
				printf("------------------------------------------------------------------------------------------\n");
				printf("이름을 입력하세요: \n");
				printf("Enter: ");
				scanf("%s", playerInfo.playerName);
				printSlowly("안녕하세요, ", 30);
				printSlowly(playerInfo.playerName, 200);
				printf("님!\n");
				printf("------------------------------------------------------------------------------------------\n");
				setColor(SKYBLUE);
				printSlowly("Tip: 인벤토리 열기는 아이템을 획득하였을 때만 가능하니 주의하세요!\n", 30);
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("시작...\n", 300);

				setColor(WHITE);
				printSlowly("깊은 숲 속에 숨겨진 고대 왕국, '아르카디아'. 한때 번영했던 이 왕국은 어둠의 마법사 \n'말레피센트'의 저주로 인해 멸망하고, 사람들의 기억 속에서 잊혀졌습니다. \n당신은 우연히 아르카디아의 존재를 알게 된 모험가입니다. \n잊혀진 왕국의 비밀을 밝혀내고 말레피센트의 저주를 풀어 아르카디아를 부활시킬 수 있을까요?\n", 30);
				printf("------------------------------------------------------------------------------------------\n");
				
				printSlowly("캐릭터 선택: \n", 300);
				for (int i = 0; i < 3; i++) {
					setColor(i == 0 ? GREEN : i == 1 ? BLUE : RED);
					printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
					printSlowly(characterInfo[i].name, 200);
					printf(": ");
					setColor(WHITE);
					printSlowly(characterInfo[i].charState, 30);
					printf("\n");
				}
				setColor(WHITE);
				while (1) {
					printf("Enter: ");
					scanf("%d", &charSel);
					int use = -1;
					strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
					strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
					strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
					playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
					playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
					playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
					playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
					
					if (charSel == 1) {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("검사를 위한 \'목검\'이 지급되었습니다.\n", 30);
						printf("------------------------------------------------------------------------------------------\n");
						
						strcpy(playerInfo.inventory[0].item, "목검");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 5;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 0;
						playerInfo.inventory[itemIndex].addMana = 0;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. 인벤토리\n2. 취소\n", 100);
						while (1) {

						
						printf("Enter: ");
						scanf("%d", &use);
						if (use == 1) {
							displayInventory();
							break;
						}
						else if (use == 2) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("취소되었습니다.\n", 100);
							break;
						}
						else {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
							while (getchar() != '\n');
						}

						}
						break;

					}
					else if (charSel == 2) {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("마법사를 위한 \'마법사의 목걸이\'가 지급되었습니다.\n", 100);
						printf("------------------------------------------------------------------------------------------\n");
						strcpy(playerInfo.inventory[0].item, "마법사의 목걸이");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 0;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 0;
						playerInfo.inventory[itemIndex].addMana = 10;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. 인벤토리\n2. 취소\n", 100);
						while (1) {


							printf("Enter: ");
							scanf("%d", &use);
							if (use == 1) {
								displayInventory();
								break;
							}
							else if (use == 2) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("취소되었습니다.\n", 100);
								break;
							}
							else {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}

						}
						break;

					}
					else if (charSel == 3) {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("도적를 위한 \'도적의 망토\'가 지급되었습니다.\n", 100);
						printf("------------------------------------------------------------------------------------------\n");
						strcpy(playerInfo.inventory[0].item, "도적의 망토");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 0;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 10;
						playerInfo.inventory[itemIndex].addMana = 0;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. 인벤토리\n2. 취소\n", 100);
						while (1) {


							printf("Enter: ");
							scanf("%d", &use);
							if (use == 1) {
								displayInventory();
								break;
							}
							else if(use == 2) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("취소되었습니다.\n", 100);
								break;
							}
							else {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}

						}
						break;

					}
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						while (getchar() != '\n');

					}
				}
				itemIndex++;
				

				
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("아르카디아로 향하는 길...\n", 200);
				setColor(WHITE);
				printSlowly("울창한 숲 속에서 길을 잃은 당신은 오래된 석판을 발견합니다.\n석판에는 아르카디아로 향하는 길에 대한 희미한 글귀가 새겨져 있습니다.\n", 20);
				printSlowly("\"저주받은 숲을 지나, 잊혀진 신전을 찾아라. \n신전의 수호자를 물리치고, 아르카디아의 문을 열어라.\"\n\n", 20);


				setColor(RED);
				printf("선택: \n");
				setColor(WHITE);
				printSlowly("1. 저주받은 숲으로 향한다.\n", 100);
				printSlowly("2. 석판을 무시하고 다른 길을 찾는다.\n", 100);
				while (1) {
					printf("Enter: ");
					scanf("%d", &choice);
					printf("------------------------------------------------------------------------------------------\n");
					if (choice == 1) { //1번 스토리
						setColor(YELLOW);
						printSlowly("숲의 보물\n", 50);
						setColor(WHITE);
						printSlowly("당신은 석판의 가르침에 따라 깊은 숲 속으로 들어섰다.\n저주받은 숲은 음산한 기운으로 가득하다...\n나무들은 기괴하게 뒤틀려 있고, 숲 속에는 알 수 없는 생명체들의 울음소리가 울려 퍼진다.\n", 20);
						printSlowly("깊은 숲을 헤치고 나아가던 중, 갑자기 시야에 오래된 유적지가 나타났다. 이곳은 분명 인간의 손길이 닿지 않은 듯한 모습이다.\n", 20);
						printSlowly("유적 한가운데 작은 제단이 놓여 있고, 그 위에는 뭔지모를 상자가 놓여있다.\n", 20);
						setColor(YELLOW);
						printSlowly("60% : 갑옷, 40 % : 포션\n", 100);
						setColor(WHITE);
						int use = -1;
						
						// 아이템 획득 확률 계산
						int itemChance = rand() % 100; // 0에서 99 사이의 랜덤 숫자
						if (itemChance < 60) { // 60% 확률로 갑옷 획득
							printSlowly("상자를 열어보니 갑옷이 들어있다.\n낡아 보이지만 아직 견고해 보인다.\n", 30);
							strcpy(playerInfo.inventory[itemIndex].item, "낡은 갑옷");
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 1;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 0;
							playerInfo.inventory[itemIndex].addDefense = 5;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 0;
							printSlowly("1. 인벤토리\n2. 취소\n", 100);
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("취소되었습니다.\n", 100);
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
								}

							}

						}
						else { // 40% 확률로 공격력 증가 포션 획득
							printSlowly("상자를 열어보니 빛나는 포션이 들어있다.\n", 70);
							strcpy(playerInfo.inventory[itemIndex].item, "빛나는 포션");
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 2;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 10;
							playerInfo.inventory[itemIndex].addDefense = 0;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 0;
							printSlowly("1. 인벤토리\n2. 취소\n", 100);
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("취소되었습니다.\n", 100);
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
								}

							}


						}
						itemIndex++;
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("아이템을 획득한 당신은 숲 속에서 빠져나가려 하지만, 여전히 음산한 기운이 주위를 감싸고 있다...\n", 20);
						printSlowly("숲 속에서 무언가가 움직이는 소리가 들린다. 당신은 발걸음을 재촉해 이곳을 빠져나가기로 한다.\n", 20);

						//***1번 스토리 추가해야됨.***
						
						break;
					}
					else if (choice == 2) { //2번 스토리

						setColor(RED);
						printSlowly("숲의 수호자\n", 50);
						setColor(WHITE);
						//몬스터 마주침
						printSlowly("석판의 가르침을 의심하며 다른 길을 선택한 당신은 숲을 헤매던 도중 거대한 몬스터, '펜리르'와 마주칩니다. \n펜리르는 숲의 수호자로, 아르카디아로 향하는 길을 막고 있습니다.\n\n", 20);
						setColor(YELLOW);
						printMonster1();
						setColor(WHITE);
						printSlowly("이름: ", 50);
						printSlowly(monster[0].name, 50);
						printf("\n");
						setColor(RED);
						printSlowly(" - HP: ", 50);
						printSlowly(StringvalueOf(monster[0].hp), 50);
						setColor(WHITE);
						printf("\n");
						printSlowly(" - 스킬: ", 50);
						printSlowly(monster[0].skill, 50);
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
						

						//그림 추가: 전사, 마법사, 도적
						drawChar();
						printSlowly(playerInfo.playerName, 200);
						printSlowly("님: ", 200);
						printSlowly(playerInfo.playerScharacterInfo.name, 200);
						printf("!\n");

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

						int end = battle(0);
						if (end == 0) {
							break;
						}
						else {
							//승리일 경우 스토리 지속
							
							playerInfo.playerScharacterInfo.hp = tempH;
							playerInfo.playerScharacterInfo.attack = tempA;
							playerInfo.playerScharacterInfo.defense = tempD;
							playerInfo.playerScharacterInfo.mana = tempM;
						
						}
						
					
						break;
					}


					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						while (getchar() != '\n');
					}
				}





			
				break;
			}
			//스토리 통합


			else if (st_ex == 2) {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("Game is closed!", 100);
				break;
			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
				while (getchar() != '\n');
			}
		}

	
	}
	printf("------------------------------------------------------------------------------------------\n");
	printSlowly("플레이어가 사망했습니다.\n", 100);
	printSlowly("Game is closed!", 100);
}