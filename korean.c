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
		if (strcmp(playerInfo.inventory[i].item, "목검") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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
		if (strcmp(playerInfo.inventory[i].item, "마법사의 목걸이") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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
		if (strcmp(playerInfo.inventory[i].item, "도적의 망토") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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
	if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0) {
		drawWarrior_ko();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
		drawMage_ko();
	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
		drawRogue_ko();
	}
	else {
		//추가 캐릭터
	}
}
void deleteItem_ko(char* target_itemName, int index) {
	int i, j;

	// target_itemName과 일치하는 아이템을 찾습니다.
	for (i = 0; i < index; i++) {
		if (strcmp(playerInfo.inventory[i].item, target_itemName) == 0) {
			// 찾았으면, 해당 아이템 이후의 아이템들을 앞으로 당깁니다.

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
			// 인벤토리 아이템 개수를 감소시킵니다.
			break; // 삭제 후 반복문 종료
		}
	}
	return;
}



void displayInventory_ko() {
	clear();
	int selected = 0;

	while (1) { // while 루프를 사용하여 반복
		int equippedWeaponIndex; // 무기용 equippedIndex
		int equippedArmorIndex; // 장비용 equippedIndex
		selected = 0; // selected 값 초기화
		printBar();
		setColor(YELLOW);
		printf("===== 인벤토리 =====\n");
		setColor(WHITE);
		for (int i = 0; i < 10; i++) {
			if (playerInfo.inventory[i].quantity > 0) {
				if (playerInfo.inventory[i].isEquipped == 1) {
					printf("%d. %s: %d개 / 장착 중\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
				}
				else {
					if (playerInfo.inventory[i].type == 2) {
						printf("%d. %s: %d개 / 미사용\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else if (playerInfo.inventory[i].type == 3) {
						printf("%d. %s: %d개\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
					}
					else {
						printf("%d. %s: %d개 / 미장착 중\n", selected + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
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
		printBar();
		printSlowly("몇 번째 아이템을 선택하시겠습니까?\n0. 나가기\n", 30);
		while (1) {
			printf("Enter: ");
			scanf("%d", &selectedIndex);

			if (selectedIndex <= selected && selectedIndex != 0) {
				printBar();
				printSlowly("선택한 아이템: ", 30);
				printSlowly(playerInfo.inventory[selectedIndex - 1].item, 30);
				printf("\n");
				printBar();
				printf("1. 장착/사용\n2. 장착 해제(장비)\n3. 취소\n4. 버리기\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						if (playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
							printBar();
							printSlowly("이미 장착 중입니다.\n", 30);
							break;
						}
						else if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
							if (playerInfo.inventory[selectedIndex - 1].type == 2) {
								if (playerInfo.inventory[selectedIndex - 1].addMana > 0 && strcmp(playerInfo.playerScharacterInfo.name, "마법사") != 0) {
									printSlowly("마나 증가 포션은 마법사만 사용할 수 있습니다.\n", 100);
								}
								else {
									playerInfo.inventory[selectedIndex - 1].quantity--;
									if (playerInfo.inventory[selectedIndex - 1].quantity == 0) {
										deleteItem_ko(playerInfo.inventory[selectedIndex - 1].item, selected);
									}
									printBar();
									printSlowly("포션을 사용했습니다.\n임시 ", 30);
									playerInfo.potionUsed = 1;

								}
								if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
									setColor(RED);
									printSlowly("체력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
									playerInfo.potionAdd = playerInfo.inventory[selectedIndex - 1].addHp;
									playerInfo.type = 'H';
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
									setColor(SKYBLUE);
									printSlowly("방어력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addDefense), 100);
									playerInfo.potionAdd = playerInfo.inventory[selectedIndex - 1].addDefense;
									playerInfo.type = 'D';
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
									setColor(DARK_RED);
									printSlowly("공격력: +", 30);
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
									playerInfo.potionAdd = playerInfo.inventory[selectedIndex - 1].addAttack;
									playerInfo.type = 'A';
									printf("\n");
									setColor(WHITE);
								}
								else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
									if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
										setColor(BLUE);
										printSlowly("마나: +", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addMana), 100);
										playerInfo.potionAdd = playerInfo.inventory[selectedIndex - 1].addMana;
										playerInfo.type = 'M';
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
							else if (playerInfo.inventory[selectedIndex - 1].type == 3) {
								printBar();
								printSlowly(playerInfo.inventory[selectedIndex - 1].state, 50);
								printf("\n");
						
							

							}
							else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
								
								equippedWeaponIndex = -1;
								for (int i = 0; i < playerInfo.itemIndex; i++) {
									if (playerInfo.inventory[i].isEquipped == 1 && playerInfo.inventory[i].type == 1 && i != selectedIndex - 1) {
										equippedWeaponIndex = i;

										break; // 이미 장착된 무기가 있다면 인덱스 저장 후 루프 종료
									}
								}

			
								if (equippedWeaponIndex != -1) {
									printBar();
									printSlowly("이미 ", 50);
									printSlowly(playerInfo.inventory[equippedWeaponIndex].item, 50);
									printSlowly("을(를) 착용하고 있습니다.\n", 50);
									printSlowly(playerInfo.inventory[equippedWeaponIndex].item, 50);
									printSlowly("을(를) 해제하고 ", 50);
									printSlowly(playerInfo.inventory[selectedIndex - 1].item, 50);
									printSlowly("을(를) 착용합니다.\n", 50);

									// 기존 장착 아이템 해제
									playerInfo.inventory[equippedWeaponIndex].isEquipped = 0;
									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedWeaponIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedWeaponIndex].addDefense;

									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedWeaponIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedWeaponIndex].addDefense;
									playerInfo.playerScharacterInfo.hp -= playerInfo.inventory[equippedWeaponIndex].addHp;
									playerInfo.playerScharacterInfo.mana -= playerInfo.inventory[equippedWeaponIndex].addMana;
									if (playerInfo.inventory[equippedWeaponIndex].addHp > 0) {
										setColor(RED);
										printSlowly("체력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedWeaponIndex].addHp), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedWeaponIndex].addDefense > 0) {
										setColor(SKYBLUE);
										printSlowly("방어력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedWeaponIndex].addAttack), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedWeaponIndex].addAttack > 0) {
										setColor(DARK_RED);
										printSlowly("공격력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedWeaponIndex].addAttack), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedWeaponIndex].addMana > 0) {
										if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
											setColor(BLUE);
											printSlowly("마나: -", 30);
											printSlowly(StringvalueOf(playerInfo.inventory[equippedWeaponIndex].addMana), 100);
											printf("\n");
											setColor(WHITE);
										}

									}
								}

								playerInfo.inventory[selectedIndex - 1].isEquipped = 1;
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;
								printBar();
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
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addDefense), 100);
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
								
							}else if (playerInfo.inventory[selectedIndex - 1].type == 4) {
								
								equippedArmorIndex = -1;
								for (int i = 0; i < playerInfo.itemIndex; i++) {
									if (playerInfo.inventory[i].isEquipped == 1 && playerInfo.inventory[i].type == 4 && i != selectedIndex - 1) {
										equippedArmorIndex = i;

										break; // 이미 장착된 장비가 있다면 인덱스 저장 후 루프 종료
									}
								}

									
								
								if (equippedArmorIndex != -1) {
									printBar();
									printSlowly("이미 ", 50);
									printSlowly(playerInfo.inventory[equippedArmorIndex].item, 50);
									printSlowly("을(를) 착용하고 있습니다.\n", 50);
									printSlowly(playerInfo.inventory[equippedArmorIndex].item, 50);
									printSlowly("을(를) 해제하고 ", 50);
									printSlowly(playerInfo.inventory[selectedIndex - 1].item, 50);
									printSlowly("을(를) 착용합니다.\n", 50);

									// 기존 장착 아이템 해제
									playerInfo.inventory[equippedArmorIndex].isEquipped = 0;
									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedArmorIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedArmorIndex].addDefense;

									playerInfo.playerScharacterInfo.attack -= playerInfo.inventory[equippedArmorIndex].addAttack;
									playerInfo.playerScharacterInfo.defense -= playerInfo.inventory[equippedArmorIndex].addDefense;
									playerInfo.playerScharacterInfo.hp -= playerInfo.inventory[equippedArmorIndex].addHp;
									playerInfo.playerScharacterInfo.mana -= playerInfo.inventory[equippedArmorIndex].addMana;
									if (playerInfo.inventory[equippedArmorIndex].addHp > 0) {
										setColor(RED);
										printSlowly("체력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedArmorIndex].addHp), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedArmorIndex].addDefense > 0) {
										setColor(SKYBLUE);
										printSlowly("방어력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedArmorIndex].addDefense), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedArmorIndex].addAttack > 0) {
										setColor(DARK_RED);
										printSlowly("공격력: -", 30);
										printSlowly(StringvalueOf(playerInfo.inventory[equippedArmorIndex].addAttack), 100);
										printf("\n");
										setColor(WHITE);
									}
									else if (playerInfo.inventory[equippedArmorIndex].addMana > 0) {
										if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
											setColor(BLUE);
											printSlowly("마나: -", 30);
											printSlowly(StringvalueOf(playerInfo.inventory[equippedArmorIndex].addMana), 100);
											printf("\n");
											setColor(WHITE);
										}

									}
								}

								playerInfo.inventory[selectedIndex - 1].isEquipped = 1;
								playerInfo.playerScharacterInfo.attack += playerInfo.inventory[selectedIndex - 1].addAttack;
								playerInfo.playerScharacterInfo.defense += playerInfo.inventory[selectedIndex - 1].addDefense;
								playerInfo.playerScharacterInfo.hp += playerInfo.inventory[selectedIndex - 1].addHp;
								playerInfo.playerScharacterInfo.mana += playerInfo.inventory[selectedIndex - 1].addMana;
								printBar();
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
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addDefense), 100);
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



							//여기까지
						}
						break;

					}
					else if (temp == 2) {
						if (playerInfo.inventory[selectedIndex - 1].type == 2) {
							printBar();
							printSlowly("포션은 장착 해제가 불가합니다.\n", 30);

						}
						else if (playerInfo.inventory[selectedIndex - 1].type == 3) {
							printBar();
							printSlowly("소모품은 장착 해제가 불가합니다.\n", 30);
				
							break;
						}
						else if (playerInfo.inventory[selectedIndex - 1].type == 1 || playerInfo.inventory[selectedIndex - 1].type == 4) {
							if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
								printBar();
								printSlowly("이미 장착하지 않고 있습니다.\n", 30);
								break;
							}
							else {
								printBar();
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
									printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addDefense), 100);
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
						printBar();
						printf("취소되었습니다.\n");
						break;
					}
					else if (temp == 4) {
						printBar();
						printSlowly("정말 버리시겠습니까?\n", 50);
						printSlowly("1. 예\n2. 아니오\n", 50);
						while (1) {
							int trash = 0;
							printf("Enter: ");
							scanf("%d", &trash);

							if (trash == 1) {
								if ((playerInfo.inventory[selectedIndex - 1].type == 1 || playerInfo.inventory[selectedIndex - 1].type == 4) && playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
									printBar();
									printSlowly("아이템을 버려 장비가 착용 해제되었습니다. \n", 30);
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
										printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addDefense), 100);
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
								}
								printBar();

								printSlowly(playerInfo.inventory[selectedIndex - 1].item, 50);
								printSlowly("(을/를) 버렸습니다.", 50);
								printSlowly("\n남은 개수: ", 50);
								printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].quantity - 1), 50);
								printf("\n");


								playerInfo.inventory[selectedIndex - 1].quantity--;
								if (playerInfo.inventory[selectedIndex - 1].quantity == 0) {
									deleteItem_ko(playerInfo.inventory[selectedIndex - 1].item, selected);
								}


								break;
							}
							else if (trash == 2) {
								printSlowly("취소되었습니다.", 50);
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
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
						while (getchar() != '\n');
					}
				}

				break; // 아이템 장착/사용 후 루프 종료

				
			}
			else if (selectedIndex == 0) {
				if (strlen(playerInfo.playerScharacterInfo.name) != 0 && strcmp(playerInfo.playerScharacterInfo.name, "UNDEFINED") != 0) {


					printBar();
					drawChar_ko();
					printSlowly(playerInfo.playerName, 200);
					printSlowly("님: ", 200);
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
					printBar();
					printSlowly("아직 캐릭터를 선택하지 않으셨습니다.\n", 100);
					return; // 인벤토리 종료 후 함수 종료
				}
			}
			else {
				printBar();
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
				while (getchar() != '\n');
			}
		}
	}
}



