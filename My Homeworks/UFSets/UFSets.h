#ifndef __ELEM_NODE_H__
#define __ELEM_NODE_H__

#include "Assistance.h"			// 辅助软件包

// 并查集元素结点类
template <class ElemType>
struct ElemNode 
{
// 数据成员:
	ElemType data;				// 数据域
	int parent;	                // 双亲域 
};

#endif


#ifndef __UFSETS_H__			// 如果没有定义__UFSETS_H__
#define __UFSETS_H__			// 那么定义__UFSETS_H__

// 并查集
template <class ElemType>
class UFSets
{
protected:
// 并查集的数据成员:
	ElemNode<ElemType> *sets;	         // 存储结点的双亲
	int size;					         // 结点个数

// 辅助函数
    int Find(ElemType e) const;		     // 查找元素e所在等价类的根
    int CollapsingFind(ElemType e) const;// 查找元素e所在等价类的根

public:
// 并查集的函数成员:
	UFSets(ElemType es[], int n);	     // 构造sz个单结点树(等价类)
	virtual ~UFSets();				     // 析构函数
	ElemType GetElem(int p)const;        // 取指定元素在数组中的下标 
	int GetOrder(ElemType e)const;       // 根据指定下标取元素值 
    bool Differ(ElemType a, ElemType b); // 判断元素a、b是否在同一个等价类
	UFSets(const UFSets &copy);		     // 复制构造函数
	UFSets &operator =(const UFSets &copy);	// 赋值运算符
	
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
// 并查集的实现部分
template <class ElemType>
UFSets<ElemType>::UFSets(ElemType es[], int n)
// 操作结果：根据数组es中的元素，构造n个单元素等价类
{
	size = n;									// 设置容量
	sets = new ElemNode<ElemType>[size];		// 分配空间
	for (int i = 0; i < size; i++) {
        sets[i].data = es[i];
		sets[i].parent = -1;			
    }
}

template <class ElemType>
int UFSets<ElemType>::Find(ElemType e) const
// 操作结果：查找元素e所在树的根
{
    int p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;								// 集合中不存在元素e 
	while (sets[p].parent > -1)
        p = sets[p].parent;                     // 查找根
	return p;					
}

template <class ElemType>
int UFSets<ElemType>::CollapsingFind(ElemType e) const
// 操作结果：带压缩路径功能，查找元素e所在树的根
{
    int i, k, p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;								// 集合中不存在元素e 
    for(i = p ; sets[i].parent >= 0; i= sets[i].parent) ; //查找p的根结点的序号i
    while ( i!= sets[p].parent ) {  //从p开始向上逐层压缩
        k = sets[p].parent ;
        sets[p].parent = i;
        p = k; 
    }
    return i; 
}


template <class ElemType>
UFSets<ElemType>::~UFSets()
// 操作结果：释放对象占用的空间——析构函数
{
	delete []sets;							// 释放数组parent
}

template <class ElemType>
ElemType UFSets<ElemType>::GetElem(int p) const
// 操作结果：求下标为p的元素值 
{
	if (p < 0 || p >= size)
		throw Error("元素不存在!");			// 抛出异常
	return sets[p].data;					// 返回元素值
}

template <class ElemType>
int UFSets<ElemType>::GetOrder(ElemType e) const
// 操作结果：取指定元素e的下标 
{
    int p = 0;
    while (p < size && sets[p].data != e)
        p++;
	if (p == size)
		return -1;							// 集合中不存在元素e 
	return p;							    // 返元素下标 
}

template <class ElemType>
bool UFSets<ElemType>::Differ(ElemType a, ElemType b)
// 操作结果：如果a与b不在同一等价类上，返回true，否则返回false
{
	int r1 = Find(a);				    // 查找a所在等价类的根		
	int r2 = Find(b);					// 查找b所在等价类的根		
	return r1 != r2;					
}

template <class ElemType>
UFSets<ElemType>::UFSets(const UFSets &copy)
// 操作结果：由copy构造新对象——复制构造函数
{
	size = copy.size;						// 设置容量
	sets = new ElemNode<ElemType>[size];	// 分配空间
	for (int i = 0; i < size; i++) 
		sets[i] = copy.sets[i];             // 复制每个元素
}

template <class ElemType>
UFSets<ElemType> &UFSets<ElemType>::operator=(const UFSets<ElemType> &copy)
// 操作结果：将copy赋值给当前对象——赋值运算符
{
	if (&copy != this)	{
		size = copy.size;					// 设置容量
		delete []sets;						// 释放原空间
	    sets = new ElemNode<ElemType>[size];// 分配新空间
	    for (int i = 0; i < size; i++) 
		    sets[i] = copy.sets[i];			// 复制每个元素
	}
	return *this;
}

#endif
