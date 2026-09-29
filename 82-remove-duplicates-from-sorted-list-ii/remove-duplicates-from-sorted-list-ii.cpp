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
        
        if ( head == NULL || head -> next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while ( curr != NULL) {

            if (curr -> next != NULL && curr -> val == curr -> next -> val){
                int duplicateVal = curr -> val;

                while ( curr != NULL && curr -> val == duplicateVal ){
                    prev -> next = curr -> next;
                    ListNode* temp = curr;
                    temp -> next = NULL;
                    delete temp;
                    curr = prev -> next;
                } 
            }
            else {
                prev = curr;
                curr = curr -> next;
            }

        }
        head = dummy -> next;
        dummy -> next = NULL;
        delete dummy;
        return head;
    }
};