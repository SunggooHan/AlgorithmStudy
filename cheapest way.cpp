#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
	int col, row, i, j, min, x, result;
	int input[MAX][MAX], mat[MAX][MAX], path[MAX];

	printf("col & row: ", MAX);
	scanf_s("%d", &col);
	scanf_s("%d", &row);

	printf("Matrix\n");
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			scanf_s("%d", &input[i][j]);
		}
	}

	for (i = 0; i < col; i++) {
		mat[i][0] = input[i][0];
	}

	for (j = 1; j < row; j++) {
		for (i = 0; i < col; i++) {
			min = mat[(i - 1 + col) % col][j - 1];
			if (mat[i][j - 1] < min) {
				min = mat[i][j - 1];
			}

			if (mat[(i + 1) % col][j - 1] < min) {
				min = mat[(i + 1) % col][j - 1];
			}

			mat[i][j] = input[i][j] + min;
		}
	}

	min = mat[0][row - 1];
	path[row - 1] = input[0][row - 1];
	x = 0;

	for (i = 1; i < col; i++) {
		if (mat[i][row - 1] < min) {
			min = mat[i][row - 1];
			path[row - 1] = input[i][row - 1];
			x = i;
		}
	}

	result = min;

	for (j = row - 2; j >= 0; j--) {
		i = x;
		min = mat[i][j];
		path[j] = input[i][j];

		if (mat[(i - 1 + col) % col][j] < min) {
			min = mat[(i - 1 + col) % col][j];
			path[j] = input[(i - 1 + col) % col][j];
			x = (i - 1 + col) % col;
		}

		if (mat[(i + 1) % col][j] < min) {
			min = mat[(i + 1) % col][j];
			path[j] = input[(i + 1) % col][j];
			x = (i + 1) % col;
		}
	}

	printf("\noutput\n");
	for (i = 0; i < row; i++) {
		printf("%d ", path[i]);
	}

	printf("\nresult: %d\n", result);

	return 0;
}