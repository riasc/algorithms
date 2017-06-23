#include <iostream>
#include <stddef.h>
using namespace std;

struct Node {
  int key;
  Node* left; // nodes left child
  Node* right; // nodes right child
  Node* parent; // nodes parent
  // constructor 
  Node() {
    left = NULL;
    right = NULL;
    parent = NULL;
  }
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
    Node* search(Node * x, int k);
    Node* search_iterative();

    // replace subtree rooted at node u with the subtree rooted at node v
    void transplant(Node * u, Node* v);


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
void BinaryTree::insert(Node * insertnode) {
  Node * buff = NULL; // buffering nodes
  Node * elem  = get_root(); // start with provided root
  while ( elem != NULL ) { // 
    buff = elem; // 
    cout << "insertnode:" << insertnode->key << endl;
    cout << "elem" << elem->key << endl;
    if (elem == NULL) {
      cout << "nullptr" << endl; 
    }

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
  if (( x == NULL ) || ( k == x->key )) {
    return root; 
  }
  if ( k < x->key ) {
    return search( x->left, k); 
  } else {
    return search ( x->right, k); 
  }
}

// move subtrees u and v around
void BinaryTree::transplant(Node * u, Node* v) {
  if ( u->parent == NULL ) {
    set_root(v); //  
  } else {
    if (u == u->parent->left) {
      u->parent->left = v;
    } else {
          u->parent->right = v; 
    }
  }
}


int main() {
  BinaryTree bt; // create new binary tree object
  int menu = 0; // 
  Node * temp;
  int value;
  Node * searchres;

  while (1) {
    cout << endl<<endl;
    cout << "--------------------------------------------" << endl;
    cout << "-- Operations on Binary Search Tree (BST) --" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "(1) - insert node into tree" << endl;
    cout << "(2) - print tree (preorder tree walk)" << endl;
    cout << "(3) - print tree (inorder tree walk)" << endl;
    cout << "(4) - print tree (postorder tree walk)" << endl;
    cout << "(5) - search for key in tree" << endl;
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
              cin >> value;
              searchres = bt.search(bt.get_root(), value );
              if ( searchres != NULL ) {
                cout << "node with key = " << value << " has been found" <<endl;
              } else {
                cout << "node with key = " << value << " has not been found" <<endl;
              }
              break;

      case 9: cout << "exit program - e called" << endl;
              exit(0);
              break;

    }
  }
}
