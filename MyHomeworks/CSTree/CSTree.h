#ifndef __CS_TREE_H__
#define __CS_TREE_H__

#include "CSTreeNode.h"

template <class ElemType>
class CSTree
{
public:
	CSTree();
	CSTree(const ElemType &e);
	CSTree(const CSTree<ElemType> &t);
	CSTree(ElemType *preorder_array, ElemType *inorder_array, int length);
	CSTree<ElemType> &operator=(const CSTree<ElemType> &t);
	virtual ~CSTree(){};
	void Show() const;
	int Degree();
protected:
	void CreateCSTree(CSTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
							int preLeft, int preRight, int inLeft, int inRight);
	void Show(CSTreeNode<ElemType> *r, int level) const;
	int Degree(int max_degree, CSTreeNode<ElemType> *r);//not return the degree of Node r, but return the degree of the tree which r point.
private:
	CSTreeNode<ElemType> *root;
};

template <class ElemType>
CSTree<ElemType>::CSTree()
{
	root = NULL;
}

template <class ElemType>
CSTree<ElemType>::CSTree(const ElemType &e)
{
	root = new CSTreeNode<ElemType>(e);
}

template <class ElemType>
CSTree<ElemType>::CSTree(ElemType *preorder_array, ElemType *inorder_array, int length)
{
	CreateCSTree(root, preorder_array, inorder_array, 0, length - 1, 0, length - 1);
}

template <class ElemType>
void CSTree<ElemType>::Show() const
{
	Show(root, 1);
	cout << endl;
}

template <class ElemType>
int CSTree<ElemType>::Degree()
{
	return Degree(0, root);
}

template <class ElemType>
void CSTree<ElemType>::CreateCSTree(CSTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
							int preLeft, int preRight, int inLeft, int inRight)	
{
	if (inLeft > inRight)
		r = NULL;
	else	{
		r = new CSTreeNode<ElemType>(pre[preLeft]);
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
			mid++;
		CreateCSTree(r->first_child, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
		CreateCSTree(r->next_sibling, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, inRight);
	}
} 

template <class ElemType>
void CSTree<ElemType>::Show(CSTreeNode<ElemType> *r, int level) const
{
	if(r != NULL)
	{
		Show(r->next_sibling, level + 1);
		cout << endl;
		for(int i = 0; i < level - 1; i++)
			cout << "  ";
		cout << r->data;
		Show(r->first_child, level + 1);
	}
}

template <class ElemType>
int CSTree<ElemType>::Degree(int max_degree, CSTreeNode<ElemType> *r)
{
	if(r == NULL) return 0;
	int new_max_degree = max_degree;
	CSTreeNode<ElemType> *p = r;
	int count_degree = 0;
	while(p->next_sibling != NULL)
	{
		p = p->next_sibling;
		++count_degree;
	}
	if(count_degree > new_max_degree)
		new_max_degree = count_degree;
	int temp_degree = Degree(new_max_degree, r -> first_child);
	if(temp_degree > new_max_degree)
		new_max_degree = temp_degree;
	temp_degree = Degree(new_max_degree, r -> next_sibling);
	if(temp_degree > new_max_degree)
		new_max_degree = temp_degree;
	return new_max_degree;
}

#endif

