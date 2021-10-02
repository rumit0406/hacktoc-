#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    vector<Node*> child;
 
    Node(int data) {
        this->data = data;
    }
};

void printTree(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }

    cout << root->data << ' ';

    for (Node* child: root->child) {
        printTree(child);
    }
}

void convertToMirror(Node* root)
{
    // base case
    if (root == nullptr) {
        return;
    }
    for (Node* child: root->child) {
        convertToMirror(child);
    }

    reverse(root->child.begin(), root->child.end());
    for (int i = 0, j = (root->child).size() - 1; i < j; i++, j--) {
        swap(root->child[i], root->child[j]);
    }
    */
}
 
int main()
{
    Node* root = new Node(1);
 
    (root->child).push_back(new Node(2));
    (root->child).push_back(new Node(3));
    (root->child).push_back(new Node(4));
    (root->child).push_back(new Node(5));
    (root->child).push_back(new Node(6));
 
    (root->child[0]->child).push_back(new Node(7));
    (root->child[0]->child).push_back(new Node(8));
    (root->child[0]->child).push_back(new Node(9));
 
    (root->child[2]->child).push_back(new Node(10));
    (root->child[2]->child).push_back(new Node(11));
    (root->child[2]->child).push_back(new Node(12));
 
    (root->child[4]->child).push_back(new Node(13));
    (root->child[4]->child).push_back(new Node(14));
 
    (root->child[0]->child[1]->child).push_back(new Node(15));
    (root->child[0]->child[1]->child).push_back(new Node(16));
 
    (root->child[4]->child[0]->child).push_back(new Node(17));
    (root->child[4]->child[0]->child).push_back(new Node(18));
    (root->child[4]->child[0]->child).push_back(new Node(19));
    (root->child[4]->child[0]->child).push_back(new Node(20));
 
    convertToMirror(root);
    printTree(root);
 
    return 0;
}
