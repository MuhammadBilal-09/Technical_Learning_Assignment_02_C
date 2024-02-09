#include<stdio.h>
#define max_size 100

int main()
{
	char arr[max_size];
	int frequency[256] = {0};        // Assuming ASCII characters
	
	int n, i;
	
	//Input
	printf("Enter the number of characters(n): ");
	scanf("%d", &n);
	
	if(n <= 0 || n > max_size)
	{
		printf("Invalid input for n.\n");
		return 1;        // Exit with an error code
	}
	
	printf("Enter %d characters: ", n);
	for(i = 0; i < n; i++)
	{
		scanf(" %c", &arr[i]);
		frequency[arr[i]]++;
	}
	
	// most frequently occurring character
	char mostFrequent = arr[0];
	int maxFrequency = frequency[arr[0]];
	
	for(i = 1; i < n; i++)
	{
		if(frequency[arr[i]] > maxFrequency)
		{
			mostFrequent = arr[i];
			maxFrequency = frequency[arr[i]];
		}
	}
	
	// Output result
	if(maxFrequency > 1)
	{
		printf("The most frequently occurring character is: %c\n", mostFrequent);
	}
	else
	{
		printf("No character occurs more than once.\n");
	}
	
	return 0;
}