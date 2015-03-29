#ifndef CRECLE_H
#define CRECLE_H
#include "DblLinkList.h"
class Circle
	:public DblLinkList<int>
{
public:
	Circle::Circle(int v[], int n):DblLinkList<int>(v, n){};
	bool Show();
	bool CountMaxFour(int max_four[],int &max);
	bool CountMinFour(int min_four[],int &min);
protected:
	DblNode<int>* GetNext(DblNode<int>* p);
};

bool Circle::Show()
{
	if(DblLinkList<int>::GetLength() <= 0)
		return false;
	
	for(DblNode<int> *p = (DblLinkList<int>::GetHead())->next;
		p != NULL && p != (DblLinkList<int>::GetHead()); p = p->next)
	{
		cout << p->data << '\t';
	}
	return true;
}

bool Circle::CountMaxFour(int max_four[],int &max)
{
	if(DblLinkList<int>::GetLength() <= 4)
	{
		return false;
	}
	int temp_max;
	for(DblNode<int> *p = (DblLinkList<int>::GetHead())->next;
		p != NULL && p != (DblLinkList<int>::GetHead()); p = p->next)
	{
		int temp = p->data + GetNext(p)->data + GetNext(GetNext(p))->data + GetNext(GetNext(GetNext(p)))->data;
		if(temp > temp_max|| p == (DblLinkList<int>::GetHead())->next)
		{
			DblNode<int> *pi = p;
			for(int i = 0; i < 4; ++i, pi = GetNext(pi))
			{
				max_four[i] = pi->data;
			}
			temp_max = temp;
		}
	}
	max = temp_max;
	return true;
}

bool Circle::CountMinFour(int min_four[],int &min)
{
	if(DblLinkList<int>::GetLength() <= 4)
	{
		return false;
	}
	int temp_min;
	for(DblNode<int> *p = (DblLinkList<int>::GetHead())->next;
		p != NULL && p != (DblLinkList<int>::GetHead()); p = p->next)
	{
		int temp = p->data + GetNext(p)->data + GetNext(GetNext(p))->data + GetNext(GetNext(GetNext(p)))->data;
		if(temp < temp_min || p == (DblLinkList<int>::GetHead())->next)
		{
			DblNode<int> *pi = p;
			for(int i = 0; i < 4; ++i, pi = GetNext(pi))
			{
				min_four[i] = pi->data;
			}
			temp_min = temp;
		}
	}
	min = temp_min;
	return true;
}

DblNode<int>* Circle::GetNext(DblNode<int>* p)
{
	if(p->next == DblLinkList<int>::GetHead())
		return p->next->next;
	return p->next;
}
#endif
