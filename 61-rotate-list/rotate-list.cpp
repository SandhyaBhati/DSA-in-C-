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
int getLength( ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;
    while ( temp != NULL) {
        cnt++;
        temp = temp -> next;
    }
    return cnt;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int length = getLength(head);
        if ( k == 0 || length == 0 || length == 1 || k == length) return head;

        k = k % length ;
        if (k == 0) return head;
        int digit = length - k;

        ListNode* temp = head;
        int cnt = 1;

        while ( cnt < digit ) {
            temp = temp -> next;
            cnt++;
        }

        ListNode* newhead = temp-> next;
        temp -> next = NULL;

        temp = newhead;
        while ( temp -> next != NULL){
            temp = temp -> next; 
        }
        temp -> next = head;
    
    return newhead;
    }
};