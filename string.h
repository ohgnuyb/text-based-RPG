#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

void printSlowly(const char* text, int delay) { //print 문자열 하나하나 천천히
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