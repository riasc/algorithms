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
    BinaryTree();

    // getter n' setter
    Node * get_root();
    void set_root(Node * rootnode); 

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

BinaryTree::BinaryTree() {
  root = NULL;
}

Node* BinaryTree::get_root() {
  return root;
}

void BinaryTree::set_root(Node * rootnode) {
  root = rootnode;
}

void BinaryTree::preorder_tree_walk(Node *startnode) {
  if ( startnode != NULL ) {
    cout << startnode->key << endl;
    preorder_tree_walk(startnode->left);
    preorder_tree_walk(startnode->right);
  }
}

void BinaryTree::inorder_tree_walk(Node *startnode) {
}

void BinaryTree::postorder_tree_walk(Node *startnode) {
}

void BinaryTree::insert(Node *insertnode) {
  Node * buf = NULL; // buffering nodes
  Node * element = get_root(); // start with root
  while ( root != NULL ) {
    buf = root; // 
    if ( insertnode->key < element->key ) {
      element = element->left;
    } else {
      element = element->right; 
    }
  }
  if ( buf == NULL ) {
    set_root(insertnode);
  } else {
    if ( insertnode->key < buf->key ) {
      buf->left = insertnode; 
    }
    else {
      buf->right = insertnode; 
    }
  }
}

/*Node* BinaryTree::search(int searchvalue) {
}*/


int main() {
  BinaryTree bt; // create new binary tree object
  int menu = 0; // 
  int key;
  
  Node tempnode;
  Node * ptrnode = &tempnode;

  while (menu != 9) {
    cout << "(1) - insert node" << endl;
    cout << "(2) - print tree (preorder tree walk)" << endl;
    cout << "(9) - exit" << endl;
    cin >> menu;
    switch(menu) {
      case 1: cout << "key to insert ";
              cin >> key; // get key input from user
              ptrnode->key = key; // add inserted key
              bt.insert(ptrnode);
              break;
      case 2: bt.preorder_tree_walk(bt.get_root());
              break;
      case 9: cout << "exit program - e called" << endl;
              exit(0);
    }
  }
}
