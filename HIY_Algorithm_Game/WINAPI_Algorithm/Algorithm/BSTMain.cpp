#include <unordered_map>
#include <map>

#include "BinarySearchTree.h"

// 해쉬 테이블 : 메모리를 주고 탐색 시간을 취한다.
// 탐색 : 상수 ... 해쉬 충돌로 인한 체이닝에 따라 달라질 수 있다.
// 삽입 : 상수
// 충돌, 체이닝

// 자가 균형 이진 탐색 트리
// 탐색 : logN
// 삽입 : logN

// 해쉬 테이블 vs 자가 균형 이진 탐색 트리
// 해쉬 함수 후 충돌이 많이 일어날 경우 ... 자가 균형 이진 탐색 트리 승
// 충돌이 적을 경우 ... 해쉬 테이블 승

int main()
{
#pragma region BST
	BinarySearchTree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);

	bst.Insert(100);
	bst.Insert(60);
	bst.Insert(47);

	bst.PrintTree(bst._root);

	Node* tmp = bst.Search(bst._root, 100);
	if (tmp != nullptr)
	{
		cout << tmp->key << endl;
	}
	else
	{
		cout << "해당 노드가 없습니다." << endl;
	}

	tmp = bst.Min(bst._root);
	cout << tmp->key << endl;

	tmp = bst.Max(bst._root);
	cout << tmp->key << endl;
#pragma endregion

	unordered_map<int, int> um;

	um[5] = 1;

	return 0;
}