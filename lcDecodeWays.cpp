#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        //int res = 0;
        int *dp = (int*)malloc(sizeof(int) * s.length());
        if(s[0] == '0'){
        	return 0;
        }else if(s.length() < 0){
        	return 0;
        } else if(s.length() == 1){
        	return 1;
        } else{
        	dp[0] = 1;
        	cout << s[0]-'0' << ":" << dp[0] << " ";
        	for(int i = 1; i < s.length(); ++i){
        		if(s[i] == '0' && s[i-1] != '1' && s[i-2] != '2'){
        			return 0;
        		} else if(i == 1 && ((s[i] - '0') + (s[i-1] - '0') * 10 <= 26) && (s[i] != '0')){
        			dp[i] = dp[i - 1] + 1;
        		} else if((s[i] - '0') + (s[i-1] - '0') * 10 <= 26){
        			dp[i] = dp[i - 1] + dp[i - 2];
        		} else{
                    dp[i] = dp[i - 1];
        		}
        		cout << s[i]-'0' << ":" << dp[i] << " ";
        	}
        }
        int temp = dp[s.length() - 1];
        delete(dp);
        return temp;
    }
};

int main(){
	Solution *s = new Solution();
	cout << s->numDecodings("101") << endl;
	return 0;
}