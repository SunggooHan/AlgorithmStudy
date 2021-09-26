#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#define max 100

//arr - will have list of needed coins
int ans[max];

int findMinCoins(int coins[], int size, int value)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (value == 0 || value < 0)
			break;

		else {
			//take as much from coins[i]
			while (value >= coins[i])
			{
				//after taking the coin, reduce the value.
				value -= coins[i];
				ans[count] = coins[i];
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int coins[] = { 500, 100, 50, 10, 1 }; //the units of coins
	int value = 0;

	printf("Enter your money : ");
	scanf_s("%d", &value);

	//find the size of the coins array
	int size = sizeof(coins) / sizeof(int);

	int MinCount = findMinCoins(coins, size, value);
	printf("Total Coins Needed = %d\n", MinCount);
	printf("Coins are: ");
	for (int i = 0; i < MinCount; i++)
		printf("%d ", ans[i]);

	return 0;
}