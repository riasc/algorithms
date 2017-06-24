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

    // get and set root of tree
    Node * get_root();
    void set_root(Node * rootnode); 

    // perform tree walks
    void preorder_tree_walk(Node *startnode);
    void inorder_tree_walk(Node *startnode);
    void postorder_tree_walk(Node *startnode);

    void insert(Node* insertnode);
    Node* search(Node * x, int k);
    Node* search_iterative();

    // replace subtree rooted at node u with the subtree rooted at node v
    void transplant(Node * u, Node* v);
    void delete_node( Node * z );

    Node* tree_minimum( Node * x );
    Node* tree_maximum( Node * x );
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

// minimum node in the subtree rooted at x
Node * BinaryTree::tree_minimum( Node * x ) {
  while( x->left != NULL ) { 
    x = x->left; // traverse left
  }
  return x;
}

// maximum node in the subtree rooted at x
Node * BinaryTree::tree_maximum( Node * x ) {
  while( x->right != NULL ) {
    x = x->right; // traverse right 
  }
  return x;
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
  insertnode->parent = buff;
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

// replace subtree rooted at u with subtree rooted at v
void BinaryTree::transplant( Node * u, Node* v ) {
  if ( u->parent == NULL ) { // u is root of tree
    set_root( v ); //  
  } else {
    if ( u == u->parent->left ) { // u is a left child
      u->parent->left = v;
    } else { // u is a right child
          u->parent->right = v; 
    }
  }
  if ( v != NULL ) { // update the parent
    v->parent = u->parent; 
  }
}

void BinaryTree::delete_node( Node * z ) {
  if ( z->left == NULL ) { // tree has no left child
    transplant( z, z->right  ); // replace parent with right child
  } else {
    if ( z->right == NULL  ) { // tree has left child but no right child
      transplant ( z, z->left ); // replace parent with left child 
    } else { // tree has both a left and a right child
        Node * y = tree_minimum( z->right ); // get successor of z (lies right of z)
        if( y->parent != z  ) { 
          transplant( y, y->right );
          y->right = z->right;
          y->right->parent = y;
        } 
        // y has no left child: parent of y is z
        transplant( z,y );
        y->left = z->left;
        y->left->parent = y;
    } 
  }
}

int main() {
  BinaryTree bt; // create new binary tree object
  int menu = 0; // 
  Node * temp;
  int value;
  Node * searchres;
  
  int del_cin;
  Node * del_node;

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
    cout << "(6) - delete node with key in tree" << endl;
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

      case 5: cout << "search for key in tree" << endl;
              cout << "- enter key of node to search" << endl;
              cin >> value;
              searchres = bt.search(bt.get_root(), value );
              if ( searchres != NULL ) {
                cout << "node with key = " << value << " has been found" <<endl;
              } else {
                cout << "node with key = " << value << " has not been found" <<endl;
              }
              break;

      case 6: cout << "delete node in tree" << endl;
              cout << "- enter key of node to delete from tree" << endl;
              cin >> del_cin;
              del_node = bt.search( bt.get_root(), del_cin );
              bt.delete_node( del_node );
              cout << "node with key= " << del_cin << "has been removed from tree" << endl;
              break;

      case 9: cout << "exit program - e called" << endl;
              exit(0);
              break;

    }
  }
}
