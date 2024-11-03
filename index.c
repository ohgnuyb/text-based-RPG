#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
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

};

struct character characterInfo[3] = {
	{"전사", "파괴의 일격", "강인한 체력과 뛰어난 검술 실력을 가진 전사입니다.", 120, 10, 10, 0},
	{"마법사", "화염구", "강력한 마법을 사용하는 마법사입니다.", 100, 30, 0, 20},
	{"도적", "은신", "민첩한 움직임과 은밀한 행동에 능숙한 도적입니다.", 80, 40, 0, 0}
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
	struct inventoryItem inventory[100];
} playerInfo;


void displayInventory() {

	printf("===== 인벤토리 =====\n");
	for (int i = 0; i < 100; i++) {
		if(playerInfo.inventory[i].quantity > 0)
			if (playerInfo.inventory[0].isEquipped == 1) {
				printf("%d. %s: %d개 / 장착 중\n", i+1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[0].isEquipped);
			}
			else {
				printf("%d. %s: %d개 / 미장착 중\n", i+1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[0].isEquipped);
			}
			}

	int temp = 0; //하다 말았음 **여기 해야됨**
	printSlowly("몇 번째 아이템을 선택하시겠습니까?", 100);
	printf("Enter: ");
	scanf("%d", &temp);
	printSlowly("선택한 아이템: ", 100);
	printSlowly(playerInfo.inventory[temp].item, 100);
	printf("\n");
	printf("1. 장착\n2.취소\n");
	printf("Enter: ");
	scanf("%d", &temp);
	playerInfo.inventory[temp].isEquipped = 1; 
	
}





