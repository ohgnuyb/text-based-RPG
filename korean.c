#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"
#include "rpg_struct.h"
#include "string.h"



void drawWarrior_ko() {
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

void drawMage_ko() {
	setColor(YELLOW);
	printf("==== *\n");
	setColor(WHITE);
	printf("\\  O\n");
	for (int i = 0; i < 10; i++) {
		if (strcmp(playerInfo.inventory[i].item, "�������� �����") == 0 && playerInfo.inventory[i].isEquipped == 1) {
			setColor(BLUE);
		}
	}
	printf("  \\|\\\n");
	setColor(WHITE);
	printf("  / \\\n");
	printf(" /   \\\n");
	printf("\n");
}

void drawRogue_ko() {
	printf("   O\n");
	for (int i = 0; i < 10; i++) {
		if (strcmp(playerInfo.inventory[i].item, "������ ����") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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

void drawChar_ko() {
	if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
		drawWarrior_ko();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		drawMage_ko();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
		drawRogue_ko();
	}
	else {
		//�߰� ĳ����
	}
}



void displayInventory_ko() {
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
				drawChar_ko();
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



void printstatus_ko() {
	drawChar_ko();
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


void useSkill_ko(int monsterIndex, int* skillIndex, int* con) { //��ų �������� ĳ������ ���� ���ݷ� * 2
	//������� ���� -=10 / ������ ������ �ƴ϶� ���� 100���� ���� ����
	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "������") != 0) {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("��ų ���: ", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			setColor(SKYBLUE);
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
		if (monster[monsterIndex].hp > 0) {
			printSlowly(StringvalueOf(monster[monsterIndex].hp), 50);
			printf("\n");
			setColor(WHITE);
		}
		else {
			printSlowly("0", 50);
			printf("\n");
			setColor(WHITE);
		}
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
			setColor(VIOLET);
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
			if (monster[monsterIndex].hp > 0) {
				printSlowly(StringvalueOf(monster[monsterIndex].hp), 50);
				printf("\n");
				setColor(WHITE);
			}
			else {
				printSlowly("0", 50);
				printf("\n");
				setColor(WHITE);
			}

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
bool battle_ko(int monsterIndex) {
	int turn = 0;
	int defenseTurn = 0; //0. ��� �� ��, 1. ��� ����
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

		printf("------------------------------------------------------------------------------------------\n");
		setColor(SKYBLUE);
		printSlowly("Tip. ���� �� Ȯ�� - ġ��Ÿ: 20%, ����� Ÿ��: 20%, �Ϲ� ����: 60% / ġ��Ÿ ����: 150%, ����� Ÿ��: 60%\n", 100);

		printSlowly("Tip. ���&���� �� �⺻ �������� 60%�� �����մϴ�.\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		setColor(YELLOW);
		printf("===== ���� ���� =====\n");
		setColor(WHITE);
		turn = 0;
		while (1) {
			int playerChoice;
			if (turn > 0) {
				setColor(YELLOW);
				printf("-- ���� �� --\n");
			}
			setColor(WHITE);
			con = 0;
			printSlowly("1. ����\n2. ���&����\n3. ��ų\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);
			int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
			int damageRatio = rand() % 100; //0~99
			int defenseDamage = damage;
			if (playerChoice == 1) {
				// �÷��̾� ����
				printf("------------------------------------------------------------------------------------------\n");
				if (damageRatio < 20) {
				//ġ��Ÿ
					setColor(RED);
					printSlowly("ġ��Ÿ �ߵ�!\n", 100);
					damage *= 1.5;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("���� �����Ͽ����ϴ�.\n������: ", 100);
				}
				else if (damageRatio < 40) {
				//�����
					setColor(BLUE);
					printSlowly("�ƽ���! ������ ��������.\n", 100);
					damage *= 0.6;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("���� �����Ͽ����ϴ�.\n������: ", 100);
					
				}
				else {
				//�Ϲ�
					damage *= 1.0;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("���� �����Ͽ����ϴ�.\n������: ", 100);
				}
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
				damage = defenseDamage;
			}
			else if (playerChoice == 2) {
				// �÷��̾� ���
				defenseTurn = 1;
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�÷��̾ ��� �ڼ��� ���߽��ϴ�.\n", 50);
				setColor(SKYBLUE);
				printSlowly("�ӽ� ����: +50\n", 50);
				setColor(VIOLET);
				printSlowly(monster[monsterIndex].name, 100);
				setColor(WHITE);
				printSlowly("���� �����Ͽ����ϴ�.\n������: ", 100);
				playerInfo.playerScharacterInfo.defense += 50;
				setColor(WHITE);
				//��� �� ����
				monster[monsterIndex].hp -= defenseDamage * 0.6;
				setColor(DARK_RED);
				printSlowly(StringvalueOf(defenseDamage*0.6), 100);
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
			else if (playerChoice == 3) {

				useSkill_ko(monsterIndex, &skillIndex, &con);


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
					setColor(VIOLET);
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
		setColor(VIOLET);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(DARK_GRAY);
		printSlowly("���� �й�...\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return false;
	}
}



