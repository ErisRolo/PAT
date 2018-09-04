/* 1123. Is It a Complete AVL Tree (30)

An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to output the level-order traversal sequence of the resulting AVL tree, and to tell if it is a complete binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 20). Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, insert the keys one by one into an initially empty AVL tree. Then first print in a line the level-order traversal sequence of the resulting AVL tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. Then in the next line, print "YES" if the tree is complete, or "NO" if not.

Sample Input 1:
5
88 70 61 63 65
Sample Output 1:
70 63 88 61 65
YES
Sample Input 2:
8
88 70 61 96 120 90 65 68
Sample Output 2:
88 65 96 61 70 90 120 68
NO */

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N;

struct Node{
	int data;
	int height;
	Node *left;
	Node *right;
};

vector<Node *> vec; // 保存层序结果

// 主要是为了更新高度
Node *newNode(int data){
	Node *node = new Node;
	node->data = data;
	node->height = 1;
	node->left = node->right = NULL;
	return node;
}

int getHeight(Node *root){
	if(root == NULL) return 0;
	return root->height;
}

void update(Node *root){
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int balance(Node *root){
	return getHeight(root->left) - getHeight(root->right);
}

// 适合 RR 型， 左旋
//    1
//   /  \
//  1    1
//      / \
//     1   1
//          \
//          (X)
void L(Node *&root){
	Node *tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	update(root); // 更新高度
	update(tmp);
	root = tmp;
}

// 适合 LL 型， 左旋
//       1
//      / \ 
//     1   1 
//    / \
//   1   1
//  /
// (X)
void R(Node *&root){
	Node *tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	update(root); // 更新高度
	update(tmp);
	root = tmp;
}




void insert(Node *&root, int data){
	if(root==NULL){
		root = newNode(data);
	}
	else{
		if(data < root->data){
			insert(root->left, data);
			update(root);
			if(balance(root) == 2){
				if(balance(root->left) == 1){
					// LL 型， 右旋 root
					R(root);
				}
				else if(balance(root->left) == -1){
					// LR 型， 先左旋 left， 再右旋 root
					L(root->left); // 这里 L 就是左旋
					R(root);       
				}
			}
		}
		else if(data > root->data){
			insert(root->right, data);
			update(root);
			if(balance(root) == -2){
				if(balance(root->right) == -1){
					// RR 型， 左旋 root
					L(root);
				}
				else if(balance(root->right) == 1){
					// RL 型， 先右旋 right， 再左旋 root
					R(root->right); 
					L(root);       
				}
			}
		}
	}

}

void levelTraverse(Node *root){
	queue<Node *> q;
	q.push(root);
	bool flag = true;
	vec.push_back(NULL);
	while(!q.empty()){
		Node *now = q.front();
		if(flag){
			flag = false;
			printf("%d", now->data);
		}
		else{
			printf(" %d", now->data);
		}
		vec.push_back(now);
		q.pop();
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
	printf("\n");
}

void isComplete(Node *root){
	bool flag = true;
	// vec 按编号保存 node
	// 1 2 3 4 5 ... 10 ... 
	for(int i = N; i > 1; i--){
		int parent_index = i / 2;
		if(i % 2){ // 奇数， 则是右节点
			if(vec[parent_index]->right != vec[i]){
				flag = false;
				break;
			}
		}
		else{
			if(vec[parent_index]->left != vec[i]){
				flag = false;
				break;
			}
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}



int main(){
	scanf("%d", &N);
	int tmp;
	Node *root = NULL;
	for(int i = 0; i < N; i++){
		scanf("%d", &tmp);
		insert(root, tmp);
	}
	levelTraverse(root);
	isComplete(root);
	return 0;
}