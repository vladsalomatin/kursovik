#include "Header.h"

void vvod1(int m, int **mat) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				mat[i][j] = rand() % 2;
				if (mat[i][j] == 0)
					mat[i][j] = mat[i][j];
				else
					mat[i][j] = 1 + rand() % 30;
			}
			mat[j][i] = mat[i][j];
		}
	}
}
void vvod2(int m, int **mat) {
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				mat[i][j] = 0;
			}
			if (i > j) {
				scanf_s(" %d", &mat[i][j]);
			}
			mat[j][i] = mat[i][j];
		}
	}
}

void vivod(FILE *f, int m, int **mat, int *mass) {
	for (int i = 0; i < m; i++) { //VIVOD
		for (int j = 0; j < m; j++) {
			printf(" %4d", mat[i][j]);
			fprintf(f, " %4d", mat[i][j]);
		}
		printf("\n");
		fprintf(f, "\n");
	}
	;
	for (int i = 0; i < m; i++) {
		int iz = 0;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) {
				iz += 1;
			}
		}

		mass[i] = iz;
	}
	int flag = 0;
	for (int i = 0; i < m; i++) {
		if (mass[i] == 0) {
			printf("\nВершина %d является изолированной", i + 1);
			fprintf(f, "\nВершина %d является изолированной", i + 1);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("Матрица не имеет изолированных вершин!");
		fprintf(f, "Матрица не имеет изолированных вершин!");
	}
	free(mass);
	free(mat);
}