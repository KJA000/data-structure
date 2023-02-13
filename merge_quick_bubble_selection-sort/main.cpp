#include <iostream>
#include "Student.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"

using namespace std;
int main()
{
	Student stu[100];
	stu[0].InitValue(20031234, "ÀÌ¿õÀç", 3.0);

	stu[1].InitValue(21000000, "±è¿õÀç", 3.2);

	stu[2].InitValue(20000000, "¹Ú¿õÀç", 2.7);

	BubbleSort(stu, 3);
	Print(cout, stu, 3);
}
