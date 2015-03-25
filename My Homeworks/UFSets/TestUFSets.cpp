#include "UFSets.h"		            // 并查类

int main(void)
{
		//const int n = 10;
		//char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		//char a[] = {'a', 'g', 'i', 'c', 'a', 'h', 'f', 'f'};
		//char b[] = {'b', 'd', 'j', 'b', 'c', 'i', 'e', 'd'};
	const int n = 16;
	int elems[16];
	for(int i = 0; i < 16; ++i)
		elems[i] = i + 1;
	int a[] = {1,	3,	3,	1,	3,	8,	1,	2,	3,	3,	3,	14,	16,	14,	1,	1};
	int b[] = {2,	4,	5,	7,	6,	9,	8,	10,	11,	12,	13,	15,	0,	16,	3,	14};
	{//test Union()
		UFSets<int> e(elems,n);
		int i;
		for (i = 0; i < 16; i++)
			e.Union(a[i], b[i]);
		
		cout << "Show the status:" << endl;
		bool out[n];
		for (i = 0; i < n; i++)
			out[i] = false;
		int p = 0;
		while (p < n)		{
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}
		cout << "Show the logic:" << endl;
		e.ShowTree();
		system("PAUSE");
	}
	
	{//test WeightedUnion()
		UFSets<int> e(elems,n);
		int i;
		for (i = 0; i < 16; i++)
			e.WeightedUnion(a[i], b[i]);
		
		cout << "Show the status:" << endl;
		bool out[n];
		for (i = 0; i < n; i++)
			out[i] = false;
		int p = 0;
		while (p < n)		{
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}
		cout << "Show the logic:" << endl;
		e.ShowTree();
		system("PAUSE");
	}
	return 0;               // 返回值0, 返回操作系统
}


