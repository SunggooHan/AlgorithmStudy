#include <stdio.h>
#include <stdlib.h>
const int INF = 100000;

//k is number of denominations of the coin or length of d
void coin_change_modified(int d[], int n, int k) {
    int count = 0;
    int* M = malloc(sizeof(int) * n + 1);
    M[0] = 0;

    int* S = malloc(sizeof(int) * n + 1);
    S[0] = 0;

    int i, j;
    for (j = 1; j <= n; j++) {
        int minimum = INF;
        int coin = 0;

        for (i = 1; i <= k; i++) {
            if (j >= d[i]) {
                if ((1 + M[j - d[i]]) < minimum) {
                    minimum = 1 + M[j - d[i]];
                    coin = i;

                }

            }
        }
        M[j] = minimum;
        S[j] = coin;
    }

    int l = n;
    while (l > 0) {
        l = l - d[S[l]];
        count++;
    }

    l = n;
    printf("Total Coins Needed = %d\n", count);
    printf("Coins are: ");
    while (l > 0) {
        printf("%d ", d[S[l]]);
        l = l - d[S[l]];
        count++;
    }

}

int main() {
    // array starting from 1, element at index 0 is fake
    int d[] = { 0,1,5,6,9 };
    int value = 0;
    int size = sizeof(d) / sizeof(int);
    printf("Enter your money : ");
    scanf_s("%d", &value);
    coin_change_modified(d, value, size - 1);
    return 0;
}