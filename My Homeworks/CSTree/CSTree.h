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
	CSTree(CSTreeNode<ElemType> *inorder_array, CSTreeNode<ElemType> *preorder_array);
	CSTree<ElemType> &operator=(const CSTree<ElemType> &t);
	virtual ~CSTree(){};
	bool IsEmpty() const;
	bool Show() const;
	bool Insert(const ElemType &parent, const ElemType &prior_sibling);
	bool Delete(const ElemType &n);
protected:
	void (*Visit)(const ElemType &e);//if I add "const" in the end, it will be wrong, I don`t know why.
	CSTreeNode<ElemType>* Find(const ElemType &e);
private:
	CSTreeNode<ElemType> *root;
};

CSTree<ElemType>::CSTree()
{
	root = NULL;
}

CSTree<ElemType>::CSTree(const ElemType &e)
{
	root = new CSTreeNode(e);
}

CSTree(CSTreeNode<ElemType> *inorder_array, CSTreeNode<ElemType> *preorder_array, int length)
{

}

template <class ElemType>
void CreateBinaryTree(BinTreeNode<ElemType> *&r, ElemType pre[], ElemType in[], 
							int preLeft, int preRight, int inLeft, int inRight)	
// 操作结果：已知二叉树的先序序列pre[preLeft..preRight]和中序序列in[inLeft..inRight]构造
//	以r为根的二叉树
{
	if (inLeft > inRight)	// 二叉树无结点,空二叉树
		r = NULL;			// 空二叉树根为空
	else	{	// 二叉树有结点,非空二叉树
		r = new BinTreeNode<ElemType>(pre[preLeft]);// 生成根结点
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// 查找pre[preLeft]在in[]中的位置,也就是中序序列中根的位置
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// 生成左子树
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, 
			inRight);								// 生成右子树
	}
} 

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
// 操作结果：已知先序和中序序列构造二叉树
{
	BinTreeNode<ElemType> *r;						// 二叉树的根
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// 由先序和中序序列构造以r为根的二叉树 
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);	// 生成二叉树
	return *bt;
}
#endif

