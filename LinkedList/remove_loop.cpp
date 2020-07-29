void removeLoop(Node* head)
{
    Node *slow=head;
    Node *fast=head;
    bool isLoop=false;
    while(slow!=NULL && fast!=NULL) {
        
        if(fast->next==NULL)
            return;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            isLoop=true;
            break;
        }
    }
    if(!isLoop)
        return;
    slow=head;
    while(slow!=fast) {
        slow=slow->next;
        fast=fast->next;
    }
    while(slow->next!=fast) {
        slow=slow->next;
    }
    slow->next=NULL;
}