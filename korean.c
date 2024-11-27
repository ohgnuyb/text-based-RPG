#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"
#include "rpg_struct.h"
#include "stringFunc.h"



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
void deleteItem_ko(char* target_itemName, int index) {
	int i, j;

	// target_itemName�� ��ġ�ϴ� �������� ã���ϴ�.
	for (i = 0; i < index; i++) {
		if (strcmp(playerInfo.inventory[i].item, target_itemName) == 0) {
			// ã������, �ش� ������ ������ �����۵��� ������ ���ϴ�.

			if (index == 1) {
				strcpy(playerInfo.inventory[i].item, "");
				playerInfo.inventory[i].quantity = 0;
				playerInfo.inventory[i].type = 0;
				playerInfo.inventory[i].isEquipped = -1;
				playerInfo.inventory[i].addAttack = 0;
				playerInfo.inventory[i].addDefense = 0;
				playerInfo.inventory[i].addHp = 0;
				playerInfo.inventory[i].addMana = 0;
				strcpy(playerInfo.inventory[i].state, "");
				playerInfo.itemIndex--;
			}
			else {

	
			for (j = i; j < index - 1; j++) {
				strcpy(playerInfo.inventory[j].item, playerInfo.inventory[j + 1].item);
				playerInfo.inventory[j].quantity = playerInfo.inventory[j + 1].quantity;
				playerInfo.inventory[j].type = playerInfo.inventory[j + 1].type;
				playerInfo.inventory[j].isEquipped = playerInfo.inventory[j + 1].isEquipped;
				playerInfo.inventory[j].addAttack = playerInfo.inventory[j + 1].addAttack;
				playerInfo.inventory[j].addDefense = playerInfo.inventory[j + 1].addDefense;
				playerInfo.inventory[j].addHp = playerInfo.inventory[j + 1].addHp;
				playerInfo.inventory[j].addMana = playerInfo.inventory[j + 1].addMana;
				strcpy(playerInfo.inventory[j].state, playerInfo.inventory[j + 1].state);
				strcpy(playerInfo.inventory[j + 1].item, "");
				playerInfo.inventory[j + 1].quantity = 0;
				playerInfo.inventory[j + 1].type = 0;
				playerInfo.inventory[j + 1].isEquipped = -1;
				playerInfo.inventory[j + 1].addAttack = 0;
				playerInfo.inventory[j + 1].addDefense = 0;
				playerInfo.inventory[j + 1].addHp = 0;
				playerInfo.inventory[j + 1].addMana = 0;
				strcpy(playerInfo.inventory[j + 1].state, "");

			}
			
			playerInfo.itemIndex--;
			}
			// �κ��丮 ������ ������ ���ҽ�ŵ�ϴ�.
			break; // ���� �� �ݺ��� ����
		}
	}
	return;
}



