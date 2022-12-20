#include"TreeNode.h"
template <typename V>
TreeNode<V>::TreeNode() {
	for (int i = 0; i < sizeNode; i++)
		to[i] = NULL;
	terminated = 0;
	address = "";
}
template <typename V>
TreeNode<V>::~TreeNode() {
	for(int i=0;i<sizeNode;i++)
		if(to[i]!=nullptr)
			delete to[i];
	if(to == nullptr)
		delete[] to;
}
