pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename type>
struct TreeNode
{
	type data_;
	TreeNode *Left_;
	TreeNode *Right_;
	TreeNode *Parent_;
public:
	TreeNode(type D);
	TreeNode();
};


template <typename type>
class BinaryTree
{

	TreeNode<type> *Root_;
public:
	BinaryTree<type>();
	void add(type Data);
	void Rec_Search(type Data, TreeNode<type> *& Head, TreeNode<type> *& Head_Parent);
	void Tree_Print(TreeNode<type>* buff, unsigned int lvl);
	TreeNode<type>* Get_Root();
	TreeNode<type>* Search(type Data, TreeNode<type> *& Head);
	void Delete_Element(type Data);
	void Add_PartTree(TreeNode<type> *& Buff);
};
template <typename type>
TreeNode<type>::TreeNode()
{

}
template <typename type>
TreeNode<type>::TreeNode(type D)
{
	data_ = D;
	Left_ = nullptr;
	Right_ = nullptr;
	Parent_ = nullptr;
}
template <typename type>
BinaryTree<type>::BinaryTree()
{
	Root_ = nullptr;
}
template <typename type>
void BinaryTree<type>::add(type Data)
{
	TreeNode<type> *Head_Parent = new TreeNode<type>();
	Head_Parent = nullptr;
	if (Root_ != nullptr) {
		Rec_Search(Data, Root_, Head_Parent);
	}
	else {
		Root_ = new TreeNode<type>(Data);
	}
}
template <typename type>
void BinaryTree<type>::Rec_Search(type Data, TreeNode<type> *& Head, TreeNode<type> *& Head_Parent)
{
	if (Head == nullptr) {
		Head = new TreeNode<type>(Data);
		Head->Parent_ = Head_Parent;
	}
	else if (Data < Head->data_) {
		Rec_Search(Data, Head->Left_, Head);
	}
	else if (Data > Head->data_) {
		Rec_Search(Data, Head->Right_, Head);
	}
}
template <typename type>
void BinaryTree<type>::Tree_Print(TreeNode<type>* buff, unsigned int lvl)
{
	if (buff != NULL) {
		Tree_Print(buff->Right_, lvl + 1);
		for (unsigned int i = 0; i < lvl; ++i) cout << "--";
		cout << buff->data_ << endl;
		Tree_Print(buff->Left_, lvl + 1);
	}
}
template <typename type>
void BinaryTree<type>::Delete_Element(type Data)
{
	if (Data == Root_->data_)
	{
		type dt = Data;
		if (Root_->Right_ != nullptr) dt = Root_->Right_->data_;
		else
			if (Root_->Left_ != nullptr) dt = Root_->Left_->data_;
			else {
				Root_ = nullptr; return;
			}
			Delete_Element(dt);
			Root_->data_ = dt;
			TreeNode<type> *BufferL = Root_->Left_;
			TreeNode<type> *BufferR = Root_->Right_;
			Root_->Left_ = nullptr;
			Root_->Right_ = nullptr;
			Add_PartTree(BufferL);
			Add_PartTree(BufferR);
	}
	else {
		TreeNode<int> *Buffer = Search(Data, Root_);
		if (Buffer->data_ > Buffer->Parent_->data_)
		{
			Buffer->Parent_->Right_ = nullptr;
		}
		else Buffer->Parent_->Left_ = nullptr;

		Add_PartTree(Buffer->Left_);
		Add_PartTree(Buffer->Right_);
	}
}
template <typename type>
void BinaryTree<type>::Add_PartTree(TreeNode<type> *& Buff)
{
	if (Buff != nullptr) {
		add(Buff->data_);
		Add_PartTree(Buff->Left_);
		Add_PartTree(Buff->Right_);
	}
}
template <typename type>
TreeNode<type>* BinaryTree<type>::Search(type Data, TreeNode<type> *& Head)
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
template <typename type>
TreeNode<type>* BinaryTree<type>::Get_Root()
{
	return Root_;
}
