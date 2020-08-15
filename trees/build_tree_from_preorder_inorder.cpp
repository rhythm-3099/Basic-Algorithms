int search(char inorder[], int inorderStart, int inorderEnd, int value){
    for(int i=inorderStart;i<=inorderEnd;i++){
        if(inorder[i]==value){
            return i;
        }
    }
}


node* buildTree(char inorder[], char preorder[], int inorderStart, int inorderEnd){
    static int preIndex=0;
    if(inorderStart>inorderEnd){
        return null;
    }

    node* root = newNode(preorder[preIndex]);
    preIndex++;

    if(inorderStart == inorderEnd){
        return root;
    }

    int inIndex = search(inorder, inorderStart, inorderEnd, root->data);

    root->left = buildTree(inorder, preorder, inorderStart, inIndex-1);
    root->right = buildTree(inorder, preorder, inIndex+1, inorderEnd);

    return root;
}