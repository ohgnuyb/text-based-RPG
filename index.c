#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
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
};

struct character characterInfo[3] = {
	{"����", "�ı��� �ϰ�", "������ ü�°� �پ �˼� �Ƿ��� ���� �����Դϴ�.", 120, 20, 10},
	{"������", "ȭ����", "������ ������ ����ϴ� �������Դϴ�.", 100, 30, 0},
	{"����", "����", "��ø�� �����Ӱ� ������ �ൿ�� �ɼ��� �����Դϴ�.", 80, 40, 0}
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
	struct character;
} playerInfo;

struct {
	char item[20];
	int  num;

} inventory;




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
	monster[0].hp = 100;
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
	printf("Enter: ");
	scanf("%d", &st_ex);
	if (st_ex == 1) {
		printf("------------------------------------------------------------------------------------------\n");
		printf("�̸��� �Է��ϼ���: \n");
		printf("Enter: ");
		scanf("%s", playerInfo.playerName);
		printSlowly("�ȳ��ϼ���, ", 100);
		printSlowly(playerInfo.playerName, 200);
		printf("��!");
		printf("\n");
		while (1) {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(RED);
		printf("����...\n");

		setColor(WHITE);
		printSlowly("���� �� �ӿ� ������ ��� �ձ�, '�Ƹ�ī���'. �Ѷ� �����ߴ� �� �ձ��� ����� ������ '�����Ǽ�Ʈ'�� ���ַ� ���� ����ϰ�, ������� ��� �ӿ��� ���������ϴ�. ����� �쿬�� �Ƹ�ī����� ���縦 �˰� �� ���谡�Դϴ�.������ �ձ��� ����� �������� �����Ǽ�Ʈ�� ���ָ� Ǯ�� �Ƹ�ī��Ƹ� ��Ȱ��ų �� �������?\n", 70);
		printf("------------------------------------------------------------------------------------------\n");

		printSlowly("ĳ���� ����: \n", 200);
		for (int i = 0; i < 3; i++) {
			setColor(i == 0 ? GREEN : i == 1 ? BLUE : RED);
			printSlowly(i == 0 ? "1. ": i == 1 ? "2. " : "3. ", 200);
			printSlowly(characterInfo[i].name, 200);
			printf(": ");
			setColor(WHITE);
			printSlowly(characterInfo[i].charState, 100);
			printf("\n");
		}
		setColor(WHITE);
		
		printf("Enter: ");
		scanf("%d", &charSel);
	
		if (charSel == 1) {
			strcpy(playerInfo.name, "����");
			strcpy(playerInfo.skill, "�ı��� �ϰ�");
			strcpy(playerInfo.charState, "������ ü�°� �پ �˼� �Ƿ��� ���� �����Դϴ�.");
			playerInfo.hp = 120;
			playerInfo.attack = 20;
			playerInfo.defense = 10;
			
			break;
			
		}
		else if (charSel == 2) {
			strcpy(playerInfo.name, "������");
			strcpy(playerInfo.skill, "ȭ����");
			strcpy(playerInfo.charState, "������ ������ ����ϴ� �������Դϴ�.");
			playerInfo.hp = 100;
			playerInfo.attack = 30;
			playerInfo.defense = 0;
			
			break;
			
		}
		else if (charSel == 3) {
			strcpy(playerInfo.name, "����");
			strcpy(playerInfo.skill, "����");
			strcpy(playerInfo.charState, "��ø�� �����Ӱ� ������ �ൿ�� �ɼ��� �����Դϴ�.");
			playerInfo.hp = 80;
			playerInfo.attack = 40;
			playerInfo.defense = 0;
			
			break;
			
		}
		else {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
			while (getchar() != '\n');
		
		}
		}
		printf("------------------------------------------------------------------------------------------\n");

		printSlowly(playerInfo.playerName, 200);
		printSlowly("���� ����: ", 200);
		printSlowly(playerInfo.name, 200);
		printf("!\n");

		setColor(RED);
		printSlowly("  - HP: ", 100);
		printSlowly(StringvalueOf(playerInfo.hp), 100);
		printf("\n");

		setColor(WHITE);
		printSlowly("  - ��ų: ", 100);
		printSlowly(playerInfo.skill, 100);
		printf("\n");

		printSlowly("  - ���ݷ�: ", 100);
		printSlowly(StringvalueOf(playerInfo.attack), 100);
		printf("\n");

		setColor(BLUE);
		printSlowly("  - ����: ", 100);
		printSlowly(StringvalueOf(playerInfo.defense), 100);
		printf("\n");
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		setColor(RED);
		printSlowly("�Ƹ�ī��Ʒ� ���ϴ� ��...\n", 200);
		setColor(WHITE);
		printSlowly("��â�� �� �ӿ��� ���� ���� ����� ������ ������ �߰��մϴ�.\n���ǿ��� �Ƹ�ī��Ʒ� ���ϴ� �濡 ���� ����� �۱Ͱ� ������ �ֽ��ϴ�.\n", 70);
		printSlowly("\"���ֹ��� ���� ����, ������ ������ ã�ƶ�. ������ ��ȣ�ڸ� ����ġ��, �Ƹ�ī����� ���� �����.\"\n\n", 70);
		
		while (1) {
		setColor(RED);
		printf("����: \n");
		setColor(WHITE);
		printSlowly("1. ���ֹ��� ������ ���Ѵ�.\n", 100);
		printSlowly("2. ������ �����ϰ� �ٸ� ���� ã�´�.\n", 100);
		printf("Enter: ");
		scanf("%d", &choice);
		printf("------------------------------------------------------------------------------------------\n");
		if (choice == 1) { //1�� ���丮
			
			printSlowly("����� ������ ����ħ�� ���� ���� �� ������ ����.\n���ֹ��� ���� ������ ������� �����ϴ�... �������� �Ⱬ�ϰ� ��Ʋ�� �ְ�, �� �ӿ��� �� �� ���� ����ü���� �����Ҹ��� ��� ������.\n", 70);
			//������ ȹ��: 60���� Ȯ���� ü�� ���� / 40���� Ȯ���� ���ݷ� ���� ����

			break;
		}
		else if (choice == 2) { //2�� ���丮
			
			setColor(RED);
			printSlowly("���� ��ȣ��\n", 50);
			setColor(WHITE);
			//���� ����ħ
			printSlowly("������ ����ħ�� �ǽ��ϸ� �ٸ� ���� ������ ����� ���� ��Ŵ� ����� �Ŵ��� ����, '�渮��'�� ����Ĩ�ϴ�. �渮���� ���� ��ȣ�ڷ�, �Ƹ�ī��Ʒ� ���ϴ� ���� ���� �ֽ��ϴ�.\n\n", 70);
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
			printSlowly("ü��: ", 50);
			printSlowly(StringvalueOf(monster[0].hp), 50);
			printf("\n");
			printSlowly("��ų: ", 50);
			printSlowly(monster[0].skill, 50);
			printf("\n");
			printSlowly("���ݷ�: ", 50);
			printSlowly(StringvalueOf(monster[0].attack), 50);
			printf("\n");
			printSlowly("����: ", 50);
			printSlowly(StringvalueOf(monster[0].defense), 50);
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


	else {
		printSlowly("Game is closed!", 100);
	}
	

}