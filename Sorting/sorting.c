#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void menu() {
	printf_s("Меню:\n 1.Ввод массива\n 2.Линейная сортировка\n 3.Пузырьковая сортировка\n 4.Сортировка вставкой\n 5.Линейный поиск\n 6.Бинарный поиск\n 7.Бинарный поиск\n 8.Время выполнения сортировки\n 9.Текущий массив\n 0.Выход\n ");
}
void input_array(int* firstelem, int len) {
	if (len <= 20) {
		printf_s("Введите элементы массива:");
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
		printf_s("Выберете пункт в меню и введите его номер:\n");
		scanf_s("%d", &number);
		switch (number) {
		case 1:
			do {
				printf_s("Введите количество элементов в массиве:");
				scanf_s("%d", &n);
				if ((n <= 0) && (n > 100)) {
					printf("Ошибка");
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
			//printf_s("до свидания");
			break;
		}
	}
	free(arr);
	
}
