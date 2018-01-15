#include <bits/stdc++.h>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        myStack.push(-1);
        int maxLength = 0;
        for(int i = 0; i < s.length(); ++i){
        	if(s[i] == ')'){
        		myStack.pop();
        		if(myStack.empty()){
        			myStack.push(i);
        		}else{
        			int diff = i - myStack.top();
        			if(diff > maxLength){
        				maxLength = diff;
        			}
        		}
        	}else if(s[i] == '('){
        		myStack.push(i);
        	}
        }
        return maxLength;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->longestValidParentheses("()()") << endl;
	return 0;
}