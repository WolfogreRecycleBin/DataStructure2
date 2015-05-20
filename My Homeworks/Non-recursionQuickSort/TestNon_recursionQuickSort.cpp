#include "Non_recursionQuickSort.h"	
int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72, -55, -63, -38, -21, -63, -92, -16,};
	int n = 17;
	cout << "ÅÅÐòÇ°:";
	Display(a, n);				 
	Non_recursionQuickSort(a, n);	
	cout << "ÅÅÐòºó:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}
