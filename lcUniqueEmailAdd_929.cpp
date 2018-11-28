class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.empty()){
            return 0;
        }
        set<string> mySet;
        bool isDomain = false;
        for(int i = 0; i < emails.size(); ++i){
            string cStr = emails[i];
            //cout << "curr: " << cStr << endl;
            string rStr = "";
            isDomain = false;
            for(int j = 0; j < cStr.length(); ++j){
                if(cStr[j] == '+'){
                    while(cStr[j] != '@') j++;
                    isDomain = true;
                    
                }
                if(!isDomain){
                    if(cStr[j] != '.'){
                        rStr = rStr + cStr[j];
                    }
                }else{
                    rStr = rStr + cStr[j];
                }
            }
            //cout << rStr << endl;
            mySet.insert(rStr);
        }
        return mySet.size();
    }
};