#include "Circle.h"
int main()
{
	int num[] = {1,2,3,4,5,6,7,8,9,0,19,18,17,16,15,14,13,12,11,0};
	Circle c(num,20);
	c.Show();
	int max_four[4];
	int max = 100;
	c.CountMaxFour(max_four, max);
	int min_four[4];
	int min = 100;
	c.CountMinFour(min_four, min);
	cout << max << endl;
	cout << min << endl;
	return 0;
}

