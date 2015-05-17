#include "DblLinkList.h"
#include <iostream>
using namespace std;

bool Larger(const int &a, const int &b)
{
	return a > b;
}

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72};
	int n = 10;
	DblLinkList<int> dll(a,n);
	cout << "ÅÅÐòÇ°:";
	dll.Display();
	dll.BubbleSort(Larger);
	cout << "ÅÅÐòºó:";
	dll.Display();

	system("PAUSE");
	return 0;
}
