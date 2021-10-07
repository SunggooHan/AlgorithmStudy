#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char city_name[100][100];
int city_num;
int train_num;
int dep_time;
int start;
int end;
int schedule_num[1000];
int train[1000][100][2];
int min_time[100][2];
int check[100];
int city(char* name);
int input(void);
void scheduler(void);

int main(void) {
    int i, j, s, n;

    printf("How many cases: ");
    scanf("%d", &n);

    for (j = 0; j < n; j++) {
        printf("--------------------------------------------------\n");
        scanf("%d", &s);
        for (i = 0; i < s; i++)
        {
            if (input() == -1) {
                exit(0);
            }
            scheduler();

            if (check[end]){
                printf("\nDeparture: %04d %s\n", min_time[start][1], city_name[start]);
                printf("Arrival: %4d %s\n", min_time[end][0], city_name[end]);
            }
            else {
                printf("Error\n");
            }
        }
    }
    printf("--------------------------------------------------\n");
}

int input(void) {
    int i, j;
    char name[100];

    scanf("%d", &city_num);

    for (i = 0; i < city_num; i++) {
        scanf("%s", &city_name[i]);
    }

    scanf("%d", &train_num);

    for (i = 0; i < train_num; i++) {
        scanf("%d", &schedule_num[i]);

        for (j = 0; j < schedule_num[i]; j++) {
            scanf("%d %s", &train[i][j][0], &name);
            train[i][j][1] = city(name);
        }
    }

    scanf("%d", &dep_time);
    scanf("%s", &name);
    start = city(name);
    scanf("%s", &name);
    end = city(name);

    return 0;
}

int city(char* name) {
    int i;

    for (i = 0; i < city_num; i++) {
        if (strcmp(name, city_name[i]) == 0) {
            return i;
        }
    }

    return -1;
}

void scheduler() {
    int i, j, k, l, now;

    for (i = 0; i < train_num; i++) {
        min_time[i][0] = 2500;
        min_time[i][1] = -1;
        check[i] = 0;
    }

    min_time[start][0] = dep_time;

    for (i = 0; i < train_num; i++) {
        now = -1;
        for (j = 0; j < train_num; j++) {
            if (check[j]) {
                continue;
            }

            if (now == -1 || min_time[now][0] > min_time[j][0]) {
                now = j;
            }
        }

        check[now] = -1;

        for (j = 0; j < train_num; j++) {
            for (k = 0; k < schedule_num[j] - 1; k++) {
                if (train[j][k][1] == now && min_time[now][0] <= train[j][k][0]) {
                    l = k + 1;

                    if (min_time[train[j][l][1]][0] > train[j][l][0]) {
                        min_time[train[j][l][1]][0] = train[j][l][0];
                    }
                }
            }
        }
    }

    if (check[end] == 0) {
        return;
    }

    for (i = 0; i < city_num; i++) {
        check[i] = 0;
    }

    min_time[end][1] = min_time[end][0];

    for (i = 0; i < city_num; i++) {
        now = -1;

        for (j = 0; j < city_num; j++) {
            if (check[j]) {
                continue;
            }
            if (now == -1 || min_time[now][1] < min_time[j][1]) {
                now = j;
            }
        }

        check[now] = 1;

        for (j = 0; j < train_num; j++) {
            for (k = 1; k < schedule_num[j]; k++) {
                if (train[j][k][1] == now && min_time[now][1] >= train[j][k][0]) {
                    l = k - 1;

                    if (min_time[train[j][l][1]][1] < train[j][l][0]) {
                        min_time[train[j][l][1]][1] = train[j][l][0];
                    }
                }
            }
        }
    }
}