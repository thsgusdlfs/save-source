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
void exit() { //��������
	printf("exit\n");
}
int decision(Food a[]);
int select(Food a[], int n);
int start() {
	int sel = 0;
	printf("���ŷ��� 1, ���̵�޴��� 2, ����� 3�� �Է��ϼ���.\n");
	scanf("%d", &sel);
	return sel;
}
int burger(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. �Ұ�����, 2. ġ�����, 3. ġŲ����, 4. �Ұ����� ��Ʈ\n--------------------------\n");
	printf("�ֹ��Ͻ� ������ ��ȣ : ");
	scanf("%d", &mnusel);
	if (a[mnusel - 1].left == 0) {
		printf("ǰ��\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel - 1].name);
		printf("\n���� �Է� : ");
		scanf("%d", &cnt);
		if (a[mnusel - 1].left < cnt) {
			printf("���� ������ %d�� �Դϴ�.\n", a[mnusel - 1].left);
		}
		else {
			a[mnusel - 1].left = a[mnusel - 1].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel - 1].price;
	printf("�ܹ��� �ֹ��ݾ� : %d\n", price);
	return price;
}
int side(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. ����Ƣ��, 2. ��䰨��, 3. ġ�ƽ, 4. ����Ʈ��\n--------------------------\n");
	printf("�ֹ��Ͻ� ���̵� �޴��� ��ȣ : ");
	scanf("%d", &mnusel);
	if (a[mnusel + 3].left == 0) {
		printf("ǰ��\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel + 3].name);
		printf("\n���� �Է� : ");
		scanf("%d", &cnt);
		if (a[mnusel + 3].left < cnt) {
			printf("���� ������ %d�� �Դϴ�.\n", a[mnusel - 1].left);
		}
		else {
			a[mnusel + 3].left = a[mnusel + 3].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel + 3].price;
	printf("�ܹ��� �ֹ��ݾ� : %d\n", price);
	return price;
}
int drink(Food a[], int n) {
	int cnt = 0;
	int mnusel = 0;
	int price = 0;
	printf("1. �ݶ�, 2. ���̴�\n--------------------------\n");
	printf("�ֹ��Ͻ� ������ ��ȣ : ");
	scanf("%d", &mnusel);
	if (a[mnusel + 7].left == 0) {
		printf("ǰ��\n");
	}
	else {
		printf("%d. %s", mnusel, a[mnusel + 7].name);
		printf("\n���� �Է� : ");
		scanf("%d", &cnt);
		if (a[mnusel + 7].left < cnt) {
			printf("���� ������ %d�� �Դϴ�.\n", a[mnusel + 7].left);
		}
		else {
			a[mnusel + 7].left = a[mnusel + 7].left - cnt;
			printf("\n");
		}
	}
	price += cnt * a[mnusel + 7].price;
	printf("�ܹ��� �ֹ��ݾ� : %d\n", price);
	return price;
}
int main() {
	FILE * ff;
	fopen_s(&ff, "food.txt", "w");
	struct Food Menu[10];
	Menu[0] = { "�Ұ�����", 2500, 20 };
	Menu[1] = { "ġ�����", 2500, 20 };
	Menu[2] = { "ġŲ����", 2500, 20 };
	Menu[3] = { "�Ұ����� ��Ʈ", 2500, 20 };
	Menu[4] = { "����Ƣ��", 1000, 20 };
	Menu[5] = { "��䰨��", 1500, 20 };
	Menu[6] = { "ġ�ƽ", 1000, 20 };
	Menu[7] = { "����Ʈ��", 500, 20 };
	Menu[8] = { "�ݶ�", 1000, 20 };
	Menu[9] = { "���̴�", 1000, 20 };
	int boolean = 1;
	int sel = 0;
	while (boolean == 1) {
		printf("      �ܹ���\n----------------\n      �޴���\n----------------\n");
		for (int i = 0; i < 10; i++) {
			printf("%d. %s %d��\n", i + 1, Menu[i].name, Menu[i].price);
		}
		printf("-------------------\n");
		boolean = decision(Menu);
	}
	for (int i = 0; i < 10; i++) {
		printf("%s", Menu[i].name);
		printf("%d", i + 1);
		printf("���� ���� %d��\n", Menu[i].left);
		fprintf(ff, "%s\n" , Menu[i].name);
		fprintf(ff, "%d\n", Menu[i].price);
		fprintf(ff, "%d\n", Menu[i].left);
		if (ff == NULL) {
			printf("���� ���� ����\n");
			return 0;
			fclose;
		}
	
	}
	//printf("�� �ݾ� : %d", );
}

int decision(Food a[]) {
	printf("�ֹ��� 1, ������ 2�� �Է��ϼ���\n");
	int sel = 0;
	int boolean = 1;
	int price;
	scanf("%d", &sel);
	if (sel == 1) {
		price = select(a, start());
		printf("���� �� ��� �ݾ� : %d\n", price);
	}
	else if (sel == 2) {
		exit();
		boolean = 0;
	}
	else
		printf("�߸��Է��ϼ̽��ϴ�.\n");
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
		printf("�߸��Է��ϼ̽��ϴ�.\n");
	}
	return price;
}