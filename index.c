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

void setColor(unsigned short text) { //cmdâ ���ڻ� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
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
	int type; //1: ���, 2: ����
	int isEquipped;

};

struct character characterInfo[3] = {
	{"����", "�ı��� �ϰ�", "������ ü�°� �پ �˼� �Ƿ��� ���� �����Դϴ�.", 120, 10, 10, 0},
	{"������", "ȭ����", "������ ������ ����ϴ� �������Դϴ�.", 100, 30, 0, 20},
	{"����", "����", "��ø�� �����Ӱ� ������ �ൿ�� �ɼ��� �����Դϴ�.", 80, 40, 0, 0}
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

	printf("===== �κ��丮 =====\n");
	for (int i = 0; i < 100; i++) {
		if(playerInfo.inventory[i].quantity > 0)
			if (playerInfo.inventory[0].isEquipped == 1) {
				printf("%d. %s: %d�� / ���� ��\n", i+1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[0].isEquipped);
			}
			else {
				printf("%d. %s: %d�� / ������ ��\n", i+1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity, playerInfo.inventory[0].isEquipped);
			}
			}

	int temp = 0; //�ϴ� ������ **���� �ؾߵ�**
	printSlowly("�� ��° �������� �����Ͻðڽ��ϱ�?", 100);
	printf("Enter: ");
	scanf("%d", &temp);
	printSlowly("������ ������: ", 100);
	printSlowly(playerInfo.inventory[temp].item, 100);
	printf("\n");
	printf("1. ����\n2.���\n");
	printf("Enter: ");
	scanf("%d", &temp);
	playerInfo.inventory[temp].isEquipped = 1; 
	
}





