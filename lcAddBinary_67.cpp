#include<bits/stdc++.h>
//#include<algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        //cout << "sizeof(int) * 8 is " << sizeof(int) * 8 << "\n";
        //fflush(stdout);
        int num1 = 0, num2 = 0;
        int lenA = a.length(), lenB = b.length();
        cout << "lenA" << lenA << " lenB " << lenB << "\n" ;
        //fflush(stdout);
        string result = "";
        for(int i = 0; i < lenA; ++i){
            if(a[i] == '1'){
                num1 |= (1 << (lenA-1-i));
            }
        }
        for(int i = 0; i < lenB; ++i){
            if(b[i] == '1'){
                num2 |= (1 << (lenB-1-i));
            }
        }
        //cout << "num1: " << num1 << " num2: " << num2 << "\n";
        int sum = num1 + num2;
        bool append = false;
        for(int i = sizeof(int) * 8; i >= 0; --i){
            if(sum & (1 << (i))){
                result = "1" + result;
                append = true;
            }else{
                if(append){
                    result = "0" + result;
                }
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    //cout << "Hello world1";
    //fflush(stdout);
    cout << s.addBinary("11", "1") << "\n";
    //fflush(stdout);
    return 0;
}