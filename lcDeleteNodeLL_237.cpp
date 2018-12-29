/*
    Date: 12/26/2018
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
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        while(p->next && p->next->next){
            p->val = p->val ^ p->next->val;
            p->next->val = p->val ^ p->next->val;
            p->val = p->val ^ p->next->val;
            p = p->next;
        }
        p->val = p->val ^ p->next->val;
        p->next->val = p->val ^ p->next->val;
        p->val = p->val ^ p->next->val;
        p->next = NULL;
    }
};