void main() {

	int choice = -1;
	int st_ex = -1;
	int charSel = -1;
	char title[50] = "������ �ձ��� ���";
	int totalWidth = 47;
	int strWidth = strlen(title);
	int padding = (totalWidth - strWidth) / 2;
	
	strcpy(monster[0].name, "�渮��"); //ù ��° ����
	strcpy(monster[0].skill, "�������");
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


		printf("1. ����\n2. ����\n");
		while (1) {



			printf("Enter: ");
			scanf("%d", &st_ex);
			if (st_ex == 1) {
				printf("------------------------------------------------------------------------------------------\n");
				printf("�̸��� �Է��ϼ���: \n");
				printf("Enter: ");
				scanf("%s", playerInfo.playerName);
				printSlowly("�ȳ��ϼ���, ", 100);
				printSlowly(playerInfo.playerName, 200);
				printf("��!\n");

				
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printf("����...\n");

				setColor(WHITE);
				printSlowly("���� �� �ӿ� ������ ��� �ձ�, '�Ƹ�ī���'. �Ѷ� �����ߴ� �� �ձ��� ����� ������ '�����Ǽ�Ʈ'�� ���ַ� ���� ����ϰ�, ������� ��� �ӿ��� ���������ϴ�. ����� �쿬�� �Ƹ�ī����� ���縦 �˰� �� ���谡�Դϴ�. ������ �ձ��� ����� �������� �����Ǽ�Ʈ�� ���ָ� Ǯ�� �Ƹ�ī��Ƹ� ��Ȱ��ų �� �������?\n", 70);
				printf("------------------------------------------------------------------------------------------\n");

				printSlowly("ĳ���� ����: \n", 200);
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
						printSlowly("�˻縦 ���� \'���\'�� ���޵Ǿ����ϴ�.\n", 100);
						
						strcpy(playerInfo.inventory[0].item, "���");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						printSlowly("1. �κ��丮\n", 100);
						while (1) {

						
						printf("Enter: ");
						scanf("%d", &use);
						if (use == 1) {
							displayInventory();
							break;
						}
						else {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
							while (getchar() != '\n');
						}

						}
						break;

					}
					else if (charSel == 2) {
						printSlowly("�����縦 ���� \'�������� ����̰� ���޵Ǿ����ϴ�.\'", 100);
						strcpy(playerInfo.inventory[0].item, "�������� �����");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						break;

					}
					else if (charSel == 3) {
						printSlowly("������ ���� \'������ ���䰡 ���޵Ǿ����ϴ�.\'", 100);
						strcpy(playerInfo.inventory[0].item, "������ ����");
						playerInfo.inventory[0].quantity = 1;
						playerInfo.inventory[0].type = 1;
						playerInfo.inventory[0].isEquipped = 0;
						break;

					}
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
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
				printSlowly("���� ����: ", 200);
				printSlowly(playerInfo.playerScharacterInfo.name, 200);
				printf("!\n");

				setColor(RED);
				printSlowly("  - HP: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
				printf("\n");

				setColor(WHITE);
				printSlowly("  - ��ų: ", 100);
				printSlowly(playerInfo.playerScharacterInfo.skill, 100);
				printf("\n");

				printSlowly("  - ���ݷ�: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
				printf("\n");

				setColor(BLUE);
				printSlowly("  - ����: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
				printf("\n");
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("�Ƹ�ī��Ʒ� ���ϴ� ��...\n", 200);
				setColor(WHITE);
				printSlowly("��â�� �� �ӿ��� ���� ���� ����� ������ ������ �߰��մϴ�.\n���ǿ��� �Ƹ�ī��Ʒ� ���ϴ� �濡 ���� ����� �۱Ͱ� ������ �ֽ��ϴ�.\n", 70);
				printSlowly("\"���ֹ��� ���� ����, ������ ������ ã�ƶ�. ������ ��ȣ�ڸ� ����ġ��, �Ƹ�ī����� ���� �����.\"\n\n", 70);


				setColor(RED);
				printf("����: \n");
				setColor(WHITE);
				printSlowly("1. ���ֹ��� ������ ���Ѵ�.\n", 100);
				printSlowly("2. ������ �����ϰ� �ٸ� ���� ã�´�.\n", 100);
				while (1) {
					printf("Enter: ");
					scanf("%d", &choice);
					printf("------------------------------------------------------------------------------------------\n");
					if (choice == 1) { //1�� ���丮

						printSlowly("����� ������ ����ħ�� ���� ���� �� ������ ����.\n���ֹ��� ���� ������ ������� �����ϴ�... �������� �Ⱬ�ϰ� ��Ʋ�� �ְ�, �� �ӿ��� �� �� ���� ����ü���� �����Ҹ��� ��� ������.\n", 70);
						//������ ȹ��: 60���� Ȯ���� ����(���� +10) ȹ�� / 40���� Ȯ���� ���ݷ� ���� ����

						break;
					}
					else if (choice == 2) { //2�� ���丮

						setColor(RED);
						printSlowly("���� ��ȣ��\n", 50);
						setColor(WHITE);
						//���� ����ħ
						printSlowly("������ ����ħ�� �ǽ��ϸ� �ٸ� ���� ������ ����� ���� ��Ŵ� ���� �Ŵ��� ����, '�渮��'�� ����Ĩ�ϴ�. �渮���� ���� ��ȣ�ڷ�, �Ƹ�ī��Ʒ� ���ϴ� ���� ���� �ֽ��ϴ�.\n\n", 70);
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
						printSlowly("�̸�: ", 50);
						printSlowly(monster[0].name, 50);
						printf("\n");
						setColor(RED);
						printSlowly("ü��: ", 50);
						printSlowly(StringvalueOf(monster[0].hp), 50);
						setColor(WHITE);
						printf("\n");
						printSlowly("��ų: ", 50);
						printSlowly(monster[0].skill, 50);
						printf("\n");
						printSlowly("���ݷ�: ", 50);
						printSlowly(StringvalueOf(monster[0].attack), 50);
						printf("\n");
						setColor(BLUE);
						printSlowly("����: ", 50);
						printSlowly(StringvalueOf(monster[0].defense), 50);
						setColor(WHITE);
						printf("\n");



						break;
					}


					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
						while (getchar() != '\n');
					}
				}







			}


			else if (st_ex == 2) {
				printSlowly("Game is closed!", 100);

			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
				while (getchar() != '\n');
			}
		}

		
	
}