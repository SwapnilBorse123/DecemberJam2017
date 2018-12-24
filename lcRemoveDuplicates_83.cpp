/*
Date: 12/24/2018
*/

static const auto x=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* helper = head, *start = head;
        while(helper){
            while(helper && helper->val == head->val){
                helper = helper->next;
            }
            head->next = helper;
            head = helper;
        }
        return start;
    }
};