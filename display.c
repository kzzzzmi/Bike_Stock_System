#include "header.h"

void loginDisplay(char *id, char *pwd) {
	printf("------------------------------------------------------------------\n");
	printf("\t\t\t[�α��� ������]\t\t\n");
	printf("\t\t\t\t\t���α׷� ����(ctrl+c)\n\n");
	printf("\tid  : ");
	gets_s(id, sizeof(id));
	printf("\tpwd : ");
	gets_s(pwd, sizeof(pwd));
}

void displayMenu() {
	printf("\n\t\t\t[������ ��� ��Ȳ �ý���]\t\t\t\t\n\n");
	printf("\t1. ������ ��� �߰�\n");
	printf("\t2. ������ ���� ����\n");
	printf("\t3. ������ ���� ����\n");
	printf("\tq. �α׾ƿ�(���α׷� ����)\n\n");
}

void printBikeStock(Bike* b) {
	printf("%5s  %10s\t %-5s\t\t%7s\n", "Index", "Model", "Manufacturer", "InsertDate");
	for (int i = 0; i < bikeIndexMax; i++) {
		printf("%3d\t %s\t%9s\t\t%10s\n", b[i].index, b[i].model, b[i].manufacturer, b[i].insertDate);
	}
	printf("\n------------------------------------------------------------------\n");
}