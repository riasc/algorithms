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
    cout << "key: " << startnode->key << endl;
    preorder_tree_walk(startnode->left);
    preorder_tree_walk(startnode->right);
  }
}

void BinaryTree::inorder_tree_walk(Node *startnode) {
  if ( startnode != NULL ) {
    preorder_tree_walk(startnode->left);
    cout << "key: " << startnode->key << endl;
    preorder_tree_walk(startnode->right);
  }
}

void BinaryTree::postorder_tree_walk(Node *startnode) {
  if ( startnode != NULL ) {
    preorder_tree_walk(startnode->left);
    preorder_tree_walk(startnode->right);
    cout << "key: " << startnode->key << endl;
  }
}

// insert new node into binary tree
void BinaryTree::insert(Node *insertnode) {
  Node * buff = NULL; // buffering nodes
  Node * elem  = get_root(); // start with provided root
  while ( elem != NULL ) { // 
    buff = elem; // 
    if ( insertnode->key < elem->key ) {
      elem = elem->left;
    } else {
      elem = elem->right; 
    }
  }
  if ( buff == NULL ) {
    cout << "binary tree is empty - set root" << endl;
    set_root(insertnode);
  } else {
    if ( insertnode->key < buff->key ) {
      buff->left = insertnode; 
    }
    else {
      buff->right = insertnode; 
    }
  }
}

// search for value k starting with root x
Node* BinaryTree::search(Node * x, int k) {
  if ( x == NULL ) || ( k == x->key ) {
    return root; 
  }
  if ( k < x->key ) {
    return search( x->left, k); 
  }


}

int main() {
  BinaryTree bt; // create new binary tree object
  int menu = 0; // 
  Node * temp;

  while (1) {
    cout << endl<<endl;
    cout << "(1) - insert node" << endl;
    cout << "(2) - print tree (preorder tree walk)" << endl;
    cout << "(3) - print tree (inorder tree walk)" << endl;
    cout << "(4) - print tree (postorder tree walk)" << endl;
    cout << "(5) - search for key" << endl;
    cout << "(9) - exit" << endl;
   
    cout << "please make your selection ";
    cin >> menu;
    switch(menu) {
      case 1: temp = new Node;
              cout << "key to insert ";
              cin >> temp->key; // get key input from user
              bt.insert(temp);
              cout << "root" << bt.get_root()->key << endl;
              break;

      case 2: cout << "start traversel (preorder tree walk)" << endl; 
              bt.preorder_tree_walk(bt.get_root());
              break;

      case 3: cout << "start traversel (inorder tree walk)" << endl; 
              bt.inorder_tree_walk(bt.get_root());
              break;
      
      case 4: cout << "start traversel (postorder tree walk)" << endl; 
              bt.postorder_tree_walk(bt.get_root());
              break;

      case 5: cout << "search key" << endl;
              break;

      case 9: cout << "exit program - e called" << endl;
              exit(0);
              break;

    }
  }
}
