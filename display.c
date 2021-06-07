#include "header.h"

void modifyBike(Bike *b) {
	FILE *f;
	char input[30];
	char choice[30];
	int select;

	printf("\n\t\t\t[������ ���� ���� �ý���]\n\n");
	printf("�ڷΰ��⸦ ���Ͻø� :b �� �Է��Ͻʽÿ�.\n\n");
	printBikeStock(b);

	while (true) {
		printf(" ������ index�� �Է����ּ��� : ");
		gets_s(choice, sizeof(choice));
		if (pageBack(choice)) {
			system("cls");
			return;
		}
		select = atoi(choice);
		if (select >= 0 && select < bikeIndexMax) {
			while (true) {
				printf("\n1. �𵨸��� �ٲٽðڽ��ϱ�?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" ���ο� �𵨸��� �Է����ּ��� : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<������ �Է��� �� �����ϴ�!>\n\n");
						}
						else {
							break;
						}
					}
					strcpy_s(b[select].model, sizeof(b[select].model), input);
					break;
				}
				else if (*choice == 'n' || *choice == 'N') {
					break;
				}
			}

			while (true) {
				printf("\n2. ��������� �ٲٽðڽ��ϱ�?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" ���ο� ��������� �Է����ּ��� : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<������ �Է��� �� �����ϴ�!>\n\n");
						}
						else {
							break;
						}
					}
					strcpy_s(b[select].manufacture, sizeof(b[select].manufacture), input);
					break;
				}
				else if (*choice == 'n' || *choice == 'N') {
					break;
				}
			}

			while (true) {
				printf("\n3. ������¥�� �ٲٽðڽ��ϱ�?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" ���ο� ������¥�� �Է����ּ��� : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<������ �Է��� �� �����ϴ�!>\n\n");
						}
						else {
							break;
						}
					}
					strcpy_s(b[select].insertDate, sizeof(b[select].insertDate), input);
					break;
				}
				else if (*choice == 'n' || *choice == 'N') {
					break;
				}
			}
			if (fopen_s(&f, FNAME, "w") != 0) {
				system("cls");
				printf("������ ���� ���߽��ϴ�.\n");
				exit(1);
			}
			for (int i = 0; i < bikeIndexMax; i++) {
				fprintf(f, "%d %s %s %s", i, b[i].model, b[i].manufacture, b[i].insertDate);
				if (i < bikeIndexMax - 1) {
					fprintf(f, "\n");
				}
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

void deleteBike(Bike *b) {
	FILE *f;
	char choice[30];
	int select;

	printf("\n\t\t\t[������ ���� ���� �ý���]\n\n");
	printf("�ڷΰ��⸦ ���Ͻø� :b �� �Է��Ͻʽÿ�.\n\n");
	printBikeStock(b);

	while (true) {
		printf(" ������ index�� �Է����ּ��� : ");
		gets_s(choice, sizeof(choice));
		if (pageBack(choice)) {
			system("cls");
			return;
		}
		select = atoi(choice);
		if (select >= 0 && select < bikeIndexMax) {
			while (select < bikeIndexMax) {
				strcpy_s(b[select].model, sizeof(b[select].model), b[select + 1].model);
				strcpy_s(b[select].manufacture, sizeof(b[select].manufacture), b[select + 1].manufacture);
				strcpy_s(b[select].insertDate, sizeof(b[select].insertDate), b[select + 1].insertDate);
				select++;
			}
			if (fopen_s(&f, FNAME, "w") != 0) {
				system("cls");
				printf("�ش� ������ ���� ���߽��ϴ�.\n");
				exit(1);
			}
			for (int i = 0; i < bikeIndexMax - 1; i++) {
				fprintf(f, "%d %s %s %s", i, b[i].model, b[i].manufacture, b[i].insertDate);
				if (i < bikeIndexMax - 2) {
					fprintf(f, "\n");
				}
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

void addBike(Bike *b) {
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

	bool checkmanufacture = true;
	while (checkmanufacture) {
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
			checkmanufacture = false;
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

void loginDisplay(char *id, char *pwd) {
	printf("------------------------------------------------------------------\n");
	printf("\t\t\t[�α��� ������]\t\t\n");
	printf("\t\t\t\t\t���α׷� ����(ctrl+c)\n\n");
	printf("\tid  : ");
	gets_s(id, sizeof(id));
	printf("\tpwd : ");
	gets_s(pwd, sizeof(pwd));
}

void displayMenu(char *loginId) {
	printf("\n\t\t\t[������ ��� ��Ȳ �ý���]\t\t\t\t\n\n");
	printf("\t1. ������ ��� �߰�\n");
	printf("\t2. ������ ���� ����\n");
	printf("\t3. ������ ���� ����\n");
	printf("\tq. �α׾ƿ�(���α׷� ����)\n\n");
	printf("    %s�� ȯ���մϴ� !\n\n", loginId);
	printf("    ����� �Է��ϼ��� : ");
}

void printBikeStock(Bike* b) {
	printf("%4s\t%8s\t  %9s\t%18s\n", "Index", "Model", "Manufacture", "InsertDate");
	for (int i = 0; i < bikeIndexMax; i++) {
		printf("%4d\t%8s\t%9s\t%18s\n", b[i].index, b[i].model, b[i].manufacture, b[i].insertDate);
	}
	printf("\n------------------------------------------------------------------\n");
}