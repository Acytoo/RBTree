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
	cout << "������ڵ���Ϣ����������EOF��β" << endl;
	vector<int> a;
	int x;
	while (cin >> x) {
		a.push_back(x);
	}
	
	int i;
	int ilen = a.size();
	RBTree<int>* tree = new RBTree<int>();

	cout << "== ԭʼ����: ";
	for (i = 0; i<ilen; i++)
		cout << a[i] << " ";
	cout << endl;

	for (i = 0; i<ilen; i++)
	{
		tree->insert(a[i]);

	}
	cout << "== ǰ�����: ";
	tree->preOrder();

	cout << "\n== �������: ";
	tree->inOrder();

	cout << "\n== �������: ";
	tree->postOrder();
	cout << endl;

	cout << "== ��Сֵ: " << tree->minimum() << endl;
	cout << "== ���ֵ: " << tree->maximum() << endl;
	cout << "== ������ϸ��Ϣ: " << endl;
	tree->print();

	//ɾ������
	cout << "������Ҫɾ��������" << endl;
	int delNode=0;
	scanf("%d", &delNode);
	//cin >> delNode;
	RBTNode<int> *result = tree->iterativeSearch(delNode);
	cout << "== ɾ��ǰ������ϸ��Ϣ: " << endl;
	tree->print();
	cout << endl;
	tree->remove(delNode);
	cout << "== ɾ���ڵ�: " << delNode << endl;
	cout << "== ɾ����������ϸ��Ϣ: " << endl;
	tree->print();
	cout << endl;



	//���Ĳ��뺯��
	cout << "������Ҫ���������" << endl;
	int insertNode;
	scanf("%d", &insertNode);
	cout << "== ����ǰ������ϸ��Ϣ: " << endl;
	tree->print();
	cout << endl;
	tree->insert(insertNode);
	cout << "== ��ӽڵ�: " << insertNode << endl;
	cout << "== �����������ϸ��Ϣ: " << endl;
	tree->print();
	cout << endl;




	cout << "������Ҫ���ҵĵ�kС" << endl;
	
	int num=0;
	
	scanf("%d",&num);
	//cin.flush();
	//cin >> num;

	
	RBTNode<int> *leaf = tree->iterativeSearch(tree->minimum());//��С�Ľڵ�
	for (int i = 0; i < num-1; ++i) {
		leaf = tree->successor(leaf);
	}
	cout << "��" << num << "С��Ԫ��Ϊ" << leaf->key << endl;

	
	// ���ٺ����
	tree->destroy();
	system("pause");
	return 0;
}
