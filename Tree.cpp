#include"Tree.h"
template <typename K, typename V>
Tree<K,V>::Tree() {
	root = new TreeNode<V>();
	count = 0;
	cur_str = "";
}


template <typename K, typename V>
Tree<K, V>::~Tree() {
	//help
}
template <typename K, typename V>
Tree<K, V>::Tree(const Tree& other) : root(other.root), count(other.count) {};

template <typename K, typename V>
void Tree<K, V>::add_string(const K& k, const V& v) {
	TreeNode<V> *buff = root;
	for (char c : k) {
		int letter = c - '0';

		if (!buff->to[letter]) {

			buff->to[letter] = new TreeNode<V>();
		}
		buff = buff->to[letter];
	}
	if(buff->terminated == false)
		count++;
	buff->terminated = true;
	buff->address = v;
}
template <typename K, typename V>
bool Tree<K, V>::search_string(const K& k) const{
	TreeNode<V> *buff = root;
	for (char c : k) {
		int letter = c - '0';
		if (!buff->to[letter])
			return false;
		buff = buff->to[letter];
	}
	return true;
}

template <typename K, typename V>
void Tree<K, V>::erase(const K& k) {
	TreeNode<V> *v = root;
	for (char c : k)
		v = v->to[int(c - '0')];
	v->terminated = false;
	count--;
}

template <typename K, typename V>
int Tree<K, V>::size()  const{
	return count;
}

template <typename K, typename V>
void Tree<K, V>::treeFromFile(const string& path) {
	ifstream infile(path);
	K key;
	V value;
	while (!infile.eof()) {
		infile >> key >> value;
		this->add_string(key, value);
	}
}
template <typename K, typename V>
void Tree<K, V>::treeToFile(const string& path){
	vector<K> listItems;
	listing(this->root,&listItems);
	ofstream outfile(path);
	for (int i = 0; i < listItems.size(); i++) {
        outfile << listItems[i] <<" "<< *(*this)[listItems[i]] << endl;
    }
}
template <typename K, typename V>
void Tree<K, V>::printItems(TreeNode<V> *node) const{
	vector<K> listItems;
	listing(node,&listItems);
	for (int i = 0; i < listItems.size(); i++) {
        cout <<"Found: "<< listItems[i]<<" "<<*(*this)[listItems[i]] << endl;
    }
}

template <typename K, typename V>
bool Tree<K,V>::operator ==(const Tree<K,V> &other) const{
	for (int i = 0; i < 10; i++) {
		if(this->root->to[i] != other.root->to[i])
			return false;
    }
	return true;
	//adresa
}

template <typename K, typename V>
V* Tree<K,V>:: operator [](const K& k) const{
	TreeNode<V> *buff = root;
	for (char c : k) {
		int letter = c - '0';
		if (!buff->to[letter])
			return nullptr;
		buff = buff->to[letter];
	}
	V* ptr = &buff->address;
	return ptr;
}
template <typename K, typename V>
vector<K> Tree<K,V>::searchEnd(const K& k) const{
	vector<K> listItems={};
	TreeNode<V> *buff = root;
	for (char c : k) {
		int letter = c - '0';
		if (!buff->to[letter])
			return listItems;
		buff = buff->to[letter];
	}
	listing(buff,&listItems);
	for(int i=0;i<listItems.size();i++){
		listItems[i]=k+listItems[i];
	}
	return listItems;
}
template <typename K, typename V>
void Tree<K,V>::listing(TreeNode<V> *node, vector<K>* listItems){
	for (int i = 0; i < int(node->terminated); i++) {
        listItems->push_back(cur_str);
    }
	for (int i = 0; i < 10; i++) {
        if (node->to[i] != NULL) {
            cur_str.push_back('0' + i);
            listing(node->to[i],listItems);
            cur_str.pop_back();
        }
    }
}

template <typename K, typename V>
void Tree<K,V>::clear(){
	delete this->root;
	this->count=0;
}
