#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "rbtree.h"
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	system("color f0");
	cout << "请输入节点信息（整数），EOF结尾" << endl;
	vector<int> a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	
	int i;
	int ilen = a.size();
	RBTree<int>* tree = new RBTree<int>();

	cout << "== 原始数据: ";
	for (i = 0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i<ilen; i++)
	{
		tree->insert(a[i]);

	}
	cout << "== 前序遍历: ";
	tree->preOrder();

	cout << "\n== 中序遍历: ";
	tree->inOrder();

	cout << "\n== 后序遍历: ";
	tree->postOrder();
	cout << endl;

	cout << "== 最小值: " << tree->minimum() << endl;
	cout << "== 最大值: " << tree->maximum() << endl;
	cout << "== 树的详细信息: " << endl;
	tree->print();

	//删除测试
	cout << "请输入要删除的数据" << endl;
	int delNode=0;
	scanf("%d", &delNode);
	//cin >> delNode;
	RBTNode<int> *result = tree->iterativeSearch(delNode);
	cout << "== 删除前树的详细信息: " << endl;
	tree->print();
	cout << endl;
	tree->remove(delNode);
	cout << "== 删除节点: " << delNode << endl;
	cout << "== 删除后树的详细信息: " << endl;
	tree->print();
	cout << endl;



	//树的插入函数
	cout << "请输入要插入的数据" << endl;
	int insertNode;
	scanf("%d", &insertNode);
	cout << "== 插入前树的详细信息: " << endl;
	tree->print();
	cout << endl;
	tree->insert(insertNode);
	cout << "== 添加节点: " << insertNode << endl;
	cout << "== 插入后树的详细信息: " << endl;
	tree->print();
	cout << endl;




	cout << "请输入要查找的第k小" << endl;
	
	int num=0;
	
	scanf("%d",&num);
	//cin.flush();
	//cin >> num;

	
	RBTNode<int> *leaf = tree->iterativeSearch(tree->minimum());//最小的节点
	for (int i = 0; i < num-1; ++i) {
		leaf = tree->successor(leaf);
	}
	cout << "第" << num << "小的元素为" << leaf->key << endl;

	
	// 销毁红黑树
	tree->destroy();
	system("pause");
	return 0;
}
