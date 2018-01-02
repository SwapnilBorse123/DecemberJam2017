#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	std::stack<char> parStack;
    bool isValid(string s) {
    	for(int i = 0; i < s.length(); ++i){
    		if(parStack.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')){
    			return false;
    		}
    		if(s[i] == '(' || s[i] == '{' || s[i] == '['){
    			parStack.push(s[i]);
    			//cout << parStack.size() << endl;
    		}else{
    			if(s[i] == ')'){
    				if(parStack.top() != '('){
    					return false;
    				}else{
    					parStack.pop();
    				}
    			}else if(s[i] == '}'){
    				if(parStack.top() != '{'){
    					return false;
    				}else{
    					parStack.pop();
    				}
    			}else if(s[i] == ']'){
    				if(parStack.top() != '['){
    					return false;
    				}else{
    					parStack.pop();
    				}
    			}
    		}
    	}
    	return parStack.empty() ? true : false;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->isValid("()") << endl;
	return 0;
}