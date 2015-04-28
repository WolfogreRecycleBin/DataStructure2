#include "BinaryTree.h"		// ����������
#include "JudgeBST.h"

int main(void)
{
	BinTreeNode<int> *p;
	int pre[]={6,2,0,4,10,8,14,12,16}; // ��������
	int in[]={0,2,4,6,8,10,12,14,16};  // ��������
	int n = 9;						                  // ������
	BinaryTree<int> bt;
    char c = 'x';
	int e;
	
	bt = CreateBinaryTree(pre, in, n);           // ���������
		
	cout << "������6,2,0,4,10,8,14,12,16������0,2,4,6,8,10,12,14,16����Ķ�����:" << endl;
	DisplayBTWithTreeShape<int>(bt);
	cout << endl;

	system("PAUSE");

    while (c != '0')	{
        cout << endl << "1. ��������.";
        cout << endl << "2. ɾ��������.";
        cout << endl << "3. ��α���";
        cout << endl << "4. �������.";
        cout << endl << "5. �������.";
        cout << endl << "6. �������.";
        cout << endl << "7. ��������Ľ����.";
        cout << endl << "8. ��������ĸ߶�.";
        cout << endl << "9. ��ʾ������.";
        cout << endl << "a. �ж��Ƿ�Ϊ����������.";
        cout << endl << "b. �޸Ľ���ֵ.";
		cout << endl << "0. �˳�";
		cout << endl << "ѡ����(0~7):";
		cin >> c;
		switch (c) 	{
		    case '1':
            	cout << endl << "���뱻����Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else {
            		cout << endl << "�������Ԫ�ص�ֵ:";
			    	cin >> e;
					bt.InsertLeftChild(p, e);	// ��������
			    }
			    break;
           	case '2':
            	cout << endl << "����ɾ������˫��Ԫ�ص�ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
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
				cout << "�������Ľ����Ϊ��" << bt.NodeCount() << endl;
				break;
	         case '8':
				cout << endl;
				cout << "�������ĸ߶�Ϊ��" << bt.Height() << endl;
				break;
	         case '9':
				cout << endl;
				DisplayBTWithTreeShape(bt);
				break;
			case 'a':
				cout << endl;
				if(JudgeBST(bt))
					cout << "�������Ƕ���������." << endl;
				else
					cout << "���������Ƕ���������." << endl;
				cout << endl;
				system("pause");
				break;
			case 'b':
            	cout << endl << "������Ҫ�޸ĵĽ��Ԫ��ֵ:";
			    cin >> e;
			    p = bt.Find(e);
			    if (p == NULL)
			    	cout << "�ý�㲻���ڣ�" << endl;
			    else
			    {
			    	cout << "�����޸�Ϊ:";
			    	int new_value = 0;
			    	cin >> new_value;
					bt.SetElem(p,new_value);					
			    }
			    break;
		}
	}

	system("PAUSE");
	return 0;
}

