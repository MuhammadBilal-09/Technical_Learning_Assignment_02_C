#include<stdio.h>

#define rows 5
#define cols 5

void findTreasure(int treasureArray[rows][cols])
{
	int currentRow = 0, currentCol = 0;
	
	while(1)
	{
		int currentClue = treasureArray[currentRow][currentCol];
		printf("The cell has been visited(%d, %d)\n", currentRow + 1, currentCol + 1);
		
		if(currentClue == (currentRow + 1) * 10 + (currentCol + 1))
		{
			printf("Treasure found at the cell (%d, %d)!\n", currentRow + 1, currentCol + 1);
			break;
		}
		
		currentRow = currentClue / 10 - 1;
		currentCol = currentClue % 10 - 1;
	}
}

int main()
{
	int treasureArray[rows][cols] = {
		{34, 21, 32, 41, 25},
		{14, 42, 43, 14, 31},
		{54, 45, 52, 42, 23},
		{33, 15, 51, 31, 35},
		{21, 52, 33, 13, 23}
	};
	
	printf("Starting the treasure hunt...\n");
	findTreasure(treasureArray);
	
	return 0;
}