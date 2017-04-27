#include"tree.h"
void main()
{
	BinaryTree<int> Tree;
	ifstream pF;
	pF.open("Tree.txt");
	unsigned int n;
	if (pF.is_open()) {
		pF >> n;
		for (unsigned int i = 0; i < n; ++i)
		{
			int buffer = 0;
			pF >> buffer;
			Tree.add(buffer);
		}
	}
	else cout << "Error, file is not open" << endl;
	cout << endl;
	Tree.Tree_Print(Tree.Get_Root(), 0);
	bool T = true;
	while (T)
	{
		int data;
		unsigned int choice;
		cout << "If you want to delete element type 0, to add - 1" << endl;
		cin >> choice;
        switch (choice)
		{
		case 0:
			cout << "Input element for deletion" << endl;
			cin >> data;
			Tree.Delete_Element(data);
			cout << endl;
			Tree.Tree_Print(Tree.Get_Root(), 0);
			break;
		case 1:
			cout << "Input element for addition" << endl;
			cin >> data;
			Tree.add(data);
			cout << endl;
			Tree.Tree_Print(Tree.Get_Root(), 0);
			break;
		default:
			break;
		}

		cin.clear();
		string Y;
		cout << "Do you want to add/delete another element?" << endl;
		cin >> Y;
		if (Y == "yes") T = true;
		else T = false;
	}
	system("pause");
}
