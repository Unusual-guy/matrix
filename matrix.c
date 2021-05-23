#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void mx_free(TMatrix* m) {
	if (m != NULL)
		if (m->a != NULL) {
			free(m->a);
			free(m);
		}
}

void mx_print(TMatrix* m) {
	unsigned int i, j;

	if (m != NULL) {
		if (m->a != NULL) {
			for (i = 0; i < m->m; i++) {
				for (j = 0; j < m->n; j++)
					printf("%8.2lf", m->a[i * m->n + j]);
				printf("\n");
			}
		}
	}
}

TMatrix* mx_identity(unsigned int n) {
	unsigned int i, j;
	TMatrix* m = NULL;

	m = (TMatrix*)malloc(sizeof(TMatrix));
	if (m != NULL) {
		m->a = (double*)malloc(n * n * sizeof(double));
		if (m->a != NULL) {
			m->n = m->m = n;
			for (i = 0; i < m->m; i++)
				for (j = 0; j < m->n; j++)
					m->a[i * n + j] = i == j ? 1 : 0;
		}
		else {
			free(m);
			m = NULL;
		}
	}

	return m;
}

void mx_det(int m) {
	FILE* file;
	unsigned int k, l;
	int* x, e;
	int det[11];
	file = fopen("C:/Users/123/Desktop/input.txt", "r");

    // size search
    if (k = 0) fscanf(file, "%d", &det[11]);
	e = det[10];
	int N = e;
	int array[N][N];


    // calculation the determinant
	for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
            fscanf(file, "%d", &array[k][l]);
            printf("%d", array[k][l]);
		}
		printf("\n");
	}
	x = (array[0][0] * array[1][1] * array[2][2]) + (array[1][0] * array[2][1] * array[0][2]) + (array[2][0] * array[0][1] * array[1][2]) - (array[0][2] * array[1][1] * array[2][0] + array[1][2] * array[2][1] * array[0][0] + array[2][2] * array[0][1] * array[1][0]);
    printf("%d", x);
}
