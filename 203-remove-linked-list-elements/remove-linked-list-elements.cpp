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
    ListNode* removeElements(ListNode* head, int val) {

        if ( head == NULL) return head;

        while ( head != NULL  && head -> val == val) {
            ListNode* temp = head ;
            head = head -> next ;
            delete temp;
        }
        if ( head == NULL) {
            return head;
        }
        ListNode* prev = head ;
        ListNode* curr = head -> next;

        while ( curr != NULL ) {

            if ( curr -> val != val) {
                prev = curr;
                curr = curr -> next;
            }
            else {
                ListNode* temp = curr;
                prev -> next = curr -> next ;
                curr = curr -> next ;
                temp -> next = NULL;
                delete temp;
            }
        }
        return head;
    }
};