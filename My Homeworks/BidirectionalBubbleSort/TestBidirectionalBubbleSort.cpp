#include "BidirectionalBubbleSort.h"

int main(void)
{
	int a[] = {55, 63, 38, 21, 63, 92, 16, 46, 87, 72, -55, -63, -38, -21};
	int n = 14;
	cout << "����ǰ:";
	Display(a, n);
	BidirectionalBubbleSort(a, n);
	cout << "�����:";
	Display(a, n);

	system("PAUSE");
	return 0;
}
