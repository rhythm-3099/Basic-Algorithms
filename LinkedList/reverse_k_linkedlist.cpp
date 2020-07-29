struct node *reverse (struct node *head, int k)
{ 
    // Time Comp: O(n)
    node *temp,*curr,*next,*prev;
    prev=NULL,next=NULL;
    curr=head;
    int c=0;
    while(c<k && curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        c++;
    }
    if(next!=NULL){
        head->next=reverse(curr,k);
    }
    return prev;
}