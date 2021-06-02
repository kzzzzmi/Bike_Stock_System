#include "header.h"

int bikeIndexMax = 0;
int currentIndex = 0;

void main() {
	system("mode con cols=75 lines=40");
	system("color b");

	bool mLoop = true;
	char strBuffer[256];
	char select[10];
	char loginId[30];
	char loginPwd[30];
	char *id = loginId;
	char *pwd = loginPwd;
	FILE* f;

	if (fopen_s(&f, LNAME, "a")) {
		system("cls");
		printf("������ ���� ���Ͽ����ϴ�.");
		exit(1);
	}
	fclose(f);
	if (fopen_s(&f, FNAME, "a")) {
		system("cls");
		printf("������ ���� ���Ͽ����ϴ�.");
		exit(1);
	}
	fclose(f);


	while (mLoop) {
		if (fopen_s(&f, LNAME, "r") != 0) {
			printf("������ ���� ���߽��ϴ�.\n");
			exit(1);
		}
		Login l;
		fgets(strBuffer, sizeof(strBuffer), f);
		sscanf_s(strBuffer, "%s %s", l.id, sizeof(l.id), l.pwd, sizeof(l.pwd));
		fclose(f);

		loginDisplay(id, pwd);
		
		if (!strcmp(l.id, loginId) && !strcmp(l.pwd, loginPwd)) {
			system("cls");

			while (true) {
				FILE *f;
				char strBuffer[256];
				Bike b[50] = { NULL };
				bikeIndexMax = 0;
				currentIndex = 0;

				if (fopen_s(&f, FNAME, "r") != 0) {
					system("cls");
					printf("������ ���� ���Ͽ����ϴ�.");
					exit(1);
				}

				while (!feof(f)) {
					fgets(strBuffer, sizeof(strBuffer), f);
					sscanf_s(strBuffer, "%d %s %s %s",
						&b[bikeIndexMax].index,
						b[bikeIndexMax].model, sizeof(b[bikeIndexMax].model),
						b[bikeIndexMax].manufacturer, sizeof(b[bikeIndexMax].manufacturer),
						b[bikeIndexMax].insertDate, sizeof(b[bikeIndexMax].insertDate)
					);
					bikeIndexMax++;
				}
				fclose(f);

				displayMenu();
				printf("    %s�� ȯ���մϴ� !\n\n", l.id);
				printf("    ����� �Է��ϼ��� : ");
				gets_s(select, sizeof(select));

				if (!strcmp(select, "1")) {
					system("cls");
					addBike(b);
				}
				else if (!strcmp(select, "2")) {
					system("cls");
					modifyBike(b);
				}
				else if (!strcmp(select, "3")) {
					system("cls");
					deleteBike(b);
				}
				else if (!strcmp(select, "q")) {
					system("cls");
					break;
				}
				else {
					system("cls");
					printf("\t\t<�Է¿���!>\n");
				}
			}
		}
		else {
			system("cls");
			printf("------------------------------------------------------------------\n");
			printf("\t\t\t<�Է¿���>\t\t\n\n");
		}
	}
}