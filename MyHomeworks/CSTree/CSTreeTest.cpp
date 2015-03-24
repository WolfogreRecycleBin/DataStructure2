#include "CSTree.h"

int main()
{
	char pre[]={'A','B','D','E','G','H','C','F','I'};
	char in[]={'D','B','G','E','H','A','C','F','I'};
	int n = 9;
	CSTree<char> tree(pre, in, n);
	tree.Show();
	cout << tree.Degree();
	return 0;
}
