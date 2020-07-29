/*  This function should rotate list counter-clockwise
    by k and return new head (if changed) */
Node* rotate(Node* head, int k) {
    Node *curr;
    Node *r;
    curr=head;
    int i=1;
    r=head;
    while(r->next!=NULL){
        r=r->next;
    }
    r->next=head;
    while(i<k){
        curr=curr->next;
        i++;
    }
    r=curr;
    curr=curr->next;
    r->next=NULL;
    return curr;
}