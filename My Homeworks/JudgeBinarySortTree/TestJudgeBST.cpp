#include "BinaryTree.h"		// 二叉链表类
#include "JudgeBST.h"

int main(void)
{
	BinTreeNode<int> *p;
	int pre[]={6,2,0,4,10,8,14,12,16}; // 先序序列
	int in[]={0,2,4,6,8,10,12,14,16};  // 中序序列
	int n = 9;						                  // 结点个数
	BinaryTree<int> bt;
    char c = 'x';
	int e;
	
	bt = CreateBinaryTree(pre, in, n);           // 构造二叉树
		
	cout << "由先序：6,2,0,4,10,8,14,12,16和中序：0,2,4,6,8,10,12,14,16构造的二叉树:" << endl;
	DisplayBTWithTreeShape<int>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. 插入左孩子.";
        cout << endl << "2. 删除右子树.";
        cout << endl << "3. 层次遍历";
        cout << endl << "4. 先序遍历.";
        cout << endl << "5. 中序遍历.";
        cout << endl << "6. 后序遍历.";
        cout << endl << "7. 求二叉树的结点数.";
        cout << endl << "8. 求二叉树的高度.";
        cout << endl << "9. 显示二叉树.";
        cout << endl << "a. 判断是否为二查排序树.";
        cout << endl << "b. 修改结点的值.";
        cout << endl << "c. 判断是否为二查排序树(方法2).";
		cout << endl << "0. 退出";
		cout << endl << "选择功能:";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "输入被插入元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else {
            		cout << endl << "输入插入元素的值:";
			    	cin >> e;
					bt.InsertLeftChild(p, e);	// 插入左孩子
			    }
			    break;
           	case '2':
            	cout << endl << "输入删除子树双亲元素的值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else 
					bt.DeleteRightChild(p);					
			    break;
		    case '3':
				cout << endl;
				bt.LevelOrder(Write<int>);
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
				cout << "二叉树的结点数为：" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "二叉树的高度为：" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
			case 'a':
				cout << endl;
				if(JudgeBST(bt))
					cout << "二叉树是二查排序树." << endl;
				else
					cout << "二叉树不是二查排序树." << endl;
				cout << endl;
				system("pause");
				break;
			case 'b':
            	cout << endl << "输入需要修改的结点元素值:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "该结点不存在！" << endl;
			    else
			    {
			    	cout << "将其修改为:";
			    	int new_value = 0;
			    	cin >> new_value;
					bt.SetElem(p,new_value);					
			    }
			    break;
			case 'c':
				cout << endl;
				if(JudgeBST2(bt))
					cout << "二叉树是二查排序树." << endl;
				else
					cout << "二叉树不是二查排序树." << endl;
				cout << endl;
				system("pause");
				break;
		}
	}

	system("PAUSE");
	return 0;
}

