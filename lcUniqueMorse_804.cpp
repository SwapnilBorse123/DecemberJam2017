class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.empty()){
            return 0;
        }
        vector<string> alpha = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<std::string> myset;
        for(auto &it: words){
            string res = "";
            //cout << it << endl;
            for(int i = 0; i < it.length(); ++i){
                res = res + alpha[it[i]-'a'];
                //cout << alpha[i];
            }
            //cout <<endl<< res<<endl;
            myset.insert(res);
        }
        return myset.size();
    }
};