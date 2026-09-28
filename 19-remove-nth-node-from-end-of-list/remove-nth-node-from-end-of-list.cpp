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
int getLength(ListNode* head) {
    ListNode* temp = head;
    
    int cnt = 0;
    while ( temp != NULL){
        cnt ++;
        temp = temp -> next;
    }
    return cnt;
}
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         
        int length = getLength(head);
        n = length - n + 1;
        ListNode* curr = head;
        ListNode* prev = head;
        int cnt = 1;

        while ( cnt != n) {
            prev = curr ;
            curr = curr -> next;
            cnt++;
        }
        if ( curr == head) {
            if ( curr -> next == NULL){
                head = NULL;
                delete curr;
                return head;
            }
            head = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
        else {
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete curr;
        }
        return head;
    }
};