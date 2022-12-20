#include<iostream>
#include<assert.h>
#include"Tree.cpp"

int main() {
	const string TEST_KEY = "1234";
	const string TEST_KEY2 = "12345";
	const string TEST_VALUE = "abc";
	const string TEST_VALUE2 = "abcd";
	const string PATH = "test1.txt";

	Tree<string,string> bor1;
	assert(bor1.size()==0);
	bor1.add_string(TEST_KEY,TEST_VALUE);
	assert(bor1.size()==1);
	bor1.add_string(TEST_KEY,TEST_VALUE);
	assert(bor1.size()==1);
	assert(bor1.search_string(TEST_KEY)==true);

	Tree<string,string> bor2(bor1);
	assert(bor1.size()==1);
	assert(bor1.search_string(TEST_KEY)==true);
	assert(*bor1[TEST_KEY]==TEST_VALUE);

	bor1.treeToFile(PATH);
	Tree<string,string> bor3;
	bor3.treeFromFile(PATH);
	assert(bor1==bor3);

	*bor2[TEST_KEY]=TEST_VALUE2;
	assert(*bor2[TEST_KEY]==TEST_VALUE2);

	bor1.erase(TEST_KEY);
	assert(bor1.size()==0);

	bor1.add_string(TEST_KEY,TEST_VALUE);
	bor1.add_string(TEST_KEY2,TEST_VALUE2);
	bor1.clear();

	assert(bor1.size()==0);
	cout<<"Success!";
}
