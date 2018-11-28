/*
author: Swapnil Borse
date: 9th Oct
*/

class Solution {
public:
    vector<string> result;
    
    vector<string> letterCasePermutation(string S) {
        //cout << S << endl;
        char* currStr = (char*)malloc(sizeof(char) * S.length() + sizeof(char));
        if(S.length() == 0){
            result.push_back("");
            return result;
        }else{
            util(S, 0, currStr, 0);
            return result;
        }
    }
    
    void util(string str, int indx, char* currRes, int curStrIdx){
        if(indx == str.length()){
            cout << currRes << "\n";
            currRes[indx] = '\0';
            result.push_back(currRes); // current string ready
            return;
        }
        currRes[curStrIdx] = str[indx]; // use character as it is
        util(str, indx+1, currRes, curStrIdx+1);
        if(str[indx] >= 65 && str[indx] <= 90){ // upper case character
            currRes[curStrIdx] = (str[indx]-'A'+'a'); // make it lower case
        }else if(str[indx] >= 97 && str[indx] <= 122){ // lower case character
            currRes[curStrIdx] = (str[indx]-'a'+'A'); // make it upper case
        }
        if(!(str[indx] >= 48 && str[indx] <= 57)){
            util(str, indx+1, currRes, curStrIdx+1); // skip backtracking for a number
        }
    }
};