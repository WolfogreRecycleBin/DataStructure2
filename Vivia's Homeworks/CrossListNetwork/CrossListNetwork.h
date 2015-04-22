#ifndef __CROSS_LIST_GRAPH_H__
#define __CROSS_LIST_GRAPH_H__

#include "Assistance.h"
#include "CrossListNetworkArc.h"
#include "CrossListNetworkVex.h"

template <class ElemType, class WeightType>
class CrossListNetwork
{
protected:
	int vex_num, vex_max_num, arc_num;
	CrossListNetworkVex<ElemType, WeightType> *vex_table;
	mutable Status *tag;			
	WeightType infinity;

public:
	CrossListNetwork(ElemType es[],
					int vertex_num,
					int vertex_max_num = DEFAULT_SIZE, 
					WeightType infinit = (WeightType)DEFAULT_INFINITY);
	CrossListNetwork(int vertex_max_num = DEFAULT_SIZE, 
					WeightType infinit = (WeightType)DEFAULT_INFINITY);
	~CrossListNetwork();
	void Clear();									// 清空有向网
	bool IsEmpty();									// 判断有向网是否为空
	int GetOrder(ElemType &d) const;				// 求顶点的序号
	Status GetElem(int v, ElemType &d) const;		// 求顶点的元素值
	Status SetElem(int v, const ElemType &d);		// 设置顶点的元素值
	WeightType GetInfinity() const;					// 取无穷大的值
	int GetVexNum() const;							// 求有向网的顶点个数
	int GetArcNum() const;							// 求有向网的边数个数
	int FirstToVex(int v) const;					// 求有向网中顶点v的第一个后继顶点
	int NextToVex(int v1, int v2) const;			// 求有向网中顶点v1的相对于v2的下一个后继顶点
	int FirstFromVex(int v) const;					// 求有向网中顶点v的第一个前驱顶点
	int NextFromVex(int v1, int v2) const;			// 求有向网中顶点v1的相对于v2的下一个前驱顶点
	void InsertVex(const ElemType &d);				// 插入元素值为d的顶点
	void InsertArc(int v1, int v2, WeightType w);	// 插入从顶点为v1到v2、权为w的边		 
	void DeleteVex(const ElemType &d);				// 删除元素值为d的顶点			 
	void DeleteArc(int v1, int InsertArcVv2);		// 删除从顶点为v1到v2的边，此函数有Bug，如果删除平行边会出错，暂忽略		 
	WeightType GetWeight(int v1, int v2) const;		// 求从顶点为v1到v2的边的权值
	void SetWeight(int v1, int v2, WeightType w);	// 设置从顶点为v1到v2的边的权值
	Status GetTag(int v) const;						// 求顶点v的标志		 
	void SetTag(int v, Status tag) const;			// 设置顶点v的标志为tag	 
	void Display();									// 显示有向网十字链表
protected:
	//将复制构造函数和=运算符函数设置为保护，来禁用这两个尚未完成的函数
	CrossListNetwork(const CrossListNetwork<ElemType, WeightType> &copy);// 复制构造函数
	CrossListNetwork<ElemType, WeightType> &operator = (const CrossListNetwork<ElemType, WeightType> &copy);// 重载赋值运算符 
};

template <class ElemType, class WeightType>
CrossListNetwork<ElemType, WeightType>::CrossListNetwork(ElemType es[],
														int vertex_num,
														int vertex_max_num,
														WeightType infinit)
{
	if (vertex_max_num < 0)
    	throw Error("允许的顶点最大数目不能为负!");
	if (vertex_max_num < vertex_num)
    	throw Error("顶点数目不能大于允许的顶点最大数目!");

	vex_num = vertex_num;			
	vex_max_num = vertex_max_num; 
	arc_num = 0;
	infinity = infinit;
	
	tag = new Status[vex_max_num];
	vex_table = new CrossListNetworkVex<ElemType, WeightType>[vex_max_num];
 
	for (int v = 0; v < vex_num; v++)  {
		tag[v] = UNVISITED;
		vex_table[v].data = es[v];
		vex_table[v].first_in_arc = NULL;
		vex_table[v].first_out_arc = NULL;
	}
}

template <class ElemType, class WeightType>
CrossListNetwork<ElemType, WeightType>::CrossListNetwork(int vertex_max_num, WeightType infinit)
{
	if (vertex_max_num < 0)
    	throw Error("允许的顶点最大数目不能为负!");

	vex_num = 0;			
	vex_max_num = vertex_max_num;
	arc_num = 0;
	infinity = infinit;

	tag = new Status[vex_max_num];
	vex_table = new CrossListNetworkVex<ElemType, WeightType>[vex_max_num];
}

