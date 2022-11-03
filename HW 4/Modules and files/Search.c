#include "qsort.h"
#include "Search.h"

int searchOfMinMostFrequent(int array[], int lengthOfArray)
{
	qsort(array, 0, lengthOfArray - 1);
	int minMostFrequent = array[0];
	int maxCounter = 1;
	int tempCounter = 1;
	for (int i = 1; i < lengthOfArray; i++)
	{
		if (array[i] == array[i - 1])
		{
			tempCounter++;
		}
		else
		{
			tempCounter = 1;
		}
		if (tempCounter > maxCounter)
		{
			maxCounter = tempCounter;
			minMostFrequent = array[i];
		}
	}
	return minMostFrequent;
}