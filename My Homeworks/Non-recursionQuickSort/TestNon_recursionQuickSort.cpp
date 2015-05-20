#include "Non_recursionQuickSort.h"	
//这道题目前没有完全符合题意，我弄不清楚题目想表达什么意思，稍后更新
int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	cout << "排序前:";
	Display(a, n);				 
	Non_recursionQuickSort(a, n);	
	cout << "排序后:";
	Display(a, n);				

	system("PAUSE");			
	return 0;					
}
