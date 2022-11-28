#include "Header.h"
int main()
{	
	FILE *f;
	int **mat;
	int *mass;
	int m;
	int number1, number2;
	f = fopen("f.txt", "w");
	setlocale(LC_ALL, "Rus");
	int r = 0;
	int t = 0;
	printf("Данная программа предназначена на вычисление изолированных вершин в матрице!");
	while (r < 1) {
		printf("\nВведите номер опции программы: ");
		printf("\n1)Начать программу:)");
		printf("\n2)Завершить программу:(");
		printf("\nВаш выбор: ");
		scanf_s("%d", &number1);
		switch (number1)
		{
		case 1: 
			printf("Вы выбрали опцию 'Начать программу', выберите способ заполнения матрицы:");
			r++;		
			while (t < 1) {
				printf("\n1)Автоматический способ");
				printf("\n2)Ручной способ");
				printf("\nВведите номер опции: ");
				scanf_s("%d", &number2);
				switch (number2) {
				case 1:
					t++;
					printf("Вы выбрали 'Автоматический способ заполнения матрицы'");
					fprintf(f, "Размер матрицы:");
					fprintf(f, "\n");
					printf("\nРазмер матрицы:");
					scanf_s(" %d", &m);

					mat = (int**)malloc(m * sizeof(int*));
					for (int i = 0; i < m; i++) {
						mat[i] = (int*)malloc(m * sizeof(int));
					}
					mass = (int*)malloc(m * sizeof(int));
					vvod1(m, mat);
					vivod(f, m, mat, mass);
					break;
				case 2:
					t++;
					printf("Вы выбрали 'Ручной способ заполнения матрицы'");
					fprintf(f, "Размер матрицы:");
					fprintf(f, "\n");
					printf("\nРазмер матрицы:");
					scanf_s(" %d", &m);

					mat = (int**)malloc(m * sizeof(int*));
					for (int i = 0; i < m; i++) {
						mat[i] = (int*)malloc(m * sizeof(int));
					}
					mass = (int*)malloc(m * sizeof(int));
					printf("\nВведите следующие колличество элмементов вашей матрицы %d: ", ((m*m) - m) / 2);
					vvod2(m, mat);
					vivod(f, m, mat, mass);
					break;
				default:
					printf("\nТакой опции нет!");
					break;
				}
			}

		case 2:
			r++;
			printf("\nПрограмма завершила работу");
			break;

		default:
			printf("\nТакой опции нет!");

			break;
		}
	}
	fclose(f);

	getchar();
	getchar();
	return 0;
}
