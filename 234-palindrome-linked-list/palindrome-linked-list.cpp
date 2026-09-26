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

void insertAtHead( ListNode* &head , int d) {
    ListNode* temp = new ListNode(d);
    temp -> next = head;
    head = temp;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {

       if ( head -> next == NULL) return true;

       ListNode* newhead = new ListNode(head -> val);
       ListNode* curr = head -> next;

        while (curr != NULL ) {
            insertAtHead (newhead, curr->val);
            curr = curr -> next;
        } 
        curr = head;
        ListNode* temp = newhead;

        while( curr != NULL) {
            if ( temp -> val != curr -> val) {
                return false;
            }
            curr = curr -> next;
            temp = temp -> next;
        }
        return true;


    }
};