// Date: 26/11/2017
// Website: Leetcode
// Problem: Adding two numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    int addition = 0;
    bool first = true;
    struct ListNode *result, *addedNum;
    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL && l2 != NULL){
            addition = l1->val + l2->val + carry;
        }else if(l1 != NULL && l2 == NULL){
            addition = l1->val + carry;
        }else if(l1 == NULL && l2 != NULL){
            addition = l2->val + carry;
        }
        sum = addition % 10;
        carry = addition / 10;
        if(first){
            result = (struct ListNode*)malloc(sizeof(struct ListNode));
            addedNum = result;
            result->val = sum;
            first = false;
        }else{
         	struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->val = sum;
            result->next = p;
            result = result->next;
        }
        if(l1 != NULL){
            l1 = l1->next;    
        }
        if(l2 != NULL){
            l2 = l2->next;   
        }
    }
    if(carry != 0){
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = carry;
        result->next = p;
        result = result->next;
    }
    result->next = NULL;
    return addedNum;
}