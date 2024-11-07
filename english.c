#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"

#define MAX_INVENTORY_SIZE 10
#define DEFENSE_RATE 0.2



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
	int addAttack;
	int addDefense;
	int addHp;
	int addMana;
};
struct character characterInfo[3] = {
	{"����", "�ı��� �ϰ�", "������ ü�°� �پ �˼� �Ƿ��� ���� �����Դϴ�.", 120, 10, 10, 0}, //������ ���� ��� ���� �� ���� ��ų �� �� ��� ����
	{"������", "�鸸��Ʈ", "������ ������ ����ϴ� �������Դϴ�.", 90, 20, 0, 10}, //��ų ���� ���� -10
	{"����", "����", "��ø�� �����Ӱ� ������ �ൿ�� �ɼ��� �����Դϴ�.", 60, 30, 0, 0} //������ ���� ��� ���� �� ���� ��ų �� �� ��� ����
}; //��ų �������� ĳ������ ���� ���ݷ� * 2

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
	setColor(SKYBLUE);
	for (int i = 0; i < 10; i++) {
		if (strcmp(playerInfo.inventory[i].item, "���") == 0 && playerInfo.inventory[i].isEquipped == 1) {
			setColor(YELLOW);
		}
	}
	printf("==|==>>\n");
	setColor(WHITE);
	printf("\\  O\n");
	printf("  \\|\\\n");
	printf("  / \\\n");
	printf(" /   \\\n");

	printf("\n");
}

void drawMage() {
	setColor(YELLOW);
	printf("==== *\n");
	setColor(WHITE);
	printf("\\  O\n");
	for (int i = 0; i < 10; i++) {
		if (strcmp(playerInfo.inventory[i].item, "�������� �����") == 0 && playerInfo.inventory[i].isEquipped == 1) {
			setColor(SKYBLUE);
		}
	}
	printf("  \\|\\\n");
	setColor(WHITE);
	printf("  / \\\n");
	printf(" /   \\\n");
	printf("\n");
}

void drawRogue() {
	printf("   O\n");
	for (int i = 0; i < 10; i++) {
		if (strcmp(playerInfo.inventory[i].item, "�������� �����") == 0 && playerInfo.inventory[i].isEquipped == 1) {
			setColor(RED);
		}
	}
	printf("  /|-- ");
	setColor(RED);
	printf("* * *\n");
	setColor(WHITE);
	printf("  / \\\n");
	printf(" /   \\\n");
	printf("\n");
}

void drawChar() {
	if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
		drawWarrior();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		drawMage();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
		drawRogue();
	}
	else {
		//�߰� ĳ����
	}
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

