#ifndef __NON_RECURSION_QUICK_SORT_H__
#define __NON_RECURSION_QUICK_SORT_H__

#include "Assistance.h"
#include "LinkStack.h"

struct Pair
{
	int high;
	int low;
};

template <class ElemType>
void Non_recursionQuickSort(ElemType elem[], int length)
{
	LinkStack<Pair> ls;
	Pair pair;
	pair.high = length - 1;
	pair.low = 0;
	ls.Push(pair);
	while(!ls.IsEmpty())
	{
		ls.Pop(pair);
		int low = pair.low;
		int high = pair.high;
		if(high - low >= 3)
		{
			ElemType e = elem[low];
			int i = low, j = high;
			while (i < j)
			 {
				while (i < j && elem[j] >= e)
					j--;
				if (i < j)
					elem[i++] = elem[j];

				while (i < j && elem[i] <= e)
					i++;
				if (i < j)
					elem[j--] = elem[i];
			}
			elem[i] = e;
			cout << "排序区间：" << low << "--" << high << ";中枢位置为：" << i << endl;
			Display(elem, length);
			cout << endl;
			if (low < i-1)
			{
				pair.low = low;
				pair.high = i - 1;
				ls.Push(pair);
			}
			if (i + 1 < high)
			{
				pair.low = i + 1;
				pair.high = high;
				ls.Push(pair);
			}
		}
		else
		{
			
			if(elem[low] > elem[low + 1])
				swap(elem[low], elem[low + 1]);
			if(elem[low + 1] > elem[high])
				swap(elem[low + 1], elem[high]);
			if(elem[low] > elem[low + 1])
				swap(elem[low], elem[low + 1]);
			cout << "排序区间：" << low << "--" << high << ";直接比较排序" << endl;
			Display(elem, length);
			cout << endl;
		}	 
		
	}
	
}

#endif

