#include "UFSets.h"		            // ������

int main(void)
{
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int n = 10;
		char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		char a[] = {'a', 'g', 'i', 'c', 'a', 'h', 'f', 'f'};
		char b[] = {'b', 'd', 'j', 'b', 'c', 'i', 'e', 'd'};
		//Fixed by wolfogre:the type of a,b,c should be char, not int.
		UFSets<char> e(c,n);
		int i;
		for (i = 0; i < 8; i++)
			e.Union(a[i], b[i]);	// �ϲ��ȼ���
	
		bool out[n];				// ������Ľ��ֵΪtrue������ֵΪfalse

		for (i = 0; i < n; i++)
			out[i] = false;
		int p = 0;				// ��ǰ���
		while (p < n)		{	// ��û������ĵ�ǰ��㣬�����ȼ���
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{	// ����ȼ���
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{	// p��i��ͬһ���ȼ�����
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}
		
		cout << "Show the logic:" << endl;
		e.ShowTree();
	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}