void displayInventory() {
	int selected = 0;

	while (1) { // while ������ ����Ͽ� �ݺ�
		selected = 0; // selected �� �ʱ�ȭ
		printf("------------------------------------------------------------------------------------------\n");
		setColor(YELLOW);
		printf("===== �κ��丮 =====\n");
		setColor(WHITE);
		for (int i = 0; i < 10; i++) {
			if (playerInfo.inventory[i].quantity > 0) {
				if (playerInfo.inventory[i].isEquipped == 1) {
					printf("%d. %s: %d�� / ���� ��\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
				}
				else {
					if (playerInfo.inventory[i].type == 2) {
						printf("%d. %s: %d�� / �̻��\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else {
						printf("%d. %s: %d�� / ������ ��\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
				}

				selected++;
			}
		}

		if (selected == 0) {
			printSlowly("�κ��丮�� ��� �ֽ��ϴ�.\n", 30);
			break; // �κ��丮�� ��������� while ���� ����
		}

		int selectedIndex = 0;
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("�� ��° �������� �����Ͻðڽ��ϱ�?\n0. ������\n", 30);

		while (1) {
			printf("Enter: ");
			scanf("%d", &selectedIndex);

			if (selectedIndex <= selected && selectedIndex != 0) {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("������ ������: ", 30);
				printSlowly(playerInfo.inventory[selectedIndex - 1].item, 30);
				printf("\n");
				printf("------------------------------------------------------------------------------------------\n");
				printf("1. ����/���\n2. ���� ����(���)\n3. ���\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						if (playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("�̹� ���� ���Դϴ�.\n", 30);
							break;
						}
						else if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
							if (playerInfo.inventory[selectedIndex - 1].type == 2) {
								if (playerInfo.inventory[selectedIndex - 1].addMana > 0 && strcmp(playerInfo.playerScharacterInfo.name, "������") != 0) {
									printSlowly("���� ���� ������ �����縸 ����� �� �ֽ��ϴ�.\n", 100);
								}
								else {
									playerInfo.inventory[selectedIndex - 1].quantity--;
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("������ ����߽��ϴ�. / ���ӽð� 5��\n", 30);
								}
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("ü��: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("����: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("���ݷ�: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
										setColor(BLUE);
										printSlowly("����: +", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addMana), 100);
										printf("\n");
										setColor(WHITE);
									}

								}
								else {
									//�ٸ� �ɷ��� ���
								}
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;

								// Ÿ�� ���� �ؾߵ�.

							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
								playerInfo.inventory[selectedIndex - 1].isEquipped = 1;
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("��� �����߽��ϴ�.\n", 30);
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("ü��: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("����: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("���ݷ�: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
										setColor(BLUE);
										printSlowly("����: +", 30);
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
							printSlowly("������ ���� ������ �Ұ��մϴ�.\n", 30);

						}
						else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
							if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("�̹� �������� �ʰ� �ֽ��ϴ�.\n", 30);
								break;
							}
							else {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("��� ���� �����߽��ϴ�.\n", 30);
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("ü��: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("����: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("���ݷ�: -", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
										setColor(BLUE);
										printSlowly("����: -", 30);
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
						printf("��ҵǾ����ϴ�.\n");
						break;
					}
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 30);
						while (getchar() != '\n');
					}
				}

				break; // ������ ����/��� �� ���� ����
			}
			else if (selectedIndex == 0) {
				printf("------------------------------------------------------------------------------------------\n");
				drawChar();
				printSlowly(playerInfo.playerName, 200);
				printSlowly("��: ", 200);
				printSlowly(playerInfo.playerScharacterInfo.name, 200);
				printf("!\n");

				setColor(RED);
				printSlowly(" - HP: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
				printf("\n");

				setColor(WHITE);
				printSlowly(" - ��ų: ", 100);
				printSlowly(playerInfo.playerScharacterInfo.skill, 100);
				printf("\n");
				setColor(DARK_RED);
				printSlowly(" - ���ݷ�: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
				setColor(WHITE);
				printf("\n");
				setColor(SKYBLUE);
				printSlowly(" - ����: ", 100);
				printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
				setColor(WHITE);
				printf("\n");
				if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
					setColor(BLUE);
					printSlowly(" - ����: ", 100);
					printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
					printf("\n");
					setColor(WHITE);
				}
				return; // �κ��丮 ���� �� �Լ� ����
			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 30);
				while (getchar() != '\n');
			}
		}
	}
}



void printMonster1() {
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

void printstatus() {
	drawChar();
	printSlowly(playerInfo.playerName, 200);
	printSlowly("���� ����: ", 200);
	printSlowly(playerInfo.playerScharacterInfo.name, 200);
	printf("!\n");

	setColor(RED);
	printSlowly(" - HP: ", 100);
	printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
	printf("\n");

	setColor(WHITE);
	printSlowly(" - ��ų: ", 100);
	printSlowly(playerInfo.playerScharacterInfo.skill, 100);
	printf("\n");
	setColor(DARK_RED);
	printSlowly(" - ���ݷ�: ", 100);
	printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
	setColor(WHITE);
	printf("\n");
	setColor(SKYBLUE);
	printSlowly(" - ����: ", 100);
	printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
	setColor(WHITE);
	printf("\n");
	if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		setColor(BLUE);
		printSlowly(" - ����: ", 100);
		printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
		printf("\n");
		setColor(WHITE);
	}
}


void useSkill(int monsterIndex, int* skillIndex, int* con) { //��ų �������� ĳ������ ���� ���ݷ� * 2
	//������� ���� -=10 / ������ ������ �ƴ϶� ���� 100���� ���� ����
	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "������") != 0) {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("��ų ���: ", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			setColor(GREEN);
		}
		else if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			setColor(RED);
		}
		else {
			//�߰� ĳ����
		}
		int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
		printSlowly(playerInfo.playerScharacterInfo.skill, 100);
		setColor(WHITE);
		printSlowly("!\n", 100);
		printSlowly(monster[monsterIndex].name, 50);
		printSlowly("���� ��ų�� ����߽��ϴ�. \n������: ", 50);
		setColor(DARK_RED);
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
		printSlowly("��� ���� Ƚ��: 0\n", 30);


	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		int skillMage = playerInfo.playerScharacterInfo.mana / 10;
		if (skillMage > 0) {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("��ų ���: ", 100);
			setColor(BLUE);
			int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
			printSlowly(playerInfo.playerScharacterInfo.skill, 100);
			setColor(WHITE);
			printSlowly("!\n", 100);
			printSlowly(monster[monsterIndex].name, 50);
			printSlowly("���� ��ų�� ����߽��ϴ�. ����: ", 50);
			setColor(BLUE);
			printSlowly("-10", 50);
			setColor(WHITE);
			printSlowly("\n������: ", 50);
			setColor(DARK_RED);
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
			printSlowly("������ �����մϴ�. / \n", 100);
			setColor(BLUE);
			printSlowly("�ʿ� ����: 10 \n", 100);
			setColor(WHITE);

		}
	}
	else {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("�̹� ��ų�� ����Ͽ����ϴ�.\n", 100);
		printf("------------------------------------------------------------------------------------------\n");
		*con = -1;
	}

}
bool battle(int monsterIndex) {
	int turn = 0;
	int defenseTurn = 0; //0. ��� �� ��, 1. ��� ����
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

		printf("------------------------------------------------------------------------------------------\n");
		setColor(YELLOW);
		printf("===== ���� ���� =====\n");
		setColor(WHITE);
		turn = 0;
		while (1) {
			int playerChoice;
			if (turn > 0) {
				printf("------------------------------------------------------------------------------------------\n");
				setColor(YELLOW);
				printf("-- ���� �� --\n");
			}
			setColor(WHITE);
			con = 0;
			printSlowly("1. ����\n2. ���\n3. ��ų\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);

			if (playerChoice == 1) {
				// �÷��̾� ����
				int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
				monster[monsterIndex].hp -= damage;
				printf("------------------------------------------------------------------------------------------\n");
				setColor(YELLOW);
				printSlowly(monster[monsterIndex].name, 100);
				setColor(WHITE);
				printSlowly("���� �����Ͽ����ϴ�.\n������: ", 100);
				setColor(DARK_RED);
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
				// �÷��̾� ���
				defenseTurn = 1;
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�÷��̾ ��� �ڼ��� ���߽��ϴ�.\n", 50);
				setColor(SKYBLUE);
				printSlowly("�ӽ� ����: +50\n", 50);
				playerInfo.playerScharacterInfo.defense += 50;
				setColor(WHITE);
			}
			else if (playerChoice == 3) {

				useSkill(monsterIndex, &skillIndex, &con);


			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
				while (getchar() != '\n');
			}
			// ���� ��
			int monsterDamage = monster[monsterIndex].attack - playerInfo.playerScharacterInfo.defense * DEFENSE_RATE;
			playerInfo.playerScharacterInfo.hp -= monsterDamage;
			if (monster[monsterIndex].hp > 0) {
				if (con == -1) {

				}
				else {

					setColor(WHITE);
					printf("------------------------------------------------------------------------------------------\n");
					setColor(YELLOW);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("�� ", 100);
					printSlowly(playerInfo.playerName, 100);
					printSlowly("�Կ��� �����Ͽ����ϴ�.\n������: ", 100);
					setColor(DARK_RED);
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
						printSlowly("0\n", 50);
						setColor(WHITE);
						break;
					}
					printf("\n");
					setColor(WHITE);
					printf("------------------------------------------------------------------------------------------\n");
					if (defenseTurn == 1) {
						playerInfo.playerScharacterInfo.defense -= 50;
					}
					defenseTurn = 0;
					turn++;
				}

			}
			else {
				break;
			}
		}



	}

	if (playerInfo.playerScharacterInfo.hp > 0 || monster[monsterIndex].hp <= 0) {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(SKYBLUE);
		printSlowly("�¸�!\n", 40);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return true;
	}
	else {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(DARK_GRAY);
		setColor(YELLOW);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(WHITE);
		printSlowly("���� �й�...\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return false;
	}
}



