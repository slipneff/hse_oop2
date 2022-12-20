#pragma once
#define sizeNode 10
template <typename V>
class TreeNode {
public:
	TreeNode* to[sizeNode];
	bool terminated;
	V address;
	TreeNode();
	~TreeNode();
};
