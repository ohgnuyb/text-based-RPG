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

void drawWarrior_en() {
    setColor(SKYBLUE);
    for (int i = 0; i < 10; i++) {
        if (strcmp(playerInfo.inventory[i].item, "A wooden sword") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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

void drawMage_en() {
    setColor(YELLOW);
    printf("==== *\n");
    setColor(WHITE);
    printf("\\  O\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(playerInfo.inventory[i].item, "The Wizard's Necklace") == 0 && playerInfo.inventory[i].isEquipped == 1) {
            setColor(BLUE);
        }
    }
    printf("  \\|\\\n");
    setColor(WHITE);
    printf("  / \\\n");
    printf(" /   \\\n");
    printf("\n");
}

void drawRogue_en() {
    printf("   O\n");
    for (int i = 0; i < 10; i++) {
        if (strcmp(playerInfo.inventory[i].item, "A bandit's cloak") == 0 && playerInfo.inventory[i].isEquipped == 1) {
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

void drawChar_en() {
    if (strcmp(playerInfo.playerScharacterInfo.name, "Warrior") == 0) {
        drawWarrior_en();
    }
    else if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
        drawMage_en();
    }
    else if (strcmp(playerInfo.playerScharacterInfo.name, "Rogue") == 0) {
        drawRogue_en();
    }
    else {
        //추가 캐릭터
    }
}




void displayInventory_en() {
    int selected = 0;

    while (1) { // while 루프를 사용하여 반복
        selected = 0; // selected 값 초기화
        printf("------------------------------------------------------------------------------------------\n");
        setColor(YELLOW);
        printf("===== Inventory =====\n");
        setColor(WHITE);
        for (int i = 0; i < 10; i++) {
            if (playerInfo.inventory[i].quantity > 0) {
                if (playerInfo.inventory[i].isEquipped == 1) {
                    printf("%d. %s: %d / Mounting\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
                }
                else {
                    if (playerInfo.inventory[i].type == 2) {
                        printf("%d. %s: %d / Not used\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
                    }
                    else {
                        printf("%d. %s: %d / Not installed\n", i + 1, playerInfo.inventory[i].item, playerInfo.inventory[i].quantity);
                    }
                }

                selected++;
            }
        }

        if (selected == 0) {
            printSlowly("Inventory is empty.\n", 30);
            break; // 인벤토리가 비어있으면 while 루프 종료
        }

        int selectedIndex = 0;
        printf("------------------------------------------------------------------------------------------\n");
        printSlowly("Which item do you want to select?\n0. Get out\n", 30);

        while (1) {
            printf("Enter: ");
            scanf("%d", &selectedIndex);

            if (selectedIndex <= selected && selectedIndex != 0) {
                printf("------------------------------------------------------------------------------------------\n");
                printSlowly("Selected Items: ", 30);
                printSlowly(playerInfo.inventory[selectedIndex - 1].item, 30);
                printf("\n");
                printf("------------------------------------------------------------------------------------------\n");
                printf("1. Install/Use\n2. Unfit (Equipment)\n3. Cancel\n");
                int temp = 0;
                while (1) {
                    printf("Enter: ");
                    scanf("%d", &temp);
                    if (temp == 1) {
                        if (playerInfo.inventory[selectedIndex - 1].isEquipped == 1) {
                            printf("------------------------------------------------------------------------------------------\n");
                            printSlowly("It's already being installed.\n", 30);
                            break;
                        }
                        else if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
                            if (playerInfo.inventory[selectedIndex - 1].type == 2) {
                                if (playerInfo.inventory[selectedIndex - 1].addMana > 0 && strcmp(playerInfo.playerScharacterInfo.name, "Wizard") != 0) {
                                    printSlowly("Mana Growth Potion is available only to wizards.\n", 100);
                                }
                                else {
                                    playerInfo.inventory[selectedIndex - 1].quantity--;
                                    printf("------------------------------------------------------------------------------------------\n");
                                    printSlowly("Potion was used. / Duration of 5 minutes\n", 30);
                                }
                                if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
                                    setColor(RED);
                                    printSlowly("HP: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
                                    setColor(SKYBLUE);
                                    printSlowly("DEFr: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
                                    setColor(DARK_RED);
                                    printSlowly("ATK: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
                                    if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
                                        setColor(BLUE);
                                        printSlowly("Mana: +", 30);
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
                                printSlowly("I'm wearing the equipment.\n", 30);
                                if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
                                    setColor(RED);
                                    printSlowly("HP: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
                                    setColor(SKYBLUE);
                                    printSlowly("DEF: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
                                    setColor(DARK_RED);
                                    printSlowly("ATKr: +", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
                                    if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
                                        setColor(BLUE);
                                        printSlowly("Mana: +", 30);
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
                            printSlowly("Potion cannot be unmounted.\n", 30);

                        }
                        else if (playerInfo.inventory[selectedIndex - 1].type == 1) {
                            if (playerInfo.inventory[selectedIndex - 1].isEquipped == 0) {
                                printf("------------------------------------------------------------------------------------------\n");
                                printSlowly("It is not already installed.\n", 30);
                                break;
                            }
                            else {
                                printf("------------------------------------------------------------------------------------------\n");
                                printSlowly("The equipment has been uninstalled.\n", 30);
                                if (playerInfo.inventory[selectedIndex - 1].addHp > 0) {
                                    setColor(RED);
                                    printSlowly("HP: -", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addHp), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addDefense > 0) {
                                    setColor(SKYBLUE);
                                    printSlowly("DEF: -", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addAttack > 0) {
                                    setColor(DARK_RED);
                                    printSlowly("ATK: -", 30);
                                    printSlowly(StringvalueOf(playerInfo.inventory[selectedIndex - 1].addAttack), 100);
                                    printf("\n");
                                    setColor(WHITE);
                                }
                                else if (playerInfo.inventory[selectedIndex - 1].addMana > 0) {
                                    if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
                                        setColor(BLUE);
                                        printSlowly("Mana: -", 30);
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
                        printf("It has been canceled.\n");
                        break;
                    }
                    else {
                        printf("------------------------------------------------------------------------------------------\n");
                        printSlowly("Invalid selection, please re-select.\n", 30);
                        while (getchar() != '\n');
                    }
                }

                break; // 아이템 장착/사용 후 루프 종료
            }
            else if (selectedIndex == 0) {
                printf("------------------------------------------------------------------------------------------\n");
                drawChar_en();

                printSlowly("Mr/Ms ", 200);
                printSlowly(playerInfo.playerName, 200);
                printSlowly(": ", 200);
                printSlowly(playerInfo.playerScharacterInfo.name, 200);
                printf("!\n");

                setColor(RED);
                printSlowly(" - HP: ", 100);
                printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
                printf("\n");

                setColor(WHITE);
                printSlowly(" - Skill: ", 100);
                printSlowly(playerInfo.playerScharacterInfo.skill, 100);
                printf("\n");
                setColor(DARK_RED);
                printSlowly(" - ATKr: ", 100);
                printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
                setColor(WHITE);
                printf("\n");
                setColor(SKYBLUE);
                printSlowly(" - DEF: ", 100);
                printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
                setColor(WHITE);
                printf("\n");
                if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
                    setColor(BLUE);
                    printSlowly(" - Mana: ", 100);
                    printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
                    printf("\n");
                    setColor(WHITE);
                }
                return; // 인벤토리 종료 후 함수 종료
            }
            else {
                printf("------------------------------------------------------------------------------------------\n");
                printSlowly("Invalid choice, please re-select.\n", 30);
                while (getchar() != '\n');
            }
        }
    }
}





void printstatus_en() {
    drawChar_en();
    printSlowly(playerInfo.playerName, 200);
    printSlowly("\'s chocie: ", 200);
    printSlowly(playerInfo.playerScharacterInfo.name, 200);
    printf("!\n");

    setColor(RED);
    printSlowly(" - HP: ", 100);
    printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.hp), 100);
    printf("\n");

    setColor(WHITE);
    printSlowly(" - Skill: ", 100);
    printSlowly(playerInfo.playerScharacterInfo.skill, 100);
    printf("\n");
    setColor(DARK_RED);
    printSlowly(" - ATK: ", 100);
    printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.attack), 100);
    setColor(WHITE);
    printf("\n");
    setColor(SKYBLUE);
    printSlowly(" - DEF: ", 100);
    printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.defense), 100);
    setColor(WHITE);
    printf("\n");
    if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
        setColor(BLUE);
        printSlowly(" - Mana: ", 100);
        printSlowly(StringvalueOf(playerInfo.playerScharacterInfo.mana), 100);
        printf("\n");
        setColor(WHITE);
    }
}


void useSkill_en(int monsterIndex, int* skillIndex, int* con) { //스킬 데미지는 캐릭터의 현재 공격력 * 2
    //마법사는 마나 -=10 / 도적은 공격이 아니라 방어력 100으로 은신 구현
    if (*skillIndex == 0 && strcmp(playerInfo.playerScharacterInfo.name, "Wizard") != 0) {
        printf("------------------------------------------------------------------------------------------\n");
        printSlowly("Using Skills: ", 100);
        if (strcmp(playerInfo.playerScharacterInfo.name, "Warrior") == 0) {
            setColor(SKYBLUE);
        }
        else if (strcmp(playerInfo.playerScharacterInfo.name, "Rogue") == 0) {
            setColor(RED);
        }
        else {
            //추가 캐릭터
        }
        int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
        printSlowly(playerInfo.playerScharacterInfo.skill, 100);
        setColor(WHITE);
        printSlowly("!\n", 100);
        printSlowly("Skill was used on ", 50);
        printSlowly(monster[monsterIndex].name, 50);
        printSlowly("\damage: ", 50);
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
        printSlowly("Number of Available: 0\n", 30);


    }
    else if (strcmp(playerInfo.playerScharacterInfo.name, "Wizard") == 0) {
        int skillMage = playerInfo.playerScharacterInfo.mana / 10;
        if (skillMage > 0) {
            printf("------------------------------------------------------------------------------------------\n");
            printSlowly("Using Skills: ", 100);
            setColor(VIOLET);
            int damage = (playerInfo.playerScharacterInfo.attack * 2) - (monster[monsterIndex].defense * DEFENSE_RATE);
            printSlowly(playerInfo.playerScharacterInfo.skill, 100);
            setColor(WHITE);
            printSlowly("!\n", 100);
            printSlowly("Skill was used on: ", 50);
            printSlowly(monster[monsterIndex].name, 50);
            printSlowly("Mana: ", 50);
            setColor(BLUE);
            printSlowly("-10", 50);
            setColor(WHITE);
            printSlowly("\nDamages: ", 50);
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
            printSlowly("I'm running out of mana. / \n", 100);
            setColor(BLUE);
            printSlowly("The amount of manna required: 10 \n", 100);
            setColor(WHITE);

        }
    }
    else {
        printf("------------------------------------------------------------------------------------------\n");
        printSlowly("You have already used the skill.\n", 100);
        printf("------------------------------------------------------------------------------------------\n");
        *con = -1;
    }

}
bool battle_en(int monsterIndex) {
    int turn = 0;
    int defenseTurn = 0; //0. 방어 안 함, 1. 방어 상태
    int skillIndex = 0;
    int con = 0;
    while (playerInfo.playerScharacterInfo.hp > 0 && monster[monsterIndex].hp > 0) {

        printf("------------------------------------------------------------------------------------------\n");
        setColor(SKYBLUE);
        printSlowly("Tip. Probability in attack - Critical hit: 20%, Minor strike: 20%, General attack: 60% / Critical hit ratio: 150%, Minor strike: 60%\n", 100);

        printSlowly("Tip. In case of defense and attack, attack with 60% of the basic damage.\n", 100);
        setColor(WHITE);
        printf("------------------------------------------------------------------------------------------\n");
        setColor(YELLOW);
        printf("===== The battle begins =====\n");
        setColor(WHITE);
        turn = 0;
        while (1) {
            int playerChoice;
            if (turn > 0) {
                setColor(YELLOW);
                printf("-- Next turn --\n");
            }
            setColor(WHITE);
            con = 0;
            printSlowly("1. Attacks\n2. Defensive & Attacking\n3. Skill \n", 100);
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
                    printSlowly("Critical hit trigger!\n", 100);
                    damage *= 1.5;
                    monster[monsterIndex].hp -= damage;
                    setColor(VIOLET);
                    printSlowly(monster[monsterIndex].name, 100);
                    setColor(WHITE);
                    printSlowly(" has been attacked.\nDamage: ", 100);
                }
                else if (damageRatio < 40) {
                    // Minor miss
                    setColor(BLUE);
                    printSlowly("Oh no! The attack missed.\n", 100);
                    damage *= 0.6;
                    monster[monsterIndex].hp -= damage;
                    setColor(VIOLET);
                    printSlowly(monster[monsterIndex].name, 100);
                    setColor(WHITE);
                    printSlowly(" has been attacked.\nDamage: ", 100);

                }
                else {
                    // Normal
                    damage *= 1.0;
                    monster[monsterIndex].hp -= damage;
                    setColor(VIOLET);
                    printSlowly(monster[monsterIndex].name, 100);
                    setColor(WHITE);
                    printSlowly(" has been attacked.\nDamage: ", 100);
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
                // Player defends
                defenseTurn = 1;
                printf("------------------------------------------------------------------------------------------\n");
                printSlowly("The player assumes a defensive stance.\n", 50);
                setColor(SKYBLUE);
                printSlowly("Temporary Defense: +50\n", 50);
                setColor(VIOLET);
                printSlowly(monster[monsterIndex].name, 100);
                setColor(WHITE);
                printSlowly(" has been attacked.\nDamage: ", 100);
                playerInfo.playerScharacterInfo.defense += 50;
                setColor(WHITE);
                // Attack during defense
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

                useSkill_en(monsterIndex, &skillIndex, &con);


            }
            else {
                printf("------------------------------------------------------------------------------------------\n");
                printSlowly("Invalid choice. Please choose again.\n", 100);
                while (getchar() != '\n');
            }
            // Monster's turn
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
                    printSlowly(" attacks ", 100);
                    printSlowly(playerInfo.playerName, 100);
                    printSlowly("!\nDamage: ", 100);
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
        printSlowly("Victory!\n", 40);
        setColor(WHITE);
        printf("------------------------------------------------------------------------------------------\n");
        return true;
    }
    else {
        printf("------------------------------------------------------------------------------------------\n");
        setColor(VIOLET);
        printSlowly(monster[monsterIndex].name, 100);
        setColor(DARK_GRAY);
        printSlowly(" defeated you...\n", 100);
        setColor(WHITE);
        printf("------------------------------------------------------------------------------------------\n");
        return false;
    }
}

