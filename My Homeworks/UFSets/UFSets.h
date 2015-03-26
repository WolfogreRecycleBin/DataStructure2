#ifndef __ELEM_NODE_H__
#define __ELEM_NODE_H__

#include "Assistance.h"			// ���������

// ���鼯Ԫ�ؽ����
template <class ElemType>
struct ElemNode 
{
// ���ݳ�Ա:
	ElemType data;				// ������
	int parent;	                // ˫���� 
};

#endif


#ifndef __UFSETS_H__			// ���û�ж���__UFSETS_H__
#define __UFSETS_H__			// ��ô����__UFSETS_H__

// ���鼯
template <class ElemType>
class UFSets
{
protected:
// ���鼯�����ݳ�Ա:
	ElemNode<ElemType> *sets;	         // �洢����˫��
	int size;					         // ������

// ��������
    int Find(ElemType e) const;		     // ����Ԫ��e���ڵȼ���ĸ�
    int CollapsingFind(ElemType e) const;// ����Ԫ��e���ڵȼ���ĸ�

public:
// ���鼯�ĺ�����Ա:
	UFSets(ElemType es[], int n);	     // ����sz���������(�ȼ���)
	virtual ~UFSets();				     // ��������
	ElemType GetElem(int p)const;        // ȡָ��Ԫ���������е��±� 
	int GetOrder(ElemType e)const;       // ����ָ���±�ȡԪ��ֵ 
    bool Differ(ElemType a, ElemType b); // �ж�Ԫ��a��b�Ƿ���ͬһ���ȼ���
	UFSets(const UFSets &copy);		     // ���ƹ��캯��
	UFSets &operator =(const UFSets &copy);	// ��ֵ�����
	
//There are the function declarations added to finish the homework num.6 in P208.
//------------------------------------------------------------------------------------------------------------------
//begin
protected:
	int FindIndexOf(ElemType e);//to find the index of e, not the tree include e.
	void ShowTree(int index);//to help the function ShowTree(void),show the tree which the root index is int index.
	int Height(int index);//to help the function HeightedUnion(),it could count the height of a tree.
	int NodesOf(int index);//to count the nodes in the tree of the index.
	void CheckUnion(int r1, int r2);//to check r1<-r2 is allright.
public:
	void ShowTree();//show the tree, so i can know if my new function is working right.
	void Union(ElemType a, ElemType b);	////Unnion a and b with a<-b.
	void HeightedUnion(ElemType a, ElemType b);//Unnion a and b according to the height.
	void WeightedUnion(ElemType a, ElemType b);//Unnion a and b according to the number of nodes.
//end
//------------------------------------------------------------------------------------------------------------------
};
//There are the function definitions added to finish the homework num.6 in P208.
//------------------------------------------------------------------------------------------------------------------
//begin
template <class ElemType>
int UFSets<ElemType>::FindIndexOf(ElemType e)
{
	for(int i = 0; i < size; ++i)
	{
		if(sets[i].data == e)
			return i;
	}
	return -1;
}

template <class ElemType>
void UFSets<ElemType>::ShowTree(int index)
{
	cout << sets[index].data;
	int children_of_index[1000];
	int count_children_of_index =0 ;
	
	for(int i=0; i < size; ++i)
	{
		if(sets[i].parent == index)
		{
			children_of_index[count_children_of_index] = i;
			++count_children_of_index;
		}
	}
	if(count_children_of_index != 0)
	{
		cout << "{";
		for(int i = 0; i < count_children_of_index; i++)
			ShowTree(children_of_index[i]);
		cout << "}";
	}
	cout << " ";
}

template <class ElemType>
int UFSets<ElemType>::Height(int index)
{
	int max_height = 0;
	for(int i = 0; i < size; ++i)
	{
		if(sets[i].parent == index)
		{
			int count_height = Height(i);
			if(count_height > max_height)
				max_height = count_height;
		}
	}
	return max_height + 1;
}

template <class ElemType>
int UFSets<ElemType>::NodesOf(int index)
{
	int nodes_num = 1;
	for(int i = 0; i < size; ++i)
	{
		if(sets[i].parent == index)
		{
			nodes_num += NodesOf(i);
		}
	}
	return nodes_num;
}

template <class ElemType>
void UFSets<ElemType>::CheckUnion(int r1, int r2)
{
	if(sets[r2].parent != -1)
	{
		cout << endl;
		cout << "error:" << endl;
		cout << "need to " << sets[r1].data << " <- " << sets[r2].data << ", but r2 have parent already," << endl;
		cout << sets[r2].data << "'s parent is in index " << sets[r2].parent << endl;
		system("pause");
		exit(1);
	}
}

template <class ElemType>
void UFSets<ElemType>::ShowTree()
{
	for(int i=0; i < size; ++i)
	{
		if(sets[i].parent < 0)
		{
			ShowTree(i);
			cout << endl;
		}
	}
}

template <class ElemType>
void UFSets<ElemType>::Union(ElemType a, ElemType b)
{
	int r1 = FindIndexOf(a);
	int r2 = FindIndexOf(b);
	cout <<  "To Union(" << a << "," << b << "):  ";
	if (r1 != r2 && r1 != -1 && r2 != -1) {
			CheckUnion(r1,r2);
		sets[r2].parent = r1;
		cout  << sets[r1].data << " <- " << sets[r2].data;
    }
	else
	{
		cout << "do nothing";
	}
	cout << endl;
}

