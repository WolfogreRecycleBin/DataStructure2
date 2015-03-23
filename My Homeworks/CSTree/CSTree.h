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
// �����������֪����������������pre[preLeft..preRight]����������in[inLeft..inRight]����
//	��rΪ���Ķ�����
{
	if (inLeft > inRight)	// �������޽��,�ն�����
		r = NULL;			// �ն�������Ϊ��
	else	{	// �������н��,�ǿն�����
		r = new BinTreeNode<ElemType>(pre[preLeft]);// ���ɸ����
		int mid = inLeft;
		while (in[mid] != pre[preLeft]) 	// ����pre[preLeft]��in[]�е�λ��,Ҳ�������������и���λ��
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);
			// ����������
		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, 
			inRight);								// ����������
	}
} 

template <class ElemType>
BinaryTree<ElemType> &CreateBinaryTree(ElemType pre[], ElemType in[], int n)
// �����������֪������������й��������
{
	BinTreeNode<ElemType> *r;						// �������ĸ�
	CreateBinaryTree<ElemType>(r, pre, in, 0, n - 1, 0, n - 1);
		// ��������������й�����rΪ���Ķ����� 
	BinaryTree<ElemType> *bt = new BinaryTree<ElemType>(r);	// ���ɶ�����
	return *bt;
}
#endif

