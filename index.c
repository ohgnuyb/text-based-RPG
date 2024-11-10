#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"
#include "korean.c"
#include "english.c"
#include "rpg_struct.h"
#include "stringFunc.h"


typedef void (*drawWarrior_ptr)();
typedef void (*drawMage_ptr)();
typedef void (*drawRogue_ptr)();
typedef void (*drawChar_ptr)();
typedef void (*displayInventory_ptr)();
typedef void (*printstatus_ptr)();
typedef void (*useSkill_ptr)(int monsterIndex, int* skillIndex, int* con);
typedef bool (*battle_ptr)(int monsterIndex);
typedef void (*shop_ptr)();
typedef void (*printLevel_ptr)();
typedef void (*levelUp_ptr)();
typedef void (*selectPro_ptr)();
typedef void (*loadLevelPro_ptr)(int x, char* reason);


drawWarrior_ptr drawWarrior;
drawMage_ptr drawMage;
drawRogue_ptr drawRogue;
drawChar_ptr drawChar;
displayInventory_ptr displayInventory;
printstatus_ptr printstatus;
useSkill_ptr useSkill;
battle_ptr battle;
shop_ptr shop;
printLevel_ptr printLevel;
levelUp_ptr levelUp;
loadLevelPro_ptr loadLevelPro;
selectPro_ptr selectPro;





