#include "header.h"

void modifyBike(Bike *b) {
	FILE *f;
}

void deleteBike(Bike *b) {
	FILE *f;
	int select;

	printf("\t\t\t[������ ���� �ý���]\n\n");
	printf("�ڷΰ��⸦ ���Ͻø� :b �� �Է��Ͻʽÿ�.\n\n");
	printBikeStock(b);

	while (true) {
		printf(" ������ index�� �Է����ּ��� : ");
		scanf_s("%d", &select);
		if (select >= 0 && select < bikeIndexMax) {
			while (select < bikeIndexMax) {
				strcpy_s(b[select].model, sizeof(b[select].model), b[select + 1].model);
				strcpy_s(b[select].manufacturer, sizeof(b[select].manufacturer), b[select + 1].manufacturer);
				strcpy_s(b[select].insertDate, sizeof(b[select].insertDate), b[select + 1].insertDate);
				select++;
			}
			if (fopen_s(&f, FNAME, "w") != 0) {
				system("cls");
				printf("�ش� ������ ���� ���߽��ϴ�.\n");
				exit(1);
			}
			for (int i = 0; i < bikeIndexMax - 1; i++) {
				fprintf(f, "%d %s %s %s", i, b[i].model, b[i].manufacturer, b[i].insertDate);
			}
			fclose(f);
			system("cls");
			break;
		}
		else {
			printf(" 0 ~ %d �� �Է����ּ���.\n\n", bikeIndexMax - 1);
		}
	}
}

void addBike(Bike* b) {
	FILE *f;
	char strBuffer[256] = "\n";
	char index[10];
	char input[30];
	char input2[30];

	char *delimeter = "-";
	char *strTemp = NULL;
	char *next = NULL;
	int numTemp = 0;

	_itoa_s(bikeIndexMax, index, sizeof(index), 10);

	printf("\t\t\t[������ �߰� �ý���]\n\n");
	printf("�ڷΰ��⸦ ���Ͻø� :b �� �Է��Ͻʽÿ�.\n\n");
	printBikeStock(b);
	strcat_s(strBuffer, sizeof(strBuffer), index);

	bool checkModel = true;
	while (checkModel) {
		printf(" �𵨸��� �Է��ϼ��� : ");
		gets_s(input, sizeof(input));

		if (pageBack(input)) {
			system("cls");
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("\t<������ �Է��� �� �����ϴ�!>\n\n");
			continue;
		}
		int i = 0;
		while (i < bikeIndexMax) {
			if (!strcmp(input, b[i].model)) {
				printf("�ش� %s ���� �̹� �����մϴ�.\n\n", b[i].model);
				checkModel = true;
				break;
			}
			i++;
			checkModel = false;
		}
	}
	strcat_s(strBuffer, sizeof(strBuffer), " ");
	strcat_s(strBuffer, sizeof(strBuffer), input);

	bool checkManufacturer = true;
	while (checkManufacturer) {
		printf("\n �����縦 �Է��ϼ��� : ");
		gets_s(input, sizeof(input));

		if (pageBack(input)) {
			system("cls");
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("<������ �Է��� �� �����ϴ�!>\n\n");
		}
		else {
			checkManufacturer = false;
		}
	}
	strcat_s(strBuffer, sizeof(strBuffer), " ");
	strcat_s(strBuffer, sizeof(strBuffer), input);

	bool checkDate = true;
	while (checkDate) {
		printf("\n ������ ��¥�� �Է��ϼ���\n");
		printf(" ex) 2020-05-05\n");
		printf(" ��¥ : ");
		gets_s(input, sizeof(input));
		strcpy_s(input2, sizeof(input2), input);

		if (pageBack(input)) {
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("<������ �Է��� �� �����ϴ�!>\n\n");
		}
		else {
			if (!(input[4] == '-' && input[7] == '-')) {
				printf("<���Ŀ� �°� �Է����ּ���!>\n\n");
			}
			else {
				strTemp = strtok_s(input, delimeter, &next);
				if (!(atoi(strTemp) >= 1000 && atoi(strTemp) <= 2021)) {
					printf("1000 ~ 2021 ������ �⵵�� �������ּ���.\n\n ");
					continue;
				}
				else {
					strTemp = strtok_s(NULL, delimeter, &next);
					if (!(atoi(strTemp) >= 1 && atoi(strTemp) <= 12)) {
						printf("1 ~ 12 ������ ���� �������ּ���.\n\n");
						continue;
					}
					else {
						if (!(atoi(next) >= 1 && atoi(next) <= 31)) {
							printf("1 ~ 31 ������ ���� �������ּ���.\n\n");
							continue;
						}
						else {
							checkDate = false;
						}
					}
				}
			}
		}
	}
	strcat_s(strBuffer, sizeof(strBuffer), " ");
	strcat_s(strBuffer, sizeof(strBuffer), input2);

	if (fopen_s(&f, FNAME, "a") != 0) {
		system("cls");
		printf("������ ���� ���߽��ϴ�.\n");
		exit(1);
	}
	fputs(strBuffer, f);
	fclose(f);
	system("cls");
	printf("\t\t\t[�߰��Ϸ�]\n");
}

int pageBack(char *input) {
	if (!strcmp(input, ":b")) {
		return 1;
	}
	else {
		return 0;
	}
}



