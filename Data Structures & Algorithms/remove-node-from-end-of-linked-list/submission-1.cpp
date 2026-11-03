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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* s=head;
        ListNode* f=head;

        for(int i=0;i<n;i++){
            f=f->next;
        }
        if (f == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        f=f->next;
        while(f){
            f=f->next;
            s=s->next;
        }
    
        ListNode* temp=s->next->next;
        delete s->next;
        s->next=temp;

        return head;
    }
};
