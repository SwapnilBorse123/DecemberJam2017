class Solution {
public:
    string result;
    string addBoldTag(string s, vector<string>& dict) {
        if(dict.empty()){
            return s;
        }
        vector<std::pair<int,int>> intervals;
        for(int i = 0; i < dict.size(); ++i){
            int pos = s.find(dict[i], 0);
            while(pos != string::npos){
                //cout << "For: " << dict[i] << endl;
                std::pair<int, int> p;
                p.first = pos;
                p.second = pos + dict[i].length()-1;
                intervals.push_back(p);
                //cout << "First: " << p.first << endl;
                //cout << "Second: " << p.second << endl;
                pos = s.find(dict[i], pos+1);
            }
        }
        if(intervals.empty()){
            return s;
        }
        std::sort(intervals.begin(), intervals.end());
        //for(int i = 0; i < intervals.size(); ++i){
        //   cout << intervals[i].first << " " << intervals[i].second << endl;
        //}
        // using Stack to merge intervals
        std::stack<std::pair<int,int>> myStack;
        if(intervals.size() > 0){
            myStack.push(intervals[0]);
            for(int i = 1; i < intervals.size(); ++i){
                std::pair<int, int> topPair = myStack.top();
                std::pair<int, int> curPair = intervals[i];
                //check if merging or continous
                std::pair<int, int> mergedPair = curPair;
                if(curPair.first >= topPair.first && curPair.first <= topPair.second){ // merging
                    mergedPair.first = topPair.first;
                    mergedPair.second = curPair.second > topPair.second ? curPair.second : topPair.second;
                    myStack.pop();
                }else if(curPair.first == topPair.second + 1){ // continuous
                    mergedPair.first = topPair.first;
                    mergedPair.second = curPair.second;
                    myStack.pop();
                }
                //cout << "pushing: (" << mergedPair.first << "," << mergedPair.second << ")" << endl;
                myStack.push(mergedPair);
            }
        }
        std::pair<int,int> curTop = myStack.top();
        for(int i = s.length() - 1; i >= 0; --i){
            if(i <= curTop.second && i >= curTop.first){
                if(curTop.second == i && i == curTop.first){
                    result = result  + ">b/<" + s[i] + ">b<";
                    myStack.pop();
                    if(!myStack.empty()){
                        curTop = myStack.top();   
                    }
                }
                else if(curTop.second == i){
                    result = result  + ">b/<" + s[i];
                    //cout << "res: " << result << endl;
                }else if(i == curTop.first){
                    result = result + s[i] + ">b<";
                    //cout << "res: " << result << endl;
                    myStack.pop();
                    if(!myStack.empty()){
                        curTop = myStack.top();   
                    }
                }else{
                    result = result + s[i];
                    //cout << "res: " << result << endl;
                }
            }else{
                result = result + s[i];
                //cout << "res: " << result << endl;
            }
        }
        //cout << "res:: " << result << endl;
        std::reverse(result.begin(),result.end());
        return result;
    }
};