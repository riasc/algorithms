class BinaryTree {
  private:
    struct Node {
      int key;
      Node *left;
      Node *right;
    };
    Node *root;

  public:
    void preorder_tree_walk(Node *startnode);
    void inorder_tree_walk(Node *startnode);
    void postorder_tree_walk(Node *startnode);

    void insert();
    Node* search();
    Node* search_iterative();
    Node* minimum();
    Node* maximum();
    Node* successor();
    Node* predecessor();
};

void BinaryTree::preorder_tree_walk(Node *startnode) {
}


void BinaryTree::inorder_tree_walk(Node *startnode) {
}


void BinaryTree::postorder_tree_walk(Node *startnode) {
}

void BinaryTree::insert(Node *insertnode) {

}

Node* BinaryTree::search(Node *searchnode) {
}




int main() {

}




  
  
  
  
  
