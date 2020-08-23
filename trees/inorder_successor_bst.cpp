/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

Node* find(Node* root, int x){
    while(root){
        if(root->data==x)
            return root;
        else if(root->data<x)
            root=root->right;
        else
            root=root->left;
    }
    return NULL;
    
}

Node* checkRight(Node* root){
    Node* temp=root;
    while(temp->left)
        temp=temp->left;
    return temp;
}

// returns the inorder successor of the Node x in BST (rooted at 'root')
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(!root)
        return root;
    Node* curr = find(root,x->data);
    if(curr==NULL)
        return NULL;
    if(curr->right){
        return checkRight(curr->right);
    } else {
        Node* succ = NULL;
        Node* ances = root;
        while(ances!=curr){
            if(curr->data<ances->data){
                succ=ances;
                ances=ances->left;
            } else {
                ances = ances->right;
            }
        }
        return succ;
    }
}