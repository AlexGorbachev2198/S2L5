#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct TreeNode
{
	int data_;
	TreeNode *Left_;
	TreeNode *Right_;
	TreeNode *Parent_;
public:
	TreeNode(int D);
	TreeNode();
};
class BinaryTree
{
	TreeNode *Root_;
public:
	BinaryTree();
	void add(int Data);
	void Rec_Search(int Data, TreeNode *& Head, TreeNode *& Head_Parent);
	void Tree_Print(TreeNode* buff, unsigned int lvl);
	TreeNode* Get_Root();
	TreeNode* Search(int Data, TreeNode *& Head);
	void Delete_Element(int Data);
	void Add_PartTree(TreeNode *& Buff);
};
TreeNode::TreeNode()
{

}
TreeNode::TreeNode(int D)
{
	data_ = D;
	Left_ = nullptr;
	Right_ = nullptr;
	Parent_ = nullptr;
}
BinaryTree::BinaryTree()
{
	Root_ = nullptr;
}
void BinaryTree::add(int Data)
{
	TreeNode *Head_Parent = new TreeNode();
	Head_Parent = nullptr;
	if (Root_ != nullptr) {
		Rec_Search(Data, Root_, Head_Parent);
	}
	else {
		Root_ = new TreeNode(Data);
	}
}
void BinaryTree::Rec_Search(int Data, TreeNode *& Head, TreeNode *& Head_Parent)
{
	if (Head == nullptr) {
		Head = new TreeNode(Data);
		Head->Parent_ = Head_Parent;
	}
	else if (Data < Head->data_) {
		Rec_Search(Data, Head->Left_, Head);
	}
	else if (Data > Head->data_) {
		Rec_Search(Data, Head->Right_, Head);
	}
}
void BinaryTree::Tree_Print(TreeNode* buff, unsigned int lvl)
{
	if (buff != NULL) {
		Tree_Print(buff->Right_, lvl + 1);
		for (unsigned int i = 0; i < lvl; ++i) cout << "--";
		cout << buff->data_ << endl;
		Tree_Print(buff->Left_, lvl + 1);
	}
}
void BinaryTree::Delete_Element(int Data)
{
	if (Data == Root_->data_)
	{
		int dt = Data;
		if (Root_->Right_ != nullptr) dt = Root_->Right_->data_;
		else
			if (Root_->Left_ != nullptr) dt = Root_->Left_->data_;
			else {
				Root_ = nullptr; return;
			}
			Delete_Element(dt);
			Root_->data_ = dt;
			TreeNode *BufferL = Root_->Left_;
			TreeNode *BufferR = Root_->Right_;
			Root_->Left_ = nullptr;
			Root_->Right_ = nullptr;
			Add_PartTree(BufferL);
			Add_PartTree(BufferR);
	}
	else {
		TreeNode *Buffer = Search(Data, Root_);
		if (Buffer->data_ > Buffer->Parent_->data_)
		{
			Buffer->Parent_->Right_ = nullptr;
		}
		else Buffer->Parent_->Left_ = nullptr;

		Add_PartTree(Buffer->Left_);
		Add_PartTree(Buffer->Right_);
	}
}
void BinaryTree::Add_PartTree(TreeNode *& Buff)
{
	if (Buff != nullptr) {
		add(Buff->data_);
		Add_PartTree(Buff->Left_);
		Add_PartTree(Buff->Right_);
	}
}
TreeNode* BinaryTree::Search(int Data, TreeNode *& Head)
{
	if (Head->data_ == Data)
		return Head;
	else if (Data < Head->data_) {
		Search(Data, Head->Left_);
	}
	else if (Data > Head->data_) {
		Search(Data, Head->Right_);
	}
}
TreeNode* BinaryTree::Get_Root()
{
	return Root_;
}
void main()
