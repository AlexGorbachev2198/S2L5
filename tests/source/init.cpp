#include <tree.hpp>
#include <catch.hpp>

SCENARIO ("constructor"){
	BinaryTree<int> BST;
	REQUIRE(BST.Get_Root() == nullptr);
}