void main() {

	int choice = -1;
	int st_ex = -1;
	int charSel = -1;
	char title[50] = "잊혀진 왕국의 비밀";
	int totalWidth = 47;
	int strWidth = strlen(title);
	int padding = (totalWidth - strWidth) / 2;
	
	strcpy(monster[0].name, "펜리르"); //첫 번째 몬스터
	strcpy(monster[0].skill, "내려찍기");
	monster[0].hp = 80;
	monster[0].attack = 20;
	monster[0].defense = 20;

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
	printf("                             |   ^  ^  |\n");
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
				printSlowly("안녕하세요, ", 100);
				printSlowly(playerInfo.playerName, 200);
				printf("님!\n");

				
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printf("시작...\n");

				setColor(WHITE);
				printSlowly("깊은 숲 속에 숨겨진 고대 왕국, '아르카디아'. 한때 번영했던 이 왕국은 어둠의 마법사 '말레피센트'의 저주로 인해 멸망하고, 사람들의 기억 속에서 잊혀졌습니다. 당신은 우연히 아르카디아의 존재를 알게 된 모험가입니다. 잊혀진 왕국의 비밀을 밝혀내고 말레피센트의 저주를 풀어 아르카디아를 부활시킬 수 있을까요?\n", 70);
				printf("------------------------------------------------------------------------------------------\n");

				printSlowly("캐릭터 선택: \n", 200);
				for (int i = 0; i < 3; i++) {
					setColor(i == 0 ? GREEN : i == 1 ? BLUE : RED);
					printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
					printSlowly(characterInfo[i].name, 200);
					printf(": ");
					setColor(WHITE);
					printSlowly(characterInfo[i].charState, 100);
					printf("\n");
				}
				setColor(WHITE);
				while (1) {
					printf("Enter: ");
					scanf("%d", &charSel);
					int use = -1;
					if (charSel == 1) {
						printSlowly("검사를 위한 \'목검\'이 지급되었습니다.\n", 100);
						
						strcpy(playerInfo.inventory[0].item, "목검");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						printSlowly("1. 인벤토리\n", 100);
						while (1) {

						
						printf("Enter: ");
						scanf("%d", &use);
						if (use == 1) {
							displayInventory();
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
						printSlowly("마법사를 위한 \'마법사의 목걸이가 지급되었습니다.\'", 100);
						strcpy(playerInfo.inventory[0].item, "마법사의 목걸이");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						break;

					}
					else if (charSel == 3) {
						printSlowly("도적를 위한 \'도적의 망토가 지급되었습니다.\'", 100);
						strcpy(playerInfo.inventory[0].item, "도적의 망토");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						break;

					}
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						while (getchar() != '\n');

					}
				}
				strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel-1].name);
				strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel-1].skill);
				strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel-1].charState);
				playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
				playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
				playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
				playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
				printf("------------------------------------------------------------------------------------------\n");

				printSlowly(playerInfo.playerName, 200);
				printSlowly("님의 선택: ", 200);
				printSlowly(playerInfo.playerScharacterInfo.name, 200);
				printf("!\n");

				setColor(RED);
				printSlowly("  - HP: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
				printf("\n");

				setColor(WHITE);
				printSlowly("  - 스킬: ", 100);
				printSlowly(playerInfo.playerScharacterInfo.skill, 100);
				printf("\n");

				printSlowly("  - 공격력: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
				printf("\n");

				setColor(BLUE);
				printSlowly("  - 방어력: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
				printf("\n");
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("아르카디아로 향하는 길...\n", 200);
				setColor(WHITE);
				printSlowly("울창한 숲 속에서 길을 잃은 당신은 오래된 석판을 발견합니다.\n석판에는 아르카디아로 향하는 길에 대한 희미한 글귀가 새겨져 있습니다.\n", 70);
				printSlowly("\"저주받은 숲을 지나, 잊혀진 신전을 찾아라. 신전의 수호자를 물리치고, 아르카디아의 문을 열어라.\"\n\n", 70);


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

						printSlowly("당신은 석판의 가르침에 따라 깊은 숲 속으로 들어섰다.\n저주받은 숲은 음산한 기운으로 가득하다... 나무들은 기괴하게 뒤틀려 있고, 숲 속에는 알 수 없는 생명체들의 울음소리가 울려 퍼진다.\n", 70);
						//아이템 획득: 60프로 확률로 갑옷(방어력 +10) 획득 / 40프로 확률로 공격력 증가 포션

						break;
					}
					else if (choice == 2) { //2번 스토리

						setColor(RED);
						printSlowly("숲의 수호자\n", 50);
						setColor(WHITE);
						//몬스터 마주침
						printSlowly("석판의 가르침을 의심하며 다른 길을 선택한 당신은 숲을 헤매던 도중 거대한 늑대, '펜리르'와 마주칩니다. 펜리르는 숲의 수호자로, 아르카디아로 향하는 길을 막고 있습니다.\n\n", 70);
						setColor(YELLOW);
						printf("       /\\_/\\ \n");
						printf("      ( o o )\n");
						printf("      /   *   \\ \n");
						printf("     /________\\ \n");
						printf("    |          | \n");
						printf("    |  || ||  | \n");
						printf("    |  || ||  | \n");
						printf("    |          | \n");
						printf("    \\________/ \n");
						printf("       || || \n");
						printf("       || || \n\n");
						setColor(WHITE);
						printSlowly("이름: ", 50);
						printSlowly(monster[0].name, 50);
						printf("\n");
						setColor(RED);
						printSlowly("체력: ", 50);
						printSlowly(StringvalueOf(monster[0].hp), 50);
						setColor(WHITE);
						printf("\n");
						printSlowly("스킬: ", 50);
						printSlowly(monster[0].skill, 50);
						printf("\n");
						printSlowly("공격력: ", 50);
						printSlowly(StringvalueOf(monster[0].attack), 50);
						printf("\n");
						setColor(BLUE);
						printSlowly("방어력: ", 50);
						printSlowly(StringvalueOf(monster[0].defense), 50);
						setColor(WHITE);
						printf("\n");



						break;
					}


					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						while (getchar() != '\n');
					}
				}







			}


			else if (st_ex == 2) {
				printSlowly("Game is closed!", 100);

			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
				while (getchar() != '\n');
			}
		}

		
	
}