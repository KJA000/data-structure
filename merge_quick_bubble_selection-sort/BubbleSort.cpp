#include "BubbleSort.h"

void BubbleSort(Student ary[], int numElems)
{
	int c = 0;
	while (c < numElems - 1)
	{
		for (int i = numElems - 1; i > c; i--)
		{
			if (ary[i] > ary[i - 1])
				Swap(ary[i], ary[i - 1]);
		}
		c++;
	}
}
