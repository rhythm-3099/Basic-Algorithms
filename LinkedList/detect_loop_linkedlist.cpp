int detectloop(Node *head) {

    // Tortoise hare method (Floyd algorithm)
    // Time Comp: O(n)
    int isLoop = false;
    Node *fast=head,*slow=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}