void displayInventory_ko() {
	int selected = 0;

	while (1) { // while ������ ����Ͽ� �ݺ�
		selected = 0; // selected �� �ʱ�ȭ
		printBar();
		setColor(YELLOW);
		printf("===== �κ��丮 =====\n");
		setColor(WHITE);
		for (int i = 0; i < 10; i++) {
			if (playerInfo.inventory[i].quantity > 0) {
				if (playerInfo.inventory[i].isEquipped == 1) {
					printf("%d. %s: %d�� / ���� ��\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
				}
				else {
					if (playerInfo.inventory[i].type == 2) {
						printf("%d. %s: %d�� / �̻��\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else if (playerInfo.inventory[i].type == 3) {
						printf("%d. %s: %d��\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else if(playerInfo.inventory[i].type == 1){
						printf("%d. %s: %d�� / ������ ��\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
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
		printBar();
		printSlowly("�� ��° �������� �����Ͻðڽ��ϱ�?\n0. ������\n", 30);
		while (1) {
			printf("Enter: ");
			scanf("%d", &selectedIndex);
			int equippedIndex = -1;
			if (playerInfo.inventory[selectedIndex - 1].type == 1) {
				for (int i = 0; i < playerInfo.itemIndex; i++) {
					if (playerInfo.inventory[i].isEquipped == 1 &&
						(strstr(playerInfo.inventory[i].item, "��") != NULL ||
							strstr(playerInfo.inventory[i].item, "������") != NULL ||
							strstr(playerInfo.inventory[i].item, "ǥâ") != NULL)) {
						equippedIndex = i;
						
					}
				}
			}
			if (selectedIndex <= selected && selectedIndex != 0) {
				printBar();
				printSlowly("������ ������: ", 30);
				printSlowly(playerInfo.inventory[selectedIndex - 1].item, 30);
				printf("\n");
				printBar();
				printf("1. ����/���\n2. ���� ����(���)\n3. ���\n4. ������\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						if (playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
							printBar();
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
									if (playerInfo.inventory[selectedIndex - 1].quantity == 0) {
										deleteItem_ko(playerInfo.inventory[selectedIndex - 1].item, selected);
									}
									printBar();
									printSlowly("������ ����߽��ϴ�.\n", 30);
									//5�� �����ؾ� ��.
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
							else if (playerInfo.inventory[selectedIndex - 1].type == 3) {
								printBar();
								printSlowly(playerInfo.inventory[selectedIndex - 1].state, 50);
								printBar();
								printf("\n");

							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
								if (equippedIndex != -1) {

									printSlowly("�̹� ", 50);
									printSlowly(playerInfo.inventory[equippedIndex].item, 50);
									printSlowly("��(��) �����ϰ� �ֽ��ϴ�. ", 50);
									printSlowly(playerInfo.inventory[equippedIndex].item, 50);
									printSlowly("��(��) �����ϰ� ", 50);
									printSlowly(playerInfo.inventory[selectedIndex - 1].item, 50);
									printSlowly("��(��) �����մϴ�.\n", 50);

									// ���� ���� ������ ����
									playerInfo.inventory[equippedIndex].isEquipped = 0;
									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedIndex].addDefense;

									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedIndex].addDefense;
									playerInfo.playerScharacterInfo.hp -= playerInfo.inventory[equippedIndex].addHp;
									playerInfo.playerScharacterInfo.mana -= playerInfo.inventory[equippedIndex].addMana;
									if (playerInfo.inventory[equippedIndex].addHp > 0) {
										setColor(RED);
										printSlowly("ü��: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedIndex].addHp), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedIndex].addDefense > 0) {
										setColor(SKYBLUE);
										printSlowly("����: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedIndex].addAttack), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedIndex].addAttack > 0) {
										setColor(DARK_RED);
										printSlowly("���ݷ�: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedIndex].addAttack), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedIndex].addMana > 0) {
										if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
											setColor(BLUE);
											printSlowly("����: -", 30);
											printSlowly(StringvalueOf(playerInfo.inventory[equippedIndex].addMana), 100);
											printf("\n");
											setColor(WHITE);
										}

									}
								}
							}
								playerInfo.inventory[selectedIndex - 1].isEquipped = 1;
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;
								printBar();
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

							break;

						}
						else if (temp == 2) {
							if (playerInfo.inventory[selectedIndex - 1].type == 2) {
								printBar();
								printSlowly("������ ���� ������ �Ұ��մϴ�.\n", 30);

							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 3) {
								printBar();
								printSlowly("�Ҹ�ǰ�� ���� ������ �Ұ��մϴ�.\n", 30);
								printBar();
								break;
							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
								if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
									printBar();
									printSlowly("�̹� �������� �ʰ� �ֽ��ϴ�.\n", 30);
									break;
								}
								else {
									printBar();
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
							printBar();
							printf("��ҵǾ����ϴ�.\n");
							break;
						}
						else if (temp == 4) {
							printBar();
							printSlowly("���� �����ðڽ��ϱ�?\n", 50);
							printSlowly("1. ��\n2. �ƴϿ�\n", 50);
							while (1) {
								int trash = 0;
								printf("Enter: ");
								scanf("%d", &trash);

								if (trash == 1) {
									if (playerInfo.inventory[selectedIndex - 1].type == 1) {
										printBar();
										printSlowly("�������� ���� ��� ���� �����Ǿ����ϴ�. \n", 30);
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
									}
									printBar();

									printSlowly(playerInfo.inventory[selectedIndex - 1].item, 50);
									printSlowly("(��/��) ���Ƚ��ϴ�.", 50);
									printSlowly("\n���� ����: ", 50);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].quantity - 1), 50);
									printf("\n");


									playerInfo.inventory[selectedIndex - 1].quantity--;
									if (playerInfo.inventory[selectedIndex - 1].quantity == 0) {
										deleteItem_ko(playerInfo.inventory[selectedIndex - 1].item, selected);
									}


									break;
								}
								else if (trash == 2) {
									printSlowly("��ҵǾ����ϴ�.", 50);
									break;
								}
								else {
									while (getchar() != '\n');
								}



							}
							break;

							}
						else {
								printBar();
								printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 30);
								while (getchar() != '\n');
								}
				}

				break; // ������ ����/��� �� ���� ����

				
			}
			else if (selectedIndex == 0) {
				if (strlen(playerInfo.playerScharacterInfo.name) != 0) {

				
				printBar();
				drawChar_ko();
				printSlowly(playerInfo.playerName, 200);
				printSlowly("��: ", 200);
				printSlowly(playerInfo.playerScharacterInfo.name, 200);
				printf("!\n");

				setColor(GREEN);
				printSlowly(" - Lv.", 100);
				printSlowly(StringvalueOf(playerInfo.level), 100);
				printf("\n");

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
					printBar();
					printSlowly("���� ĳ���͸� �������� �����̽��ϴ�.\n", 100);
					return; // �κ��丮 ���� �� �Լ� ����
				}
			}
			else {
				printBar();
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

	setColor(GREEN);
	printSlowly(" - Lv.", 100);
	printSlowly(StringvalueOf(playerInfo.level), 100);
	printf("\n");

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


int useSkill_ko(int monsterIndex, int* skillIndex, int* con) { //��ų �������� ĳ������ ���� ���ݷ� * 2
	//������� ���� -=10 / ������ ������ �ƴ϶� ���� 100+���� ���ݷ����� ���� ����

	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "������") != 0) {
		printBar();
		printSlowly("��ų ���: ", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			setColor(SKYBLUE);
		}
		else if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			setColor(RED);
			playerInfo.playerScharacterInfo.defense = 100;
		}
		else {
			//�߰� ĳ����
		}
		int damage = 0;
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			damage = (playerInfo.playerScharacterInfo.attack) - (monster[monsterIndex].defense * DEFENSE_RATE);
		}
		else {
			damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
		}
		
		printSlowly(playerInfo.playerScharacterInfo.skill, 100);
		setColor(WHITE);
		printSlowly("!\n", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			printSlowly("��ų�� ����Ͽ� ���� ���°� �Ǿ����ϴ�.\n����: �ӽ� ���� = 100\n", 100);
		}
		printSlowly(monster[monsterIndex].name, 50);
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			printSlowly("���� �����߽��ϴ�. \n������: ", 50);
		}
		else {
		printSlowly("���� ��ų�� ����߽��ϴ�. \n������: ", 50);
		}
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


		printBar();
		printSlowly("��� ���� Ƚ��: 0\n", 30);


	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		int skillMage = playerInfo.playerScharacterInfo.mana / 10;
		if (skillMage > 0) {
			printBar();
			printSlowly("��ų ���: ", 100);
			setColor(YELLOW);
			int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
			printSlowly(playerInfo.playerScharacterInfo.skill, 100);
			setColor(WHITE);
			printSlowly("!\n", 100);
			printSlowly(monster[monsterIndex].name, 50);
			printSlowly("���� ��ų�� ����߽��ϴ�.\n����: ", 50);
			setColor(BLUE);
			printSlowly("-10\n", 50);
			setColor(BLUE);
			printSlowly("���� ����: ", 100);
			printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 50);
			setColor(WHITE);
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

			playerInfo.playerScharacterInfo.mana -= 10;
			setColor(WHITE);
		}
		else {
			printBar();
			printSlowly("������ �����մϴ�. \n", 100);
			printSlowly("�ʿ� ����: 10 \n", 100);
			setColor(BLUE);
			printSlowly("���� ����: ", 100);
			printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 50);
			setColor(WHITE);

		}
	}
	else {
		printBar();
		printSlowly("�̹� ��ų�� ����Ͽ����ϴ�.\n", 100);
		printBar();
		*con = -1;
	}
	if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
		return 1;
	}
	else {
		return 0;
	}

}
bool battle_ko(int monsterIndex) {
	int skillDefense = 0;
	int turn = 0;
	int defenseTurn = 0; //0. ��� �� ��, 1. ��� ����
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

		printBar();
		setColor(SKYBLUE);
		printSlowly("Tip. ���� �� Ȯ�� - ġ��Ÿ: 20%, ����� Ÿ��: 20%, �Ϲ� ����: 60% / ġ��Ÿ ����: 150%, ����� Ÿ��: 60%\n", 100);

		printSlowly("Tip. ���&���� �� �⺻ �������� 60%�� �����մϴ�.\n", 100);
		setColor(WHITE);
		printBar();
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
			printSlowly("1. ����\n2. ���&����\n3. ��ų\n4. �κ��丮\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);
			int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
			int damageRatio = rand() % 100; //0~99
			int defenseDamage = damage;
			if (playerChoice == 1) {
				// �÷��̾� ����
				printBar();
				if (damageRatio < 20) {
				//ġ��Ÿ
					setColor(RED);
					printSlowly("ġ��Ÿ �ߵ�!\n", 100);
					setColor(WHITE);
					printBar();
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
					setColor(WHITE);
					printBar();
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
				printBar();
				printSlowly("��� �ڼ��� ���߽��ϴ�.\n", 50);
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

				skillDefense = useSkill_ko(monsterIndex, &skillIndex, &con);


			}
			else if (playerChoice == 4) {

				displayInventory_ko();
			}
			else {
				printBar();
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
					printBar();
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
					printBar();
					if (defenseTurn == 1) {
						playerInfo.playerScharacterInfo.defense -= 50;
					}
					if (skillDefense == 1) {
						playerInfo.playerScharacterInfo.defense -= 100;
					}
					skillDefense = 0;
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
		printBar();
		setColor(SKYBLUE);
		printSlowly("�¸�!\n", 40);
		setColor(WHITE);
		return true;
	}
	else {
		printBar();
		setColor(VIOLET);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(DARK_GRAY);
		printSlowly("���� �й�...\n", 100);
		setColor(WHITE);
		return false;
	}
}



void printLevel_ko() {
	printSlowly("���� ������ Lv.", 50);
	printSlowly(StringvalueOf(playerInfo.level), 50);
	printSlowly("\n����ġ: ", 50);
	setColor(GREEN);
	printSlowly(StringvalueOf(playerInfo.levelPro), 50);
	printSlowly("%", 50);
	setColor(WHITE);
	printSlowly(" �Դϴ�.\n", 50);
}



void money_ko(){
	printSlowly("���� ������ ���� ", 50);
	setColor(YELLOW);
	printf("$ ");
	printSlowly(StringvalueOf(playerInfo.money), 50);
	setColor(WHITE);
	printSlowly("�Դϴ�.\n", 50);
}

void addMoney_ko(int x) {
	setColor(YELLOW);
	printSlowly("$ ", 50);
	printSlowly(StringvalueOf(x), 50);
	setColor(WHITE);
	printSlowly(" ��带 ȹ���Ͽ����ϴ�.\n", 50);
	playerInfo.money += x;
	money_ko();
}


void levelUp_ko() {
	playerInfo.level += 1;
	printSlowly("===== ����ġ�� ", 50);
	setColor(GREEN);
	printSlowly("100%", 50);
	setColor(WHITE);
	printSlowly("�� �Ѿ� ������ �ö����ϴ�! =====\n", 50);

	if (strcmp(playerInfo.playerScharacterInfo.name, "") == 0) {
	
	}
	else {

	
	printBar();
	// �ɷ�ġ ��� ó��
	printSlowly("�����մϴ�! ���������� �ɷ�ġ�� ����մϴ�.\n", 50);
	printBar();
	int hpIncrease = 20;      // ü�� ������
	int attackIncrease = 5;   // ���ݷ� ������
	int defenseIncrease = 3;  // ���� ������
	int manaIncrease = 10;  // ���� ������
	
	if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		playerInfo.playerScharacterInfo.hp += manaIncrease;
	}
	playerInfo.playerScharacterInfo.hp += hpIncrease;
	playerInfo.playerScharacterInfo.attack += attackIncrease;
	playerInfo.playerScharacterInfo.defense += defenseIncrease;

	setColor(RED);
	printSlowly(" - HP: +", 50);
	printSlowly(StringvalueOf(hpIncrease), 50);
	printf("\n");

	setColor(DARK_RED);
	printSlowly(" - ���ݷ�: +", 50);
	printSlowly(StringvalueOf(attackIncrease), 50);
	printf("\n");

	setColor(SKYBLUE);
	printSlowly(" - ����: +", 50);
	printSlowly(StringvalueOf(defenseIncrease), 50);
	printf("\n");
	if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
		setColor(BLUE);
		printSlowly(" - ����: +", 50);
		printSlowly(StringvalueOf(manaIncrease), 50);
		printf("\n");
	}


	setColor(WHITE);
	printBar();
	printSlowly("���ο� �ɷ�ġ�� ����Ǿ����ϴ�.\n", 50);

	}

}

