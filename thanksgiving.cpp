#include <stdio.h>

void main() {
	int n, i;
	int cost[100];
	int total;
	int avg;
	int result;

	while (1) {
		printf("Type the number of students (End: '0'): ");
		scanf_s("%d", &n);

		if (n == 0 || n >= 100) {
			break;
		}

		total = 0;
		avg = 0;

		for (i = 0; i < n; i++) {
			printf("%d-th money spent: ", i+1);
			scanf_s("%d", &cost[i]);
			total += cost[i];
		}
		avg = total / n;

		result = 0;
		for (i = 0; i < n; i++) {
			if (cost[i] > avg) {
				result += cost[i] - avg;
			}
		}

		printf("The money exchange is %d(Won)", result);
		printf("\n\n");
	}
}
