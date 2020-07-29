/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   Node* node;
   Node* slow;
   Node* fast;
   slow=head,fast=head;
   while(slow!=NULL && fast!=NULL && fast->next!=NULL){
       slow=slow->next;
       fast=fast->next->next;
   }
   return slow->data;
}