#include "FallingBall.h"
int main()
{
	int h,n;
	cout << "please input h,n:" << endl;
	while(cin >> h >> n)
	{
		FallingBall fb(h);
		int result = 0;
		for(int i = 1; i <= n; ++i)
			result = fb.Fall();
		cout << result << endl;
	}
	return 0;
}
//If you find bugs, please e-mail wolfogre@qq.com
