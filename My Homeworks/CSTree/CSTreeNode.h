#ifndef __CS_TREE_NODE_H__
#define __CS_TREE_NODE_H__

#include <iostream>
using namespace std;

template <class ElemType>
struct CSTreeNode
{
	ElemType data;
	CSTreeNode<ElemType> *first_child;
	CSTreeNode<ElemType> *next_sibling;
	CSTreeNode();
	CSTreeNode(ElemType item, CSTreeNode<ElemType> *filrt_child_ = NULL, CSTreeNode<ElemType> *next_sibling_ = NULL);
};

template<class ElemType>
CSTreeNode<ElemType>::CSTreeNode()
{
   first_child = NULL;
   next_sibling = NULL;
}

template<class ElemType>
CSTreeNode<ElemType>::CSTreeNode(ElemType item, CSTreeNode<ElemType> *first_child_, CSTreeNode<ElemType> *next_sibling_)
{
   data = item;
   first_child = first_child_;
   next_sibling = next_sibling_;
}

#endif
