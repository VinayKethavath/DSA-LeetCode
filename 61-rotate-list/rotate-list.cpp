/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL||head->next==NULL){
            return head;
        }
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        k=k%size;
        if(k==size||k==0){
            return head;
        }
        head=rev(head);
        ListNode* temp1=head;
        ListNode* temp2=NULL;
        int i=1;
        temp=head;
        while(i<k){
            temp=temp->next;
            i++;
        }
        temp2=temp->next;
        temp->next=NULL;
        head=rev(temp1);
        temp2=rev(temp2);
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=temp2;
        return head;
    }
};