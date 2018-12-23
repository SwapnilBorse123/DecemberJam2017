class Solution {
public:
    vector<string> res;
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        if(cpdomains.empty()){
            return res;
        }
        unordered_map<string , int> myMap;
        int i = 0;
        for(auto str : cpdomains){
            for(i = 0; i < str.length() && str[i] != ' '; ++i); 
            int count = stoi(str.substr(0, i));
            //cout << count;
            for(int i = str.length()-1; i >= 0; --i){
                if(str[i] == '.' || str[i] == ' '){
                    string curStr = str.substr(i+1, str.length()-i-1);
                    if(myMap.find(curStr) != myMap.end()){
                        myMap.at(curStr) += count; 
                    }else{
                        //cout << curStr << " " << count << endl;
                        myMap.insert(std::pair<string, int>(curStr, count));
                    }
                }
            }
        }
        for(auto &it : myMap){
            res.push_back(to_string(it.second) + " " + it.first);
        }
        return res;
    }
};