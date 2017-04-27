#include <tree.hpp>
#include <catch.hpp>

SCENARIO ("Constructor"){
	BinaryTree<int> Tr;
	REQUIRE(Tr.Get_Root() == nullptr);
}
SCENARIO ("Add"){
	BinaryTree<int> tr;
	tr.add(6);
	tr.add(4);
	tr.add(8);
	REQUIRE(tr.Get_Root()->data_ == 6);
	REQUIRE(tr.Get_Root()->Left_->data_ == 4);
	REQUIRE(tr.Get_Root()->Right_->data_ == 8);
}
SCENARIO ("Delete"){
	BinaryTree<int> tr;
	tr.add(6);
	tr.add(4);
	tr.add(8);
	tr.Delete_Element(4);
	REQUIRE(tr.Get_Root()->Left_ == nullptr);
}
