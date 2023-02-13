#include "InsertionSort.h"

void InsertionSort(Student ary[], int numElems)
{
	bool fini = false;
	int cur = 0;
	bool more = (cur != 0);
	for (int c = 0; c < numElems; c++)
	{
		fini = false;
		cur = c;
		more = (cur != 0);
		while(more && !fini)
		{
			if (ary[cur] < ary[cur - 1])
			{
				Swap(ary[cur], ary[cur - 1]);
				cur--;
				more = (cur != 0);
			}
			else fini = true;
		}
	}

}