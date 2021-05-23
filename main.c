#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>
#include "matrix.c"

#define BUFFER_SIZE 5

TMatrix* mx_from_file(char* filename) {
	FILE* file;
	int colCount, rowCount;
	int n;
	int i, j;
	double value;
	TMatrix* M;

	file = fopen("C:/Users/123/Desktop/input.txt", "rt");

	n = fscanf(file, "%d %d\n", &rowCount, &colCount);
	//TODO: check if parameter count is not 2

	//TODO: check malloc for NULL
	M = (TMatrix*)malloc(sizeof(TMatrix));

	M->m = colCount;
	M->n = rowCount;
	M->a = (double*)malloc(sizeof(double) * colCount * rowCount);

	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			fscanf(file, "%lf", &value);
			//print intermediate resulst only in debug configuration
#ifdef _DEBUG
			printf("%lf ", value);
#endif
			M->a[i * colCount + j] = value;
		}

#ifdef _DEBUG
		printf("\n");
#endif

	}

	fclose(file);

	return M;

}

int main(int argc, char** argv) {
	TMatrix* m;

	if (argc != 2) {
		printf("Usage: .exe <input.txt>\n");
	}

	if (!(m = mx_from_file(argv[1]))) {
		printf("Cannot read file %s\n", argv[1]);
	}

	mx_det(m);
	mx_free(m);
}
