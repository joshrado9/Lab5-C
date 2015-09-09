#include <stdio.h>
#include <stdlib.h>

// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap)
{
	// Add your code here
	int i = 31;
	int k;
	while (i >= 0)
	{
		k = bitmap >> i;

		if (k & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		i --;
	}
	printf("\n");
	i = 31;
	while (i >= 0)
	{
		printf("%d", i % 10);
		i --;
	}
	printf("\n");
}


// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
	// Add your code here
	if (bitValue == 1)
	{
		*bitmap |= 1 << i;
	}
	else
	{
		*bitmap &= ~(1 << i);
	}
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i)
{
	// Add your code here
	int k;
	k = bitmap >> i;
	if (k & 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue)
{
	// Add your code here
	int k;
	int count = 0;
	int i = 31;
	while (i >= 0)
	{
		k = bitmap >> i;
		if (bitValue)
		{
			if (k & 1)
			{
				count ++;
			}
		}
		else 
		{
			if (!(k & 1))
			{
				count ++;
			}
		}
		i --;
	}
	return count;
}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position)
{
	// Add your code here
	int k;
	int tempCount = 0;
	int maxCount = 0;
	int maxStart = 0;
	int i = 31;
	while (i >= 0)
	{
		k = bitmap >> i;
		if ((k & 1) && tempCount == 0)
		{
			tempCount ++;
		}
		else if (!(k & 1))
		{
			if (tempCount > maxCount)
			{
				maxCount = tempCount;
				maxStart = i;
				tempCount = 0;
			}
			else
			{
				tempCount = 0;
			}
		}
		else if ((k & 1) && tempCount != 0)
		{
			tempCount ++;
		}
		i --;
	}
	*position = maxStart + 1;
	return maxCount;
}