void printMonster1() { //몬스터 첫번째
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






void main() {
	int lang = 0;
	int st_ex = -1; //시작/종료 인덱스

	printBar();
	printf("언어를 선택하세요. / Select a language.\n");
	printSlowly("1. 한국어 / Korean\n2. 영어 / English\n", 30);

	while (1) {
		printf("Enter: ");
		scanf("%d", &lang);
		printBar();
		if (lang == 1) {
			drawWarrior = drawWarrior_ko;
			drawMage = drawMage_ko;
			drawRogue = drawRogue_ko;
			drawChar = drawChar_ko;
			displayInventory = displayInventory_ko;
			printstatus = printstatus_ko;
			useSkill = useSkill_ko;
			battle = battle_ko;
			shop = shop_ko;
			printLevel = printLevel_ko;
			levelUp = levelUp_ko;
			loadLevelPro = loadLevelPro_ko;
			selectPro = selectPro_ko;


			strcpy(characterInfo[0].name, "전사");//한국어 캐릭터 구조체
			strcpy(characterInfo[0].skill, "파괴의 일격");
			strcpy(characterInfo[0].charState, "강인한 체력과 뛰어난 검술 실력을 가진 전사입니다.");
			strcpy(characterInfo[1].name, "마법사");//한국어 캐릭터 구조체
			strcpy(characterInfo[1].skill, "백만볼트");
			strcpy(characterInfo[1].charState, "강력한 마법을 사용하는 마법사입니다.");
			strcpy(characterInfo[2].name, "도적");//한국어 캐릭터 구조체
			strcpy(characterInfo[2].skill, "은신");
			strcpy(characterInfo[2].charState, "민첩한 움직임과 은밀한 행동에 능숙한 도적입니다.");

			system("title 문제해결기법 / 11조");

			playerInfo.playerScharacterInfo.hp = 1;
			while (playerInfo.playerScharacterInfo.hp > 0) { //영어 부분 여기부터 복사
				srand(time(NULL));
				setColor(BLACK);
				int choice = -1;
				int charSel = -1;
				int itemIndex = 0;
				char title[50] = "잊혀진 왕국의 비밀";
				int padding = 46;

				strcpy(monster[0].name, "펜리르"); //첫 번째 몬스터
				strcpy(monster[0].skill, "내려찍기");
				monster[0].hp = 80;
				monster[0].attack = 20;
				monster[0].defense = 20;

				//두 번째 몬스터



				for (int i = 0; i < padding; i++) {
					printf(" ");
				}
				setColor(RED);
				printf("\n");
				printf("      (\\____/)\n");
				printf("       (_oo_)\n");
				printf("        (oo)\n");
				printf("      /------\\/`\n");
				printf("     / |    ||\n");
				printf("    *  /\\---/\\\n");
				printf("       ~~   ~~\n");
				setColor(DARK_VOILET);
				for (int i = 0; i < padding -15; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding+3	;  i++) {
					printf(" ");
				}
				printSlowly(title, 250);
				printf("\n");
				for (int i = 0; i < padding - 15; i++) {
					printf(" ");
				}
				printf("+------------------------------------------------------+\n");
				for (int i = 0; i < padding + 1; i++) {
					printf(" ");
				}

				printf("\n\n");
				setColor(DARK_GREEN);
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                               .--\"\"--.\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              /        \\\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             |   *  *  |\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                             \\  .--.  /\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                              '.____.'\n");
				for (int i = 0; i < padding + 30; i++) {
					printf(" ");
				}
				printf("                                ||||\n\n\n");

				setColor(WHITE);
				printBar();
				printf("1. 시작\n2. 종료\n");
				while (1) {



					printf("Enter: ");
					scanf("%d", &st_ex);
					if (st_ex == 1) {
						playerInfo.level = 0;
						playerInfo.levelPro = 0;
						int charExit = 0;
						printBar();
						printf("이름을 입력하세요: \n");
						printf("Enter: ");
						scanf("%s", playerInfo.playerName);
						printBar();
						clear();
						printBar();
						for (int i = 0; i < padding; i++) {
							printf(" ");
						}
						setColor(RED);
						printf("\n");
						printf("      (\\____/)\n");
						printf("       (_oo_)\n");
						printf("        (oo)\n");
						printf("      /------\\/`\n");
						printf("     / |    ||\n");
						printf("    *  /\\---/\\\n");
						printf("       ~~   ~~\n");
						setColor(DARK_VOILET);
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 3; i++) {
							printf(" ");
						}
						printf(title);
						printf("\n");
						for (int i = 0; i < padding - 15; i++) {
							printf(" ");
						}
						printf("+------------------------------------------------------+\n");
						for (int i = 0; i < padding + 1; i++) {
							printf(" ");
						}

						printf("\n\n");
						setColor(DARK_GREEN);
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                               .--\"\"--.\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              /        \\\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             |   *  *  |\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                             \\  .--.  /\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                              '.____.'\n");
						for (int i = 0; i < padding + 30; i++) {
							printf(" ");
						}
						printf("                                ||||\n\n\n");
						setColor(WHITE);
						printBar();
						printSlowly("안녕하세요, ", 30);
						printSlowly(playerInfo.playerName, 200);
						printf("님!\n");
						printBar();
						loadLevelPro(100, "게임 시작");
						printBar();
						printLevel();
						printBar();
						printSlowly("\'빈 종이\'가 지급되었습니다.\n", 100);
						strcpy(playerInfo.inventory[itemIndex].item, "빈 종이");
						strcpy(playerInfo.inventory[itemIndex].state, "빈 종이입니다.");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 3;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 0;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 0;
						playerInfo.inventory[itemIndex].addMana = 0;
						itemIndex++;
						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip: 인벤토리와 상점은 선택창에 표시될 때 이용 가능합니다.\n", 30);
						setColor(WHITE);
						selectPro();
						printBar();
						setColor(RED);
						printSlowly("시작...\n", 300);

						setColor(WHITE);
						 /*printSlowly("깊은 숲 속에 숨겨진 고대 왕국, '아르카디아'. 한때 번영했던 이 왕국은 어둠의 마법사 \n'말레피센트'의 저주로 인해 멸망하고, 사람들의 기억 속에서 잊혀졌습니다. \n당신은 우연히 아르카디아의 존재를 알게 된 모험가입니다. \n잊혀진 왕국의 비밀을 밝혀내고 말레피센트의 저주를 풀어 아르카디아를 부활시킬 수 있을까요?\n", 30);
						printBar();
						setColor(SKYBLUE);
						printSlowly("Tip. 전사와 도적은 전투당 한 번의 스킬을 사용할 수 있고 마법사는 스킬 한 번당 마나 10을 소모합니다.\n", 100); */
						while (1) {
							setColor(WHITE);
							printBar();
							printSlowly("캐릭터 선택: \n", 200);
							/*
							for (int i = 0; i < 3; i++) {
								setColor(i == 0 ? SKYBLUE : i == 1 ? YELLOW : RED);
								printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
								printSlowly(characterInfo[i].name, 200);
								printf(": ");
								setColor(WHITE);
								printSlowly(characterInfo[i].charState, 30);
								printf("\n");
							}
							*/
							printBar();
							printSlowly("4. 인벤토리\n5. 상점\n", 30);
							printBar();
							printf("Enter: ");
							scanf("%d", &charSel);
							int use = -1;

							if (charSel == 1) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("을/를 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);


									printf("Enter: ");
									scanf("%d", &charExit);
									if (charExit == 1) {
										strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
										strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
										strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
										playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
										playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
										playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
										playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
										printBar();
										loadLevelPro(100, "캐릭터 선택");
										printBar();
										printLevel();
										printBar();
										printSlowly("검사를 위한 \'목검\'이 지급되었습니다.\n", 30);
										printBar();
										strcpy(playerInfo.inventory[itemIndex].item, "목검");
										playerInfo.inventory[itemIndex].quantity = 1;
										playerInfo.inventory[itemIndex].type = 1;
										playerInfo.inventory[itemIndex].isEquipped = 0;
										playerInfo.inventory[itemIndex].addAttack = 5;
										playerInfo.inventory[itemIndex].addDefense = 0;
										playerInfo.inventory[itemIndex].addHp = 0;
										playerInfo.inventory[itemIndex].addMana = 0;
										itemIndex++;
										printstatus();
										printBar();
										printSlowly("1. 인벤토리\n2. 취소\n", 100);
										while (1) {


											printf("Enter: ");
											scanf("%d", &use);
											if (use == 1) {
												displayInventory();
												break;
											}
											else if (use == 2) {
												printBar();
												printSlowly("취소되었습니다.\n", 100);
												printBar();
												break;
											}
											else {
												printBar();
												printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
												while (getchar() != '\n');
											}

										}
										break;
									}
									else if (charExit == 2) {
										printBar();
										printSlowly("취소되었습니다.\n", 100);
										while (getchar() != '\n');
									}
									else {
										printBar();
										printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
										while (getchar() != '\n');
									}
								

							}
							else if (charSel == 2) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("을 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
									
									printBar();
									loadLevelPro(100, "캐릭터 선택");
									printBar();
									printLevel();
									printBar();
									printSlowly("마법사를 위한 \'마법사의 목걸이\'가 지급되었습니다.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[itemIndex].item, "마법사의 목걸이");
									playerInfo.inventory[itemIndex].quantity = 1;
									playerInfo.inventory[itemIndex].type = 1;
									playerInfo.inventory[itemIndex].isEquipped = 0;
									playerInfo.inventory[itemIndex].addAttack = 0;
									playerInfo.inventory[itemIndex].addDefense = 0;
									playerInfo.inventory[itemIndex].addHp = 0;
									playerInfo.inventory[itemIndex].addMana = 10;
									itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (1) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("취소되었습니다.\n", 100);
									
									while (getchar() != '\n');
								}
								else {
									printBar();
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
								}

							}
							else if (charSel == 3) {
								printBar();
								printSlowly("정말 ", 50);
								printSlowly(characterInfo[charSel - 1].name, 50);
								printSlowly("을 선택하시겠습니까?\n", 50);
								printSlowly("1. 선택\n2. 취소\n", 50);
								printf("Enter: ");
								scanf("%d", &charExit);
								if (charExit == 1) {
									strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
									strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
									strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
									playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
									playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
									playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
									playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
									
									printBar();
									loadLevelPro(100, "캐릭터 선택");
									printBar();
									printLevel();
									printBar();
									printSlowly("도적를 위한 \'도적의 망토\'가 지급되었습니다.\n", 100);
									printBar();
									strcpy(playerInfo.inventory[itemIndex].item, "도적의 망토");
									playerInfo.inventory[itemIndex].quantity = 1;
									playerInfo.inventory[itemIndex].type = 1;
									playerInfo.inventory[itemIndex].isEquipped = 0;
									playerInfo.inventory[itemIndex].addAttack = 0;
									playerInfo.inventory[itemIndex].addDefense = 0;
									playerInfo.inventory[itemIndex].addHp = 10;
									playerInfo.inventory[itemIndex].addMana = 0;
									itemIndex++;
									printstatus();
									printBar();
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (1) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											printBar();
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}
									break;
								}
								else if (charExit == 2) {
									printBar();
									printSlowly("취소되었습니다.\n", 100);
								
									while (getchar() != '\n');
								}
								else {
									printBar();
									while (getchar() != '\n');
								}
							}
							else if (charSel == 4) {
								printBar();
								displayInventory();
								while (getchar() != '\n');
							}
							else if (charSel == 5) {
								printBar();
								//shop()
								while (getchar() != '\n');
							}
							else {
								printBar();
								printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
								while (getchar() != '\n');
							}
							
						}
						

						setColor(WHITE);

						selectPro();

						printBar();
						/*
						setColor(RED);
						printSlowly("아르카디아로 향하는 길...\n", 200);
						setColor(WHITE);
						printSlowly("울창한 숲 속에서 길을 잃은 당신은 오래된 석판을 발견합니다.\n석판에는 아르카디아로 향하는 길에 대한 희미한 글귀가 새겨져 있습니다.\n", 20);
						printSlowly("\"저주받은 숲을 지나, 잊혀진 신전을 찾아라. \n신전의 수호자를 물리치고, 아르카디아의 문을 열어라.\"\n\n", 20);
						*/
					
						
						while (1) {
							printBar();
							setColor(RED);
							printf("선택: \n");
							setColor(WHITE);
							printSlowly("1. 저주받은 숲으로 향한다.\n", 100);
							printSlowly("2. 석판을 무시하고 다른 길을 찾는다.\n", 100);
							printBar();
							printSlowly("3. 인벤토리\n", 100);
							printSlowly("4. 상점\n", 100);
							printBar();
							printf("Enter: ");
							scanf("%d", &choice);
							if (choice == 1) { //1번 스토리
								printBar();
								setColor(YELLOW);
								printSlowly("숲의 보물\n", 50);
								setColor(WHITE);
								printSlowly("당신은 석판의 가르침에 따라 깊은 숲 속으로 들어섰다.\n저주받은 숲은 음산한 기운으로 가득하다...\n나무들은 기괴하게 뒤틀려 있고, 숲 속에는 알 수 없는 생명체들의 울음소리가 울려 퍼진다.\n", 20);
								printSlowly("깊은 숲을 헤치고 나아가던 중, 갑자기 시야에 오래된 유적지가 나타났다. 이곳은 분명 인간의 손길이 닿지 않은 듯한 모습이다.\n", 20);
								printSlowly("유적 한가운데 작은 제단이 놓여 있고, 그 위에는 뭔지모를 상자가 놓여있다.\n", 20);
								printBar();
								setColor(YELLOW);
								printSlowly("60% : 갑옷, 40 % : 포션\n", 100);
								setColor(WHITE);
								printBar();
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
									itemIndex++;
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (1) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											break;
										}
										else {
											printBar();
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
									itemIndex++;
									printSlowly("1. 인벤토리\n2. 취소\n", 100);
									while (1) {


										printf("Enter: ");
										scanf("%d", &use);
										if (use == 1) {
											displayInventory();
											break;
										}
										else if (use == 2) {
											printBar();
											printSlowly("취소되었습니다.\n", 100);
											break;
										}
										else {
											printBar();
											printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
											while (getchar() != '\n');
										}

									}


								}
								
								printBar();
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
								printMonster1();
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
								
								setColor(GREEN);
								printSlowly(" - Lv. ", 100);
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

								//원래 체력, 공격력, 방어력, 마나 기록
								int tempH = playerInfo.playerScharacterInfo.hp;
								int tempA = playerInfo.playerScharacterInfo.attack;
								int tempD = playerInfo.playerScharacterInfo.defense;
								int tempM = playerInfo.playerScharacterInfo.mana;

								if (battle(0) == true) { //0 = 몬스터 인덱스
									//승리일 경우 스토리 지속
									playerInfo.playerScharacterInfo.hp = tempH;
									playerInfo.playerScharacterInfo.attack = tempA;
									playerInfo.playerScharacterInfo.defense = tempD;
									playerInfo.playerScharacterInfo.mana = tempM;
									//전투에서 변경된 능력치 복구




									break;
								}
								else {
									break; //패배시 return False
								}

								break;

							}
							else if (choice == 3) {
								displayInventory();
								while (getchar() != '\n');
							}

							else if (choice == 4) {
								printBar();
								shop();
								while (getchar() != '\n');
							}
							else {
									printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
									while (getchar() != '\n');
							}


						
						}

						//스토리 통합: 임시

						break;
					}
					else if (st_ex == 2) {
						printBar();
						printSlowly("Game is closed!", 100);
						break;
					}
					else {
						printBar();
						printSlowly("잘못된 선택입니다. 다시 선택해주세요.\n", 100);
						printBar();
						while (getchar() != '\n');
					}

				}

			}

			if (st_ex != 2) {
				printSlowly("플레이어가 사망했습니다.\n", 100);
				printSlowly("Game is closed!", 100);
				break;//게임 종료/언어 선택 루프 종료
			}



			//영어 부분 여기까지 복사


			break; //게임 종료/한국어 부분
		}
		else if (lang == 2) {
			//영어 부분
			drawWarrior = drawWarrior_en;
			drawMage = drawMage_en;
			drawRogue = drawRogue_en;
			drawChar = drawChar_en;
			displayInventory = displayInventory_en;
			printstatus = printstatus_en;
			useSkill = useSkill_en;
			battle = battle_en;

			strcpy(characterInfo[0].name, "Warrior");//영어 캐릭터 구조체
			strcpy(characterInfo[0].skill, "A blow to destruction");
			strcpy(characterInfo[0].charState, "A warrior with strong physical strength and excellent swordsmanship.");
			strcpy(characterInfo[1].name, "Wizard");
			strcpy(characterInfo[1].skill, "Million Volts");
			strcpy(characterInfo[1].charState, "Wizard using powerful magic.");
			strcpy(characterInfo[2].name, "Rogue");
			strcpy(characterInfo[2].skill, "The Grace");
			strcpy(characterInfo[2].charState, "The Bandit is adept at agile movements and covert actions.");
			system("title 문제해결기법 / Team 11");
			playerInfo.playerScharacterInfo.hp = 1;



		}
		else {
			printSlowly("잘못된 선택입니다. 다시 선택해주세요. / It\'s a wrong choice. Please select again.\n", 100);
			while (getchar() != '\n');
		}


	}

}