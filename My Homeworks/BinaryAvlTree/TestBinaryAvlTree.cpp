#include "BinaryAvlTree.h"

int main(void)
{
	try
	{
		BinaryAVLTree<int> bt;
		int elem[] = {11, 39, 23, 68, 85, 8, 3, 46, 27, 50};
		int n = 10;
		
		cout << "从空树开始依次插入元素{11, 39, 23, 68, 85, 8, 3, 46, 27, 50}，构造二叉平衡树。" << endl;		
		for (int i = 0; i < n; i++)
		{
			bt.Insert(elem[i]);
		}

		cout << "构造的二叉平衡树，括号内的数字为结点的左子树节点数:" << endl;
		DisplayBTWithTreeShape(bt);
		cout << endl;
		system("PAUSE");

		char c = 'x';
		int x;

		while (c != '0')	{
			cout << endl << "1. 插入元素.";
			cout << endl << "2. 查找元素.";
			cout << endl << "3. 删除元素.";
			cout << endl << "4. 先序遍历.";
			cout << endl << "5. 中序遍历.";
			cout << endl << "6. 后序遍历.";
			cout << endl << "7. 显示二叉平衡树.";
			cout << endl << "8. 查找第x个元素.";
			cout << endl << "0. 退出";
			cout << endl << "选择功能(0~7):";
			cin >> c;
			switch (c)
			{
				case '1':
					cout << endl << "输入插入元素的值:";
					cin >> x;
					bt.Insert(x);
					break;
				case '2':
					cout << endl << "输入查找元素的值:";
					cin >> x;
					if (bt.Find(x) == NULL)
					   	cout << endl << "元素不存在.";
				  	else
					   	cout << endl << "元素存在.";
					break;
				case '3':
				  	cout << endl << "输入删除元素的值:";
					cin >> x;
					bt.Delete(x);
					break;
				case '4':
					cout << endl;
					bt.PreOrder(Write<int>);
					break;
				case '5':
					cout << endl;
					bt.InOrder(Write<int>);
					break;
				case '6':
					cout << endl;
					bt.PostOrder(Write<int>);
					break;
				case '7':
					cout << endl;
					DisplayBTWithTreeShape(bt);
					break;	
				case '8':
				{
					cout << endl;
					cout << endl << "输入元素的序号x:";
					cin >> x;
					int e;
					if (bt.FindNumber(x,e) == NOT_PRESENT)
					   	cout << endl << "序号范围有误.";
				  	else
					   	cout << endl << "第" << x << "号元素是" << e << endl;
					break;	
				}
			}
		}

	}
	catch (Error err)
	{
		err.Show();
	}

	system("PAUSE");
	return 0;
}

