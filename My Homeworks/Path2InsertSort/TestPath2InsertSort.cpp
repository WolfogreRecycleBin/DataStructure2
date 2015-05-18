#include "Path2InsertSort.h"

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);				 
	Path2InsertSort(a, n);	
	cout << "排序后:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}
