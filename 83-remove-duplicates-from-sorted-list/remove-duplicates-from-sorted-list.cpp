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
    ListNode* deleteDuplicates(ListNode* head) {

      if ( head == NULL || head -> next == NULL) {
        return head;
      }  
      ListNode* second = NULL;
      ListNode* temp = head;

      while ( temp != NULL && temp -> next != NULL) {
        second = temp -> next;
        if ( second -> val == temp -> val) {
            temp -> next = second -> next;
            second -> next = NULL;
            delete second;
        }
        else {
            temp = second;
        }

      }
      return head;
    }
};