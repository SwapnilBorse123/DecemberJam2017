/*
author: Swapnil Borse
date: 24th August 2018
*/

#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    std::vector<int> myVec;
    int index, minSoFar;
    MinStack() {
        index = -1;
        minSoFar = INT_MAX;
    }
    
    void push(int x) {
    	index++;
        myVec.push_back(x);
        if(x < minSoFar){
        	minSoFar = x;
        }
    }
    
    void pop() {
        if(index >= 0){
        	//int topElem = myVec[index];
        	//index--;
        	if(myVec[--index] == minSoFar){
        		minSoFar = INT_MAX;
        		for(int i = 0; i <= index; ++i){ // O(n)
        			if(myVec[i] < minSoFar){
        				minSoFar = myVec[i];
        			}
        		}
        	}
        }else{
        	std::cout << "Stack is empty.\n";
        }
    }
    
    int top() {
    	return myVec[index];
    }
    
    int getMin() {
  		return minSoFar;      
    }
};

int main(){
   	MinStack *obj = new MinStack();
   	obj->push(3);
   	obj->pop();
   	cout << obj->top() << "\n";
   	cout << obj->getMin() << "\n";
	return 0;
}