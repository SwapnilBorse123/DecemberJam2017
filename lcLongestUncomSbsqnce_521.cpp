/*
	Date: 12/28/2018
*/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.compare(b) == 0){
            return -1;
        }else{
            return a.length() > b.length() ? a.length() : b.length();
        }
    }
};