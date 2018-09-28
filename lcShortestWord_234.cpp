/*
author: Swapnil Borse
date: 26th Sep'18
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int min = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(words[i] == word1){
                for(int j = i + 1; j <= words.size(); ++j){
                    if(words[j] == word2){
                        if(abs(i-j) < min){
                            min = abs(i-j);
                        }
                    }
                }
            }else if(words[i] == word2){
                for(int j = i + 1; j <= words.size(); ++j){
                    if(words[j] == word1){
                        if(abs(i-j) < min){
                            min = abs(i-j);
                        }
                    }
                }
            }
        }
        return min;
    }
};