void printstatus_ko() {
	drawChar_ko();
	printSlowly(playerInfo.playerName, 200);
	printSlowly("님의 선택: ", 200);
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


int useSkill_ko(int monsterIndex, int* skillIndex, int* con) { //스킬 데미지는 캐릭터의 현재 공격력 * 2
	//마법사는 마나 -=10 / 도적은 공격이 아니라 방어력 100+원래 공격력으로 은신 구현

	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "마법사") != 0) {
		printBar();
		printSlowly("스킬 사용: ", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0) {
			setColor(SKYBLUE);
		}
		else if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
			setColor(RED);
			playerInfo.playerScharacterInfo.defense = 100;
		}
		else {
			//추가 캐릭터
		}
		int damage = 0;
		if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
			damage = (playerInfo.playerScharacterInfo.attack) - (monster[monsterIndex].defense * DEFENSE_RATE);
		}
		else {
			damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
		}

		printSlowly(playerInfo.playerScharacterInfo.skill, 100);
		setColor(WHITE);
		printSlowly("!\n", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
			printSlowly("스킬을 사용하여 은신 상태가 되었습니다.\n도적: 임시 방어력 = 100\n", 100);
		}
		printSlowly(monster[monsterIndex].name, 50);
		if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
			printSlowly("에게 공격했습니다. \n데미지: ", 50);
		}
		else {
			printSlowly("에게 스킬을 사용했습니다. \n데미지: ", 50);
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
		printSlowly("사용 가능 횟수: 0\n", 30);


	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
		int skillMage = playerInfo.playerScharacterInfo.mana / 10;
		if (skillMage > 0) {
			printBar();
			printSlowly("스킬 사용: ", 100);
			setColor(YELLOW);
			int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
			printSlowly(playerInfo.playerScharacterInfo.skill, 100);
			setColor(WHITE);
			printSlowly("!\n", 100);
			printSlowly(monster[monsterIndex].name, 50);
			printSlowly("에게 스킬을 사용했습니다.\n마나: ", 50);
			setColor(BLUE);
			printSlowly("-10\n", 50);
			setColor(BLUE);
			printSlowly("보유 마나: ", 100);
			printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 50);
			setColor(WHITE);
			setColor(WHITE);
			printSlowly("\n데미지: ", 50);
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
			printSlowly("마나가 부족합니다. \n", 100);
			printSlowly("필요 마나: 10 \n", 100);
			setColor(BLUE);
			printSlowly("보유 마나: ", 100);
			printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 50);
			setColor(WHITE);

		}
	}
	else {
		printBar();
		printSlowly("이미 스킬을 사용하였습니다.\n", 100);
		printBar();
		*con = -1;
	}
	if (strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
		return 1;
	}
	else {
		return 0;
	}

}
bool battle_ko(int monsterIndex) {
	int skillDefense = 0;
	int turn = 0;
	int defenseTurn = 0; //0. 방어 안 함, 1. 방어 상태
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

		printBar();
		setColor(SKYBLUE);
		printSlowly("Tip. 공격 시 확률 - 치명타: 20%, 경미한 타격: 20%, 일반 공격: 60% / 치명타 배율: 150%, 경미한 타격: 60%\n", 100);

		printSlowly("Tip. 방어&공격 시 기본 데미지의 60%로 공격합니다.\n", 100);
		setColor(WHITE);
		printBar();
		setColor(YELLOW);
		printf("===== 전투 시작 =====\n");
		setColor(WHITE);
		turn = 0;
		while (1) {
			int playerChoice;
			if (turn > 0) {
				setColor(YELLOW);
				printf("-- 다음 턴 --\n");
			}
			setColor(WHITE);
			con = 0;
			printSlowly("1. 공격\n2. 방어&공격\n3. 스킬\n4. 인벤토리\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);
			int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
			int damageRatio = rand() % 100; //0~99
			int defenseDamage = damage;
			if (playerChoice == 1) {
				// 플레이어 공격
				printBar();
				if (damageRatio < 20) {
					//치명타
					setColor(RED);
					printSlowly("치명타 발동!\n", 100);
					setColor(WHITE);
					printBar();
					damage *= 1.5;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("에게 공격하였습니다.\n데미지: ", 100);
				}
				else if (damageRatio < 40) {
					//경미한
					setColor(BLUE);
					printSlowly("아쉽다! 공격이 빗나갔다.\n", 100);
					setColor(WHITE);
					printBar();
					damage *= 0.6;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("에게 공격하였습니다.\n데미지: ", 100);

				}
				else {
					//일반
					damage *= 1.0;
					monster[monsterIndex].hp -= damage;
					setColor(VIOLET);
					printSlowly(monster[monsterIndex].name, 100);
					setColor(WHITE);
					printSlowly("에게 공격하였습니다.\n데미지: ", 100);
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
				// 플레이어 방어
				defenseTurn = 1;
				printBar();
				printSlowly("방어 자세를 취했습니다.\n", 50);
				setColor(SKYBLUE);
				printSlowly("임시 방어력: +50\n", 50);
				setColor(VIOLET);
				printSlowly(monster[monsterIndex].name, 100);
				setColor(WHITE);
				printSlowly("에게 공격하였습니다.\n데미지: ", 100);
				playerInfo.playerScharacterInfo.defense += 50;
				setColor(WHITE);
				//방어 시 공격
				monster[monsterIndex].hp -= defenseDamage * 0.6;
				setColor(DARK_RED);
				printSlowly(StringvalueOf(defenseDamage * 0.6), 100);
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
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
				while (getchar() != '\n');
			}
			// 몬스터 턴
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
					printSlowly("가 ", 100);
					printSlowly(playerInfo.playerName, 100);
					printSlowly("님에게 공격하였습니다.\n데미지: ", 100);
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
		printSlowly("승리!\n", 40);
		setColor(WHITE);
		if (playerInfo.potionUsed == 1) {
			printBar();
			printSlowly("전투가 종료되어 포션으로 인한 능력치가 초기화됩니다.\n", 40);
			if (playerInfo.potionAdd > 0 && playerInfo.type == 'H') {
				setColor(RED);
				printSlowly("체력: -", 30);
				printSlowly(StringvalueOf(playerInfo.potionAdd), 100);
				playerInfo.playerScharacterInfo.hp -= playerInfo.potionAdd;
				printf("\n");
				setColor(WHITE);
			}
			else if (playerInfo.potionAdd > 0 && playerInfo.type == 'D') {
				setColor(SKYBLUE);
				printSlowly("방어력: -", 30);
				printSlowly(StringvalueOf(playerInfo.potionAdd), 100);
				playerInfo.playerScharacterInfo.defense -= playerInfo.potionAdd;
				printf("\n");
				setColor(WHITE);
			}
			else if (playerInfo.potionAdd > 0 && playerInfo.type == 'A') {
				setColor(DARK_RED);
				printSlowly("공격력: -", 30);
				printSlowly(StringvalueOf(playerInfo.potionAdd), 100);
				playerInfo.playerScharacterInfo.attack -= playerInfo.potionAdd;
				printf("\n");
				setColor(WHITE);
			}
			else if (playerInfo.potionAdd > 0 && playerInfo.type == 'M') {
				if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
					setColor(BLUE);
					printSlowly("마나: -", 30);
					printSlowly(StringvalueOf(playerInfo.potionAdd), 100);
					playerInfo.playerScharacterInfo.mana -= playerInfo.potionAdd;
					printf("\n");
					setColor(WHITE);
				}

			}
			printBar();
			playerInfo.potionUsed = 0;
		}
		return true;
	}
	else {
		printBar();
		setColor(VIOLET);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(DARK_GRAY);
		printSlowly("에게 패배...\n", 100);
		setColor(WHITE);
		return false;
	}
}



void printLevel_ko() {
	printSlowly("현재 레벨은 Lv.", 50);
	printSlowly(StringvalueOf(playerInfo.level), 50);
	printSlowly("\n경험치: ", 50);
	setColor(GREEN);
	printSlowly(StringvalueOf(playerInfo.levelPro), 50);
	printSlowly("%", 50);
	setColor(WHITE);
	printSlowly(" 입니다.\n", 50);
}



void money_ko() {
	printSlowly("현재 보유한 골드는 ", 50);
	setColor(YELLOW);
	printf("$ ");
	printSlowly(StringvalueOf(playerInfo.money), 50);
	setColor(WHITE);
	printSlowly("입니다.\n", 50);
}

void addMoney_ko(int x) {
	setColor(YELLOW);
	printSlowly("$ ", 50);
	printSlowly(StringvalueOf(x), 50);
	setColor(WHITE);
	printSlowly(" 골드를 획득하였습니다.\n", 50);
	playerInfo.money += x;
	money_ko();
}


void levelUp_ko() {
	playerInfo.level += 1;
	printSlowly("===== 경험치가 ", 50);
	setColor(GREEN);
	printSlowly("100%", 50);
	setColor(WHITE);
	printSlowly("를 넘어 레벨이 올랐습니다! =====\n", 50);

	if (strcmp(playerInfo.playerScharacterInfo.name, "") == 0 || strcmp(playerInfo.playerScharacterInfo.name, "UNDEFINED") == 0) {

	}
	else {


		printBar();
		// 능력치 상승 처리
		printSlowly("축하합니다! 레벨업으로 능력치가 상승합니다.\n", 50);
		printBar();
		int hpIncrease = 20;      // 체력 증가량
		int attackIncrease = 5;   // 공격력 증가량
		int defenseIncrease = 3;  // 방어력 증가량
		int manaIncrease = 10;  // 마나 증가량

		if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
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
		printSlowly(" - 공격력: +", 50);
		printSlowly(StringvalueOf(attackIncrease), 50);
		printf("\n");

		setColor(SKYBLUE);
		printSlowly(" - 방어력: +", 50);
		printSlowly(StringvalueOf(defenseIncrease), 50);
		printf("\n");
		if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
			setColor(BLUE);
			printSlowly(" - 마나: +", 50);
			printSlowly(StringvalueOf(manaIncrease), 50);
			printf("\n");
		}


		setColor(WHITE);
		printBar();
		printSlowly("새로운 능력치가 적용되었습니다.\n", 50);

	}

}

