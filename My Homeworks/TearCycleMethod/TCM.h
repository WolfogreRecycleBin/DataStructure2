#ifndef __TCM_H__
#define __TCM_H__
#include "AdjMatrixUndirNetwork.h"
struct Edge
{
	int vertex1;
	int vertex2;
	int weight;
};
//this way is :
//1,Find all edge, than sort it from max to min;
//2,Traversal those edge to do
// {
// 	a,delete the edge;
// 	b,check the gragh if become unconnected, if yes, insert the edge which just deleted, if no, go on;
// }
template <class ElemType, class WeightType>
void MiniSpanTreeTCN_1(const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
{
	Edge edge[100];
	int edge_num = 0;
	AdjMatrixUndirNetwork<ElemType, WeightType> g_temp = g;
	for (int v = 0; v < g_temp.GetVexNum(); v++)
		for (int u = g_temp.FirstAdjVex(v); u >= 0; u = g_temp.NextAdjVex(v, u))
			if (v < u){
                edge[edge_num].vertex1 = v;
                edge[edge_num].vertex2 = u;
                edge[edge_num].weight = g_temp.GetWeight(v,u);
                ++edge_num;
			}
	for(int i = edge_num; i >= 0; --i)
		for(int j = 0; j < i; ++j)
			if(edge[j].weight < edge[j+1].weight)
			{
				Edge t = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = t;
			}
	for (int i = 0; i < edge_num; ++i)
	{
		g_temp.DeleteArc(edge[i].vertex1,edge[i].vertex2);
        if(!g_temp.IsConnected())
        {
            g_temp.InsertArc(edge[i].vertex1,edge[i].vertex2,edge[i].weight);
        }
	}
	g_temp.Display();
}

//this way is :
//1,Find a cycle, if did not find exit
//2,Delete the max weight edge in the cycle;
//3,return to 1
template <class ElemType, class WeightType>
void MiniSpanTreeTCN_2(const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
{
	Edge edge[100];
	int edge_num = 0;
	AdjMatrixUndirNetwork<ElemType, WeightType> g_temp = g;
	FindCycle(edge,g_temp);
}

bool FindCycle(Edge* edge,const AdjMatrixUndirNetwork<ElemType, WeightType> &g)
{
	for (int v = 0; v < g_temp.GetVexNum(); v++)
	{
		FindWay(v,)
	}
}
#endif

