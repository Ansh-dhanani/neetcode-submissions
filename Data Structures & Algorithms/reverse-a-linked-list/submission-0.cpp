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

    void recursion(ListNode* curr,ListNode *&ans){
        if(curr==nullptr) return;

        recursion(curr->next,ans);
        
        ans->val=curr->val;
        ans->next=new ListNode();
        ans=ans->next;

        return;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr; 
        ListNode* ans=new ListNode();
        ListNode* rev_head=ans;

        recursion(head,ans);

        ListNode* temp = rev_head;
        while (temp->next && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next; 
        temp->next = nullptr;

        return rev_head;
    }
};
