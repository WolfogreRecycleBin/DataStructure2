#include "BinarySortTree.h"			// 二叉排序树类
#include <string>
using namespace std;
int main(void)
{
	BinarySortTree<int> bt;
	string command;
    int x;
	cout << "输入：“find 元素值” 查找元素" << endl;
	cout << "输入：“exit” 退出" << endl;
    while (true)
    {
        cout << endl << "输入:";
		cin >> command;
		if(command == "exit")
			break;
		if(command == "find")
		{
			cin >> x;
			bt.SuperFind(x);
			cout << "当前树:" << endl;;
			DisplayBTWithTreeShape(bt);
			cout << endl;;
		}
	}

	system("PAUSE");				
	return 0;							
}

