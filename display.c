#include "header.h"

void modifyBike(Bike *b) {
	FILE *f;
	char input[30];
	char choice[30];
	int select;

	printf("\n\t\t\t[자전거 정보 수정 시스템]\n\n");
	printf("뒤로가기를 원하시면 :b 를 입력하십시오.\n\n");
	printBikeStock(b);

	while (true) {
		printf(" 수정할 index를 입력해주세요 : ");
		gets_s(choice, sizeof(choice));
		if (pageBack(choice)) {
			system("cls");
			return;
		}
		select = atoi(choice);
		if (select >= 0 && select < bikeIndexMax) {
			while (true) {
				printf("\n1. 모델명을 바꾸시겠습니까?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" 새로운 모델명을 입력해주세요 : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<공백은 입력할 수 없습니다!>\n\n");
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
				printf("\n2. 제조사명을 바꾸시겠습니까?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" 새로운 제조사명을 입력해주세요 : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<공백은 입력할 수 없습니다!>\n\n");
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
				printf("\n3. 제조날짜를 바꾸시겠습니까?(y / n) : ");
				gets_s(choice, sizeof(choice));
				if (*choice == 'y' || *choice == 'Y') {
					while (true) {
						printf(" 새로운 제조날짜를 입력해주세요 : ");
						gets_s(input, sizeof(input));

						if (pageBack(input)) {
							system("cls");
							return;
						}
						if (*input == '\0' || *input == ' ') {
							printf("<공백은 입력할 수 없습니다!>\n\n");
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
				printf("파일을 열지 못했습니다.\n");
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
			printf(" 0 ~ %d 중 입력해주세요.\n\n", bikeIndexMax - 1);
		}
	}
}

void deleteBike(Bike *b) {
	FILE *f;
	char choice[30];
	int select;

	printf("\n\t\t\t[자전거 정보 삭제 시스템]\n\n");
	printf("뒤로가기를 원하시면 :b 를 입력하십시오.\n\n");
	printBikeStock(b);

	while (true) {
		printf(" 삭제할 index를 입력해주세요 : ");
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
				printf("해당 파일을 열지 못했습니다.\n");
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
			printf(" 0 ~ %d 중 입력해주세요.\n\n", bikeIndexMax - 1);
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

	printf("\t\t\t[자전거 추가 시스템]\n\n");
	printf("뒤로가기를 원하시면 :b 를 입력하십시오.\n\n");
	printBikeStock(b);
	strcat_s(strBuffer, sizeof(strBuffer), index);

	bool checkModel = true;
	while (checkModel) {
		printf(" 모델명을 입력하세요 : ");
		gets_s(input, sizeof(input));

		if (pageBack(input)) {
			system("cls");
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("\t<공백은 입력할 수 없습니다!>\n\n");
			continue;
		}
		int i = 0;
		while (i < bikeIndexMax) {
			if (!strcmp(input, b[i].model)) {
				printf("해당 %s 모델은 이미 존재합니다.\n\n", b[i].model);
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
		printf("\n 제조사를 입력하세요 : ");
		gets_s(input, sizeof(input));

		if (pageBack(input)) {
			system("cls");
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("<공백은 입력할 수 없습니다!>\n\n");
		}
		else {
			checkmanufacture = false;
		}
	}
	strcat_s(strBuffer, sizeof(strBuffer), " ");
	strcat_s(strBuffer, sizeof(strBuffer), input);

	bool checkDate = true;
	while (checkDate) {
		printf("\n 제조한 날짜를 입력하세요\n");
		printf(" ex) 2020-05-05\n");
		printf(" 날짜 : ");
		gets_s(input, sizeof(input));
		strcpy_s(input2, sizeof(input2), input);

		if (pageBack(input)) {
			return;
		}
		if (*input == '\0' || *input == ' ') {
			printf("<공백은 입력할 수 없습니다!>\n\n");
		}
		else {
			if (!(input[4] == '-' && input[7] == '-')) {
				printf("<형식에 맞게 입력해주세요!>\n\n");
			}
			else {
				strTemp = strtok_s(input, delimeter, &next);
				if (!(atoi(strTemp) >= 1000 && atoi(strTemp) <= 2021)) {
					printf("1000 ~ 2021 사이의 년도를 지정해주세요.\n\n ");
					continue;
				}
				else {
					strTemp = strtok_s(NULL, delimeter, &next);
					if (!(atoi(strTemp) >= 1 && atoi(strTemp) <= 12)) {
						printf("1 ~ 12 사이의 월을 지정해주세요.\n\n");
						continue;
					}
					else {
						if (!(atoi(next) >= 1 && atoi(next) <= 31)) {
							printf("1 ~ 31 사이의 일을 지정해주세요.\n\n");
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
		printf("파일을 열지 못했습니다.\n");
		exit(1);
	}
	fputs(strBuffer, f);
	fclose(f);
	system("cls");
	printf("\t\t\t[추가완료]\n");
}

void loginDisplay(char *id, char *pwd) {
	printf("------------------------------------------------------------------\n");
	printf("\t\t\t[로그인 페이지]\t\t\n");
	printf("\t\t\t\t\t프로그램 종료(ctrl+c)\n\n");
	printf("\tid  : ");
	gets_s(id, sizeof(id));
	printf("\tpwd : ");
	gets_s(pwd, sizeof(pwd));
}

void displayMenu(char *loginId) {
	printf("\n\t\t\t[자전거 재고 현황 시스템]\t\t\t\t\n\n");
	printf("\t1. 자전거 재고 추가\n");
	printf("\t2. 자전거 정보 수정\n");
	printf("\t3. 자전거 정보 삭제\n");
	printf("\tq. 로그아웃(프로그램 종료)\n\n");
	printf("    %s님 환영합니다 !\n\n", loginId);
	printf("    명령을 입력하세요 : ");
}

void printBikeStock(Bike* b) {
	printf("%4s\t%8s\t  %9s\t%18s\n", "Index", "Model", "Manufacture", "InsertDate");
	for (int i = 0; i < bikeIndexMax; i++) {
		printf("%4d\t%8s\t%9s\t%18s\n", b[i].index, b[i].model, b[i].manufacture, b[i].insertDate);
	}
	printf("\n------------------------------------------------------------------\n");
}