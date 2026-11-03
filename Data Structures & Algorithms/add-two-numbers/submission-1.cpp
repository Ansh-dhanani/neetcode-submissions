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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* head = &dummy;

        while (l1 || l2 || carry) {
            if(!l1 && !l2){
                if(carry>0){
                    ListNode* temp=new ListNode(carry);
                    tail->next=temp;
                }
                break;
            }else if(l1 && !l2){
                ListNode* temp=new ListNode(l1->val+carry);
                if(temp->val>9){
                    carry=temp->val/10;
                    temp->val=temp->val%10;
                }else{
                    carry=0;
                }
                tail->next=temp;
                tail=tail->next;
                l1=l1->next;

            }else if(!l1 && l2){
                ListNode* temp=new ListNode(l2->val+carry);
                if(temp->val>9){
                    carry=temp->val/10;
                    temp->val=temp->val%10;
                }else{
                    carry=0;
                }
                tail->next=temp;
                tail=tail->next;
                l2=l2->next;
                
            }else if(l1 && l2){
                ListNode* temp=new ListNode(l1->val+l2->val+carry);
                if(temp->val>9){
                    carry=temp->val/10;
                    temp->val=temp->val%10;
                }else{
                    carry=0;
                }
                tail->next=temp;
                tail=tail->next;
                l1=l1->next;
                l2=l2->next;
            }
        }
        return head->next;
    }
};
