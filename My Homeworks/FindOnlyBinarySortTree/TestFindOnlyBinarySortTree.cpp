#include "BinarySortTree.h"			// ������������
#include <string>
using namespace std;
int main(void)
{
	BinarySortTree<int> bt;
	string command;
    int x;
	cout << "���룺��find Ԫ��ֵ�� ����Ԫ��" << endl;
	cout << "���룺��exit�� �˳�" << endl;
    while (true)
    {
        cout << endl << "����:";
		cin >> command;
		if(command == "exit")
			break;
		if(command == "find")
		{
			cin >> x;
			bt.SuperFind(x);
			cout << "��ǰ��:" << endl;;
			DisplayBTWithTreeShape(bt);
			cout << endl;;
		}
	}

	system("PAUSE");				
	return 0;							
}