template <class ElemType, class WeightType>
CrossListNetwork<ElemType, WeightType>::~CrossListNetwork()
{
    Clear();
	delete [] tag;
	delete [] vex_table;
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::Clear()		 
{
	CrossListNetworkArc<WeightType> *p;
	for (int v = 0; v < vex_num; v++)
	{
	    p = vex_table[v].first_out_arc;
	    while (p != NULL)
	    {
			vex_table[v].first_out_arc = p->tail_next_arc;
			delete p;
			p = vex_table[v].first_out_arc;
        }	
	}
    vex_num = 0;
	arc_num = 0;	
}

template <class ElemType, class WeightType>
bool CrossListNetwork<ElemType, WeightType>::IsEmpty()
{
	return vex_num == 0;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::GetOrder(ElemType &d) const
{
	for (int v = 0; v < vex_num; v++)
 		if (d == vex_table[v].data)
			return v;
	return -1;
}

template <class ElemType, class WeightType>
Status CrossListNetwork<ElemType, WeightType>::GetElem(int v, ElemType &d) const
{
	if (v < 0 || v >= vex_num)
		return NOT_PRESENT;
	d = vex_table[v].data;
	return ENTRY_FOUND;
}

template <class ElemType, class WeightType>
Status CrossListNetwork<ElemType, WeightType>::SetElem(int v, const ElemType &d)
{
	if (v < 0 || v >= vex_num)
		return RANGE_ERROR;
	vex_table[v].data = d;
	return SUCCESS;
}

template <class ElemType, class WeightType>
WeightType CrossListNetwork<ElemType, WeightType>::GetInfinity() const
{
	return infinity;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::GetVexNum() const		 
{
	return vex_num;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::GetArcNum() const
{
	return arc_num;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::FirstToVex(int v) const		 
{
	if (v < 0 || v >= vex_num)
       throw Error("v不合法!");

	if (vex_table[v].first_out_arc == NULL)
	   return -1;
	else
	   return vex_table[v].first_out_arc->head_vex;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::NextToVex(int v1, int v2) const
{
	if (v1 < 0 || v1 >= vex_num)
       throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
       throw Error("v2不合法!");
	if (v1 == v2)
       throw Error("v1不能等于v2!");
	CrossListNetworkArc<WeightType> *p = vex_table[v1].first_out_arc;
	while (p != NULL && p->head_vex != v2)
	    p = p->tail_next_arc;

	if (p == NULL || p->tail_next_arc == NULL)
		return -1;
	else
		return p->tail_next_arc->head_vex;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::FirstFromVex(int v) const		 
{
	if (v < 0 || v >= vex_num)
       throw Error("v不合法!");

	if (vex_table[v].firs_in_tarc == NULL)
	   return -1;
	return vex_table[v].first_in_arc->tail_vex;
}

template <class ElemType, class WeightType>
int CrossListNetwork<ElemType, WeightType>::NextFromVex(int v1, int v2) const
{
	if (v1 < 0 || v1 >= vex_num)
       throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
       throw Error("v2不合法!");
	if (v1 == v2)
       throw Error("v1不能等于v2!");
	CrossListNetworkArc<WeightType> *p = vex_table[v1].first_in_arc;
	while (p != NULL && p->tail_vex != v2)
	    p = p->head_next_arc;

	if (p == NULL || p->head_next_arc == NULL)
		return -1;
	return p->head_next_arc->tail_vex;
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::InsertVex(const ElemType &d)
{
	if (vex_num == vex_max_num)
		throw Error("图的顶点数不能超过允许的最大数!");

	vex_table[vex_num].data = d;
	vex_table[vex_num].first_in_arc = vex_table[vex_num].first_out_arc = NULL;
	tag[vex_num] = UNVISITED;
    vex_num++;
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::InsertArc(int v1, int v2, WeightType w)	 
{
	if (v1 < 0 || v1 >= vex_num)
		throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
		throw Error("v2不合法!");
	if (v1 == v2)
       throw Error("v1不能等于v2!");
	if (w >= infinity)
       throw Error("w不能为无空大!");

	CrossListNetworkArc<WeightType> *p, *q;
	p = vex_table[v1].first_out_arc;
	q = vex_table[v2].first_in_arc;
	CrossListNetworkArc<WeightType> *new_arc = new CrossListNetworkArc<WeightType>(v1, v2, w, p, q);
    vex_table[v1].first_out_arc = new_arc;
    vex_table[v2].first_in_arc = new_arc;
	arc_num++;
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::DeleteVex(const ElemType &d)	 
{
	int v;
    CrossListNetworkArc<WeightType> *p;
    for (v = 0; v < vex_num; v++)
       if	(vex_table[v].data == d)
           break;
	if (v == vex_num)
       throw Error("图中不存在要删除的顶点!");

    for (int u = 0; u < vex_num; u++)
		if (u != v)
		{
			DeleteArc(u, v);
			DeleteArc(v, u);
		}

	vex_num--;
	vex_table[v].data = vex_table[vex_num].data;
	vex_table[v].first_in_arc = vex_table[vex_num].first_in_arc;
	vex_table[v].first_out_arc = vex_table[vex_num].first_out_arc;
    tag[v] = tag[vex_num];

    for (int u = 0; u < vex_num; u++)         
       if (u != v)
		{
			p = vex_table[u].first_out_arc;
			while (p != NULL)
			{
				if (p->head_vex == vex_num)
					p->head_vex = v;
				p = p->tail_next_arc;
			}
			p = vex_table[u].first_in_arc;
			while (p != NULL)
			{
				if (p->tail_vex == vex_num)
					p->tail_vex = v;
				p = p->head_next_arc;
			}
       }
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::DeleteArc(int v1, int v2)		 
{
	if (v1 < 0 || v1 >= vex_num)
       throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
       throw Error("v2不合法!");
	if (v1 == v2) throw
       Error("v1不能等于v2!");

	CrossListNetworkArc<WeightType> *p, *q;
	p = vex_table[v1].first_out_arc;
	while (p != NULL && p->head_vex != v2)
	{
		q = p;
		p = p->tail_next_arc;
	}
	if(p != NULL) {
		if (vex_table[v1].first_out_arc == p)
			vex_table[v1].first_out_arc = p->tail_next_arc;
		else
			q->tail_next_arc = p->tail_next_arc;
		//delete p;
		//arc_num--;
	}

	p = vex_table[v2].first_in_arc;
	while(p != NULL && p->tail_vex != v1)
	{
		q = p;
		p = p->head_next_arc;
	}
	if(p != NULL) {
		if (vex_table[v1].first_in_arc == p)
			vex_table[v1].first_in_arc = p->head_next_arc;
		else
			q->head_next_arc = p->head_next_arc;
		delete p;
		arc_num--;
	}
	
}

template <class ElemType, class WeightType>
WeightType CrossListNetwork<ElemType, WeightType>::GetWeight(int v1, int v2) const
{
	if(v1 < 0 || v1 >= vex_num)
		throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
		throw Error("v2不合法!");

	CrossListNetworkArc<WeightType> *p;
	p = vex_table[v1].first_out_arc;
	while(p != NULL && p->head_vex != v2) 
		p = p->tail_next_arc;
	if(p != NULL)
		return p->weight;
	else
		return infinity;
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::SetWeight(int v1, int v2, WeightType w)
{
	if(v1 < 0 || v1 >= vex_num)
		throw Error("v1不合法!");
	if (v2 < 0 || v2 >= vex_num)
		throw Error("v2不合法!");

	CrossListNetworkArc<WeightType> *p;
	p = vex_table[v1].first_out_arc;
	while(p != NULL && p->head_vex != v2) 
		p = p->tail_next_arc;
	if(p != NULL)
		p->weight = w;
}

template <class ElemType, class WeightType>
Status CrossListNetwork<ElemType, WeightType>::GetTag(int v) const	 
{
	if (v < 0 || v >= vex_num)
		throw Error("v不合法!");
	return tag[v];
}

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::SetTag(int v, Status val) const
{
	if (v < 0 || v >= vex_num)
		throw Error("v不合法!");	
	tag[v] = val;
}

/*template <class ElemType, class WeightType>
CrossListNetwork<ElemType, WeightType>::CrossListNetwork(const CrossListNetwork<ElemType, WeightType> &copy)
{
	//此函数删除，待实现
}

template <class ElemType, class WeightType>
CrossListNetwork<ElemType, WeightType>& CrossListNetwork<ElemType, WeightType>::operator = (const CrossListNetwork<ElemType, WeightType> &copy)
{
	//此函数删除，待实现
}*/

template <class ElemType, class WeightType>
void CrossListNetwork<ElemType, WeightType>::Display()
{
	CrossListNetworkArc<WeightType> *p;
    cout << "有向网共有" << vex_num << "个顶点，" << arc_num << "条边。" << endl;
    cout << "按邻接表显示:" << endl;
	for (int v = 0; v < vex_num; v++)
	{
		cout << v << ":\t" << vex_table[v].data;
	    p = vex_table[v].first_out_arc;
	    while (p != NULL)
	    {
        	cout << "  -->  (" << p->tail_vex << "->" << p->head_vex << ", " << p->weight << ")";
            p = p->tail_next_arc;
		}
		cout << endl;
	}
	cout << "按逆邻接表显示:" << endl;
	for (int v = 0; v < vex_num; v++)
	{
		cout << v << ":\t" << vex_table[v].data;
	    p = vex_table[v].first_in_arc;
	    while (p != NULL)
	    {
        	cout << "  -->  (" << p->tail_vex << "->" << p->head_vex << ", " << p->weight << ")";
            p = p->head_next_arc;
		}
		cout << endl;
	}
}

#endif
