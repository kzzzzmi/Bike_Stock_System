#include "header.h"

void displayMenu() {
	printf("\n\t\t\t[자전거 재고 현황 시스템]\t\t\t\t\n\n");
	printf("\t1. 자전거 재고 추가\n");
	printf("\t2. 자전거 정보 수정\n");
	printf("\t3. 자전거 정보 삭제\n");
	printf("\tq. 로그아웃(프로그램 종료)\n\n");
}

void printBikeStock(Bike* b) {
	printf("%5s  %10s\t %-5s\t\t%7s\n", "Index", "Model", "Manufacturer", "InsertDate");
	for (int i = 0; i < bikeIndexMax; i++) {
		printf("%3d\t %s\t%9s\t\t%10s\n", b[i].index, b[i].model, b[i].manufacturer, b[i].insertDate);
	}
	printf("\n------------------------------------------------------------------\n");
}