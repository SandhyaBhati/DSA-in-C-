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
        
        ListNode* head = NULL;
        ListNode* prev = NULL;
        int carry = 0;

        while ( l1 != NULL || l2 != NULL || carry != 0){

            int number1 = 0;
            int number2 = 0;

            if ( l1 != NULL) {
                number1 = l1 -> val;
                l1 = l1 -> next; 
            }

            if ( l2 != NULL) {
                number2 = l2 -> val;
                l2 = l2 -> next;
            }
            int sum = number1 + number2 + carry;
            int d = sum % 10;
            carry = sum / 10;
        
        ListNode* s = new ListNode (d);

        if( head == NULL) {
            head = s;
        }
        else {
            prev -> next = s;
        }
        prev = s;
        
    }
    
    return head;
    }
};