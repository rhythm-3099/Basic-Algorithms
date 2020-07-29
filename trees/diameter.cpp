
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node* node){
    if(!node)
        return 0;
    return 1+max(height(node->left),height(node->right));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    if(!node)
        return 0;
    int ldiameter = diameter(node->left);
    int rdiameter = diameter(node->right);
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(ldiameter, max(rdiameter, lheight+rheight+1));
}