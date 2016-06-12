#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
struct Food {
	char *name;
	int price;
	int left;
};
void exit() { //파일저장
	printf("exit\n");
}
int decision(Food a[]);
int select(Food a[], int n);
int start() {
	int sel = 0;
	printf("버거류는 1, 사이드메뉴는 2, 음료는 3을 입력하세요.\n");
	scanf("%d", &sel);
	return sel;
}
int burger(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. 불고기버거, 2. 치즈버거, 3. 치킨버거, 4. 불고기버거 세트\n--------------------------\n");
	printf("주문하실 버거의 번호 : ");
	scanf("%d", &mnusel);
	if (a[mnusel - 1].left == 0) {
		printf("품절\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel - 1].name);
		printf("\n갯수 입력 : ");
		scanf("%d", &cnt);
		if (a[mnusel - 1].left < cnt) {
			printf("남은 수량은 %d개 입니다.\n", a[mnusel - 1].left);
		}
		else {
			a[mnusel - 1].left = a[mnusel - 1].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel - 1].price;
	printf("햄버거 주문금액 : %d\n", price);
	return price;
}
int side(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. 감자튀김, 2. 양념감자, 3. 치즈스틱, 4. 소프트콘\n--------------------------\n");
	printf("주문하실 사이드 메뉴의 번호 : ");
	scanf("%d", &mnusel);
	if (a[mnusel + 3].left == 0) {
		printf("품절\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel + 3].name);
		printf("\n갯수 입력 : ");
		scanf("%d", &cnt);
		if (a[mnusel + 3].left < cnt) {
			printf("남은 수량은 %d개 입니다.\n", a[mnusel - 1].left);
		}
		else {
			a[mnusel + 3].left = a[mnusel + 3].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel + 3].price;
	printf("햄버거 주문금액 : %d\n", price);
	return price;
}
int drink(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. 콜라, 2. 사이다\n--------------------------\n");
	printf("주문하실 음료의 번호 : ");
	scanf("%d", &mnusel);
	if (a[mnusel + 7].left == 0) {
		printf("품절\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel + 7].name);
		printf("\n갯수 입력 : ");
		scanf("%d", &cnt);
		if (a[mnusel + 7].left < cnt) {
			printf("남은 수량은 %d개 입니다.\n", a[mnusel + 7].left);
		}
		else {
			a[mnusel + 7].left = a[mnusel + 7].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel + 7].price;
	printf("햄버거 주문금액 : %d\n", price);
	return price;
}
int main() {
	FILE * ff;
	fopen_s(&ff, "food.txt", "w");
	struct Food Menu[10];
	Menu[0] = { "불고기버거", 2500, 20 };
	Menu[1] = { "치즈버거", 2500, 20 };
	Menu[2] = { "치킨버거", 2500, 20 };
	Menu[3] = { "불고기버거 세트", 2500, 20 };
	Menu[4] = { "감자튀김", 1000, 20 };
	Menu[5] = { "양념감자", 1500, 20 };
	Menu[6] = { "치즈스틱", 1000, 20 };
	Menu[7] = { "소프트콘", 500, 20 };
	Menu[8] = { "콜라", 1000, 20 };
	Menu[9] = { "사이다", 1000, 20 };
	int boolean = 1;
	int sel = 0;
	while (boolean == 1) {
		printf("      햄버거\n----------------\n      메뉴판\n----------------\n");
		for (int i = 0; i < 10; i++) {
			printf("%d. %s %d원\n", i + 1, Menu[i].name, Menu[i].price);
		}
		printf("-------------------\n");
		boolean = decision(Menu);
	}
	for (int i = 0; i < 10; i++) {
		printf("%s", Menu[i].name);
		printf("%d", i + 1);
		printf("남은 갯수 %d개\n", Menu[i].left);
		fprintf(ff, "%s\n" , Menu[i].name);
		fprintf(ff, "%d\n", Menu[i].price);
		fprintf(ff, "%d\n", Menu[i].left);
		if (ff == NULL) {
			printf("파일 열기 실패\n");
			return 0;
			fclose;
		}
	
	}
	//printf("총 금액 : %d", );
}

int decision(Food a[]) {
	printf("주문은 1, 퇴장은 2를 입력하세요\n");
	int sel = 0;
	int boolean = 1;
	int price;
	scanf("%d", &sel);
	if (sel == 1) {
		price = select(a, start());
		printf("현재 총 계산 금액 : %d\n", price);
	}
	else if (sel == 2) {
		exit();
		boolean = 0;
	}
	else
		printf("잘못입력하셨습니다.\n");
	return boolean;
}
int select(Food a[], int n) {
	int price = 0;
	if (n == 1) {
		price += burger(a, n);
	}
	else if (n == 2) {
		price += side(a, n);
	}
	else if (n == 3) {
		price += drink(a, n);
	}
	else {
		printf("잘못입력하셨습니다.\n");
	}
	return price;
}