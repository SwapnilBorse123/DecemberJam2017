#include <sstream>
#include <stack>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
	public:

	int stoi(string s){
		int result;
		stringstream ss(s);
		ss >> result;
		return result;
	}

    int evalRPN(vector<string>& tokens) {
    	stack<string> myStack;
    	int result = 0, op1, op2;
    	for (std::vector<string>::iterator it = tokens.begin() ; it != tokens.end(); ++it){
    		if(*it == "+"){
    			op2 = stoi(myStack.top());
    			myStack.pop();
    			op1 = stoi(myStack.top());
    			myStack.pop();
    			result = op1 + op2;
    			myStack.push(to_string(result));
    		}else if(*it == "*"){
    			op2 = stoi(myStack.top());
    			myStack.pop();
    			op1 = stoi(myStack.top());
    			myStack.pop();
    			result = op1 * op2;
    			myStack.push(to_string(result));
    		}else if(*it == "/"){
    			op2 = stoi(myStack.top());
    			myStack.pop();
    			op1 = stoi(myStack.top());
    			myStack.pop();
    			result = op1 / op2;
    			//cout << "result: " << result << "\n";
    			myStack.push(to_string(result));
    		}else if(*it == "-"){
    			op2 = stoi(myStack.top());
    			myStack.pop();
    			op1 = stoi(myStack.top());
    			myStack.pop();
    			result = op1 - op2;
    			myStack.push(to_string(result));
    		}else{
    			myStack.push(*it);
    		}
    	}
    	if(!myStack.empty()){
    		result = stoi(myStack.top());
    		myStack.pop();
    	}
    	return result;    
    }
};

int main(){
	Solution *s = new Solution();
	vector<string> myVector;
	
	/*myVector.push_back("2"); //"2", "1", "+", "3", "*"
	myVector.push_back("1");
	myVector.push_back("+");
	myVector.push_back("3");
	myVector.push_back("*");*/

	myVector.push_back("4");
	myVector.push_back("13");
	myVector.push_back("5");
	myVector.push_back("/");
	myVector.push_back("+");



	cout << s->evalRPN(myVector) << endl;
	return 0;
}