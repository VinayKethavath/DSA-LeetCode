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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return list1;
        }
        else if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        else{
        ListNode* temp=list2;
        ListNode* curr=list1;
        ListNode* prev=NULL;
        int inserted;

        while(list2!=NULL){
            list2=temp->next;
            temp->next=NULL;
            curr=list1;
            inserted=0;
            while(curr!=NULL && !inserted){
                if(temp->val<=curr->val){
                    temp->next=curr;
                    if(curr==list1){
                        list1=temp;
                    }
                    else{
                        prev->next=temp;
                    }
                    inserted=1;
                }
                else{
                prev=curr;
                curr=curr->next;
                }
            }
            if(!inserted){
                prev->next=temp;
            }
            temp=list2;
        }
        }
        return list1;
    }
};