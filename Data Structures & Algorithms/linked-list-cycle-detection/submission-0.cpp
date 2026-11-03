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
    bool hasCycle(ListNode* head) {
        ListNode *front=head;
        ListNode *back=head;

        while( front && front->next ){
            front=front->next->next;
            back=back->next;

            if (back == front){
                return true;
            }
        }
        return false;
    }
};
