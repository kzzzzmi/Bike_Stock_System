#include "header.h"

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