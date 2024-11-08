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



void displayInventory_ko() {
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
						else if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
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
						else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
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
				drawChar_ko();
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



void printstatus_ko() {
	drawChar_ko();
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


void useSkill_ko(int monsterIndex, int* skillIndex, int* con) { //스킬 데미지는 캐릭터의 현재 공격력 * 2
	//마법사는 마나 -=10 / 도적은 공격이 아니라 방어력 100으로 은신 구현
	if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "마법사") != 0) {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("스킬 사용: ", 100);
		if (strcmp(playerInfo.playerScharacterInfo.name, "전사") == 0) {
			setColor(SKYBLUE);
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
		printSlowly("사용 가능 횟수: 0\n", 30);


	}
	else if (strcmp(playerInfo.playerScharacterInfo.name, "마법사") == 0) {
		int skillMage = playerInfo.playerScharacterInfo.mana / 10;
		if (skillMage > 0) {
			printf("------------------------------------------------------------------------------------------\n");
			printSlowly("스킬 사용: ", 100);
			setColor(VIOLET);
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
bool battle_ko(int monsterIndex) {
	int turn = 0;
	int defenseTurn = 0; //0. 방어 안 함, 1. 방어 상태
	int skillIndex = 0;
	int con = 0;
	while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

		printf("------------------------------------------------------------------------------------------\n");
		setColor(SKYBLUE);
		printSlowly("Tip. 공격 시 확률 - 치명타: 20%, 경미한 타격: 20%, 일반 공격: 60% / 치명타 배율: 150%, 경미한 타격: 60%\n", 100);

		printSlowly("Tip. 방어&공격 시 기본 데미지의 60%로 공격합니다.\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
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
			printSlowly("1. 공격\n2. 방어&공격\n3. 스킬\n", 100);
			printf("Enter: ");
			scanf("%d", &playerChoice);
			int damage = playerInfo.playerScharacterInfo.attack - (monster[monsterIndex].defense * DEFENSE_RATE);
			int damageRatio = rand() % 100; //0~99
			int defenseDamage = damage;
			if (playerChoice == 1) {
				// 플레이어 공격
				printf("------------------------------------------------------------------------------------------\n");
				if (damageRatio < 20) {
				//치명타
					setColor(RED);
					printSlowly("치명타 발동!\n", 100);
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
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("플레이어가 방어 자세를 취했습니다.\n", 50);
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
					printf("------------------------------------------------------------------------------------------\n");
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
		printSlowly("승리!\n", 40);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return true;
	}
	else {
		printf("------------------------------------------------------------------------------------------\n");
		setColor(VIOLET);
		printSlowly(monster[monsterIndex].name, 100);
		setColor(DARK_GRAY);
		printSlowly("에게 패배...\n", 100);
		setColor(WHITE);
		printf("------------------------------------------------------------------------------------------\n");
		return false;
	}
}



