#include "SeqList.h"
#include <iostream>
using namespace std;

bool Larger(const int &a, const int &b)
{
	return a > b;
}

int main(void)
{
	int a[] = {55, 63, 38, 21, -6, 92, 16, 46, 87, 72};
	int n = 10;
	SeqList<int> sl(a,n);
	cout << "ÅÅÐòÇ°:";
	sl.Display();
	sl.CountSort(Larger);
	cout << "ÅÅÐòºó:";
	sl.Display();

	system("PAUSE");
	return 0;
}
