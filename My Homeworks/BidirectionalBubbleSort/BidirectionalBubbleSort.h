#ifndef __BIDIRECTIONAL_BUBBLE_SORT_H__
#define __BIDIRECTIONAL_BUBBLE_SORT_H__
#include "Assistance.h"

template <class ElemType>
void BidirectionalBubbleSort(ElemType elems[], int length)
{
	bool finish = false;
	int first = 0;
	int final = length;
	int i = first;
	int step = 1;
	int count = 0;
	while(!finish && first != final)
	{
		finish = true;
		while(true)
		{
			if(i < first)
			{
				i = ++first;
				break;
			}
			if(i > final - 1)
			{
				i = --final - 1;
				break;
			}
			//cout << "检查第" << i << "个元素" << endl;
			if(elems[i] > elems[i + 1])
			{
				ElemType t = elems[i];
				elems[i] = elems[i + 1];
				elems[i + 1] = t;
				finish = false;
			}
			i += step;
		}
		cout << "第" << ++count << "趟冒泡排序的结果："; 
        Display(elems, length);
		step = -step;
	}
}

#endif
