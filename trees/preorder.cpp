void preOrder(Node* root){
	stack<Node*>st;
	st.push(root);
	Node* temp;
	map<ll,bool>mp;
	while(!st.empty()){
		temp = st.top();
		st.pop();
		cout<<temp->data<<endl;
		if(temp->right){
			st.push(temp->right);
		}
		if(temp->left){
			st.push(temp->left);
		}
	}
}

void preOrderRecursive(Node* root){
	cout<<root->data<<endl;
	preOrder(root->left);
	preOrder(root->right);
}