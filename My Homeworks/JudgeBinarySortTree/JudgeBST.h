#ifndef __JUDGE_BST_H__
#define __JUDGE_BST_H__

#include "BinaryTree.h"
#include "BinTreeNode.h"

#include <iostream>
using namespace std;

template <class ElemType>
bool JudgeBST(const BinaryTree<ElemType> &tree);

template <class ElemType>
bool CheckSubtree(BinTreeNode<ElemType> *sub_root, ElemType *min, ElemType *max);


template <class ElemType>
bool JudgeBST(const BinaryTree<ElemType> &tree)
{
	BinTreeNode<ElemType> *root = tree.GetRoot();
	
	ElemType *l_min = NULL;
	ElemType *l_max = new ElemType(root->data);
	ElemType *r_min = new ElemType(root->data);
	ElemType *r_max = NULL;
	
	bool result = true;
	if(!CheckSubtree(root->leftChild,l_min,l_max) || !CheckSubtree(root->rightChild,r_min,r_max))
		result = false;
	if(l_min != NULL)	delete l_min;
	if(l_max != NULL)	delete l_max;
	if(r_min != NULL)	delete r_min;
	if(r_max != NULL)	delete r_max;
	return result;
}

template <class ElemType>
bool CheckSubtree(BinTreeNode<ElemType> *sub_root, ElemType *min, ElemType *max)
{
	if(sub_root == NULL)
		return true;
	if(max != NULL && sub_root->data > *max)
	{
		cout << sub_root->data << "大于" << *max << endl;
		return false;
	}
	if(min != NULL && sub_root->data < *min)
	{
		cout << sub_root->data << "小于" << *min << endl;
		return false;
	}

	ElemType *l_min = NULL;
	ElemType *l_max = new ElemType(sub_root->data);
	ElemType *r_min = new ElemType(sub_root->data);
	ElemType *r_max = NULL;
	if(min != NULL)
		l_min = new ElemType(*min);
	if(max != NULL)
		r_max = new ElemType(*max);

	bool result = true;
	if(!CheckSubtree(sub_root->leftChild,l_min,l_max) || !CheckSubtree(sub_root->rightChild,r_min,r_max))
		result = false;
	if(l_min != NULL)	delete l_min;
	if(l_max != NULL)	delete l_max;
	if(r_min != NULL)	delete r_min;
	if(r_max != NULL)	delete r_max;
	return result;
}

#endif
