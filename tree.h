#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include"treenode.h"


using namespace std;
#pragma once
template <typename K, typename V>
class Tree {
private:
    int count;
    K cur_str;
public:
    bool operator ==(const Tree<K,V> &other) const;
    V* operator[](const K& k) const;
    TreeNode<V> *root;
    Tree();
    Tree(const Tree<K,V> &other);
    ~Tree();
    void add_string(const K& k, const V& v);
    bool search_string(const K& k) const;
    void erase(const K& k);
    void clear();
    int size() const;
    void listing(TreeNode<V> *node, vector<K> *listItems);
    void treeFromFile(const string& path);
    void treeToFile(const string& path);
    void printItems(TreeNode<V> *node) const;
    vector<K> searchEnd(const K& k) const;
};
