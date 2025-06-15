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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* curr = new ListNode(0);
        curr->next=head;
        for (int i = 1; i <= k; i++) {
            curr = curr->next;
        }
        ListNode* a = curr;
        ListNode* b = head;
        while (curr != NULL && curr->next != NULL) {
            curr = curr->next;
            b = b->next;
        }
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
        return head;
    }
};