#include "DblLinkList.h"
#include <iostream>
using namespace std;

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	DblLinkList<int> dll(a,n);
	cout << "����ǰ:";
	dll.Display();
	dll.BubbleSort();
	cout << "�����:";
	dll.Display();

	system("PAUSE");
	return 0;
}
