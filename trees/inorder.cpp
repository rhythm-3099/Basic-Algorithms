void inOrder(Node* root){
	stack<Node*>st;
	Node* temp;
	while(!st.empty() || root){
		while(root){
			s.push(root);
			root=root->left;
		}
		root=s.top();
		s.pop();
		cout<<root->data<<" ";

		root=root->right;
	}
}

void inOrderRecursive(Node* root){
	preOrder(root->left);
	cout<<root->data<<endl;
	preOrder(root->right);
}