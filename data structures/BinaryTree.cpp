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
    cout << "***Node has key=" << startnode->key << endl;
    cout << "***Traverse left" << endl;
    preorder_tree_walk(startnode->left);
    cout << "***Traverse right" << endl;
    preorder_tree_walk(startnode->right);
  }
}

void BinaryTree::inorder_tree_walk(Node *startnode) {
  if ( startnode != NULL ) {
    cout << "***Traverse left" << endl;
    inorder_tree_walk(startnode->left);
    cout << "***Node has key=" << startnode->key << endl;
    cout << "***Traverse right" << endl;
    inorder_tree_walk(startnode->right);
  }
}

void BinaryTree::postorder_tree_walk(Node *startnode) {
  if ( startnode != NULL ) {
    cout << "***Traverse left" << endl;
    postorder_tree_walk(startnode->left);
    cout << "***Traverse right" << endl;
    postorder_tree_walk(startnode->right);
    cout << "***Node has key=" << startnode->key << endl;
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
    cout << "*** BST is empty." << endl;
    cout << "*** BST rooted at inserted node (key=" << insertnode->key << ")" << endl;
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
    return x; 
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
  cout << "node to delete key=" << z->key << endl;
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
        cout << "transplant node: " << z->key << "with node: " << y->key << endl;
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
    cout << "(1) - Insert" << endl;
    cout << "(2) - Print (Preorder Tree Walk)" << endl;
    cout << "(3) - Print (Inorder Tree Walk)" << endl;
    cout << "(4) - Print (Postorder Tree Walk)" << endl;
    cout << "(5) - Search" << endl;
    cout << "(6) - Delete" << endl;
    cout << "(9) - Exit" << endl;
    cout << endl; 
    cout << "-- Please make your selection: ";
    cin >> menu;

    switch(menu) {
      case 1: cout << endl; 
              cout << "-- Insertion -- " << endl; 
              temp = new Node;
              cout << "*** Please enter the key of the node: ";
              cin >> temp->key; // get key input from user
              bt.insert(temp);
              cout << "*** Node with key=" << temp->key << " has been inserted." << endl;
              break;

      case 2: cout << endl; 
              cout << "-- Preorder Tree Walk (root, left, right) --" << endl; 
              bt.preorder_tree_walk(bt.get_root());
              break;

      case 3: cout << endl; 
              cout << "-- Inorder Tree Walk (left, root, right) --" << endl; 
              bt.inorder_tree_walk(bt.get_root());
              break;
      
      case 4: cout << endl; 
              cout << "-- Postorder Tree Walk -- (left, right, root)" << endl; 
              bt.postorder_tree_walk(bt.get_root());
              break;

      case 5: cout << endl; 
              cout << "-- Search --" << endl;
              cout << "*** Please enter the key of the node: ";
              cin >> value;
              searchres = bt.search(bt.get_root(), value );
              if ( searchres != NULL ) {
                cout << "*** Node (key = " << value << ") has been found" << endl;
              } else {
                cout << "*** Node (key = " << value << ") has not been found" << endl;
              }
              break;

      case 6: cout << endl; 
              cout << "-- Delete --" << endl;
              cout << "*** Please enter key of node: ";
              cin >> del_cin; // read key of node from cin
              del_node = bt.search( bt.get_root(), del_cin ); // search for node in tree
              bt.delete_node( del_node ); // delete node
              cout << "*** Node (key=" << del_cin << ") has been deleted" << endl;
              break;

      case 9: cout << endl;
              cout << "-- Exit --" << endl;
              cout << "*** Program will be terminated" << endl;
              exit(0);
              break;

    }
  }
}
