#include "BinaryTree.h"
struct FBData
{
	int num;
	bool s;
};
class FallingBall
{
public:
	FallingBall(int height = 1);
	~FallingBall();
	int Fall();
protected:
	int Fall(BinTreeNode<FBData>* p);
private:
	BinaryTree<FBData> *p_tree;
};

FallingBall::FallingBall(int height)
{
	FBData fbd;
	fbd.num = 1;
	fbd.s = false;
	p_tree = new BinaryTree<FBData>(fbd);
	LinkQueue<BinTreeNode<FBData>*> queue;
	queue.EnQueue(p_tree->GetRoot());
	int num = 2;
	for(int i = 1; i < height; ++i)
	{
		for(int j = 1; j <= 1<<(i - 1); ++j)
		{
			BinTreeNode<FBData>* p;
			queue.DelQueue(p);
			FBData l_fbd;
			l_fbd.num = num++;
			l_fbd.s = false;
			p->leftChild = new BinTreeNode<FBData>(l_fbd);
			queue.EnQueue(p->leftChild);
			FBData r_fbd;
			r_fbd.num = num++;
			r_fbd.s = false;
			p->rightChild = new BinTreeNode<FBData>(r_fbd);
			queue.EnQueue(p->rightChild);
		}
	}
	//DisplayBTWithTreeShape<FBData>(*p_tree);
}

FallingBall::~FallingBall()
{
	p_tree->~BinaryTree();
}

int FallingBall::Fall()
{
	return Fall(p_tree->GetRoot());
}

int FallingBall::Fall(BinTreeNode<FBData>* p)
{
	
	if(p->leftChild == NULL)
		return (p->data).num;
	if(!p->data.s)
	{
		p->data.s = !p->data.s;
		return Fall(p->leftChild);
	}
	p->data.s = !p->data.s;
	return Fall(p->rightChild);
	
}
