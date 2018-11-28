class Solution {
public:
    int numSquares(int n) {
        if(n == 0){
           return 0; 
        }
        int levels = 0;
        std::queue<int> q;
        q.push(n);
        q.push(-1);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == -1){
                levels++;
                q.push(-1);
                continue;
            }
            //cout << "for: " << cur << " -> ";
            for(int i = 1; i*i <= cur; ++i){
                if(cur-(i*i) == 0){
                    return levels+1;
                }
                q.push(cur - (i*i));
                //cout << cur - (i*i) << " ";
            }
            //cout << endl;
        }
    }
};