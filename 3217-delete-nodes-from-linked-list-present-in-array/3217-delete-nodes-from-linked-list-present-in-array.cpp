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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>st(nums.begin(), nums.end());

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;

        while(temp->next){
            if(st.count(temp->next->val)){
                ListNode* curr=temp->next;
                temp->next=temp->next->next;
                delete curr;
            }
            else{
                temp=temp->next;
            }
        }
        ListNode* modHead=dummy->next;
        return modHead;
    }
};