void loadLevelPro_ko(int x, char* reason) {
	playerInfo.levelPro += x;
	if (playerInfo.levelPro < 100) {
		printSlowly("경험치가 ", 50);
		setColor(GREEN);
		printf("%d", x);
		printf("%%");
		setColor(WHITE);
		printSlowly(" 만큼 올라 현재: ", 50);
		setColor(GREEN);
		printSlowly(StringvalueOf(playerInfo.levelPro), 50);
		printf("%%");
		setColor(WHITE);
		printSlowly(" 입니다. / ", 50);
		printSlowly(reason, 50);
		printf("\n");
	}
	else {
		playerInfo.levelPro -= 100;
		printSlowly(" - 경험치 : ", 50);
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

struct INVENTORY_SHOP* getShopItems_ko(const char* job) {
	if (strcmp(job, "전사") == 0) {
		static struct INVENTORY_SHOP warriorItems[] = {
			{"빛나는 검", 1, 1, 0, 12, 0, 0, 0, "빛나는 검입니다. / 공격력 +12", 50},
			{"빛나는 갑옷", 1, 4, 0, 0, 10, 0, 0, "빛나는 갑옷입니다. / 방어력 +10", 50},
			{"고급 체력 포션", 1, 2, 0, 0, 0, 20, 0, "고급 체력 포션입니다. / 체력 +20", 60}
		};
		return warriorItems;
	}
	else if (strcmp(job, "마법사") == 0) {
		static struct INVENTORY_SHOP mageItems[] = {
			{"빛나는 지팡이", 1, 1, 0, 8, 0, 0, 0, "빛나는 지팡이입니다. / 공격력 +8", 50},
			{"빛나는 갑옷", 1, 4, 0, 0, 10, 0, 0, "빛나는 갑옷입니다. / 방어력 +10", 50},
			{"고급 체력 포션", 1, 2, 0, 0, 0, 20, 0, "고급 체력 포션입니다. / 체력 +20", 60}
		};
		return mageItems;
	}
	else if (strcmp(job, "도적") == 0) {
		static struct INVENTORY_SHOP thiefItems[] = {
			{"화염 표창", 1, 1, 0, 5, 0, 0, 0, "화염 표창입니다. / 공격력 +5", 50},
			{"빛나는 갑옷", 1, 4, 0, 0, 10, 0, 0, "빛나는 갑옷입니다. / 방어력 +10", 50},
			{"고급 체력 포션", 1, 2, 0, 0, 0, 20, 0, "고급 체력 포션입니다. / 체력 +20", 60}
		};
		return thiefItems;
	}
	else {
		// 직업이 유효하지 않은 경우 빈 배열 반환 (itemCount는 0)
		static struct INVENTORY_SHOP emptyItems[1];
		return emptyItems;
	}
}
void shop_ko() {
	clear();
	int selected = 0;
	int index = 0;
	while (1) { // while 루프를 사용하여 반복
		selected = 0; // selected 값 초기화
		printBar();
		setColor(YELLOW);
		printf("===== 상점 =====\n");
		setColor(WHITE);

		struct INVENTORY_SHOP* shopItems = getShopItems_ko(playerInfo.playerScharacterInfo.name);
		struct INVENTORY_SHOP inventoryItem_shop[3] = {
			shopItems[0],
			shopItems[1],
			shopItems[2]
		};
		if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0 || strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0 || strcmp(playerInfo.playerScharacterInfo.name, "도적") == 0) {
			for (int i = 0; i < 3; i++) {
				printf("%d. %s: ", i + 1, inventoryItem_shop[i].item);
				printf("%s", inventoryItem_shop[i].state);
				printSlowly(" / 가격 ", 50);
				
				setColor(YELLOW);
				printSlowly("$ ", 50);
				printSlowly(StringvalueOf(inventoryItem_shop[i].price), 50);
				setColor(WHITE);
				printf("\n");
			}
		}
		else {
			printSlowly("아직 캐릭터를 선택하지 않았습니다.\n선택 후 다시 시도해주세요.\n", 50);
			return;
		}

		printBar();
		money_ko();
		printBar();
		printSlowly("어떤 아이템을 구매하시겠습니까?\n0. 나가기\n", 30);
		while (1) {
			printf("Enter: ");
			scanf("%d", &index);
			if (index == 0) {
				printBar();
				printSlowly("상점을 나갑니다.\n", 30);
	
				return;
			}
			else if (index < 10 && index > 0) {
				printBar();
				printSlowly("선택한 아이템: ", 30);
				printSlowly(inventoryItem_shop[index - 1].item, 30);
				printf("\n");
				printBar();
				printf("1. 구매\n2. 취소\n");
				int temp = 0;
				while (1) {
					printf("Enter: ");
					scanf("%d", &temp);
					if (temp == 1) {
						printBar();
						if (playerInfo.money >= inventoryItem_shop[index - 1].price) {
							playerInfo.money -= inventoryItem_shop[index - 1].price;
							printSlowly(inventoryItem_shop[index - 1].item, 50);
							printSlowly(" 구매 완료!\n", 50);

							strcpy(playerInfo.inventory[playerInfo.itemIndex].item, inventoryItem_shop[index - 1].item);
							playerInfo.inventory[playerInfo.itemIndex].quantity = 1;
							playerInfo.inventory[playerInfo.itemIndex].type = inventoryItem_shop[index - 1].type;
							playerInfo.inventory[playerInfo.itemIndex].isEquipped = 0;
							playerInfo.inventory[playerInfo.itemIndex].addAttack = inventoryItem_shop[index - 1].addAttack;
							playerInfo.inventory[playerInfo.itemIndex].addDefense = inventoryItem_shop[index - 1].addDefense;
							playerInfo.inventory[playerInfo.itemIndex].addHp = inventoryItem_shop[index - 1].addHp;
							playerInfo.inventory[playerInfo.itemIndex].addMana = inventoryItem_shop[index - 1].addMana;
							strcpy(playerInfo.inventory[playerInfo.itemIndex].state, inventoryItem_shop[index - 1].state);
							playerInfo.itemIndex++;
							break;
						}
						else {
							printSlowly("골드가 부족합니다.\n", 50);
							printSlowly("필요한 골드: ", 50);
							setColor(YELLOW);
							printSlowly(StringvalueOf(inventoryItem_shop[index - 1].price), 50);
							setColor(WHITE);
							printSlowly("\n현재 골드: ", 50);
							money_ko();
							break;
						}
					}
					else if (temp == 2) {
						printBar();
						printf("취소되었습니다.\n");
						break;
					}
					else {
						printBar();
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
						while (getchar() != '\n');
					}
				}
				break;
			}
			else {
				printBar();
				printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 30);
				while (getchar() != '\n');
			}
		}
	}
}

int selectPro_ko() {
	int option = 0;
	while (1) {
		printBar();
		printSlowly("1. 스토리\n2. 인벤토리\n3. 상점\n4. 게임 종료\n", 50);
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
			printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
			while (getchar() != '\n');
		}
	}
	return option;
}
