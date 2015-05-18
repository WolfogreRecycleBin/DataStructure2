#ifndef __PATH_2_INSERT_SORT_H__
#define __PATH_2_INSERT_SORT_H__

#include "Assistance.h"

template <class ElemType>
void Path2InsertSort(ElemType elems[], int length)
{
	int first = 0;
	int final = 0;
	ElemType *temp_elems = new ElemType[length];
	for(int i = 0; i < length; ++i)
		temp_elems[i] = 0;
	temp_elems[0] = elems[0];
	cout << "插入第 0 个元素 " << elems[0] << " :\t";
	Display(temp_elems,length);

	for(int i = 0 + 1; i < length; ++i,Display(temp_elems,length))
	{
		cout << "插入第 " << i << " 个元素 " << elems[i] << " :\t";
		if(elems[i] < temp_elems[first])
		{
			first = (first - 1 + length) % length;
			temp_elems[first] = elems[i];
			continue;
		}
		if(elems[i] > temp_elems[final])
		{
			final = (final + 1 + length) % length;
			temp_elems[final] = elems[i];
			continue;
		}
		final = (final + 1 + length) % length;
		int j;
		for(j = final; temp_elems[(j - 1 + length) % length] > elems[i]; j = (j - 1 + length) % length)
		{
			temp_elems[j] = temp_elems[(j - 1 + length) % length];
		}
		temp_elems[j] = elems[i];
	}

	for(int i = 0, index = first; i < length; ++i, index = (index + 1 + length) % length)
		elems[i] = temp_elems[index];

	delete [] temp_elems;
}

#endif

//reference: http://blog.csdn.net/wzy_1988/article/details/9090167