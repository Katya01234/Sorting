#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void menu() {
	printf_s("����:\n 1.���� �������\n 2.�������� ����������\n 3.����������� ����������\n 4.���������� ��������\n 5.�������� �����\n 6.�������� �����\n 7.�������� �����\n 8.����� ���������� ����������\n 9.������� ������\n 0.�����\n ");
}
void input_array(int* firstelem, int len) {
	if (len <= 20) {
		printf_s("������� �������� �������:");
		for (int i = 0; i < len; i++) {
			scanf_s("%d", &firstelem[i]);
		}
	}
	else {
		for (int i = 0; i < len; i++) {
			firstelem[i] = (rand() % 100);
		}
	}
}
void output_array(int* firstelem, int* len) {
	for (int i = 0; i < *len; i++) {
		printf_s("%d", &firstelem[i]);
	}

}
void linsort() {

}

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 1, number;
	int *arr = malloc (sizeof(int) * n);
	

	menu();
	while (1) {
		printf_s("�������� ����� � ���� � ������� ��� �����:\n");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			do {
				printf_s("������� ���������� ��������� � �������:");
				scanf_s("%d", &n);
				if ((n <= 0) && (n > 100)) {
					printf("������");
					break;
				}
			} while (n <= 0);
			free(arr);
			arr = malloc(n * (sizeof(int)));
			input_array(arr, n);
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:
			for (int i = 0; i < n; i++) {
				printf_s("%d ", arr[i]);
			}
			break;
		case 10:
			//system("C:\\WINDOWS\\System32\\shutdown /s /t 5");
			//printf_s("�� ��������");
			break;
		}
	}
	free(arr);
	
}
