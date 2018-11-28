/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> res;
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()){
            return res;
        }
        std::sort(intervals.begin(), intervals.end(), Solution::pairCompare);
        std::stack<Interval> myStack;
        
        if(intervals.size() > 0){
            myStack.push(intervals[0]);
            for(int i = 1; i < intervals.size(); ++i){
                Interval topPair = myStack.top();
                Interval curPair = intervals[i];
                //check if merging or continous
                Interval mergedPair = curPair;
                if(curPair.start >= topPair.start && curPair.start <= topPair.end){ // merging
                    mergedPair.start = topPair.start;
                    mergedPair.end = curPair.end > topPair.end ? curPair.end : topPair.end;
                    myStack.pop();
                }
                //cout << "pushing: (" << mergedPair.start << "," << mergedPair.end << ")" << endl;
                myStack.push(mergedPair);
            }
        }
        while(!myStack.empty()){
            res.push_back(myStack.top());
            myStack.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
    
    static bool pairCompare(const Interval &firstElem, const Interval &secondElem) {
        return firstElem.start < secondElem.start;
    }
    
};