#include <iostream>
#include <stddef.h>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

class BinaryTree {
  private:
    Node* root;

  public:
    Node* getRoot();
    void preorder_tree_walk(Node *startnode);
    void inorder_tree_walk(Node *startnode);
    void postorder_tree_walk(Node *startnode);

    void insert(Node* insertnode);
    Node* search(int value);
    Node* search_iterative();
    Node* minimum();
    Node* maximum();
    Node* successor();
    Node* predecessor();
};

Node* BinaryTree::getRoot() {
  return root;
}

void BinaryTree::preorder_tree_walk(Node *startnode) {
}


void BinaryTree::inorder_tree_walk(Node *startnode) {
}


void BinaryTree::postorder_tree_walk(Node *startnode) {
}

void BinaryTree::insert(Node *insertnode) {
  Node * buf = NIL; // buffering nodes
}

Node* BinaryTree::search(int searchvalue) {

}


int main() {
  BinaryTree bt;
  string menu;
  int key;
  
  Node tempnode;
  Node * ptrnode = &tempnode;

  while (menu != "e"){
    cout << "(i) - insert node" << endl;
    cin >> key; // get key input from user
    ptrnode->key = key; // add inserted key
    bt.insert(ptrnode);
  }

  cout << "exit program - e called" << endl;
}




  
  
  
  
  
