/*
author: Swapnil Borse
date: 24th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA == NULL || headB == NULL){
			return NULL;
		}
        int countA = 1, countB = 1;
        ListNode* traverse = headA;
        while(traverse->next != NULL){
        	traverse = traverse->next;
        	countA++;
        }
        traverse = headB;
        while(traverse->next != NULL){
        	traverse = traverse->next;
        	countB++;
        }
        //cout << "ListA count:" << countA << " ListB count:" << countB << "\n";
        int diff = abs(countA - countB);
        //ListNode *ptr1 = NULL, *ptr2 = NULL;
        /*
        if(countA >= countB){
        	traverse = headA;
        	for(int i = 0; i < diff; ++i){
        		traverse = traverse->next;
        	}
        	ptr1 = traverse;
        	ptr2 = headB;
        }else{
        	traverse = headB;
        	for(int i = 0; i < diff; ++i){
        		traverse = traverse->next;
        	}
        	ptr1 = headA;
        	ptr2 = traverse;
        }
        while(ptr1 != ptr2){
        	if(ptr1 == NULL || ptr2 == NULL){
        		return NULL;
        	}
        	ptr1 = ptr1->next;
        	ptr2 = ptr2->next;
        }
        */
        if(countA >= countB){
        	for(int i = 0; i < diff; ++i){
        		headA = headA->next;
        	}
        }else{
        	for(int i = 0; i < diff; ++i){
        		headB = headB->next;
        	}
        }
        while(headA != headB){
        	if(headA == NULL || headB == NULL){
        		return NULL;
        	}
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }   
};

int main(){
	Solution s;
	ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
	list1->val = 3; list1->next = NULL;
	ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
	list2->val = 2; list2->next = list1;

	ListNode* commonNode = s.getIntersectionNode(list1, list2);
	if(commonNode == NULL){
		std::cout << "Intersection is NULL\n";
	}else{
		std::cout << commonNode->val << "\n";
	}
	return 0;
}