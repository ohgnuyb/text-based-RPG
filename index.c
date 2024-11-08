#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"
int lang = 0;
#if lang == 1
#include "korean.c"
#elif lang == 2
#include "english.c"
#else
#include "korean.c"
#endif

#define MAX_INVENTORY_SIZE 10
#define DEFENSE_RATE 0.2

void main() {
	int st_ex = -1; //����/���� �ε���
	printf("------------------------------------------------------------------------------------------\n");
	printSlowly("�� �����ϼ���. / Select a language.\n", 50);
	printSlowly("1. �ѱ��� / Korean\n2. ���� / English\n", 50);
	while (1) {
		printf("Enter: ");
		scanf("%d", &lang);
		if (lang == 1) {

	system("title �����ذ��� / 11��");

	playerInfo.playerScharacterInfo.hp = 1;
	while(playerInfo.playerScharacterInfo.hp > 0){
	srand(time(NULL));
	setColor(BLACK);
	int choice = -1;
	int charSel = -1;
	int itemIndex = 0;
	char title[50] = "������ �ձ��� ���";
	int totalWidth = 47;
	int strWidth = strlen(title);
	int padding = (totalWidth - strWidth) / 2;

	strcpy(monster[0].name, "�渮��"); //ù ��° ����
	strcpy(monster[0].skill, "�������");
	monster[0].hp = 80;
	monster[0].attack = 20;
	monster[0].defense = 20;

									  //�� ��° ����

	printf("------------------------------------------------------------------------------------------\n");
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
	for (int i = 0; i < padding; i++) {
		printf(" ");
	}
	printSlowly(title, 250);
	for (int i = 0; i < padding; i++) {
		printf(" ");
	}

	printSlowly("\n\n", 150);
	setColor(DARK_GREEN);

	printf("                               .--\"\"--.\n");
	printf("                              /        \\\n");
	printf("                             |   *  *  |\n");
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
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�ȳ��ϼ���, ", 30);
				printSlowly(playerInfo.playerName, 200);
				printf("��!\n");
				printf("------------------------------------------------------------------------------------------\n");
				setColor(SKYBLUE);
				printSlowly("Tip: �κ��丮 ����� �������� ȹ���Ͽ��� ���� �����ϴ� �����ϼ���!\n", 30);
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("����...\n", 300);

				setColor(WHITE);
				printSlowly("���� �� �ӿ� ������ ��� �ձ�, '�Ƹ�ī���'. �Ѷ� �����ߴ� �� �ձ��� ����� ������ \n'�����Ǽ�Ʈ'�� ���ַ� ���� ����ϰ�, ������� ��� �ӿ��� ���������ϴ�. \n����� �쿬�� �Ƹ�ī����� ���縦 �˰� �� ���谡�Դϴ�. \n������ �ձ��� ����� �������� �����Ǽ�Ʈ�� ���ָ� Ǯ�� �Ƹ�ī��Ƹ� ��Ȱ��ų �� �������?\n", 30);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(SKYBLUE);
				printSlowly("Tip. ����� ������ ������ �� ���� ��ų�� ����� �� �ְ� ������� ��ų �� ���� ���� 10�� �Ҹ��մϴ�.\n", 100);
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("ĳ���� ����: \n", 300);
				for (int i = 0; i < 3; i++) {
					setColor(i == 0 ? SKYBLUE : i == 1 ? YELLOW : RED);
					printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
					printSlowly(characterInfo[i].name, 200);
					printf(": ");
					setColor(WHITE);
					printSlowly(characterInfo[i].charState, 30);
					printf("\n");
				}
				while (1) {
					printf("Enter: ");
					scanf("%d", &charSel);
					int use = -1;
					strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
					strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
					strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
					playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
					playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
					playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
					playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;
					
					if (charSel == 1) {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�˻縦 ���� \'���\'�� ���޵Ǿ����ϴ�.\n", 30);
						printf("------------------------------------------------------------------------------------------\n");
						
						strcpy(playerInfo.inventory[0].item, "���");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 5;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 0;
						playerInfo.inventory[itemIndex].addMana = 0;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. �κ��丮\n2. ���\n", 100);
						while (1) {

						
						printf("Enter: ");
						scanf("%d", &use);
						if (use == 1) {
							displayInventory();
							break;
						}
						else if (use == 2) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("��ҵǾ����ϴ�.\n", 100);
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
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�����縦 ���� \'�������� �����\'�� ���޵Ǿ����ϴ�.\n", 100);
						printf("------------------------------------------------------------------------------------------\n");
						strcpy(playerInfo.inventory[0].item, "�������� �����");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 0;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 0;
						playerInfo.inventory[itemIndex].addMana = 10;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. �κ��丮\n2. ���\n", 100);
						while (1) {


							printf("Enter: ");
							scanf("%d", &use);
							if (use == 1) {
								displayInventory();
								break;
							}
							else if (use == 2) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("��ҵǾ����ϴ�.\n", 100);
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
					else if (charSel == 3) {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("������ ���� \'������ ����\'�� ���޵Ǿ����ϴ�.\n", 100);
						printf("------------------------------------------------------------------------------------------\n");
						strcpy(playerInfo.inventory[0].item, "������ ����");
						playerInfo.inventory[itemIndex].quantity = 1;
						playerInfo.inventory[itemIndex].type = 1;
						playerInfo.inventory[itemIndex].isEquipped = 0;
						playerInfo.inventory[itemIndex].addAttack = 0;
						playerInfo.inventory[itemIndex].addDefense = 0;
						playerInfo.inventory[itemIndex].addHp = 10;
						playerInfo.inventory[itemIndex].addMana = 0;
						printstatus();
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("1. �κ��丮\n2. ���\n", 100);
						while (1) {


							printf("Enter: ");
							scanf("%d", &use);
							if (use == 1) {
								displayInventory();
								break;
							}
							else if(use == 2) {
								printf("------------------------------------------------------------------------------------------\n");
								printSlowly("��ҵǾ����ϴ�.\n", 100);
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
					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
						while (getchar() != '\n');

					}
				}
				itemIndex++;
				

				
				setColor(WHITE);
				printf("------------------------------------------------------------------------------------------\n");
				setColor(RED);
				printSlowly("�Ƹ�ī��Ʒ� ���ϴ� ��...\n", 200);
				setColor(WHITE);
				printSlowly("��â�� �� �ӿ��� ���� ���� ����� ������ ������ �߰��մϴ�.\n���ǿ��� �Ƹ�ī��Ʒ� ���ϴ� �濡 ���� ����� �۱Ͱ� ������ �ֽ��ϴ�.\n", 20);
				printSlowly("\"���ֹ��� ���� ����, ������ ������ ã�ƶ�. \n������ ��ȣ�ڸ� ����ġ��, �Ƹ�ī����� ���� �����.\"\n\n", 20);


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
						setColor(YELLOW);
						printSlowly("���� ����\n", 50);
						setColor(WHITE);
						printSlowly("����� ������ ����ħ�� ���� ���� �� ������ ����.\n���ֹ��� ���� ������ ������� �����ϴ�...\n�������� �Ⱬ�ϰ� ��Ʋ�� �ְ�, �� �ӿ��� �� �� ���� ����ü���� �����Ҹ��� ��� ������.\n", 20);
						printSlowly("���� ���� ��ġ�� ���ư��� ��, ���ڱ� �þ߿� ������ �������� ��Ÿ����. �̰��� �и� �ΰ��� �ձ��� ���� ���� ���� ����̴�.\n", 20);
						printSlowly("���� �Ѱ�� ���� ������ ���� �ְ�, �� ������ ������ ���ڰ� �����ִ�.\n", 20);
						setColor(YELLOW);
						printSlowly("60% : ����, 40 % : ����\n", 100);
						setColor(WHITE);
						int use = -1;
						
						// ������ ȹ�� Ȯ�� ���
						int itemChance = rand() % 100; // 0���� 99 ������ ���� ����
						if (itemChance < 60) { // 60% Ȯ���� ���� ȹ��
							printSlowly("���ڸ� ����� ������ ����ִ�.\n���� �������� ���� �߰��� ���δ�.\n", 30);
							strcpy(playerInfo.inventory[itemIndex].item, "���� ����");
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 1;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 0;
							playerInfo.inventory[itemIndex].addDefense = 5;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 0;
							printSlowly("1. �κ��丮\n2. ���\n", 100);
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("��ҵǾ����ϴ�.\n", 100);
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
									while (getchar() != '\n');
								}

							}

						}
						else { // 40% Ȯ���� ���ݷ� ���� ���� ȹ��
							printSlowly("���ڸ� ����� ������ ������ ����ִ�.\n", 70);
							strcpy(playerInfo.inventory[itemIndex].item, "������ ����");
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 2;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 10;
							playerInfo.inventory[itemIndex].addDefense = 0;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 0;
							printSlowly("1. �κ��丮\n2. ���\n", 100);
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("��ҵǾ����ϴ�.\n", 100);
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
									while (getchar() != '\n');
								}

							}


						}
						itemIndex++;
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�������� ȹ���� ����� �� �ӿ��� ���������� ������, ������ ������ ����� ������ ���ΰ� �ִ�...\n", 20);
						printSlowly("�� �ӿ��� ���𰡰� �����̴� �Ҹ��� �鸰��. ����� �߰����� ������ �̰��� ����������� �Ѵ�.\n", 20);

						//***1�� ���丮 �߰��ؾߵ�.***
						
						break;
					}
					else if (choice == 2) { //2�� ���丮

						setColor(RED);
						printSlowly("���� ��ȣ��\n", 50);
						setColor(WHITE);
						//���� ����ħ
						printSlowly("������ ����ħ�� �ǽ��ϸ� �ٸ� ���� ������ ����� ���� ��Ŵ� ���� �Ŵ��� ����, '�渮��'�� ����Ĩ�ϴ�. \n�渮���� ���� ��ȣ�ڷ�, �Ƹ�ī��Ʒ� ���ϴ� ���� ���� �ֽ��ϴ�.\n\n", 20);
						printMonster1();
						printSlowly("�̸�: ", 50);
						printSlowly(monster[0].name, 50);
						printf("\n");
						setColor(RED);
						printSlowly(" - HP: ", 50);
						printSlowly(StringvalueOf(monster[0].hp), 50);
						setColor(WHITE);
						printf("\n");
						printSlowly(" - ��ų: ", 50);
						printSlowly(monster[0].skill, 50);
						printf("\n");
						setColor(DARK_RED);
						printSlowly(" - ���ݷ�: ", 50);
						printSlowly(StringvalueOf(monster[0].attack), 50);
						setColor(WHITE);
						printf("\n");
						setColor(SKYBLUE);
						printSlowly(" - ����: ", 50);
						printSlowly(StringvalueOf(monster[0].defense), 50);
						setColor(WHITE);
						printf("\n\n");
						

						//�׸� �߰�: ����, ������, ����
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

						//���� ü��, ���ݷ�, ����, ���� ���
						int tempH = playerInfo.playerScharacterInfo.hp;
						int tempA = playerInfo.playerScharacterInfo.attack;
						int tempD = playerInfo.playerScharacterInfo.defense;
						int tempM = playerInfo.playerScharacterInfo.mana;

						if (battle(0) == true) { //0 = ���� �ε���
							//�¸��� ��� ���丮 ����
							playerInfo.playerScharacterInfo.hp = tempH;
							playerInfo.playerScharacterInfo.attack = tempA;
							playerInfo.playerScharacterInfo.defense = tempD;
							playerInfo.playerScharacterInfo.mana = tempM;
							//�������� ����� �ɷ�ġ ����




							break;
						}
						else {
							break; //�й�� return False
						}
						
					
						break;
					}


					else {
						printf("------------------------------------------------------------------------------------------\n");
						printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
						while (getchar() != '\n');
					}
					break; //
				}





			
				break; //���� ����
			}
			//���丮 ����: �ӽ�


			else if (st_ex == 2) {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("Game is closed!", 100);
				break;
			}
			else {
				printf("------------------------------------------------------------------------------------------\n");
				printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���.\n", 100);
				while (getchar() != '\n');
			}
			break; //���� ���� 2�� ����/���� ����
		}
		break; //hp ����/���� ����
	
	}

		if (st_ex != 2) {
		printSlowly("�÷��̾ ����߽��ϴ�.\n", 100);
		printSlowly("Game is closed!", 100);
		break;//���� ����/��� ���� ���� ����
		}

	}
	else if (lang == 2) {
		//���� �κ�
		system("title �����ذ��� / 11��");

		playerInfo.playerScharacterInfo.hp = 1;
		while (playerInfo.playerScharacterInfo.hp > 0) {
			srand(time(NULL));
			setColor(BLACK);
			int choice = -1;
			int charSel = -1;
			int itemIndex = 0;
			char title[50] = "The Secret of the Forgotten Kingdom"; //������ �ձ��� ���
			int totalWidth = 47;
			int strWidth = strlen(title);
			int padding = (totalWidth - strWidth) / 2;

			strcpy(monster[0].name, "Fenrir"); //ù ��° ����(�渮��)
			strcpy(monster[0].skill, "Take it down"); //�������
			monster[0].hp = 80;
			monster[0].attack = 20;
			monster[0].defense = 20;

			//�� ��° ����

			printf("------------------------------------------------------------------------------------------\n");
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
			for (int i = 0; i < padding; i++) {
				printf(" ");
			}
			printSlowly(title, 250);
			for (int i = 0; i < padding; i++) {
				printf(" ");
			}

			printSlowly("\n\n", 150);
			setColor(DARK_GREEN);

			printf("                               .--\"\"--.\n");
			printf("                              /        \\\n");
			printf("                             |   *  *  |\n");
			printf("                             \\  .--.  /\n");
			printf("                              '.____.'\n");
			printf("                                ||||\n");
			setColor(WHITE);

			printf("1. Start\n2. End\n"); //1.���� 2.����
			while (1) {



				printf("Enter: ");
				scanf("%d", &st_ex);
				if (st_ex == 1) {
					printf("------------------------------------------------------------------------------------------\n");
					printf("Please enter your name: \n"); //�̸��� �Է��ϼ���: 
					printf("Enter: ");
					scanf("%s", playerInfo.playerName);
					printf("------------------------------------------------------------------------------------------\n");
					printSlowly("Hello, ", 30); //�ȳ��ϼ���,
					printSlowly(playerInfo.playerName, 200);
					//printf("��!\n");
					printf("\n");
					printf("------------------------------------------------------------------------------------------\n");
					setColor(SKYBLUE);
					printSlowly("Tip. Open inventory is only possible when you acquire an item, so be careful!\n", 30); //Tip. �κ��丮 ����� �������� ȹ���Ͽ��� ���� �����ϴ� �����ϼ���!
					setColor(WHITE);
					printf("------------------------------------------------------------------------------------------\n");
					setColor(RED);
					printSlowly("Start...\n", 300); //����

					setColor(WHITE);
					printSlowly("Arcadia, an ancient kingdom hidden in a deep forest. This once prosperous kingdom is a dark wizard \nDestroyed by the curse of Maleficent, forgotten in people's memory. \nYou are an adventurer who happens to know Arcadia's existence. \nCan we uncover the secrets of the forgotten kingdom and unlock the curse of Maleficent to resurrect Arcadia?\n", 30);
					//���� �� �ӿ� ������ ��� �ձ�, '�Ƹ�ī���'. �Ѷ� �����ߴ� �� �ձ��� ����� ������ \n'�����Ǽ�Ʈ'�� ���ַ� ���� ����ϰ�, ������� ��� �ӿ��� ���������ϴ�. \n����� �쿬�� �Ƹ�ī����� ���縦 �˰� �� ���谡�Դϴ�. \n������ �ձ��� ����� �������� �����Ǽ�Ʈ�� ���ָ� Ǯ�� �Ƹ�ī��Ƹ� ��Ȱ��ų �� �������?
					printf("------------------------------------------------------------------------------------------\n");
					setColor(SKYBLUE);
					printSlowly("Tip. Warriors and bandits can use one skill per battle and the wizard consumes Mana 10 per skill.\n", 100); //Tip. ����� ������ ������ �� ���� ��ų�� ����� �� �ְ� ������� ��ų �� ���� ���� 10�� �Ҹ��մϴ�.
					setColor(WHITE);
					printf("------------------------------------------------------------------------------------------\n");
					printSlowly("Select a character:\n", 300); //ĳ���� ����:
					for (int i = 0; i < 3; i++) {
						setColor(i == 0 ? SKYBLUE : i == 1 ? YELLOW : RED);
						printSlowly(i == 0 ? "1. " : i == 1 ? "2. " : "3. ", 200);
						printSlowly(characterInfo[i].name, 200);
						printf(": ");
						setColor(WHITE);
						printSlowly(characterInfo[i].charState, 30);
						printf("\n");
					}
					while (1) {
						printf("Enter: ");
						scanf("%d", &charSel);
						int use = -1;
						strcpy(playerInfo.playerScharacterInfo.name, characterInfo[charSel - 1].name);
						strcpy(playerInfo.playerScharacterInfo.skill, characterInfo[charSel - 1].skill);
						strcpy(playerInfo.playerScharacterInfo.charState, characterInfo[charSel - 1].charState);
						playerInfo.playerScharacterInfo.hp = characterInfo[charSel - 1].hp;
						playerInfo.playerScharacterInfo.attack = characterInfo[charSel - 1].attack;
						playerInfo.playerScharacterInfo.defense = characterInfo[charSel - 1].defense;
						playerInfo.playerScharacterInfo.mana = characterInfo[charSel - 1].mana;

						if (charSel == 1) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("A \'wooden sword'\ was provided for sword fighter.\n", 30); //�˻縦 ���� \'���\'�� ���޵Ǿ����ϴ�.
							printf("------------------------------------------------------------------------------------------\n");

							strcpy(playerInfo.inventory[0].item, "A wooden sword"); //���
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 1;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 5;
							playerInfo.inventory[itemIndex].addDefense = 0;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 0;
							printstatus();
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("1. Inventory\n2. Cancellation\n", 100); //1. �κ��丮\n2. ���
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("Canceled.\n", 100); //��ҵǾ����ϴ�.
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
									while (getchar() != '\n');
								}

							}
							break;

						}
						else if (charSel == 2) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("A \'Wizard's Necklace\' has been provided for wizards.\n", 100); //�����縦 ���� \'�������� �����\'�� ���޵Ǿ����ϴ�.
							printf("------------------------------------------------------------------------------------------\n");
							strcpy(playerInfo.inventory[0].item, "The Wizard's Necklace"); //�������� �����
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 1;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 0;
							playerInfo.inventory[itemIndex].addDefense = 0;
							playerInfo.inventory[itemIndex].addHp = 0;
							playerInfo.inventory[itemIndex].addMana = 10;
							printstatus();
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("1. Inventory\n2. Cancellation\n", 100); //1.�κ��丮 2.���
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("Canceled.\n", 100); //��ҵǾ����ϴ�.
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
									while (getchar() != '\n');
								}

							}
							break;

						}
						else if (charSel == 3) {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("A 'Cloak of the Rogue' has been granted to the rogue.\n", 100); //������ ���� \'������ ����\'�� ���޵Ǿ����ϴ�.
							printf("------------------------------------------------------------------------------------------\n");
							strcpy(playerInfo.inventory[0].item, "A bandit's cloak"); //������ ����
							playerInfo.inventory[itemIndex].quantity = 1;
							playerInfo.inventory[itemIndex].type = 1;
							playerInfo.inventory[itemIndex].isEquipped = 0;
							playerInfo.inventory[itemIndex].addAttack = 0;
							playerInfo.inventory[itemIndex].addDefense = 0;
							playerInfo.inventory[itemIndex].addHp = 10;
							playerInfo.inventory[itemIndex].addMana = 0;
							printstatus();
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("1. Inventory\n2. Cancellation\n", 100); //1. �κ��丮\n2. ���\n
							while (1) {


								printf("Enter: ");
								scanf("%d", &use);
								if (use == 1) {
									displayInventory();
									break;
								}
								else if (use == 2) {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("Canceled.\n", 100); //��ҵǾ����ϴ�.
									break;
								}
								else {
									printf("------------------------------------------------------------------------------------------\n");
									printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
									while (getchar() != '\n');
								}

							}
							break;

						}
						else {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
							while (getchar() != '\n');

						}
					}
					itemIndex++;



					setColor(WHITE);
					printf("------------------------------------------------------------------------------------------\n");
					setColor(RED);
					printSlowly("On the way to Arcadia...\n", 200); //�Ƹ�ī��Ʒ� ���ϴ� ��...
					setColor(WHITE);
					printSlowly("Lost in the dense forest, you find an old lithograph.\nThere is a faint inscription on the stone tablet about the path to Arcadia.\n\n", 20); //��â�� �� �ӿ��� ���� ���� ����� ������ ������ �߰��մϴ�.\n���ǿ��� �Ƹ�ī��Ʒ� ���ϴ� �濡 ���� ����� �۱Ͱ� ������ �ֽ��ϴ�.\n
					printSlowly("Through the cursed forest, find a forgotten temple. \nDefeat the guardian of the temple, and open the door of Arcadia.\"\"\n\n", 20); //���ֹ��� ���� ����, ������ ������ ã�ƶ�. \n������ ��ȣ�ڸ� ����ġ��, �Ƹ�ī����� ���� �����.


					setColor(RED);
					printf("Select: \n"); //����
					setColor(WHITE);
					printSlowly("1. Head to the cursed forest.\n", 100); //1. ���ֹ��� ������ ���Ѵ�.
					printSlowly("2. Ignore the stone slab and find another path.\n", 100); //2. ������ �����ϰ� �ٸ� ���� ã�´�.
					while (1) {
						printf("Enter: ");
						scanf("%d", &choice);
						printf("------------------------------------------------------------------------------------------\n");
						if (choice == 1) { //1�� ���丮
							setColor(YELLOW);
							printSlowly("the treasure of the forest\n", 50); //���� ����
							setColor(WHITE);
							printSlowly("You have entered the deep forest following the instructions of the lithograph.\nCursed forests are full of dreary energy...\nThe trees are grotesquely twisted, and the cries of unknown creatures echo through the forest.\n", 20);
							//����� ������ ����ħ�� ���� ���� �� ������ ����.\n���ֹ��� ���� ������ ������� �����ϴ�...\n�������� �Ⱬ�ϰ� ��Ʋ�� �ְ�, �� �ӿ��� �� �� ���� ����ü���� �����Ҹ��� ��� ������.
							printSlowly("While wading through the deep forest, an old ruin suddenly appeared in sight. This place clearly appears to have been untouched by humans.\n", 20);
							//���� ���� ��ġ�� ���ư��� ��, ���ڱ� �þ߿� ������ �������� ��Ÿ����. �̰��� �и� �ΰ��� �ձ��� ���� ���� ���� ����̴�.
							printSlowly("There is a small altar in the middle of the ruins, and an unknown box is placed on top of it.\n", 20); //���� �Ѱ�� ���� ������ ���� �ְ�, �� ������ ������ ���ڰ� �����ִ�.
							setColor(YELLOW);
							printSlowly("60%: Armor, 40%: Potion\n", 100); //60% : ����, 40 % : ����
							setColor(WHITE);
							int use = -1;

							// ������ ȹ�� Ȯ�� ���
							int itemChance = rand() % 100; // 0���� 99 ������ ���� ����
							if (itemChance < 60) { // 60% Ȯ���� ���� ȹ��
								printSlowly("When I opened the box, there was armor inside.\nIt looks old, but still seems sturdy.\n", 30); //���ڸ� ����� ������ ����ִ�.\n���� �������� ���� �߰��� ���δ�.\n
								strcpy(playerInfo.inventory[itemIndex].item, "A old armor"); //���� ����
								playerInfo.inventory[itemIndex].quantity = 1;
								playerInfo.inventory[itemIndex].type = 1;
								playerInfo.inventory[itemIndex].isEquipped = 0;
								playerInfo.inventory[itemIndex].addAttack = 0;
								playerInfo.inventory[itemIndex].addDefense = 5;
								playerInfo.inventory[itemIndex].addHp = 0;
								playerInfo.inventory[itemIndex].addMana = 0;
								printSlowly("1. Inventory\n2. Cancellation\n", 100); //1. �κ��丮\n2. ���\n
								while (1) {


									printf("Enter: ");
									scanf("%d", &use);
									if (use == 1) {
										displayInventory();
										break;
									}
									else if (use == 2) {
										printf("------------------------------------------------------------------------------------------\n");
										printSlowly("Canceled.\n", 100); //��ҵǾ����ϴ�.
										break;
									}
									else {
										printf("------------------------------------------------------------------------------------------\n");
										printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
										while (getchar() != '\n');
									}

								}

							}
							else { // 40% Ȯ���� ���ݷ� ���� ���� ȹ��
								printSlowly("When I opened the box, there was a glowing potion inside.\n", 70); //���ڸ� ����� ������ ������ ����ִ�.
								strcpy(playerInfo.inventory[itemIndex].item, "A glowing potion"); //������ ����(���ô� ����)
								playerInfo.inventory[itemIndex].quantity = 1;
								playerInfo.inventory[itemIndex].type = 2;
								playerInfo.inventory[itemIndex].isEquipped = 0;
								playerInfo.inventory[itemIndex].addAttack = 10;
								playerInfo.inventory[itemIndex].addDefense = 0;
								playerInfo.inventory[itemIndex].addHp = 0;
								playerInfo.inventory[itemIndex].addMana = 0;
								printSlowly("1. Inventory\n2. Cancellation\n", 100); //1. �κ��丮\n2. ���\n
								while (1) {


									printf("Enter: ");
									scanf("%d", &use);
									if (use == 1) {
										displayInventory();
										break;
									}
									else if (use == 2) {
										printf("------------------------------------------------------------------------------------------\n");
										printSlowly("Canceled.\n", 100); //��ҵǾ����ϴ�.
										break;
									}
									else {
										printf("------------------------------------------------------------------------------------------\n");
										printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
										while (getchar() != '\n');
									}

								}


							}
							itemIndex++;
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("After acquiring the item, you try to escape from the forest, but a gloomy energy still surrounds you...\n", 20); //�������� ȹ���� ����� �� �ӿ��� ���������� ������, ������ ������ ����� ������ ���ΰ� �ִ�...
							printSlowly("I hear something moving in the forest. You decide to hurry up and get out of here.\n", 20); //�� �ӿ��� ���𰡰� �����̴� �Ҹ��� �鸰��. ����� �߰����� ������ �̰��� ����������� �Ѵ�.

							//***1�� ���丮 �߰��ؾߵ�.***

							break;
						}
						else if (choice == 2) { //2�� ���丮

							setColor(RED);
							printSlowly("guardian of the forest\n", 50); //���� ��ȣ��
							setColor(WHITE);
							//���� ����ħ
							printSlowly("Doubting the teachings of the stone tablets and choosing a different path, you encounter the huge monster ��Fenrir�� while wandering through the forest. \nFenrir is the guardian of the forest, blocking the road to Arcadia.\n\n", 20);
							//������ ����ħ�� �ǽ��ϸ� �ٸ� ���� ������ ����� ���� ��Ŵ� ���� �Ŵ��� ����, '�渮��'�� ����Ĩ�ϴ�. \n�渮���� ���� ��ȣ�ڷ�, �Ƹ�ī��Ʒ� ���ϴ� ���� ���� �ֽ��ϴ�.
							printMonster1();
							printSlowly("Name: ", 50);
							printSlowly(monster[0].name, 50);
							printf("\n");
							setColor(RED);
							printSlowly(" - HP: ", 50);
							printSlowly(StringvalueOf(monster[0].hp), 50);
							setColor(WHITE);
							printf("\n");
							printSlowly(" - Skill: ", 50);
							printSlowly(monster[0].skill, 50);
							printf("\n");
							setColor(DARK_RED);
							printSlowly(" - ATK: ", 50); //Attack��� ���� ���
							printSlowly(StringvalueOf(monster[0].attack), 50);
							setColor(WHITE);
							printf("\n");
							setColor(SKYBLUE);
							printSlowly(" - DEF: ", 50); //Defense��� ���� ���
							printSlowly(StringvalueOf(monster[0].defense), 50);
							setColor(WHITE);
							printf("\n\n");


							//�׸� �߰�: ����, ������, ����
							drawChar();
							printstatus();

							//���� ü��, ���ݷ�, ����, ���� ���
							int tempH = playerInfo.playerScharacterInfo.hp;
							int tempA = playerInfo.playerScharacterInfo.attack;
							int tempD = playerInfo.playerScharacterInfo.defense;
							int tempM = playerInfo.playerScharacterInfo.mana;

							if (battle(0) == true) { //0 = ���� �ε���
								//�¸��� ��� ���丮 ����
								playerInfo.playerScharacterInfo.hp = tempH;
								playerInfo.playerScharacterInfo.attack = tempA;
								playerInfo.playerScharacterInfo.defense = tempD;
								playerInfo.playerScharacterInfo.mana = tempM;
								//�������� ����� �ɷ�ġ ����




								break;
							}
							else {
								break; //�й�� return False
							}


							break;
						}


						else {
							printf("------------------------------------------------------------------------------------------\n");
							printSlowly("It's a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
							while (getchar() != '\n');
						}
						break; //
					}






					break; //���� ����
				}
				//���丮 ����: �ӽ�


				else if (st_ex == 2) {
					printf("------------------------------------------------------------------------------------------\n");
					printSlowly("Game is closed!", 100);
					break;
				}
				else {
					printf("------------------------------------------------------------------------------------------\n");
					printSlowly("It\'s a wrong choice. Please select again.\n", 100); //�߸��� �����Դϴ�. �ٽ� �������ּ���.
					while (getchar() != '\n');
				}
				break; //���� ���� 2�� ����/���� ����
			}
			break; //hp ����/���� ����

		}

		if (st_ex != 2) {
			printSlowly("The player has died.\n", 100);
			printSlowly("Game is closed!", 100);
			break;//���� ����/��� ���� ���� ����
		}






		break; //���� ����/���� �κ�
		}
		else {
		printf("------------------------------------------------------------------------------------------\n");
		printSlowly("�߸��� �����Դϴ�. �ٽ� �������ּ���. / It\'s a wrong choice. Please select again.\n", 100);
		while (getchar() != '\n');
		}
		break; //���� ����/��� ���� ����
	}

}