#include "SelectionSort.h"

void SelectionSort(Student ary[], int numElems)
{
	int end = numElems - 1;
	for (int cur = 0; cur < end; cur++)
	{
		int min = cur;
		for (int i = cur + 1; i <= end; i++)
		{
			if (min > i)
				min = i;
		}
		Swap(ary[cur], ary[min]);
	}
}
