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
	cout << "Max:";
	for(int i = 0; i < 4; ++i)
		cout << max_four[i] << " ";
	cout << "Sum:" << max << endl;
	cout << "Min:";
	for(int i = 0; i < 4; ++i)
		cout << min_four[i] << " ";
	cout << "Sum:" << min << endl;
	return 0;
}
//If you find bugs, please e-mail wolfogre@qq.com
