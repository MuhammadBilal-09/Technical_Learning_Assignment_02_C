#include<stdio.h>
#include<string.h>

// Function to check if two strings are anagrams
int areAnagrams(char *str1, char *str2)
{
	// Get the length of both strings
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	// If lengths are not equal, they cannot be anagrams
	if(len1 != len2)
	{
		return 0;
	}
	
	// Sort both strings
	int i, j;
	for(i = 0; i < len1 - 1; i++)
	{
		for(j = i + 1; j < len1; j++)
		{
			if(str1[i] > str1[j])
			{
				// Swap characters if they are in the wrong order
				char temp = str2[i];
				str2[i] = str2[j];
				str2[j] = temp;
			}
		}
	}
	
	// Compare sorted strings
	if(strcmp(str1, str2) == 0)
	{
		return 1;   // Strings are anagrams
	}
	else
	{
		return 0;   // Strings are not anagrams
	}
}

int main()
{
	char str1[100], str2[100];
	
	// Input first string
	printf("Enter the first string: ");
	scanf("%s", str1);
	
	// Input second string
	printf("Enter the second string: ");
	scanf("%s", str2);
	
	// Check if strings are anagrams
	if(areAnagrams(str1, str2))
	{
		printf("The strings are anagrams.\n");
	}
	else
	{
		printf("The strings are not anagrams.\n");
	}
	
	return 0;
}