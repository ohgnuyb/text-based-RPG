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

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

struct character {
	char name[20];
	char skill[20];
	int hp;
	int attack;
	int defense;

};

struct character characterInfo[3] = { {"Warrior", "Strong Slash", 120, 20, 10}, {"Mage", "Fireball", 100, 30, 0}, {"Rogue", "Evade", 80, 40, 0}};





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
	char title[50] = "Secrets of the Forgotten Kingdom";
	int totalWidth = 47; // 전체 출력 너비
	int strWidth = strlen(title); // 문자열 길이
	int padding = (totalWidth - strWidth) / 2; // 양쪽 패딩 계산

	
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
	printf("1. Start\n2. Exit\n");
	printf("Enter: ");
	scanf("%d", &st_ex);
	if (st_ex == 1) {
		printf("------------------------------------------------------------------------------------------\n");
		printf("Enter the player name: \n");
		printf("Enter: ");
		scanf("%s", playerInfo.playerName);
		printf("Hello! %s\n", playerInfo.playerName);
		while (1) {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(RED);
		printf("Start!\n");
		setColor(WHITE);
		printf("Beginning Deep within a vast forest lies the ancient kingdom of Arcadia. Once a prosperous land,\nit fell to ruin under the curse of the dark sorcerer, Maleficent, \nfading from the memories of all who once knew it.\n");
		printf("------------------------------------------------------------------------------------------\n");
		printf("Select character: ");
		setColor(GREEN);
		printf("\n1. Warrior: ");
		setColor(WHITE);
		printf("A mighty warrior with strong physique and exceptional swordsmanship.");
		setColor(BLUE);
		printf("\n2. Mage: ");
		setColor(WHITE);
		printf("A skilled mage wielding powerful magic spells.");
		setColor(RED);
		printf("\n3. Rogue: ");
		setColor(WHITE);
		printf("A cunning rogue with agile movements and expertise in stealth.\n");
		setColor(WHITE);
		
		
		printf("Enter: ");
		scanf("%d", &charSel);
	
		if (charSel == 1) {
			strcpy(playerInfo.name, "Warrior");
			strcpy(playerInfo.skill, "Strong Slash");
			playerInfo.hp = 120;
			playerInfo.attack = 20;
			playerInfo.defense = 10;
			printf("------------------------------------------------------------------------------------------\n");
			printf("You chose %s!\n");
			setColor(RED);
			printf("  - HP: 120\n");
			setColor(WHITE);
			printf("  - Skills: Strong Slash\n");
			printf("  - Attack: 20\n");
			setColor(BLUE);
			printf("  - Defense: 10\n");
			setColor(WHITE);
			break;
			
		}
		else if (charSel == 2) {
			strcpy(playerInfo.name, "Mage");
			strcpy(playerInfo.skill, "Fireball");
			playerInfo.hp = 100;
			playerInfo.attack = 30;
			playerInfo.defense = 0;
			printf("------------------------------------------------------------------------------------------\n");
			printf("You chose Mage!\n");
			setColor(RED);
			printf("  - HP: 100\n");
			setColor(WHITE);
			printf("  - Skills: Fireball\n");
			printf("  - Attack: 30\n");
			setColor(BLUE);
			printf("  - Defense: 0\n");
			setColor(WHITE);
			break;
			
		}
		else if (charSel == 3) {
			strcpy(playerInfo.name, "Rogue");
			strcpy(playerInfo.skill, "Evade");
			playerInfo.hp = 80;
			playerInfo.attack = 40;
			playerInfo.defense = 0;
			printf("------------------------------------------------------------------------------------------\n");
			printf("You chose Rogue!\n");
			setColor(RED);
			printf("  - HP: 80\n");
			setColor(WHITE);
			printf("  - Skills: Evade\n");
			printf("  - Attack: 40\n");
			setColor(BLUE);
			printf("  - Defense: 0\n");
			setColor(WHITE);
			break;
			
		}
		else {
			printf("------------------------------------------------------------------------------------------\n");
			printf("Invalid choice. Please select again!\n");
			while (getchar() != '\n');
		
		}
		}
		printf("------------------------------------------------------------------------------------------\n");
		setColor(RED);
		printf("The Path to Arcadia...\n");
		setColor(WHITE);
		printf("Lost in the dense forest, you come across an ancient stone tablet. \nFaint etchings on the tablet reveal the path to Arcadia.\n");
		printf("'Through the cursed woods, find the forgotten temple.Defeat the guardian, and open the gates of Arcadia.'\n\n");
		while (1) {
	
		printf("Choice: \n");
		printf("1. Venture into the cursed woods.\n");
		printf("2. Ignore the tablet and seek another path.\n");
		printf("Enter: ");
		scanf("%d", &choice);
		
		if (choice == 1) {
			
		}
		else if (choice == 2) {

		}
		else {
			printf("------------------------------------------------------------------------------------------\n");
			printf("Invalid choice. Please select again!\n");
			while (getchar() != '\n');
		}
		} 

		
			


		

	}


	else {
		printf("Game is closed!");
	}
	

}