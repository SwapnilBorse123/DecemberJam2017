// Explanation URL: https://leetcode.com/articles/longest-valid-parentheses/

/**
 @author: SwapnilB
 @date: 01/09/2018
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int* dp = (int*)malloc(sizeof(int) * s.length());
        int maxLength = 0;
        memset(dp, 0, s.length());
        for(int i = 0; i < s.length(); ++i){
            if (s[i] == ')' && s[i-1] == '('){
                dp[i] = dp[i-2] + 2;
                if(dp[i] > maxLength){
                    maxLength = dp[i];
                }
            } else if(s[i] == ')' && s[i-1] == ')'){
                if(s[i - dp[i-1] - 1] == '('){
                    dp[i] = dp[i-1] + dp[i - dp[i-1] - 2] + 2;
                    if(dp[i] > maxLength){
                        maxLength = dp[i];
                    }
                }
            }
        }
        delete(dp);
        return maxLength;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->longestValidParentheses(")()(((())))(") << endl;
	return 0;
}