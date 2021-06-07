#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>

#define LNAME "User.txt"
#define FNAME "Stock.txt"

extern int bikeIndexMax;

typedef struct {
	int index;						// index��ȣ
	char model[30];					// �𵨸�
	char manufacture[30];			// ������
	char insertDate[15];			// ������		ex) 2021 - 06 - 02	
} Bike;

typedef struct {
	char id[30];
	char pwd[30];
} Login;

// display
void addBike(Bike *b);
void modifyBike(Bike *b);
void deleteBike(Bike *b);
void loginDisplay(char *id, char *pwd);
void displayMenu(char* loginId);
void printBikeStock(Bike* b);


// controller
int pageBack(char *input);