void loadLevelPro_ko(int x, char* reason) {
	playerInfo.levelPro += x;
	if (playerInfo.levelPro < 100) {	
	printSlowly("����ġ�� ", 50);
	setColor(GREEN);
	printf("%d", x);
	printf("%%");
	setColor(WHITE);
	printSlowly(" ��ŭ �ö� ����: ", 50);
	setColor(GREEN);
	printSlowly(StringvalueOf(playerInfo.levelPro), 50);
	printf("%%");
	setColor(WHITE);
	printSlowly(" �Դϴ�. / ", 50);
	printSlowly("����: ", 50);
	printSlowly(reason, 50);
	printf("\n");
	}
	else {
		playerInfo.levelPro -= 100;
		printSlowly(" - ����ġ : ", 50);
		setColor(GREEN);
		printf("+%d", x);
		printf("%%");
		setColor(WHITE);
		printSlowly(" / ", 50);
		printSlowly(reason, 50);
		printf("\n");
		printBar();
		levelUp_ko();
	}
}
void shop_ko() {
	int selected = 0;
	int index = 0;
	while (1) { // while ������ ����Ͽ� �ݺ�
		selected = 0; // selected �� �ʱ�ȭ
		printBar();
		setColor(YELLOW);
		printf("===== ���� =====\n");
		setColor(WHITE);

		struct inventoryItem_shop shopItem[10] = {
			{"������ ��", 1, 1, 0, 12, 0, 0, 0, "������ ���Դϴ�. / ���ݷ� +12", 50},
			{"������ ����", 1, 1, 0, 0, 10, 0, 0, "������ �����Դϴ�. / ���� +10", 50},
			{"ü�� ����", 1, 2, 0, 0, 0, 20, 0, "ü�� �����Դϴ�. / ü�� +20", 60},
			{"������ ������", 1, 1, 0, 8, 0, 0, 0, "������ �������Դϴ�. / ���ݷ� +8", 50},
			{"������ ����", 1, 1, 0, 0, 10, 0, 0, "������ �����Դϴ�. / ���� +10", 50},
			{"ü�� ����", 1, 2, 0, 0, 0, 20, 0, "ü�� �����Դϴ�. / ü�� +20", 60},
			{"ȭ�� ǥâ", 1, 1, 0, 5, 0, 0, 0, "���� ǥâ�Դϴ�. / ���ݷ� +5", 50},
			{"������ ����", 1, 1, 0, 0, 10, 0, 0, "������ �����Դϴ�. / ���� +10", 50},
			{"ü�� ����", 1, 2, 0, 0, 0, 20, 0, "ü�� �����Դϴ�. / ü�� +20", 60}
		};
		if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			for (int i = 0; i < 3; i++) {
				printf("%d. %s: / ", i + 1, shopItem[i].item);
				printf("%s", shopItem[i].state);
				printf("\n");
			}
		}
		else if (strcmp(playerInfo.playerScharacterInfo.name, "������") == 0) {
			for (int i = 3; i < 6; i++) {
				printf("%d. %s: \n", i + 1, shopItem[i].item);
				printf("%s", shopItem[i].state);
				printf("\n");
			}
		}
		else if (strcmp(playerInfo.playerScharacterInfo.name, "����") == 0) {
			for (int i = 6; i < 9; i++) {
				printf("%d. %s: \n", i + 1, shopItem[i].item);
				printf("%s", shopItem[i].state);
				printf("\n");
			}
		}
		else {
			printSlowly("���� ĳ���͸� �������� �ʾҽ��ϴ�.\n���� �� �ٽ� �õ����ּ���.\n", 50);
			return;
		}
		printBar();
		money_ko();
		printBar();
		printSlowly("� �������� �����Ͻðڽ��ϱ�?\n0. ������\n", 30);
		while (1) {
			printf("Enter: ");
			scanf("%d", &index);
			if (index == 0) {
				printBar();
				printSlowly("������ �����ϴ�.\n", 30);
				return;
			}
			else if (index < 10 && index > 0) {
				printBar();
				printSlowly("������ ������: ", 30);
				printSlowly(shopItem[index - 1].item, 30);
				printf("\n");
				printBar();
				printf("1. ����\n2. ���\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						printBar();
						if (playerInfo.money >= 50) {
							playerInfo.money -= shopItem[index - 1].price;
							printSlowly(shopItem[index - 1].item, 50);
							printSlowly(" ���� �Ϸ�!\n", 50);
		
							strcpy(playerInfo.inventory[playerInfo.itemIndex].item, shopItem[index - 1].item);
							playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
							playerInfo.inventory[playerInfo.itemIndex].type = shopItem[index - 1].type;
							playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
							playerInfo.inventory[playerInfo.itemIndex].addAttack = shopItem[index - 1].addAttack;
							playerInfo.inventory[playerInfo.itemIndex].addDefense = shopItem[index - 1].addDefense;
							playerInfo.inventory[playerInfo.itemIndex].addHp = shopItem[index - 1].addHp;
							playerInfo.inventory[playerInfo.itemIndex].addMana = shopItem[index - 1].addMana;
							if (shopItem[index - 1].type == 3) {
								strcpy(playerInfo.inventory[playerInfo.itemIndex].state, shopItem[index - 1].state);
							}
							playerInfo.itemIndex++;
							break;
						}
						else {
							printSlowly("��尡 �����մϴ�.\n", 50);
							printSlowly("�ʿ��� ���: ", 50);
							setColor(YELLOW);
							printSlowly(StringvalueOf(shopItem[index - 1].price), 50);
							setColor(WHITE);
							printSlowly("\n���� ���: ", 50);
							money_ko();
							break;
						}
					}
					else if (temp == 2) {
						printBar();
						printf("��ҵǾ����ϴ�.\n");
						break;
					}
					else {
						printBar();
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 30);
						while (getchar() != '\n');
					}
				}
				break;
			}
			else {
				printBar();
				printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 30);
				while (getchar() != '\n');
			}
		}
	}
}

int selectPro_ko() {
	int option = 0;
	while (1) {
		printBar();
		printSlowly("1. ���丮\n2. �κ��丮\n3. ����\n4. ���� ����\n", 50);
		printf("Enter: ");
		scanf("%d", &option);
		if (option == 1) {
			break;
		}
		else if (option == 2) {
			displayInventory_ko();
			while (getchar() != '\n');
		}
		else if (option == 3) {
			shop_ko();
			while (getchar() != '\n');
		}
		else if (option == 4) {
			break;	
		}
		else {
			printBar();
			printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
			while (getchar() != '\n');
		}
	}
	return option;
}  
