#include<stdio.h>
#include<stdlib.h>

int isContained(int *a1, int n, int *a2, int m)
{
	int i, j, found;
	
	for(i = 0; i <= n - m; i++)
	{
		found = 1;
		for (j = 0; j < m; j++)
		{
			if (a1[i + j] != a2[j])
			{
				found = 0;
				break;
			}
		}
		if(found)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, m, i;
	int *a1, *a2;
	
	printf("Enter the size of a1: ");
	scanf("%d", &n);
	
	printf("Enter the size of a2: ");
	scanf("%d", &m);
	
	if(n < m)
	{
		printf("Error! Size of a1 must be greater than or equal to size of a2.\n");
		return 1;
	}
	
	// Dynamically allocate memory for arrays
	a1 = malloc(n * sizeof(int));
	a2 = malloc(m * sizeof(int));
		
	if(!a1 || !a2)
	{
		printf("Failed to allocate memory.\n");
		return 1;
	}
	
	printf("Enter the elements of a1:\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a1[i]);
	}
	
	printf("Enter the elements of a2:\n");
	for(i = 0; i < m; i++)
	{
		scanf("%d", &a2[i]);
	}
	
	if(isContained(a1, n, a2, m))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	// Free the allocate memory
	free(a1);
	free(a2);
	
	return 0;
}