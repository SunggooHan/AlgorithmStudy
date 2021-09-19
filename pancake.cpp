#include <stdio.h>
#define SIZE 30

int stack[SIZE];
int top;
int current;

int push(int key) {
	if (top != SIZE - 1) {
		stack[++top] = key;
		return 1;
	}
	else {
		return 0;
	}
}

void flip(int n) {
	int i;
	int count = 0;
	int temp[SIZE];
	for (i = n; i >= 0; i--) {
		temp[count++] = stack[i];
	}
	for (i = 0; i <= n; i++) {
		stack[i] = temp[i];
	}
}

void main(){
	int i, n;
	int temp;
	int max;
	top = -1;

	printf("Enter the number of input data: \n");
	scanf_s("%d", &n);
	current = n - 1;

	printf("Enter the input numbers: ");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &temp);
		push(temp);
	}

	while (current != 0) {
		for (i = 0; i <= current; i++) {
			if (i == 0)
				max = i;
			else if (stack[max] < stack[i])
				max = i;
		}

		if (max == current) {
			current--;
		}

		else {
			if (max == 0) {
				flip(current);
				printf("filp(%d) ", n - current);
			}
			else {
				flip(max);
				printf("filp(%d) ", n - max);
				flip(current);
				printf("filp(%d) ", n - current);
			}
			current--;
		}
	}
	printf("flip(%d)", current);

	printf("\nOutput: ");
	for (i = 0; i < n; i++) {
		printf("%d ", stack[i]);
	}
}
