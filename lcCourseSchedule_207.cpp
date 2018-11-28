/*
author: Swapnil Borse
date: 20th Oct
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //int adj[numCourses * numCourses]; memset(adj, 0, sizeof(int)*numCourses*numCourses);
        vector<vector<int>> adj(numCourses, vector<int>(0));
        buildPreReqGraph(adj, prerequisites, numCourses); // building a requirement graph
        //printGraph(adj, numCourses);
        return dfs(adj, numCourses); // perform a dfs to find a cycle
        //return false;
    }
    
    bool dfs(vector<vector<int>> &adj, int numCourses){
        int visited[numCourses]; memset(visited, 0, sizeof(int) * numCourses); // initialize all node's visited as not visited
        int ifCyclePresent = 0;
        for(int i = 0; i < adj.size(); ++i){
            for(int j = 0; j < adj[i].size(); ++i){
                if(visited[j] == 0 && ifCyclePresent == 0){
                    bool* curVisitedStack = new bool[numCourses];
                    for(int i = 0; i < numCourses; ++i){
                        curVisitedStack[i] = false;
                    }
                    dfsUtil(i, adj, visited, curVisitedStack, &ifCyclePresent, numCourses);
                    delete(curVisitedStack);
                }   
            }
        }
        return ifCyclePresent ? false : true;
    }
    
    void dfsUtil(int src, vector<vector<int>> &adj, int* visited, bool* curVis, int* ifCyclePresent, int numCourses){
        if(visited[src] == 0){
            visited[src] = 1;
            curVis[src] = 1;
            //cout << "marking " << src << " as visited.\n";
            vector<int> currVec = adj[src];
            for(int j = 0; j < currVec.size() && *ifCyclePresent == 0; ++j){
                //cout << src <<"'s neb is " << currVec[j] << "\n";
                if(curVis[currVec[j]] == 0 && *ifCyclePresent == 0)
                    dfsUtil(currVec[j], adj, visited, curVis, ifCyclePresent, numCourses);
                else{
                    //cout << "back-edge found from: " << src << " to " << currVec[j] <<"\n";
                    *ifCyclePresent = 1;
                    return;
                }
            }
            curVis[src] = 0;
        }
    }
    
    void buildPreReqGraph(vector<vector<int>> &adj, vector<pair<int, int>>& prerequisites, int numCourses){
        for(int i = 0; i < prerequisites.size(); ++i){
            pair<int, int> currPair = prerequisites[i];
            adj[currPair.second].push_back(currPair.first);
        }
    }
    
    void printGraph(vector<vector<int>> &adj, int numCourses){
        for(int i = 0; i < adj.size(); ++i){
            for(int j = 0; j < adj[i].size(); ++j){
                cout << "edge present:" << i << " -> " << adj[i][j] << "\n"; 
            }
        }
    }
    
    /*
    void dfsUtil(int src, int* adj, int* visited, bool* curVis, int* ifCyclePresent, int numCourses){
        visited[src] = 1;
        curVis[src] = 1;
        cout << "marking " << src << " as visited.\n";
        //bool noNeigh;
        for(int j = 0; j < numCourses; ++j){
            
            if(adj[src*numCourses + j] == 1 && visited[j] == 0){ // neighbor found
                if(curVis[j] == 1){
                    cout << "back-edge true for: " << src << " to " << j <<"\n";
                    *ifCyclePresent = 1;
                    cout << "cycle found returning\n";
                    return;
                }
                //noNeigh = false;
                cout << src <<"'s neb is " << j << "\n";
                if(*ifCyclePresent == 0){
                    dfsUtil(j, adj, visited, curVis, ifCyclePresent, numCourses);   
                }
            }
        }
        curVis[src] = 0;    
    }
    */
    /*void dfsUtil(int src, int* adj, int* visited, int* ifCyclePresent){ // return false if a back edge is found
        visited[src] = 1;
        stack<int> dfsStack;
        dfsStack.push(src);
        while(!dfsStack.empty()){
            int currNode = dfsStack.top();
            bool allNebsDone = true;
            for(int i = 0; i < numCourses; ++i){
                if(adj[currNode*numCourses + i]){ // neighbor found
                    if(!visited[i]){ // not visited
                        allNebsDone = false;
                        dfsStack.push(i);
                        visited[i] = 1;
                    }else{ // visited
                        *ifCyclePresent = 1;
                        return;
                    }
                }
            }
            if(allNebsDone){
                dfsStack.pop();
            }
        }
    }*/
    /*
    void buildPreReqGraph(int *adj, vector<pair<int, int>>& prerequisites, int numCourses){
        for(int i = 0; i < prerequisites.size(); ++i){
            pair<int, int> currPair = prerequisites[i];
            adj[currPair.second * numCourses + currPair.first] = 1;
        }
    }
    
    void printGraph(int *adj, int numCourses){
        for(int i = 0; i < numCourses; ++i){
            for(int j = 0; j < numCourses; ++j){
                if(adj[i*numCourses + j] == 1){
                    cout << "edge present:" << i << " -> " << j << "\n"; 
                }
            }
        }
    }
    */
};