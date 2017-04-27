#include <tree.hpp>
#include <catch.hpp>

SCENARIO ("constructor"){
	BinarySearchTree<int> BST;
	REQUIRE(BST.root() == nullptr);
}
