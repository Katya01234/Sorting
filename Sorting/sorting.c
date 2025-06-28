#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>



void menu() {
	printf_s("����:\n 1.���� �������\n 2.�������� ����������\n 3.����������� ����������\n 4.���������� ��������\n 5.�������� �����\n 6.����� � ��������\n 7.�������� �����\n 8.��������� ������� ���������� ����������\n 9.��������� ������\n 0.�����\n ");
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
void output_array(int* firstelem, int len, int* copy) {
	printf_s("��������� ������:\n");
	for (int i = 0; i < len; i++) {
		printf_s("%d ", firstelem[i]);
	}
	printf_s("\n");
	printf_s("������� ������:\n");
	for (int i = 0; i < len; i++) {
		printf("%d ", copy[i]);
		
	}
	printf_s("\n");
}

void linsort(int* firstelem, int len, int* copy) {
	
	for (int i = 0; i < len; i++) copy[i] = firstelem[i];

	long long operations = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (copy[i] > copy[j]) {
				int r = copy[i];
				copy[i] = copy[j];
				copy[j] = r;
			}
			operations++;
		}
	}

	printf_s("���������� ��������: %lld\n", operations);
	/*for (int i = 0; i < len; i++) {
		printf("%d ", copy[i]);
	}*/
	
}
void bubble_sort(int* firstelem, int len, int* copy) {
	for (int i = 0; i < len; i++) copy[i] = firstelem[i];

	long long operations = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (copy[j] > copy[j + 1]) {
				int r  = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = r;
			}
			operations++;
		}
	}
	/*for (int i = 0; i < len; i++) {
		printf("%d ", copy[i]);
	}*/
	printf_s("���������� ��������: %lld\n", operations);


}
void insert_sort(int* firstelem, int len, int* copy) {
	for (int i = 0; i < len; i++) copy[i] = firstelem[i];

	long long operations = 0;
	for (int i = 1; i < len; i++) {
		int j = i - 1;
		int key = copy[i];
		while ((j >=  0) && (key < copy[j])) {
			copy[j + 1] = copy[j];
			j -= 1;
			operations++;
		}
		copy[j + 1] = key;
	}
	/*for (int i = 0; i < len; i++) {
		printf("%d ", copy[i]);
	}*/
	printf_s("���������� ��������: %lld\n", operations);

}
int lin_search(int* firstelem, int len) {
	int elem;
	printf_s("������� ������� �������: ");
	scanf_s("%d", &elem);
	for (int i = 0; i < len; i++) {
		if (firstelem[i] == elem) { 
			printf_s("������� ������, ��� ������ = %d\n", i);
			return i;
		}
		}
	printf_s("������� �� ������\n");
	return -1;
}
int bar_search(int* firstelem, int len, int* copy) {
	
	for (int i = 0; i < len; i++) copy[i] = firstelem[i];
	int elem;
	printf_s("������� ������� �������: ");
	scanf_s("%d", &elem);

	if (copy[len - 1] == elem) {
		printf_s("������� ������, ��� ������ = %d\n", len - 1);
		return len - 1;
	}
	else copy[len - 1] = elem;

	for (int i = 0; ; i++) {
		if (copy[i] == elem) {
			if (i == len - 1) {
				printf_s("������� �� ������\n");
				return -1;
			}
			else {
				printf_s("������� ������, ��� ������ = %d\n", i);
				return i;
			}
		}

	}
	
}
int bin_search(int* firstelem, int len,int* copy) {
	for (int i = 0; i < len; i++) copy[i] = firstelem[i];
	int left, right, middle, res;
	int elem;
	printf_s("������� ������� �������: ");
	scanf_s("%d", &elem);
	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (copy[j] > copy[j + 1]) {
				int r = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = r;
			}
		}
	}
	left = 0;
	right = len - 1;
	res = -1;
	while (left <= right) {
		middle = (left + right) / 2;
		if (elem == copy[middle]) {
			res = middle;
			printf_s("������� ������, ������ = %d\n", middle);
			return middle;
		}
		else {
			if (elem > copy[middle]) left = middle + 1;
			else right = middle - 1;
		}
	}
	printf_s("������� �� ������\n");
	return res;

}
void timer(int* arr, int n, int* ans) {
	clock_t start = clock();
	linsort(arr, n, ans);
	printf_s("����� ���������� �������� ����������: %lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);

	start = clock();
	bubble_sort(arr, n, ans);
	printf_s("����� ���������� ����������� ����������: %lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);


	start = clock();
	insert_sort(arr, n, ans);
	printf_s("����� ���������� ���������� ��������: %lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	
}
int main() {
	int flag = 1;
	int flag1 = 0;
	setlocale(LC_ALL, "Russian");
	int n = 1, number;
	int* arr = malloc (sizeof(int) * n);
	int* ans = malloc(sizeof(int) * n);
	
	menu();
	while (flag) {
		printf_s("�������� ����� � ���� � ������� ��� �����:\n");
		scanf_s("%d", &number);
		
		switch (number) {
		case 1:
			flag1= 1;
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
			ans = malloc(n * (sizeof(int)));
			input_array(arr, n);
			break;

		case 2:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));
				input_array(arr, n);
				
			}
			linsort(arr, n, ans);
			break;

		case 3:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));
				input_array(arr, n);
				
			}
			bubble_sort(arr, n, ans);
			break;
		case 4:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));
				
			}
			insert_sort(arr, n, ans);
			break;
		case 5:
			if (flag1 == 0) {
				flag1 = 1;
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
				
				
			}
			lin_search(arr, n);
			break;
		case 6:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));
				input_array(arr, n);
				
			}
			bar_search(arr, n, ans);
			break;
		case 7:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));
				input_array(arr, n);
				
			}
			bin_search(arr, n, ans);
			break;
		case 8:
			if (flag1 == 0) {
				flag1 = 1;
				do {
					printf_s("������� ���������� ��������� � �������:");
					scanf_s("%d", &n);
					if ((n <= 0) && (n > 100)) {
						printf("������");
						break;
					}
				} while (n <= 0);
				free(arr);
				free(ans);
				arr = malloc(n * (sizeof(int)));
				ans = malloc(n * (sizeof(int)));
				input_array(arr, n);
				
			}
			timer(arr, n, ans);
			break;
		case 9:
			if (flag1 == 0) {
				flag1 = 1;
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
				ans = malloc(n * (sizeof(int)));

				input_array(arr, n);
				
			}
			output_array(arr,n, ans);
			break;
		case 10:
			
		case 0:
			flag = 0;
			break;
		}
	}

	free(arr);
	
}

