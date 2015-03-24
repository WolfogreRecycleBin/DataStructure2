#include "CSTree.h"

int main()
{
	char pre[]={'A','B','E','F','K','L','C','G','D','H','I','M','N','J'};
	char in[]= {'E','K','L','F','B','G','C','H','M','N','I','J','D','A'};
	int n = 14;
	CSTree<char> tree(pre, in, n);
	tree.Show();
	cout << tree.Degree();
	return 0;
}
