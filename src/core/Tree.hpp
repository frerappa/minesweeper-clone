typedef struct Node{
    int data;
    struct Node *left, *right;
} 
Node;

class Tree {
  private:
    Node *root;

  public:
    Tree();

    bool search_insert(int v);
};