template <class ElemType>
void UFSets<ElemType>::HeightedUnion(ElemType a, ElemType b)
{
	int r1 = FindIndexOf(a);
	int r2 = FindIndexOf(b);
	cout <<  "To HeightedUnion(" << a << "," << b << "):  ";
	if (r1 != r2 && r1 != -1 && r2 != -1)
	{
       if (Height(r1) >= Height(r2))
	   {
			CheckUnion(r1,r2);
			sets[r2].parent = r1;
			cout  << sets[r1].data << " <- " << sets[r2].data;
       }
       else
	   {
			sets[r2].parent = r1;
			cout << sets[r2].data << " <- " << sets[r1].data;
       }
    }
	else
	{
		cout << "do nothing";
	}
	cout << endl;
}

template <class ElemType>
void UFSets<ElemType>::WeightedUnion(ElemType a, ElemType b)
{
	int r1 = FindIndexOf(a);
	int r2 = FindIndexOf(b);
	cout <<  "To WeightedUnion(" << a << "," << b << "):  ";
	if (r1 != r2 && r1 != -1 && r2 != -1) {
       if (NodesOf(r1) >= NodesOf(r2)) {
			CheckUnion(r1,r2);
			sets[r2].parent = r1;
			cout  << sets[r1].data << " <- " << sets[r2].data;
       }
       else {
			CheckUnion(r2,r1);
			sets[r1].parent = r2;
			cout << sets[r2].data << " <- " << sets[r1].data;
       }
    }
	else
	{
		cout << "do nothing";
	}
	cout << endl;
}

//end
//------------------------------------------------------------------------------------------------------------------
// ���鼯��ʵ�ֲ���
template <class ElemType>
UFSets<ElemType>::UFSets(ElemType es[], int n)
// �����������������es�е�Ԫ�أ�����n����Ԫ�صȼ���
{
	size = n;									// ��������
	sets = new ElemNode<ElemType>[size];		// ����ռ�
	for (int i = 0; i < size; i++) {
        sets[i].data = es[i];
		sets[i].parent = -1;			
    }
}

template <class ElemType>
int UFSets<ElemType>::Find(ElemType e) const
// �������������Ԫ��e�������ĸ�
{
    int p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;								// �����в�����Ԫ��e 
	while (sets[p].parent > -1)
        p = sets[p].parent;                     // ���Ҹ�
	return p;					
}

template <class ElemType>
int UFSets<ElemType>::CollapsingFind(ElemType e) const
// �����������ѹ��·�����ܣ�����Ԫ��e�������ĸ�
{
    int i, k, p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;								// �����в�����Ԫ��e 
    for(i = p ; sets[i].parent >= 0; i= sets[i].parent) ; //����p�ĸ��������i
    while ( i!= sets[p].parent ) {  //��p��ʼ�������ѹ��
        k = sets[p].parent ;
        sets[p].parent = i;
        p = k; 
    }
    return i; 
}


template <class ElemType>
UFSets<ElemType>::~UFSets()
// ����������ͷŶ���ռ�õĿռ䡪����������
{
	delete []sets;							// �ͷ�����parent
}

template <class ElemType>
ElemType UFSets<ElemType>::GetElem(int p) const
// ������������±�Ϊp��Ԫ��ֵ 
{
	if (p < 0 || p >= size)
		throw Error("Ԫ�ز�����!");			// �׳��쳣
	return sets[p].data;					// ����Ԫ��ֵ
}

template <class ElemType>
int UFSets<ElemType>::GetOrder(ElemType e) const
// ���������ȡָ��Ԫ��e���±� 
{
    int p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;							// �����в�����Ԫ��e 
	return p;							    // ��Ԫ���±� 
}

template <class ElemType>
bool UFSets<ElemType>::Differ(ElemType a, ElemType b)
// ������������a��b����ͬһ�ȼ����ϣ�����true�����򷵻�false
{
	int r1 = Find(a);				    // ����a���ڵȼ���ĸ�		
	int r2 = Find(b);					// ����b���ڵȼ���ĸ�		
	return r1 != r2;					
}

template <class ElemType>
UFSets<ElemType>::UFSets(const UFSets &copy)
// �����������copy�����¶��󡪡����ƹ��캯��
{
	size = copy.size;						// ��������
	sets = new ElemNode<ElemType>[size];	// ����ռ�
	for (int i = 0; i < size; i++) 
		sets[i] = copy.sets[i];             // ����ÿ��Ԫ��
}

template <class ElemType>
UFSets<ElemType> &UFSets<ElemType>::operator=(const UFSets<ElemType> &copy)
// �����������copy��ֵ����ǰ���󡪡���ֵ�����
{
	if (&copy != this)	{
		size = copy.size;					// ��������
		delete []sets;						// �ͷ�ԭ�ռ�
	    sets = new ElemNode<ElemType>[size];// �����¿ռ�
	    for (int i = 0; i < size; i++) 
		    sets[i] = copy.sets[i];			// ����ÿ��Ԫ��
	}
	return *this;
}

#endif
