#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result = 0;
char arr1[100];
char arr2[10];
int table[10][100];
int m, n;

void cal(int i, int j) {
	if ((table[i][j] == 1) && (i < strlen(arr2)) && (j < strlen(arr1))) {
		cal(i + 1, j + 1);
		cal(i, j + 1);
	}
	else if ((table[i][j] == 1) && (i == strlen(arr2))) {
		result = result + 1;
		cal(i, j + 1);
	}
	else if ((table[i][j] == 0) && (i <= strlen(arr2)) && (j <= strlen(arr1))) {
		cal(i, j + 1);
	}
}

int main(void) {
	printf("Type the number of test sets: ");
	scanf_s("%d", &m);

	for (n = 0; n < m; n++) {
		memset(table, 0, 10 * 100);
		table[0][0] = 1;

		printf("Sequence: ");
		scanf_s("%s", arr1, sizeof(arr1));
		printf("Sub-sequence: ");
		scanf_s("%s", arr2, sizeof(arr2));

		for (int i = 1; i < strlen(arr2) + 1; i++) {
			for (int j = 1; j < strlen(arr1) + 1; j++) {
				if (arr1[j - 1] == arr2[i - 1])
					table[i][j] = 1;
			}
		}

		for (int i = 0; i < strlen(arr2) + 1; i++) {
			for (int j = 0; j < strlen(arr1) + 1; j++) {
				printf("%d ", table[i][j]);
			}
			printf("\n");
		}
			
		cal(0, 0);

		printf("Result: %d\n", result);
		printf("\n");
		result = 0;
	}

	return 0;
}