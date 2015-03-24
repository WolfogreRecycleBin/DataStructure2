#include "CSTree.h"

int main()
{
	int n = 14;
	char pre1[]={'A','B','E','F','K','L','C','G','D','H','I','M','N','J'};
	char in1[]= {'E','K','L','F','B','G','C','H','M','N','I','J','D','A'};
	CSTree<char> tree1(pre1, in1, n);
	tree1.Show();
	cout <<"Degree of this tree is " << tree1.Degree() << endl;
	system("pause");
	char pre2[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N',};
	char in2[]= {'B','C','D','E','F','G','H','I','J','K','L','M','N','A'};
	CSTree<char> tree2(pre2, in2, n);
	tree2.Show();
	cout <<"Degree of this tree is " << tree2.Degree() << endl;
	system("pause");
	return 0;
}
